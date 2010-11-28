#ifndef DYN_UI_NAVIGATOR_H
#define DYN_UI_NAVIGATOR_H

/********************************************************************************
** Form generated from reading UI file 'navigator.ui'
**
** Created: Fri Nov 26 22:18:28 2010
**      by: Qt User Interface Compiler version 4.7.1
********************************************************************************/


#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTabWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QtGui/QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE

class Ui_Navigator : public QWidget
{

public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout,*tabHLayout;
    QToolButton *backButton;
    QComboBox *addressBar;
    QToolButton *goButton;
    QTabWidget *tabWidget;
    QWidget *drives;
    QWidget *fav;
    QWidget *Navigator;
    QMainWindow *mw;

public:
    Ui_Navigator(QWidget *Navigator,QMainWindow *mw)
    {
        this->Navigator = Navigator;
        this->mw = mw;
	if (Navigator->objectName().isEmpty())
	    Navigator->setObjectName(QString::fromUtf8("Navigator"));
	Navigator->resize(467, 97);
	verticalLayout = new QVBoxLayout(Navigator);
	verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
	verticalLayout->setContentsMargins(2, 2, 2, 5);
	horizontalLayout = new QHBoxLayout();
	horizontalLayout->setSpacing(1);
	horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
	backButton = new QToolButton(Navigator);
	backButton->setObjectName(QString::fromUtf8("backButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
	sizePolicy.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);

	horizontalLayout->addWidget(backButton);

	addressBar = new QComboBox(Navigator);
	addressBar->setObjectName(QString::fromUtf8("addressBar"));
        //this->addressBar->setEditable(1);
	sizePolicy.setHeightForWidth(addressBar->sizePolicy().hasHeightForWidth());
        addressBar->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
	addressBar->setInsertPolicy(QComboBox::InsertAtTop);

	horizontalLayout->addWidget(addressBar);

	goButton = new QToolButton(Navigator);
	goButton->setObjectName(QString::fromUtf8("goButton"));
	sizePolicy.setHeightForWidth(goButton->sizePolicy().hasHeightForWidth());
        goButton->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);

	horizontalLayout->addWidget(goButton);

	horizontalLayout->setStretch(1, 1);

	verticalLayout->addLayout(horizontalLayout);
	tabWidget = new QTabWidget(Navigator);
	tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
	tabWidget->setTabPosition(QTabWidget::South);
	tabWidget->setTabsClosable(true);
	drives = new QWidget();
	drives->setObjectName(QString::fromUtf8("drives"));
        tabHLayout = new QHBoxLayout(drives);

	tabWidget->addTab(drives, QString());
	fav = new QWidget();
	fav->setObjectName(QString::fromUtf8("fav"));
	tabWidget->addTab(fav, QString());

	verticalLayout->addWidget(tabWidget);


	retranslateUi(Navigator);

	tabWidget->setCurrentIndex(0);


	QMetaObject::connectSlotsByName(Navigator);
    } // setupUi

    void retranslateUi(QWidget *Navigator)
    {
	Navigator->setWindowTitle(QApplication::translate("Navigator", "Form", 0, QApplication::UnicodeUTF8));
	backButton->setText(QApplication::translate("Navigator", "Back", 0, QApplication::UnicodeUTF8));
	goButton->setText(QApplication::translate("Navigator", "Go", 0, QApplication::UnicodeUTF8));
	tabWidget->setTabText(tabWidget->indexOf(drives), QApplication::translate("Navigator", "Meghajt\303\263", 0, QApplication::UnicodeUTF8));
	tabWidget->setTabText(tabWidget->indexOf(fav), QApplication::translate("Navigator", "Kedvencek", 0, QApplication::UnicodeUTF8));
    } // retranslateUi
    void add_drive_button(QString button){
            QStringList letter = button.split("://");
            QToolButton *drive = new QToolButton(drives);
            tabHLayout->addWidget(drive);
            QSizePolicy sizePolicy = QSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
            sizePolicy.setHorizontalStretch(1);
            sizePolicy.setVerticalStretch(0);
            drive->setObjectName(button);
            drive->setText(letter[1]);
            drive->setSizePolicy(sizePolicy);
            // signalokat itt kene letrehozni a buttonhoz
            connect(drive,SIGNAL(clicked()),mw,SLOT(driveButtonClicked()));
    } //adddrivebutton
    void addAddressBarItem(QString url){
        this->addressBar->insertItem(0,url,url);
        this->addressBar->setCurrentIndex(0);
    }
   void setPreviousAddress(){
        this->addressBar->setCurrentIndex(this->addressBar->currentIndex()+1);
    }
};

namespace Ui {
    class Navigator: public Ui_Navigator {};
} // namespace Ui

QT_END_NAMESPACE


#endif // DYN_UI_NAVIGATOR_H
