#include <iostream>
#include <set>
#include <vector>

using namespace std;

class SudokuSolver {
private:
    int grid[9][9];  // Судоку
    vector<set<int>> candidates[9][9];  // Возможные значения для каждой клетки

    const int size = 9;
    const int subgrid_size = 3;

public:
    // Конструктор для инициализации судоку
    SudokuSolver(int board[9][9]) {
        for (int row = 0; row < size; ++row) {
            for (int col = 0; col < size; ++col) {
                grid[row][col] = board[row][col];
            }
        }
    }

    // Функция для проверки, можно ли вставить число
    bool can_place(int row, int col, int num) {
        for (int i = 0; i < size; ++i) {
            if (grid[row][i] == num || grid[i][col] == num) {
                return false;
            }
        }
        int block_row_start = (row / subgrid_size) * subgrid_size;
        int block_col_start = (col / subgrid_size) * subgrid_size;
        for (int i = 0; i < subgrid_size; ++i) {
            for (int j = 0; j < subgrid_size; ++j) {
                if (grid[block_row_start + i][block_col_start + j] == num) {
                    return false;
                }
            }
        }
        return true;
    }

    // Инициализация возможных кандидатов для всех клеток
    void init_candidates() {
        for (int row = 0; row < size; ++row) {
            for (int col = 0; col < size; ++col) {
                if (grid[row][col] == 0) {
                    set<int> possible_values;
                    for (int num = 1; num <= 9; ++num) {
                        if (can_place(row, col, num)) {
                            possible_values.insert(num);
                        }
                    }
                    candidates[row][col].push_back(possible_values);
                }
            }
        }
    }

    // Обновление кандидатов после того, как клетка заполнена
    void update_candidates(int row, int col, int num) {
        for (int i = 0; i < size; ++i) {
            if (grid[row][i] == 0) {
                candidates[row][i][0].erase(num);
            }
            if (grid[i][col] == 0) {
                candidates[i][col][0].erase(num);
            }
        }
        int block_row_start = (row / subgrid_size) * subgrid_size;
        int block_col_start = (col / subgrid_size) * subgrid_size;
        for (int i = 0; i < subgrid_size; ++i) {
            for (int j = 0; j < subgrid_size; ++j) {
                if (grid[block_row_start + i][block_col_start + j] == 0) {
                    candidates[block_row_start + i][block_col_start + j][0].erase(num);
                }
            }
        }
    }

    // Основной метод решения
    bool solve() {
        init_candidates();  // Инициализация возможных кандидатов
        bool progress = true;

        while (progress) {
            progress = false;

            // Проходим по всем клеткам и проверяем, есть ли клетки с единственным возможным кандидатом
            for (int row = 0; row < size; ++row) {
                for (int col = 0; col < size; ++col) {
                    if (grid[row][col] == 0 && candidates[row][col][0].size() == 1) {
                        // Заполняем клетку, если есть только один кандидат
                        int num = *candidates[row][col][0].begin();
                        grid[row][col] = num;
                        update_candidates(row, col, num);
                        progress = true;
                    }
                }
            }

            // Проверка, не остались ли кандидаты, если прогресса нет
            if (!progress) {
                for (int row = 0; row < size; ++row) {
                    for (int col = 0; col < size; ++col) {
                        if (grid[row][col] == 0 && candidates[row][col][0].empty()) {
                            return false;  // Нет возможных кандидатов, решение не найдено
                        }
                    }
                }
            }
        }

        return true;  // Судоку решено
    }

    // Печать решённого судоку
    void print_grid() {
        for (int row = 0; row < size; ++row) {
            for (int col = 0; col < size; ++col) {
                cout << grid[row][col] << " ";
            }
            cout << endl;
        }
    }
};

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

    SudokuSolver solver(sudoku_grid);
    if (solver.solve()) {
        cout << "Решенное судоку: " << endl;
        solver.print_grid();
    } else {
        cout << "Решение не найдено." << endl;
    }

    return 0;
}
