#include <iostream>
#include <cmath>

using namespace std;

const int rows = 100;
const int cols = 100;

void arrayOutputHandler(int arr[][cols], int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void arrayOutputHandler(int **arr, int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void arrayInputHandler(int arr[][cols], int row, int col, int option) {
    if (option == 1) {
        cout << "Input array, use enter to switch to new row\n";
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                cin >> arr[i][j];
            }
        }
    } else if (option == 2) {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                arr[i][j] = rand() % 100 + 1;
            }
        }
    }
}

void arrayInputHandler(int **arr, int row, int col, int option) {
    if (option == 1) {
        cout << "Input array, use enter to switch to new row\n";
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                cin >> arr[i][j];
            }
        }
    } else if (option == 2) {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                arr[i][j] = rand() % 100 + 1;
            }
        }
    }
}

void matrixTransposition(int arr[][cols], int row, int col) {
    int t;
    for (int i = 0; i < row; ++i) {
        for (int j = i + 1; j < col; ++j) {
            t = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = t;
        }
    }
}

void matrixTransposition(int **arr, int row, int col) {
    int t;
    for (int i = 0; i < row; ++i) {
        for (int j = i + 1; j < col; ++j) {
            t = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = t;
        }
    }
}

int main() {
    int taskOption = 0, n = 0;
    while (taskOption != 3) {
        cout << "Select the task \n"
                "1 - A matrix of size n*n is given. Transpose the matrices.\n"
                "2 - Two convex polygons in the plane are given by the coordinates of the vertices in the order of the boundary.\n Determine the area of the polygon and determine if they are nested. \n"
                "3 - exit \n";
        cin >> taskOption;

        if (taskOption == 1) {
            cout << "Select the type of an array: \n"
                    "1 - static \n"
                    "2 - dynamic \n";
            cin >> n;
            if (n == 1) {
                int option;
                int arr[rows][cols];
                int row, col;
                cout << "Enter the number of rows and columns: \n";
                cin >> row >> col;
                cout << "Select the option of input: \n"
                        "1 - Manual\n"
                        "2 - Random\n";
                cin >> option;
                if (option == 1 || option == 2) {
                    arrayInputHandler(arr, row, col, option);
                    cout << "Current matrix is:\n";
                    arrayOutputHandler(arr, row, col);
                    matrixTransposition(arr, row, col);
                    cout << "Transposed matrix is:\n";
                    arrayOutputHandler(arr, row, col);
                } else {
                    cout << "There is no such option \n";
                }
            } else if (n == 2) {
                int row, col, option = 0;
                cout << "Enter the number of rows and columns:\n";
                cin >> row >> col;
                int **arr = new int *[row];
                for (int i = 0; i < row; ++i) {
                    arr[i] = new int[cols];
                }
                cout << "Select the method of input: \n"
                        "1 - Manual\n"
                        "2 - Random\n";
                cin >> option;
                if (option == 1 || option == 2) {
                    arrayInputHandler(arr, row, col, option);
                    cout << "Current matrix is:\n";
                    arrayOutputHandler(arr, row, col);
                    matrixTransposition(arr, row, col);
                    cout << "Transposed matrix is:\n";
                    arrayOutputHandler(arr, row, col);
                } else {
                    cout << "There is no such option \n";
                }
                for (int i = 0; i < row; ++i) {
                    delete[] arr[i];
                }
                delete[] arr;
            }
        }
    }
    return 0;
}

