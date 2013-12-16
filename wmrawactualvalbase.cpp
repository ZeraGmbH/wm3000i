//Added by qt3to4:
#include <QContextMenuEvent>
#include <QCloseEvent>
#include <QFileInfo>
#include "wmrawactualvalbase.h"
#include "ui_wmrawactualvalbase.h"

const double PI2 = 6.283185307;


WMRawActualValBase::WMRawActualValBase( QWidget* parent):
    QDialog(parent),
    ui(new Ui::WMRawActualValBase)
{
    ui->setupUi(this);
    init();
}


WMRawActualValBase::~WMRawActualValBase()
{
    destroy();
    delete ui;
}

void WMRawActualValBase::init()
{
    AmplDispMode = x1;
    PrimSekDispMode = prim;
    WinkelDispMode = mathpos;
    m_pContextMenu = new WMRawActualConfigBase(this);
    m_Timer.setSingleShot(true);
    connect(this,SIGNAL(SendVektorDispFormat(int,int,int)),m_pContextMenu,SLOT(ReceiveDisplayConfSlot(int,int,int)));
    connect(m_pContextMenu,SIGNAL(SendVektorDisplayFormat(int,int,int)),this,SLOT(ReceiveVektorDispFormat(int,int,int)));
    connect(&m_Timer, SIGNAL(timeout()), this, SLOT(saveConfiguration()));
    LoadSession(".ses");
}


void WMRawActualValBase::destroy()
{
    SaveSession(".ses");
}


void WMRawActualValBase::saveConfiguration()
{
    SaveSession(".ses");
}


void WMRawActualValBase::closeEvent(QCloseEvent* ce)
{
    m_widGeometry.SetGeometry(pos(),size()); // wir halten visible und geometrie nach
    m_widGeometry.SetVisible(0);
    emit isVisibleSignal(false);
    m_Timer.start(500);
    ce->accept();
}


void WMRawActualValBase::resizeEvent(QResizeEvent *)
{
    m_Timer.start(500);
}

void WMRawActualValBase::moveEvent(QMoveEvent *)
{
    m_Timer.start(500);
}


void WMRawActualValBase::ShowHideAVSlot( bool b)
{
    if (b) show();else close();
}


void WMRawActualValBase::ReceiveAVDataSlot( cwmActValues *ActValues )
{
        m_ActValues = *ActValues;
        // hier wird später die Anzeige bedient
        if (isVisible()) {
            double phi;
            double radgrad = 57.295779; // 360/(2*PI) winkel sind im bogenmass

            // amplitude der grundschwingung
            double ampl;
            if (PrimSekDispMode == prim)
                ampl = fabs(m_ActValues.VekN);
            else
                ampl = fabs(m_ActValues.VekNSek);
            if (AmplDispMode == x1_SQRT2)
                ampl/=1.414213562;
            ui->XnAmplDisp -> setText( QString("%1 A").arg(ampl,10,'f',5) );

            /*
        phi = m_ActValues.PHIN * radgrad;
        if (WinkelDispMode == techpos)
            phi = 360.0-phi;
        XnPhaseDisp -> setText( QString("%1 %2").arg(phi,8,'f',4).arg( trUtf8("°")) );
        */

            phi = m_ActValues.PHIN; // winkel sind zwischen 0 .. 2PI
            if (WinkelDispMode == techpos)
                phi = PI2 - phi;
            phi = normWinkelrad_PIPI(phi);
            phi *= radgrad;
            ui->XnPhaseDisp -> setText( QString("%1 %2").arg(phi,8,'f',4).arg( trUtf8("°")) );

            // amplitude der grundschwingung
            if (PrimSekDispMode == prim)
                ampl = fabs(m_ActValues.VekX);
            else
                ampl = fabs(m_ActValues.VekXSek);
            if (AmplDispMode == x1_SQRT2)
                ampl/=1.414213562;
            ui->XxAmplDisp -> setText( QString("%1 A").arg(ampl,10,'f',5) );

            /*
        phi = m_ActValues.PHIX * radgrad;
        if (WinkelDispMode == techpos)
            phi = 360.0-phi;
        XxPhaseDisp -> setText( QString("%1 %2").arg(phi,8,'f',4).arg( trUtf8("°")) );
        */

            phi = m_ActValues.PHIX;
            if (WinkelDispMode == techpos)
                phi = PI2 - phi;
            phi = normWinkelrad_PIPI(phi);
            phi *= radgrad;
            ui->XxPhaseDisp -> setText( QString("%1 %2").arg(phi,8,'f',4).arg( trUtf8("°")) );

            // amplitude der grundschwingung
            if (PrimSekDispMode == prim)
                ampl = fabs(m_ActValues.VekDX);
            else
                ampl = fabs(m_ActValues.VekDXSek);
            if (AmplDispMode == x1_SQRT2)
                ampl/=1.414213562;
            ui->dXxAmplDisp -> setText( QString("%1 A").arg(ampl,10,'f',5) );

            phi = UserAtan(m_ActValues.VekDX);
            if (WinkelDispMode == techpos)
                phi = PI2 - phi;
            phi = normWinkelrad_PIPI(phi);
            phi *= radgrad;
            ui->dXxPhaseDisp -> setText( QString("%1 %2").arg(phi,8,'f',4).arg( trUtf8("°")) );

            ui->FreqDisp -> setText( QString("%1 Hz").arg(ActValues->Frequenz,9,'f',5) );
        }

}


