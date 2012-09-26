/****************************************************************************
** Form interface generated from reading ui file 'rangedialogbase.ui'
**
** Created: Mi Sep 19 14:11:07 2012
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.4   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef RANGEDIALOGBASE_H
#define RANGEDIALOGBASE_H

#include <qvariant.h>
#include <qdialog.h>
#include "wmglobal.h"

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QComboBox;
class QLabel;

class RangeDialogBase : public QDialog
{
    Q_OBJECT

public:
    RangeDialogBase( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~RangeDialogBase();

    QComboBox* RangeNComboBox;
    QComboBox* RangeECTComboBox;
    QLabel* RangeXTextLabel;
    QComboBox* RangeXComboBox;
    QLabel* RangeECTTextLabel;
    QLabel* RangeNTextLabel;

public slots:
    virtual void SetRangeListSlot( cWMRangeList & nx, cWMRangeList & ect );
    void SetConfInfoSlot( cConfData * cd );
    void SetNRangeSlot( const QString & nr );
    void SetXRangeSlot( const QString & xr );
    virtual void SetECTRangeSlot( const QString & er );
    virtual void RemoteCtrlInfoSlot( bool remote );

signals:
    void SendRange(cConfData*);
    void isVisible(bool);
    void SendRangeInfoReqSignal();

protected:
    virtual void showEvent( QShowEvent * );

    QGridLayout* RangeDialogBaseLayout;

protected slots:
    virtual void languageChange();

private:
    QStringList m_sECTItemList;
    QStringList m_sNXItemList;
    cConfData m_ConfData;

    void ActualizeDialog();

};

#endif // RANGEDIALOGBASE_H
