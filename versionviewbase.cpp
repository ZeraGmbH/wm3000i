/****************************************************************************
** Form implementation generated from reading ui file 'versionviewbase.ui'
**
** Created: Mi Sep 19 14:16:00 2012
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.4   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "versionviewbase.h"
#include "ui_versionviewbase.h"

VersionsViewBase::VersionsViewBase( QWidget* parent ):
    QDialog(parent),
    ui(new Ui::VersionViewBase)
{
    ui->setupUi(this);
}

VersionsViewBase::~VersionsViewBase()
{
    delete ui;
}

void VersionsViewBase::ReceiveVersionData(tVersSerial* p)
{
    pVersion = p;
    ui->DeviceLabel->setText(p->DeviceName);
    ui->DevVersionLabel->setText(p->DeviceVersion);
    ui->SerialNrLabel->setText(p->PCBSerialNr);
    ui->AdjDataText->setText(p->JDataChksum);
    ui->PCBVersionText->setText( p->PCBVersion);
    ui->PCBServerText->setText(p->PCBServer);
    ui->DSPVersionText->setText(p->DSPVersion);
    ui->DSPServerText->setText( p->DSPServer);
}




void VersionsViewBase::ShowVersionSlot()
{
    show();
}
