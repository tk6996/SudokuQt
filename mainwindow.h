#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "sudokuFunction.h"
#include "stackundo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		MainWindow(QWidget *parent = nullptr);
		~MainWindow();

	private slots:
		void on_B0_0_clicked();
		void on_B0_1_clicked();
		void on_B0_2_clicked();
		void on_B0_3_clicked();
		void on_B0_4_clicked();
		void on_B0_5_clicked();
		void on_B0_6_clicked();
		void on_B0_7_clicked();
		void on_B0_8_clicked();
		void on_B1_0_clicked();
		void on_B1_1_clicked();
		void on_B1_2_clicked();
		void on_B1_3_clicked();
		void on_B1_4_clicked();
		void on_B1_5_clicked();
		void on_B1_6_clicked();
		void on_B1_7_clicked();
		void on_B1_8_clicked();
		void on_B2_0_clicked();
		void on_B2_1_clicked();
		void on_B2_2_clicked();
		void on_B2_3_clicked();
		void on_B2_4_clicked();
		void on_B2_5_clicked();
		void on_B2_6_clicked();
		void on_B2_7_clicked();
		void on_B2_8_clicked();
		void on_B3_0_clicked();
		void on_B3_1_clicked();
		void on_B3_2_clicked();
		void on_B3_3_clicked();
		void on_B3_4_clicked();
		void on_B3_5_clicked();
		void on_B3_6_clicked();
		void on_B3_7_clicked();
		void on_B3_8_clicked();
		void on_B4_0_clicked();
		void on_B4_1_clicked();
		void on_B4_2_clicked();
		void on_B4_3_clicked();
		void on_B4_4_clicked();
		void on_B4_5_clicked();
		void on_B4_6_clicked();
		void on_B4_7_clicked();
		void on_B4_8_clicked();
		void on_B5_0_clicked();
		void on_B5_1_clicked();
		void on_B5_2_clicked();
		void on_B5_3_clicked();
		void on_B5_4_clicked();
		void on_B5_5_clicked();
		void on_B5_6_clicked();
		void on_B5_7_clicked();
		void on_B5_8_clicked();
		void on_B6_0_clicked();
		void on_B6_1_clicked();
		void on_B6_2_clicked();
		void on_B6_3_clicked();
		void on_B6_4_clicked();
		void on_B6_5_clicked();
		void on_B6_6_clicked();
		void on_B6_7_clicked();
		void on_B6_8_clicked();
		void on_B7_0_clicked();
		void on_B7_1_clicked();
		void on_B7_2_clicked();
		void on_B7_3_clicked();
		void on_B7_4_clicked();
		void on_B7_5_clicked();
		void on_B7_6_clicked();
		void on_B7_7_clicked();
		void on_B7_8_clicked();
		void on_B8_0_clicked();
		void on_B8_1_clicked();
		void on_B8_2_clicked();
		void on_B8_3_clicked();
		void on_B8_4_clicked();
		void on_B8_5_clicked();
		void on_B8_6_clicked();
		void on_B8_7_clicked();
		void on_B8_8_clicked();
		void on_Number1_clicked();
		void on_Number2_clicked();
		void on_Number3_clicked();
		void on_Number4_clicked();
		void on_Number5_clicked();
		void on_Number6_clicked();
		void on_Number7_clicked();
		void on_Number8_clicked();
		void on_Number9_clicked();
		void on_Number0_clicked();

		void on_Hint_clicked();

		void on_undo_clicked();

	private:
		Ui::MainWindow *ui;
		int position = -1;
		byte solveBoard[81]={0};
		byte unsolveBoard[81];
		bool editBoard[81];
		QPushButton *boardButton[81];
		void afterClick();
		void initSudoku();
		void clearBoard();
		void checkRow(int row);
		void checkColumn(int col);
		void checkBox(int startRow,int startCol);
		int hint = 3;
		StackUndo container;
};
#endif // MAINWINDOW_H
