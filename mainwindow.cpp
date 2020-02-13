#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPalette>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	boardButton[0] = ui->B0_0;
	boardButton[1] = ui->B0_1;
	boardButton[2] = ui->B0_2;
	boardButton[3] = ui->B0_3;
	boardButton[4] = ui->B0_4;
	boardButton[5] = ui->B0_5;
	boardButton[6] = ui->B0_6;
	boardButton[7] = ui->B0_7;
	boardButton[8] = ui->B0_8;
	boardButton[9] = ui->B1_0;
	boardButton[10] = ui->B1_1;
	boardButton[11] = ui->B1_2;
	boardButton[12] = ui->B1_3;
	boardButton[13] = ui->B1_4;
	boardButton[14] = ui->B1_5;
	boardButton[15] = ui->B1_6;
	boardButton[16] = ui->B1_7;
	boardButton[17] = ui->B1_8;
	boardButton[18] = ui->B2_0;
	boardButton[19] = ui->B2_1;
	boardButton[20] = ui->B2_2;
	boardButton[21] = ui->B2_3;
	boardButton[22] = ui->B2_4;
	boardButton[23] = ui->B2_5;
	boardButton[24] = ui->B2_6;
	boardButton[25] = ui->B2_7;
	boardButton[26] = ui->B2_8;
	boardButton[27] = ui->B3_0;
	boardButton[28] = ui->B3_1;
	boardButton[29] = ui->B3_2;
	boardButton[30] = ui->B3_3;
	boardButton[31] = ui->B3_4;
	boardButton[32] = ui->B3_5;
	boardButton[33] = ui->B3_6;
	boardButton[34] = ui->B3_7;
	boardButton[35] = ui->B3_8;
	boardButton[36] = ui->B4_0;
	boardButton[37] = ui->B4_1;
	boardButton[38] = ui->B4_2;
	boardButton[39] = ui->B4_3;
	boardButton[40] = ui->B4_4;
	boardButton[41] = ui->B4_5;
	boardButton[42] = ui->B4_6;
	boardButton[43] = ui->B4_7;
	boardButton[44] = ui->B4_8;
	boardButton[45] = ui->B5_0;
	boardButton[46] = ui->B5_1;
	boardButton[47] = ui->B5_2;
	boardButton[48] = ui->B5_3;
	boardButton[49] = ui->B5_4;
	boardButton[50] = ui->B5_5;
	boardButton[51] = ui->B5_6;
	boardButton[52] = ui->B5_7;
	boardButton[53] = ui->B5_8;
	boardButton[54] = ui->B6_0;
	boardButton[55] = ui->B6_1;
	boardButton[56] = ui->B6_2;
	boardButton[57] = ui->B6_3;
	boardButton[58] = ui->B6_4;
	boardButton[59] = ui->B6_5;
	boardButton[60] = ui->B6_6;
	boardButton[61] = ui->B6_7;
	boardButton[62] = ui->B6_8;
	boardButton[63] = ui->B7_0;
	boardButton[64] = ui->B7_1;
	boardButton[65] = ui->B7_2;
	boardButton[66] = ui->B7_3;
	boardButton[67] = ui->B7_4;
	boardButton[68] = ui->B7_5;
	boardButton[69] = ui->B7_6;
	boardButton[70] = ui->B7_7;
	boardButton[71] = ui->B7_8;
	boardButton[72] = ui->B8_0;
	boardButton[73] = ui->B8_1;
	boardButton[74] = ui->B8_2;
	boardButton[75] = ui->B8_3;
	boardButton[76] = ui->B8_4;
	boardButton[77] = ui->B8_5;
	boardButton[78] = ui->B8_6;
	boardButton[79] = ui->B8_7;
	boardButton[80] = ui->B8_8;
	initSudoku();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::afterClick()
{

}

void MainWindow::initSudoku()
{
	generateSoduku(solveBoard,time(nullptr));
	QDebug debug = qDebug();
	std::copy(solveBoard,solveBoard+81,unsolveBoard);
	for (int i = 0,j = 0;i < 81;i++,j++,j%=9) {
		if(j == 0) debug << "\n";
		debug << solveBoard[i];
	}
	randompick(unsolveBoard,50);
	for (int i = 0; i < 81; i++) {
		if(unsolveBoard[i] != 0)
		{
			boardButton[i]->setText(QString::number(unsolveBoard[i]));
			editBoard[i] = false;
		}
		else
			editBoard[i] = true;
		boardButton[i]->setStyleSheet("QPushButton:hover{background-color:green; color:red;}");
	}
	afterClick();
}

void MainWindow::on_B0_0_clicked()
{
	this->position = 0;
	afterClick();
}

void MainWindow::on_B0_1_clicked()
{
	this->position = 1;
	afterClick();
}

