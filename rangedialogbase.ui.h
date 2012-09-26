//Added by qt3to4:
#include <QShowEvent>
/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you want to add, delete, or rename functions or slots, use
** Qt Designer to update this file, preserving your code.
**
** You should not define a constructor or destructor in this file.
** Instead, write your code in functions called init() and destroy().
** These will automatically be called by the form's constructor and
** destructor.
*****************************************************************************/


void RangeDialogBase::ActualizeDialog() // aktualisiert dialoganzeige
{
    if ( m_ConfData.m_sRangeNVorgabe == "Auto" )
	RangeNComboBox->setCurrentItem(m_sNXItemList.findIndex(m_ConfData.m_sRangeNVorgabe));
    else
	RangeNComboBox->setCurrentItem(m_sNXItemList.findIndex(m_ConfData.m_sRangeN));
    if ( m_ConfData.m_sRangeXVorgabe == "Auto" )
	RangeXComboBox->setCurrentItem(m_sNXItemList.findIndex(m_ConfData.m_sRangeXVorgabe));
    else
	RangeXComboBox->setCurrentItem(m_sNXItemList.findIndex(m_ConfData.m_sRangeX));
    if ( m_ConfData.m_sRangeECTVorgabe == "Auto")
	RangeECTComboBox->setCurrentItem(m_sECTItemList.findIndex(m_ConfData.m_sRangeECTVorgabe));
    else
	RangeECTComboBox->setCurrentItem(m_sECTItemList.findIndex(m_ConfData.m_sRangeECT));
    switch (m_ConfData.m_nMeasMode) {
	case In_IxDiff:
	    RangeXComboBox->setEnabled(true);
	    RangeECTComboBox->setEnabled(false);
	    break;
	case In_ECT:
	    RangeXComboBox->setEnabled(false);
	    RangeECTComboBox->setEnabled(true);
	    break;
	case In_nConvent:
	    RangeXComboBox->setEnabled(false);
	    RangeECTComboBox->setEnabled(false);
	    break;
	}
}


void RangeDialogBase::SetRangeListSlot( cWMRangeList& nx,  cWMRangeList& ect)
{
    CWMRange *Range;
    Q3PtrListIterator<CWMRange> it(nx);
   
   while (!m_sNXItemList.isEmpty()) m_sNXItemList.pop_back(); // liste erst mal leeren
   for(Range=it.toFirst();Range;Range=++it) m_sNXItemList.append(Range->Name());
   RangeNComboBox->clear();
   RangeNComboBox->insertStringList(m_sNXItemList);
   RangeXComboBox->clear();
   RangeXComboBox->insertStringList(m_sNXItemList);
      
   it=ect;
   while (!m_sECTItemList.isEmpty()) m_sECTItemList.pop_back(); // liste erst mal leeren   
   for(Range=it.toFirst();Range;Range=++it) m_sECTItemList.append(Range->Name());
   RangeECTComboBox->clear();
   RangeECTComboBox->insertStringList(m_sECTItemList);
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
