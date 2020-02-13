#ifndef SUDOKUFUNCTION_H
#define SUDOKUFUNCTION_H
typedef unsigned char byte;
extern "C" bool isRow(byte *board,byte row,byte number);
extern "C" bool isColumn(byte *board,byte coloumn,byte number);
extern "C" bool isBox(byte *board,byte startRow,byte startCol,byte number);
extern "C" bool isSafe(byte *board,byte row,byte column,byte number);
extern "C" void randseqNumNumber(byte *number);
extern "C" void fillDiagonal(byte *board);
extern "C" bool solveSudoku(byte *board,byte *pattern,byte pos);
extern "C" int checkSolution(byte *board,byte pos);
extern "C" void generateSoduku(byte *board,int seed);
extern "C" int randompick(byte *board,int attemp);
#endif // SUDOKUFUNCTION_H