void MainWindow::on_B0_2_clicked()
{
	this->position = 2;
	afterClick();
}

void MainWindow::on_B0_3_clicked()
{
	this->position = 3;
	afterClick();
}

void MainWindow::on_B0_4_clicked()
{
	this->position = 4;
	afterClick();
}

void MainWindow::on_B0_5_clicked()
{
	this->position = 5;
	afterClick();
}

void MainWindow::on_B0_6_clicked()
{
	this->position = 6;
	afterClick();
}

void MainWindow::on_B0_7_clicked()
{
	this->position = 7;
	afterClick();
}

void MainWindow::on_B0_8_clicked()
{
	this->position = 8;
	afterClick();
}

void MainWindow::on_B1_0_clicked()
{
	this->position = 9;
	afterClick();
}

void MainWindow::on_B1_1_clicked()
{
	this->position = 10;
	afterClick();
}

void MainWindow::on_B1_2_clicked()
{
	this->position = 11;
	afterClick();
}

void MainWindow::on_B1_3_clicked()
{
	this->position = 12;
	afterClick();
}

void MainWindow::on_B1_4_clicked()
{
	this->position = 13;
	afterClick();
}

void MainWindow::on_B1_5_clicked()
{
	this->position = 14;
	afterClick();
}

void MainWindow::on_B1_6_clicked()
{
	this->position = 15;
	afterClick();
}

void MainWindow::on_B1_7_clicked()
{
	this->position = 16;
	afterClick();
}

void MainWindow::on_B1_8_clicked()
{
	this->position = 17;
	afterClick();
}

void MainWindow::on_B2_0_clicked()
{
	this->position = 18;
	afterClick();
}

void MainWindow::on_B2_1_clicked()
{
	this->position = 19;
	afterClick();
}

void MainWindow::on_B2_2_clicked()
{
	this->position = 20;
	afterClick();
}

void MainWindow::on_B2_3_clicked()
{
	this->position = 21;
	afterClick();
}

void MainWindow::on_B2_4_clicked()
{
	this->position = 22;
	afterClick();
}

void MainWindow::on_B2_5_clicked()
{
	this->position = 23;
	afterClick();
}

void MainWindow::on_B2_6_clicked()
{
	this->position = 24;
	afterClick();
}

void MainWindow::on_B2_7_clicked()
{
	this->position = 25;
	afterClick();
}

void MainWindow::on_B2_8_clicked()
{
	this->position = 26;
	afterClick();
}

void MainWindow::on_B3_0_clicked()
{
	this->position = 27;
	afterClick();
}

void MainWindow::on_B3_1_clicked()
{
	this->position = 28;
	afterClick();
}


void MainWindow::on_B3_2_clicked()
{
	this->position = 29;
	afterClick();
}

void MainWindow::on_B3_3_clicked()
{
	this->position = 30;
	afterClick();
}


void MainWindow::on_B3_4_clicked()
{
	this->position = 31;
	afterClick();
}

void MainWindow::on_B3_5_clicked()
{
	this->position = 32;
	afterClick();
}


void MainWindow::on_B3_6_clicked()
{
	this->position = 33;
	afterClick();
}

void MainWindow::on_B3_7_clicked()
{
	this->position = 34;
	afterClick();
}


void MainWindow::on_B3_8_clicked()
{
	this->position = 35;
	afterClick();
}

void MainWindow::on_B4_0_clicked()
{
	this->position = 36;
	afterClick();
}

void MainWindow::on_B4_1_clicked()
{
	this->position = 37;
	afterClick();
}

void MainWindow::on_B4_2_clicked()
{
	this->position = 38;
	afterClick();
}

void MainWindow::on_B4_3_clicked()
{
	this->position = 39;
	afterClick();
}

void MainWindow::on_B4_4_clicked()
{
	this->position = 40;
	afterClick();
}

void MainWindow::on_B4_5_clicked()
{
	this->position = 41;
	afterClick();
}

void MainWindow::on_B4_6_clicked()
{
	this->position = 42;
	afterClick();
}

void MainWindow::on_B4_7_clicked()
{
	this->position = 43;
	afterClick();
}

void MainWindow::on_B4_8_clicked()
{
	this->position = 44;
	afterClick();
}

void MainWindow::on_B5_0_clicked()
{
	this->position = 45;
	afterClick();
}

void MainWindow::on_B5_1_clicked()
{
	this->position = 46;
	afterClick();
}

void MainWindow::on_B5_2_clicked()
{
	this->position = 47;
	afterClick();
}

void MainWindow::on_B5_3_clicked()
{
	this->position = 48;
	afterClick();
}

void MainWindow::on_B5_4_clicked()
{
	this->position = 49;
	afterClick();
}

void MainWindow::on_B5_5_clicked()
{
	this->position = 50;
	afterClick();
}

