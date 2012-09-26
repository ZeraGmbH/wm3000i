/****************************************************************************
** Form implementation generated from reading ui file 'rangedialogbase.ui'
**
** Created: Mi Sep 19 14:15:53 2012
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.4   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "rangedialogbase.h"

#include <qvariant.h>
#include <qptrlist.h>
#include <qcombobox.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "wmglobal.h"
#include "range.h"
#include "rangedialogbase.ui.h"
/*
 *  Constructs a RangeDialogBase as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
RangeDialogBase::RangeDialogBase( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "RangeDialogBase" );
    setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)5, (QSizePolicy::SizeType)5, 0, 0, sizePolicy().hasHeightForWidth() ) );
    setMinimumSize( QSize( 100, 10 ) );
    QFont f( font() );
    setFont( f ); 
    setSizeGripEnabled( FALSE );
    setModal( FALSE );
    RangeDialogBaseLayout = new QGridLayout( this, 1, 1, 11, 6, "RangeDialogBaseLayout"); 
    RangeDialogBaseLayout->setResizeMode( QLayout::Fixed );

    RangeNComboBox = new QComboBox( FALSE, this, "RangeNComboBox" );

    RangeDialogBaseLayout->addWidget( RangeNComboBox, 0, 1 );

    RangeECTComboBox = new QComboBox( FALSE, this, "RangeECTComboBox" );

    RangeDialogBaseLayout->addWidget( RangeECTComboBox, 2, 1 );

    RangeXTextLabel = new QLabel( this, "RangeXTextLabel" );

    RangeDialogBaseLayout->addWidget( RangeXTextLabel, 1, 0 );

    RangeXComboBox = new QComboBox( FALSE, this, "RangeXComboBox" );

    RangeDialogBaseLayout->addWidget( RangeXComboBox, 1, 1 );

    RangeECTTextLabel = new QLabel( this, "RangeECTTextLabel" );
    RangeECTTextLabel->setAlignment( int( QLabel::AlignVCenter ) );

    RangeDialogBaseLayout->addWidget( RangeECTTextLabel, 2, 0 );

    RangeNTextLabel = new QLabel( this, "RangeNTextLabel" );

    RangeDialogBaseLayout->addWidget( RangeNTextLabel, 0, 0 );
    languageChange();
    resize( QSize(149, 115).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( RangeNComboBox, SIGNAL( activated(const QString&) ), this, SLOT( SetNRangeSlot(const QString&) ) );
    connect( RangeXComboBox, SIGNAL( activated(const QString&) ), this, SLOT( SetXRangeSlot(const QString&) ) );
    connect( RangeECTComboBox, SIGNAL( activated(const QString&) ), this, SLOT( SetECTRangeSlot(const QString&) ) );

    // buddies
    RangeXTextLabel->setBuddy( RangeXComboBox );
    RangeECTTextLabel->setBuddy( RangeECTComboBox );
    RangeNTextLabel->setBuddy( RangeNComboBox );
}

/*
 *  Destroys the object and frees any allocated resources
 */
RangeDialogBase::~RangeDialogBase()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void RangeDialogBase::languageChange()
{
    setCaption( tr( "Messbereiche" ) );
    RangeXTextLabel->setText( tr( "&X:" ) );
    RangeECTTextLabel->setText( tr( "&ECT:" ) );
    RangeNTextLabel->setText( tr( "&N:" ) );
}

