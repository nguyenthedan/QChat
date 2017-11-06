#include "mainwindow.h"
//#include "ui_mainwindow.h"

//#include "aboutdialog.hpp"
//#include "addfrienddialog.hpp"
//#include "appinfo.hpp"
//#include "closeapplicationdialog.hpp"
//#include "friendrequestdialog.hpp"
//#include "pageswidget.hpp"
//#include "Settings/settings.hpp"

#include <QApplication>
#include <QDesktopWidget>
#include <QFontDatabase>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QMessageBox>
#include <QStackedWidget>
#include <QToolBar>
#include <QToolButton>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    const int screenWidth = QApplication::desktop()->width();
    const int screenHeight = QApplication::desktop()->height();
    const int appWidth = 500;
    const int appHeight = 300;

    setGeometry((screenWidth - appWidth) / 2, (screenHeight - appHeight) / 2, appWidth, appHeight);

    setObjectName("MainWindow");
    setWindowTitle("developers' test version, not for public use");
    setWindowIcon(QIcon(":/icons/icon64.png"));
    setContextMenuPolicy(Qt::PreventContextMenu);

    // install Unicode 6.1 supporting font
    QFontDatabase::addApplicationFont("://DejaVuSans.ttf");

    splitterWidget = new QSplitter(Qt::Horizontal, this);
    splitterWidget->setObjectName("FriendsSplitter");

    QWidget* friendsLayout = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(friendsLayout);
    layout->setMargin(0);
    layout->setSpacing(0);

//    ourUserItem = new OurUserItemWidget(this);
//    friendsWidget = new FriendsWidget(friendsLayout);

    // Create toolbar
    QToolBar *toolBar = new QToolBar(this);
    toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
    toolBar->setIconSize(QSize(16, 16));
    toolBar->setFocusPolicy(Qt::ClickFocus);

    QToolButton *addFriendButton = new QToolButton(toolBar);
    addFriendButton->setIcon(QIcon("://icons/user_add.png"));
    addFriendButton->setToolTip(tr("Add friend"));
//    connect(addFriendButton, &QToolButton::clicked, this, &MainWindow::onAddFriendButtonClicked);

    QWidget *spacer = new QWidget(toolBar);
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    QToolButton *menuButton = new QToolButton(toolBar);
    menuButton->setIcon(QIcon("://icons/cog.png"));
    menuButton->setToolTip(tr("Menu"));
    menuButton->setPopupMode(QToolButton::InstantPopup);
    QMenu *menu = new QMenu(menuButton);
    settingsAction = menu->addAction(QIcon(":/icons/setting_tools.png"), tr("Settings"), this, SLOT(onSettingsActionTriggered()));
    menu->addAction(QIcon(":/icons/find.png"), tr("Find"), this, SLOT(onSearchActionTriggered()), QKeySequence::Find);
    menu->addSeparator();
//    menu->addAction(tr("About %1").arg(AppInfo::name), this, SLOT(onAboutAppActionTriggered()));
    menu->addAction(tr("About Qt"), qApp, SLOT(aboutQt()));
    menu->addSeparator();
    menu->addAction(tr("Quit"), this, SLOT(onTrayMenuQuitApplicationActionTriggered()), QKeySequence::Quit);
    menuButton->setMenu(menu);

    toolBar->addWidget(addFriendButton);
    toolBar->addWidget(spacer);
    toolBar->addWidget(menuButton);
    // Create toolbar end

    //layout->addWidget(ourUserItem);
    //layout->addWidget(friendsWidget);
    layout->addWidget(toolBar);

//    pages = new PagesWidget(this);
//    connect(friendsWidget, &FriendsWidget::friendSelectionChanged, pages, &PagesWidget::activatePage);

    //FIXME: start core in a separate function
    //all connections to `core` should be done after its creation because it registers some types
//    core = new Core();

    coreThread = new QThread(this);
//    core->moveToThread(coreThread);
//    connect(coreThread, &QThread::started, core, &Core::start);

//    qRegisterMetaType<Status>("Status");

