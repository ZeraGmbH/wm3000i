// zerainfo definition

#include <qstring.h>
#include <qmessagebox.h>
#include <qpixmap.h>

#include "zerainfo.h"
#include "wm3000i.h"

extern cWM3000I* g_WMDevice;

void cZeraInfo::AboutZeraSlot()
{
    QMessageBox *pAboutZera=new QMessageBox(QString("About ZERA"),
					       tr("<h3>About ZERA</h3>"
					          "<p><br>ZERA was founded in 1920.</p>"
					          "<p>It is a developer and manufactor of high precision<br>measurement systems for the energy market.</p>"
					          "<p>We provide powerful solutions for meter testing<br>as well as transformer testing.</p>"
					          "<p>For further information please visit <tt>http://www.zera.de</tt></p>"),
					      QMessageBox::NoIcon,
					      QMessageBox::NoButton,
					      QMessageBox::NoButton,
					      QMessageBox::NoButton);
    
    pAboutZera->setIconPixmap(QPixmap("./images/zeralogo.png"));
    pAboutZera->show();
}					    


void cZeraInfo::AboutWM3000Slot()
{
    QMessageBox *pAboutWM;

    if (g_WMDevice->isConventional())
        pAboutWM=new QMessageBox(QString("About WM1000I"),
                     tr("<h3>About WM1000I</h3>"
                        "<p>WM1000I is the new current transformer test<br>device developed by ZERA.</p>"
                        "<p>It provides abilities of testing conventional<br>transformers.</p>"),
                        QMessageBox::NoIcon,
                        QMessageBox::NoButton,
                        QMessageBox::NoButton,
                        QMessageBox::NoButton);
    else
        pAboutWM=new QMessageBox(QString("About WM3000I"),
                     tr("<h3>About WM3000I</h3>"
                        "<p>WM3000I is the new current transformer test<br>device developed by ZERA.</p>"
                        "<p>It provides abilities of testing conventional<br>transformers, ECT as well as nonconventional<br>transformers using IEC 61850-9-2.</p>"),
                        QMessageBox::NoIcon,
                        QMessageBox::NoButton,
                        QMessageBox::NoButton,
                        QMessageBox::NoButton);
    
     pAboutWM->show();
}

