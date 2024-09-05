#include <iostream>
#include <vector>
#include <string>

using namespace std;

#проверка соответсвия условиям
bool SolveSudoku(int su[9][9]) {
    for (int x=0; x < 9, x++) {
        for (int y = 0; y < 9; y++) {
            if (su[x][y] == 0)
        }
    }
}

bool Correct {
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num || grid[i][col] == num || 
            grid[row - row % 3 + i / 3][col - col % 3 + i % 3] == num) {
            return false;
        }
    }
    return true;
}

int main()
{
    int su[9][9];
    cout << " Введите ваш судоку, вместо пустой строки введите 0:" << endl;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> sudoku[i][j];
        }
    }

    cout << "Вы ввели:" << endl;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (su[i][j] != 0)
            su[i][j] = su[i][j];
            else
            SolveSudoku (int su[9][9]);
        }
    }



    return 0;
}
