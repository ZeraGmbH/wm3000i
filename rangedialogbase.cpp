//Added by qt3to4:
#include <QShowEvent>
#include "rangedialogbase.h"
#include "ui_rangedialogbase.h"

RangeDialogBase::RangeDialogBase( QWidget* parent ):
    QDialog(parent),
    ui(new Ui::RangeDialogBase)
{
    ui->setupUi(this);
}

RangeDialogBase::~RangeDialogBase()
{
    delete ui;
}



void RangeDialogBase::ActualizeDialog() // aktualisiert dialoganzeige
{
    if ( m_ConfData.m_sRangeNVorgabe == "Auto" )
    ui->RangeNComboBox->setCurrentItem(m_sNXItemList.findIndex(m_ConfData.m_sRangeNVorgabe));
    else
    ui->RangeNComboBox->setCurrentItem(m_sNXItemList.findIndex(m_ConfData.m_sRangeN));
    if ( m_ConfData.m_sRangeXVorgabe == "Auto" )
    ui->RangeXComboBox->setCurrentItem(m_sNXItemList.findIndex(m_ConfData.m_sRangeXVorgabe));
    else
    ui->RangeXComboBox->setCurrentItem(m_sNXItemList.findIndex(m_ConfData.m_sRangeX));
    if ( m_ConfData.m_sRangeECTVorgabe == "Auto")
    ui->RangeECTComboBox->setCurrentItem(m_sECTItemList.findIndex(m_ConfData.m_sRangeECTVorgabe));
    else
    ui->RangeECTComboBox->setCurrentItem(m_sECTItemList.findIndex(m_ConfData.m_sRangeECT));
    switch (m_ConfData.m_nMeasMode) {
    case In_IxDiff:
    case In_IxAbs:
        ui->RangeXComboBox->setEnabled(true);
        ui->RangeECTComboBox->setEnabled(false);
        break;
    case In_ECT:
        ui->RangeXComboBox->setEnabled(false);
        ui->RangeECTComboBox->setEnabled(true);
        break;
    case In_nConvent:
        ui->RangeXComboBox->setEnabled(false);
        ui->RangeECTComboBox->setEnabled(false);
        break;
    }
}


void RangeDialogBase::SetRangeListSlot( cWMRangeList& nx,  cWMRangeList& ect)
{
    CWMRange *Range;
    Q3PtrListIterator<CWMRange> it(nx);

   while (!m_sNXItemList.isEmpty()) m_sNXItemList.pop_back(); // liste erst mal leeren
   for(Range=it.toFirst();Range;Range=++it) m_sNXItemList.append(Range->Name());
   ui->RangeNComboBox->clear();
   ui->RangeNComboBox->insertStringList(m_sNXItemList);
   ui->RangeXComboBox->clear();
   ui->RangeXComboBox->insertStringList(m_sNXItemList);

   it=ect;
   while (!m_sECTItemList.isEmpty()) m_sECTItemList.pop_back(); // liste erst mal leeren
   for(Range=it.toFirst();Range;Range=++it) m_sECTItemList.append(Range->Name());
   ui->RangeECTComboBox->clear();
   ui->RangeECTComboBox->insertStringList(m_sECTItemList);
   ActualizeDialog();
}


void RangeDialogBase::SetConfInfoSlot(cConfData *cd)
{
    m_ConfData=*cd;
    ActualizeDialog();
}


void RangeDialogBase::SetNRangeSlot( const QString & nr )
{
    m_ConfData.m_sRangeNVorgabe=nr;
    if ( nr != QString("Auto") ) m_ConfData.m_sRangeNSoll=nr; // damit wird sofort geschaltet
    emit SendRange(&m_ConfData);
}


void RangeDialogBase::SetXRangeSlot( const QString & xr)
{
    m_ConfData.m_sRangeXVorgabe=xr;
    if ( xr != QString("Auto") ) m_ConfData.m_sRangeXSoll=xr;
    emit SendRange(&m_ConfData);
}



void RangeDialogBase::SetECTRangeSlot( const QString & er)
{
    m_ConfData.m_sRangeECTVorgabe=er;
    if ( er != QString("Auto") ) m_ConfData.m_sRangeECTSoll=er;
    emit SendRange(&m_ConfData);
}


void RangeDialogBase::showEvent( QShowEvent * )
{
    emit SendRangeInfoReqSignal(); // aufforderung an device bereichliste und configuration zu senden
}


void RangeDialogBase::RemoteCtrlInfoSlot(bool remote)
{
    setEnabled(!remote);
}
