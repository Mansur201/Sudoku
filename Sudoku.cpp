#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Проверка, можно ли вставить число num в ячейку (row, col)
bool isValid(int grid[9][9], int row, int col, int num) {
    // Проверка строки
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num) {
            return false;
        }
    }

    // Проверка столбца
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == num) {
            return false;
        }
    }

    // Проверка 3x3 блока
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Функция для решения судоку с помощью метода backtracking
bool solveSudoku(int grid[9][9]) {
    int row, col;
    bool emptySpot = false;

    // Поиск пустой ячейки (значение 0)
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (grid[row][col] == 0) {
                emptySpot = true;
                break;
            }
        }
        if (emptySpot) break;
    }

    // Если пустых ячеек нет, судоку решено
    if (!emptySpot) {
        return true;
    }

    // Пробуем вставить числа от 1 до 9
    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;

            // Рекурсивно вызываем функцию для следующей ячейки
            if (solveSudoku(grid)) {
                return true;
            }

            // Если решение не найдено, сбрасываем значение
            grid[row][col] = 0;
        }
    }

    return false;
}

// Функция для вывода судоку
void printSudoku(int grid[9][9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Пример судоку
    int grid[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Initial Sudoku:" << endl;
    printSudoku(grid);

    if (solveSudoku(grid)) {
        cout << "Solved Sudoku:" << endl;
        printSudoku(grid);
    } else {
        cout << "Impossible to solve Sudoku." << endl;
    }

    return 0;
}
