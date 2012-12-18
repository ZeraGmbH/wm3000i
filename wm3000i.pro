TEMPLATE	= app
LANGUAGE	= C++

CONFIG	+= qt debug

INCLUDEPATH	+= .


HEADERS	+= bigletter.h \
	cbiface.h \
	cmdiface.h \
	cmdinterpret.h \
	complex.h \
	confdata.h \
	devserver.h \
	dspiface.h \
	en61850.h \
	eparameter.h \
	ethadress.h \
	formatinfo.h \
	lbrowser.h \
	logfile.h \
	logfileview.h \
	ownerror.h \
	parse.h \
	pcbiface.h \
	range.h \
	zeraglobal.h \
	wmglobal.h \
	wm3000i.h \
	zhclientsocket.h \
	zhserveriface.h \
	zerainfo.h \
	scpi.h \
	wm3000scpiface.h \
	scpiface.h \
	tools.h \
	widgeom.h \
	wmeditor.h \
    wmviewbase.h \
    wmmeasvaluesbase.h \
    wmoeviewbase.h \
    wmrawactualvalbase.h \
    en61850monitor.h \
    confdialogbase.h \
    rangedialogbase.h \
    versionviewbase.h \
    wmmeasconfigbase.h \
    wmrawactualconfigbase.h

SOURCES	+= BigLetter.cpp \
	Logfile.cpp \
	Range.cpp \
	cmdinterpret.cpp \
	complex.cpp \
	confdata.cpp \
	devserver.cpp \
	dspiface.cpp \
	eparameter.cpp \
	ethadress.cpp \
	formatinfo.cpp \
	lbrowser.cpp \
	logfileview.cpp \
	main.cpp \
	ownerror.cpp \
	parse.cpp \
	pcbiface.cpp \
	wm3000i.cpp \
	zhclientsocket.cpp \
	zhserveriface.cpp \
	zerainfo.cpp \
	scpi.cpp \
	wm3000scpiface.cpp \
	scpiface.cpp \
	tools.cpp \
	widgeom.cpp \
	wmeditor.cpp \
    wmviewbase.cpp \
    wmmeasvaluesbase.cpp \
    wmoeviewbase.cpp \
    wmrawactualvalbase.cpp \
    en61850monitor.cpp \
    confdialogbase.cpp \
    rangedialogbase.cpp \
    versionviewbase.cpp \
    wmmeasconfigbase.cpp \
    wmrawactualconfigbase.cpp


FORMS	= confdialogbase.ui \
	en61850monitor.ui \
	rangedialogbase.ui \
	versionviewbase.ui \
	wmmeasconfigbase.ui \
	wmmeasvaluesbase.ui \
	wmoeviewbase.ui \
	wmrawactualconfigbase.ui \
	wmrawactualvalbase.ui \
	wmviewbase.ui


######################################################################
# Automatically generated by qmake (1.07a) Thu May 12 09:23:36 2005
######################################################################


TRANSLATIONS    = wm3000i_gb.ts

# Input
#The following line was inserted by qt3to4
QT += xml  qt3support 

target.path = /usr/bin
INSTALLS += target
