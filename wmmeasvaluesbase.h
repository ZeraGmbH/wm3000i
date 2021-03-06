/****************************************************************************
** Form interface generated from reading ui file 'wmmeasvaluesbase.ui'
**
** Created: Mi Sep 19 15:32:20 2012
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.4   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef WMMEASVALUESBASE_H
#define WMMEASVALUESBASE_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qdialog.h>
#include <qlabel.h>
#include <QTimer>

#include "bigletter.h"
#include "wmglobal.h"
#include "widgeom.h"
#include "wmmeasconfigbase.h"
#include "formatinfo.h"

namespace Ui {
    class WMMeasValuesBase;
}

class WMMeasValuesBase : public QDialog
{
    Q_OBJECT

public:
    explicit WMMeasValuesBase( QWidget* parent = 0);
    ~WMMeasValuesBase();

public slots:
    virtual void ShowHideMVSlot( bool b );
    virtual void SetActualValuesSlot( cwmActValues * av );
    virtual void ActualizeLPSlot( cwmActValues * av );
    virtual void SetConfInfoSlot( cConfData * cd );
    virtual void ActualizeLoadPoint();
    bool LoadSession( QString session );
    void SaveSession( QString session );
    virtual void ReceiveFormatInfoSlot(int m, int m2, int n, cFormatInfo * fi );

signals:
    void isVisibleSignal(bool);
    void SendFormatInfoSignal(bool, int, int, int, cFormatInfo*);

protected:
    virtual void closeEvent( QCloseEvent * ce );
    virtual void resizeEvent( QResizeEvent * e );
    virtual void showEvent( QShowEvent* e);
    virtual void moveEvent( QMoveEvent *);
    virtual void contextMenuEvent( QContextMenuEvent * );

private:
    Ui::WMMeasValuesBase *ui;
    cWidgetGeometry m_widGeometry;
    cwmActValues m_ActValues;
    cConfData m_ConfData;
    WMMeasConfigBase* m_pContextMenu;
    cFormatInfo m_Format[4];
    int m_nDisplayMode;
    int m_nLPDisplayMode;

    QPixmap image0;
    QTimer m_Timer;

    void init();
    void destroy();
    void cmpResize();
    virtual void ActualizeDisplay();

private slots:
    void saveConfiguration();

};

#endif // WMMEASVALUESBASE_H
