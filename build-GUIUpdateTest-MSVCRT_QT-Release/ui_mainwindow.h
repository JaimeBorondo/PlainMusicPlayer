/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd_Songs_To_Libary;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QTreeWidget *LibraryMenu;
    QTableView *tableView;
    QVBoxLayout *verticalLayout;
    QTextBrowser *NowPlaying;
    QHBoxLayout *Controls;
    QHBoxLayout *PrevPlayNext_Controls;
    QPushButton *previousButton;
    QPushButton *playpauseButton;
    QPushButton *nextButton;
    QHBoxLayout *time_Controls;
    QSlider *horizontalSlider;
    QTextBrowser *textBrowser_2;
    QHBoxLayout *volume_Controls;
    QPushButton *pushButton;
    QSlider *volumeslider;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(841, 406);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionAdd_Songs_To_Libary = new QAction(MainWindow);
        actionAdd_Songs_To_Libary->setObjectName(QStringLiteral("actionAdd_Songs_To_Libary"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMaximumSize(QSize(20000, 20000));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        LibraryMenu = new QTreeWidget(splitter);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        LibraryMenu->setHeaderItem(__qtreewidgetitem);
        LibraryMenu->setObjectName(QStringLiteral("LibraryMenu"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LibraryMenu->sizePolicy().hasHeightForWidth());
        LibraryMenu->setSizePolicy(sizePolicy1);
        LibraryMenu->setMaximumSize(QSize(300, 16777215));
        splitter->addWidget(LibraryMenu);
        LibraryMenu->header()->setVisible(false);
        tableView = new QTableView(splitter);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setTextElideMode(Qt::ElideNone);
        tableView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableView->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableView->setShowGrid(true);
        tableView->setWordWrap(false);
        splitter->addWidget(tableView);
        tableView->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_2->addWidget(splitter);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        NowPlaying = new QTextBrowser(centralWidget);
        NowPlaying->setObjectName(QStringLiteral("NowPlaying"));
        NowPlaying->setMaximumSize(QSize(16777215, 25));

        verticalLayout->addWidget(NowPlaying);

        Controls = new QHBoxLayout();
        Controls->setSpacing(6);
        Controls->setObjectName(QStringLiteral("Controls"));
        Controls->setSizeConstraint(QLayout::SetMinimumSize);
        PrevPlayNext_Controls = new QHBoxLayout();
        PrevPlayNext_Controls->setSpacing(6);
        PrevPlayNext_Controls->setObjectName(QStringLiteral("PrevPlayNext_Controls"));
        previousButton = new QPushButton(centralWidget);
        previousButton->setObjectName(QStringLiteral("previousButton"));
        previousButton->setMaximumSize(QSize(30, 25));
        QIcon icon;
        icon.addFile(QStringLiteral("../../../Downloads/Previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        previousButton->setIcon(icon);

        PrevPlayNext_Controls->addWidget(previousButton);

        playpauseButton = new QPushButton(centralWidget);
        playpauseButton->setObjectName(QStringLiteral("playpauseButton"));
        playpauseButton->setMaximumSize(QSize(30, 25));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../../../Downloads/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral("../../../Downloads/Pause.png"), QSize(), QIcon::Normal, QIcon::On);
        playpauseButton->setIcon(icon1);
        playpauseButton->setCheckable(true);
        playpauseButton->setFlat(false);

        PrevPlayNext_Controls->addWidget(playpauseButton);

        nextButton = new QPushButton(centralWidget);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setMaximumSize(QSize(30, 25));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../../../Downloads/Next.png"), QSize(), QIcon::Normal, QIcon::Off);
        nextButton->setIcon(icon2);

        PrevPlayNext_Controls->addWidget(nextButton);


        Controls->addLayout(PrevPlayNext_Controls);

        time_Controls = new QHBoxLayout();
        time_Controls->setSpacing(6);
        time_Controls->setObjectName(QStringLiteral("time_Controls"));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximumSize(QSize(16777215, 25));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(182, 218, 230, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(218, 236, 242, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(91, 109, 115, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(121, 145, 153, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        horizontalSlider->setPalette(palette);
        horizontalSlider->setMaximum(1000);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickInterval(0);

        time_Controls->addWidget(horizontalSlider);

        textBrowser_2 = new QTextBrowser(centralWidget);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setMaximumSize(QSize(70, 25));

        time_Controls->addWidget(textBrowser_2);


        Controls->addLayout(time_Controls);

        volume_Controls = new QHBoxLayout();
        volume_Controls->setSpacing(6);
        volume_Controls->setObjectName(QStringLiteral("volume_Controls"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(false);
        pushButton->setMaximumSize(QSize(16777215, 25));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../../../Downloads/volume.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon3);
        pushButton->setAutoDefault(false);
        pushButton->setFlat(true);

        volume_Controls->addWidget(pushButton);

        volumeslider = new QSlider(centralWidget);
        volumeslider->setObjectName(QStringLiteral("volumeslider"));
        volumeslider->setMaximumSize(QSize(16777215, 25));
        volumeslider->setValue(20);
        volumeslider->setOrientation(Qt::Horizontal);

        volume_Controls->addWidget(volumeslider);


        Controls->addLayout(volume_Controls);


        verticalLayout->addLayout(Controls);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 841, 20));
        menuBar->setNativeMenuBar(true);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionAdd_Songs_To_Libary);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Plain Music Player", 0));
        actionAdd_Songs_To_Libary->setText(QApplication::translate("MainWindow", "Add Songs To Libary", 0));
        previousButton->setText(QString());
        playpauseButton->setText(QString());
        nextButton->setText(QString());
        pushButton->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
