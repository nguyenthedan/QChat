#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QListView>
#include <QTextBrowser>
#include <QThread>
#include <QSplitter>
#include <QSystemTrayIcon>

//class PagesWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
//    void closeEvent(QCloseEvent *event);

private:
//    Core* core;
    QThread* coreThread;
//    FriendsWidget* friendsWidget;
//    OurUserItemWidget* ourUserItem;
    QSplitter* splitterWidget;
//    PagesWidget *pages;
    QSystemTrayIcon* trayIcon;
    QAction* settingsAction;
    QAction* trayMenuShowHideAction;
    QList<QAction*> trayMenuStatusActions;

private slots:
//    void onAddFriendButtonClicked();
//    void onConnected();
//    void onDisconnected();
//    void onFriendRequestReceived(const QString &userId, const QString &message);
//    void onFailedToRemoveFriend(int friendId);
//    void onFailedToAddFriend(const QString& userId);
//    void onFailedToStartCore();
//    void onSettingsActionTriggered();
//    void onAboutAppActionTriggered();
//    void onSearchActionTriggered();
//    void onTrayMenuStatusActionTriggered();
//    void onTrayMenuQuitApplicationActionTriggered();
//    void onShowHideWindow();
//    void onTrayIconClick(QSystemTrayIcon::ActivationReason reason);
//    void onStatusSet(Status status);

signals:
//    void friendRequestAccepted(const QString& userId);
//    void friendRequested(const QString& friendAddress, const QString& message);
//    void statusSet(Status status);

};

#endif // MAINWINDOW_H
