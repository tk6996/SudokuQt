#ifndef MAINMENU_H
#define MAINMENU_H

#include "mainwindow.h"

#include <QMainWindow>
#include <QPropertyAnimation>

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

    void startMenuPage();
    void startGamePage();

private slots:
    void moveToMenu();

    void on_playButton_clicked();

    void on_exitButton_clicked();

    void on_pushButton_clicked();

    void on_tutorialButton_clicked();

private:
    Ui::MainMenu *ui;
	MainWindow game;
    QPropertyAnimation *animation;
};

#endif // MAINMENU_H