bool WMRawActualValBase::LoadSession(QString session)
{
    QFileInfo fi(session);
    QString ls = QString("%1/.wm3000i/%2%3").arg(wm3000iHome).arg(name()).arg(fi.fileName());
    QFile file(ls);
    if ( file.open( QIODevice::ReadOnly ) ) {
    QDataStream stream( &file );
    stream >> m_widGeometry;
    stream >> AmplDispMode;
    stream >> WinkelDispMode,
    stream >> PrimSekDispMode;
    file.close();
    hide();
    resize(m_widGeometry.m_Size);
    move(m_widGeometry.m_Point);
    if (m_widGeometry.vi)
    {
        show();
        emit isVisibleSignal(true);
    }
// FVWM und Gnome verhalten sich anders
#ifndef FVWM
    move(m_widGeometry.m_Point);
#endif
    return true;
    }
    return false;
}


void WMRawActualValBase::SaveSession(QString session)
{
    if(!QDir(QString("%1/.wm3000i/").arg(wm3000iHome)).exists())
    {
      //create temporary object that gets deleted when leaving the control block
      QDir().mkdir(QString("%1/.wm3000i/").arg(wm3000iHome));
    }
    QFileInfo fi(session);
    QString ls = QString("%1/.wm3000i/%2%3").arg(wm3000iHome).arg(name()).arg(fi.fileName());
    QFile file(ls);
//    file.remove();
    if ( file.open( QIODevice::Unbuffered | QIODevice::WriteOnly ) ) {
    file.at(0);

    int vi;
    vi = (isVisible()) ? 1 : 0;
    if (vi)
        m_widGeometry.SetGeometry(pos(),size());
    m_widGeometry.SetVisible(vi);

    QDataStream stream( &file );
    stream << m_widGeometry;
    stream << AmplDispMode;
    stream << WinkelDispMode;
    stream << PrimSekDispMode;
    file.close();
    }
}


void WMRawActualValBase::contextMenuEvent( QContextMenuEvent * )
{
    emit SendVektorDispFormat(AmplDispMode, WinkelDispMode, PrimSekDispMode);
    m_pContextMenu->show();
}


void WMRawActualValBase::ReceiveVektorDispFormat( int m, int m2, int m3)
{
    AmplDispMode = m;
    WinkelDispMode = m2;
    PrimSekDispMode = m3;
}


