#include <iostream>

using namespace std;

const int rows = 100;
const int cols = 100;

void matrixOutputHandler(int arr[][cols], size_t row, size_t col) {
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void inputArrayHandler(int arr[][cols], size_t row, size_t col) {
    int option;

    cout << "Select an option: \n"
            "1 - manual filling of the matrix \n"
            "2 - random filling of the matrix \n";
    cin >> option;
    switch (option) {
        case 1: {
            for (size_t i = 0; i < row; ++i) {
                for (size_t j = 0; j < col; ++j) {
                    cin >> arr[i][j];
                }
            }
            cout << "Your matrix is: \n" ;
            matrixOutputHandler(arr, row, col);
            break;
        }
        case 2: {
            for (size_t i = 0; i < row; ++i) {
                for (size_t j = 0; j < col; ++j) {
                    arr[i][j] = rand() % 1000;
                }
            }
            break;
        }
        default:
            cout << "There's no such option \n";
    }
}


void matrixTransposition(int arr[][cols], size_t row, size_t col) {
    int t;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            t = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = t;
        }
    }
}


int main() {

    int taskOption = 0, n = 0, typeOfArray;
    while (taskOption != 3) {
        cout << "Select the task \n"
                "1 - Matrix transposition\n"
                "2 - alalalalalala \n"
                "3 - exit \n";
        cin >> taskOption;

        if (taskOption == 1) {
            cout << "Select the type of an array: \n"
                    "1 - static \n"
                    "2 - dynamic \n";
            cin >> n;
            if (n == 1) {
                int arr[rows][cols];
                size_t row, col;
                cout << "Enter the number of rows: \n";
                cin >> row;
                cout << "Enter the number of columns: \n";
                cin >> col;
                inputArrayHandler(arr, row, col);
                matrixTransposition(arr, row, col);
                matrixOutputHandler(arr, row, col);
            }
        }

    }


    return 0;
}