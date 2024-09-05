#include <iostream>
#include <vector>
#include <string>

using namespace std;

#проверка соответсвия условиям
int return_method (int ss, int su) {
    for (int x = 1; i < 10; ++i) {
        for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << sudoku[i][j] << " ";
        }
    }

    }
}


int main()
{
    int su[9][9]; #нерешенный
    int ss[9][9]; #решенный судоку
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
            ss[i][j] = su[i][j];
            else
            return_method (int ss[i][j])
        }
    }



    return 0;
}