//    connect(core, &Core::connected, this, &MainWindow::onConnected);
//    connect(core, &Core::disconnected, this, &MainWindow::onDisconnected);
//    connect(core, &Core::friendRequestReceived, this, &MainWindow::onFriendRequestReceived);
//    connect(core, SIGNAL(friendStatusChanged(int, Status)), friendsWidget, SLOT(setStatus(int, Status)));
//    connect(core, &Core::friendAddressGenerated, ourUserItem, &OurUserItemWidget::setFriendAddress);
//    connect(core, &Core::friendAdded, pages, &PagesWidget::addPage);
//    connect(core, &Core::friendAdded, friendsWidget, &FriendsWidget::addFriend);
//    connect(core, &Core::friendMessageReceived, pages, &PagesWidget::messageReceived);
//    connect(core, &Core::actionReceived, pages, &PagesWidget::actionReceived);
//    connect(core, &Core::friendUsernameChanged, friendsWidget, &FriendsWidget::setUsername);
//    connect(core, &Core::friendUsernameLoaded,  friendsWidget, &FriendsWidget::setUsername);
//    connect(core, &Core::friendUsernameChanged, pages, &PagesWidget::onFriendUsernameChanged);
//    connect(core, &Core::friendUsernameLoaded,  pages, &PagesWidget::onFriendUsernameLoaded);
//    connect(core, &Core::friendTypingChanged, pages, &PagesWidget::onFriendTypingChanged);
//    connect(core, &Core::friendRemoved, friendsWidget, &FriendsWidget::removeFriend);
//    connect(core, &Core::friendRemoved, pages, &PagesWidget::removePage);
//    connect(core, &Core::failedToRemoveFriend, this, &MainWindow::onFailedToRemoveFriend);
//    connect(core, &Core::failedToAddFriend, this, &MainWindow::onFailedToAddFriend);
//    connect(core, &Core::messageSentResult, pages, &PagesWidget::messageSentResult);
//    connect(core, &Core::actionSentResult, pages, &PagesWidget::actionResult);
//    connect(core, &Core::friendStatusMessageChanged, friendsWidget, &FriendsWidget::setStatusMessage);
//    connect(core, &Core::friendStatusMessageLoaded,  friendsWidget, &FriendsWidget::setStatusMessage);
//    connect(core, &Core::friendStatusMessageChanged, pages, &PagesWidget::onFriendStatusMessageChanged);
//    connect(core, &Core::friendStatusMessageLoaded,  pages, &PagesWidget::onFriendStatusMessageLoaded);

//    connect(core, &Core::failedToStart, this, &MainWindow::onFailedToStartCore);

//    connect(core, &Core::friendStatusChanged, pages, &PagesWidget::onFriendStatusChanged);

//    connect(this, &MainWindow::statusSet, core, &Core::setStatus);
//    connect(core, &Core::statusSet, this, &MainWindow::onStatusSet);

//    connect(core, &Core::friendLastSeenChanged, friendsWidget, &FriendsWidget::setLastSeen);

//    connect(this, &MainWindow::friendRequested, core, &Core::requestFriendship);

//    connect(this, &MainWindow::friendRequestAccepted, core, &Core::acceptFriendRequest);

//    connect(ourUserItem, &OurUserItemWidget::usernameChanged, core, &Core::setUsername);
//    connect(core, &Core::usernameSet, ourUserItem, &OurUserItemWidget::setUsername);
//    connect(core, &Core::usernameSet, pages, &PagesWidget::onOurUsernameChanged);

//    connect(ourUserItem, &OurUserItemWidget::statusMessageChanged, core, &Core::setStatusMessage);
//    connect(core, &Core::statusMessageSet, ourUserItem, &OurUserItemWidget::setStatusMessage);

//    connect(ourUserItem, &OurUserItemWidget::statusSelected, core, &Core::setStatus);
//    connect(core, &Core::statusSet, ourUserItem, &OurUserItemWidget::setStatus);

//    connect(pages, &PagesWidget::sendMessage, core, &Core::sendMessage);
//    connect(pages, &PagesWidget::sendAction,  core, &Core::sendAction);
//    connect(pages, &PagesWidget::sendTyping,  core, &Core::sendTyping);

//    connect(friendsWidget, &FriendsWidget::friendRemoved, core, &Core::removeFriend);

    coreThread->start();

    splitterWidget->addWidget(friendsLayout);
//    splitterWidget->addWidget(pages);
    splitterWidget->setStretchFactor(0, 0);
    splitterWidget->setStretchFactor(1, 1);
    setCentralWidget(splitterWidget);

//    Settings::getInstance().restoreGeometryState(splitterWidget);
//    Settings::getInstance().restoreGeometryState(this);

    trayIcon = new QSystemTrayIcon(QIcon(":/icons/icon64.png"), this);
    QMenu* trayMenu = new QMenu(this);
    trayMenuShowHideAction = trayMenu->addAction(tr("Hide"), this, SLOT(onShowHideWindow()));
    trayMenu->addSeparator();
//    for (int i = 0; i <= StatusHelper::MAX_STATUS; i ++) {
//        StatusHelper::Info statusInfo = StatusHelper::getInfo(i);
//        QAction* statusAction = new QAction(QIcon(statusInfo.iconPath), statusInfo.name, trayMenu);
//        statusAction->setData(i);
//        connect(statusAction, &QAction::triggered, this, &MainWindow::onTrayMenuStatusActionTriggered);
//        trayMenuStatusActions << statusAction;
//    }
    trayMenu->addActions(QList<QAction*>() << trayMenuStatusActions);
    trayMenu->addSeparator();
    trayMenu->addActions(QList<QAction*>() << settingsAction);
    trayMenu->addSeparator();
    trayMenu->addAction(tr("Quit"), this, SLOT(onTrayMenuQuitApplicationActionTriggered()), QKeySequence::Quit);
    trayIcon->setContextMenu(trayMenu);
//    connect(trayIcon, &QSystemTrayIcon::activated, this, &MainWindow::onTrayIconClick);
    trayIcon->show();
}

MainWindow::~MainWindow()
{
    coreThread->quit();
    coreThread->wait();
//    delete core;
}
