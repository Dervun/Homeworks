#pragma once

#include "game.h"
#include "./NetworkComponent/networkobject.h"

#include <QMainWindow>
#include <QShortcut>

namespace Ui {
class MainWindow;
}

/*!
 * \brief The MainWindow class, GUI of Game
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void createClient();
    void createServer();
    void hideNetworkSettings();
    void activateKeys();
    void deactivateKeys();

private:
    void setKeys();
    void connectButtons();

    Ui::MainWindow *ui;
    Game* game;
    NetworkObject* network = nullptr;

    QShortcut* keyNewGame = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_N), this);

    QShortcut* keyEnter = new QShortcut(this);
    QShortcut* keySpace = new QShortcut(this);
    QShortcut* keyTab = new QShortcut(this);

    QShortcut* keyUp = new QShortcut(this);
    QShortcut* keyDown = new QShortcut(this);
    QShortcut* keyLeft = new QShortcut(this);
    QShortcut* keyRight = new QShortcut(this);

    /// Synonyms of left, right, up, down
    QShortcut* keyW = new QShortcut(this);
    QShortcut* keyA = new QShortcut(this);
    QShortcut* keyS = new QShortcut(this);
    QShortcut* keyD = new QShortcut(this);
};
