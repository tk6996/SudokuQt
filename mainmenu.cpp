#include "mainmenu.h"
#include "ui_mainmenu.h"

#include <QMessageBox>
#include <QDebug>
#include <QPixmap>

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    startMenuPage();
    setWindowTitle("SUDOKU GAME");
    setWindowIcon(QIcon("D:/YEAR 2-2/Software Development Processes/SudokuQt/Pictures/logo.png"));

    // ADD USER CODE HERE
	ui->stackedWidget->insertWidget(1, &game);

	connect(&game, SIGNAL(menuClicked()), this, SLOT(moveToMenu()));
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::startMenuPage()
{
    // set background image
    QPixmap bg("D:/YEAR 2-2/Software Development Processes/SudokuQt/Pictures/BG_MuenuPage_1.png");
    bg = bg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bg);
    this->setPalette(palette);

    // set button
    ui->playButton->setStyleSheet("QPushButton{background-color: rgb(0, 180, 0);} QPushButton:hover{color:rgb(0, 0, 120);}");
    ui->exitButton->setStyleSheet("QPushButton{background-color: rgb(0, 180, 0);} QPushButton:hover{color:rgb(0, 0, 120);}");
    ui->tutorialButton->setStyleSheet("QPushButton{background-color: rgb(0, 180, 0);} QPushButton:hover{color:rgb(0, 0, 120);}");

    // set image
    QPixmap img("D:/YEAR 2-2/Software Development Processes/SudokuQt/Pictures/mikky.png");
    ui->label->setGeometry(50, 400, 180, 180);
    int img_w = ui->label->width();
    int img_h = ui->label->height();
    ui->label->setPixmap(img.scaled(img_w, img_h, Qt::KeepAspectRatio));

    animation = new QPropertyAnimation(ui->label, "geometry");
    animation->setDuration(10000);
    animation->setStartValue(ui->label->geometry());
    animation->setEndValue(QRect(800, 400, 180, 180));
    //animation->start();
}

void MainMenu::startGamePage()
{
    QPalette palette;
    palette.setBrush(QPalette::Background, Qt::white);
    this->setPalette(palette);
}

void MainMenu::moveToMenu()
{
    ui->stackedWidget->setCurrentIndex(0);
    startMenuPage();
}

void MainMenu::on_playButton_clicked()
{
	game.initSudoku();
	ui->stackedWidget->setCurrentIndex(1);
	startGamePage();
}

void MainMenu::on_exitButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,
                                 "EXIT GAME", "Do you want to exit now?",
                                 QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
        QApplication::quit();
    else {
        qDebug() << "No is clicked";
    }
}

void MainMenu::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainMenu::on_tutorialButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
