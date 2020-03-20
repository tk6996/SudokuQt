#include "mainmenu.h"
#include "ui_mainmenu.h"

#include <QMessageBox>
#include <QDebug>
#include <QPixmap>

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
	ui(new Ui::MainMenu) , game(this)
{
    ui->setupUi(this);

    startMenuPage();
    setWindowTitle("SUDOKU GAME");
	setWindowIcon(QIcon("./Pictures/logo.png"));
	setFixedSize(800,600);

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
    QPixmap bg("./Pictures/BG_MenuPage_2.png");
    bg = bg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bg);
    this->setPalette(palette);

    // set button
    ui->playButton->setStyleSheet("QPushButton{background-color: rgb(51, 204, 51);} QPushButton:hover{background-color: rgb(153, 255, 51); color:rgb(0, 0, 120);}");
    ui->exitButton->setStyleSheet("QPushButton{background-color: rgb(51, 204, 51);} QPushButton:hover{background-color: rgb(153, 255, 51); color:rgb(0, 0, 120);}");
    ui->tutorialButton->setStyleSheet("QPushButton{background-color: rgb(51, 204, 51);} QPushButton:hover{background-color: rgb(153, 255, 51); color:rgb(0, 0, 120);}");
    ui->pushButton->setStyleSheet("QPushButton{margin: 1px; border:1px solid white; background-color: rgb(255, 179, 255);} QPushButton:hover{margin: 1px; border:1px solid white; background-color: rgb(255, 77, 255); color:rgb(255, 255, 255);}");
    // set image
	QPixmap img("./Pictures/mikky.png");
    ui->label->setGeometry(50, 360, 180, 180);
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
	QPixmap bg("./Pictures/BG_gamePage2.jpg");
    bg = bg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bg);
    this->setPalette(palette);
}

void MainMenu::moveToMenu()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,
                                 "EXIT GAME", "Do you want to go back to MENU now?",
                                 QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        ui->stackedWidget->setCurrentIndex(0);
        startMenuPage();
    }
    else {
		qDebug() << "No is clicked";
		emit exitSignal();
    }
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