void MainWindow::on_B5_6_clicked()
{
	this->position = 51;
	afterClick();
}

void MainWindow::on_B5_7_clicked()
{
	this->position = 52;
	afterClick();
}

void MainWindow::on_B5_8_clicked()
{
	this->position = 53;
	afterClick();
}

void MainWindow::on_B6_0_clicked()
{
	this->position = 54;
	afterClick();
}

void MainWindow::on_B6_1_clicked()
{
	this->position = 55;
	afterClick();
}

void MainWindow::on_B6_2_clicked()
{
	this->position = 56;
	afterClick();
}

void MainWindow::on_B6_3_clicked()
{
	this->position = 57;
	afterClick();
}

void MainWindow::on_B6_4_clicked()
{
	this->position = 58;
	afterClick();
}

void MainWindow::on_B6_5_clicked()
{
	this->position = 59;
	afterClick();
}

void MainWindow::on_B6_6_clicked()
{
	this->position = 60;
	afterClick();
}

void MainWindow::on_B6_7_clicked()
{
	this->position = 61;
	afterClick();
}

void MainWindow::on_B6_8_clicked()
{
	this->position = 62;
	afterClick();
}

void MainWindow::on_B7_0_clicked()
{
	this->position = 63;
	afterClick();
}

void MainWindow::on_B7_1_clicked()
{
	this->position = 64;
	afterClick();
}

void MainWindow::on_B7_2_clicked()
{
	this->position = 65;
	afterClick();
}

void MainWindow::on_B7_3_clicked()
{
	this->position = 66;
	afterClick();
}

void MainWindow::on_B7_4_clicked()
{
	this->position = 67;
	afterClick();
}

void MainWindow::on_B7_5_clicked()
{
	this->position = 68;
	afterClick();
}

void MainWindow::on_B7_6_clicked()
{
	this->position = 69;
	afterClick();
}

void MainWindow::on_B7_7_clicked()
{
	this->position = 70;
	afterClick();
}

void MainWindow::on_B7_8_clicked()
{
	this->position = 71;
	afterClick();
}

void MainWindow::on_B8_0_clicked()
{
	this->position = 72;
	afterClick();
}

void MainWindow::on_B8_1_clicked()
{
	this->position = 73;
	afterClick();
}

void MainWindow::on_B8_2_clicked()
{
	this->position = 74;
	afterClick();
}

void MainWindow::on_B8_3_clicked()
{
	this->position = 75;
	afterClick();
}

void MainWindow::on_B8_4_clicked()
{
	this->position = 76;
	afterClick();
}

void MainWindow::on_B8_5_clicked()
{
	this->position = 77;
	afterClick();
}

void MainWindow::on_B8_6_clicked()
{
	this->position = 78;
	afterClick();
}

void MainWindow::on_B8_7_clicked()
{
	this->position = 79;
	afterClick();
}

void MainWindow::on_B8_8_clicked()
{
	this->position = 80;
	afterClick();
}

void MainWindow::on_Number1_clicked()
{
	if(!editBoard[position])
		return;
	unsolveBoard[position] = 1;
	afterClick();
	boardButton[position]->setText("1");
}

void MainWindow::on_Number2_clicked()
{
	if(!editBoard[position])
		return;
	unsolveBoard[position] = 2;
	afterClick();
	boardButton[position]->setText("2");
}

void MainWindow::on_Number3_clicked()
{
	if(!editBoard[position])
		return;
	unsolveBoard[position] = 3;
	afterClick();
	boardButton[position]->setText("3");
}

void MainWindow::on_Number4_clicked()
{
	if(!editBoard[position])
		return;
	unsolveBoard[position] = 4;
	afterClick();
	boardButton[position]->setText("4");
}

void MainWindow::on_Number5_clicked()
{
	if(!editBoard[position])
		return;
	unsolveBoard[position] = 5;
	afterClick();
	boardButton[position]->setText("5");
}

void MainWindow::on_Number6_clicked()
{
	if(!editBoard[position])
		return;
	unsolveBoard[position] = 6;
	afterClick();
	boardButton[position]->setText("6");
}

void MainWindow::on_Number7_clicked()
{
	if(!editBoard[position])
		return;
	unsolveBoard[position] = 7;
	afterClick();
	boardButton[position]->setText("7");
}

void MainWindow::on_Number8_clicked()
{
	if(!editBoard[position])
		return;
	unsolveBoard[position] = 8;
	afterClick();
	boardButton[position]->setText("8");
}

void MainWindow::on_Number9_clicked()
{
	if(!editBoard[position])
		return;
	unsolveBoard[position] = 9;
	afterClick();
	boardButton[position]->setText("9");
}

void MainWindow::on_Number0_clicked()
{
	if(!editBoard[position])
		return;
	unsolveBoard[position] = 0;
	afterClick();
	boardButton[position]->setText("");
}

