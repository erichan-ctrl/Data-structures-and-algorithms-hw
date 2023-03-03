#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

void arrayInputHandler(int *arr, size_t array_size) {
    for (int i = 0; i < array_size; ++i) {
        cin >> arr[i];
    }
}

//перегрузка функции для вектора
void arrayInputHandler(vector<int> &arr) {
    for (int &el: arr) {
        cin >> el;
    }
}

void printArray(int arr[], size_t array_size) {
    for (int i = 0; i < array_size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


//перегрузка функции для вектора
void printArray(vector<int> &arr) {
    for (int i: arr) {
        cout << i << " ";
    }
    cout << endl;
}

bool isPrime(int n) { // функция, проверяющая число на простое
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}


int findPrime(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        if (isPrime(arr[i])) {
            return i;
        }
    }
    return -1;
}

int findPrime(vector<int> &arr) {
    for (int i = 0; i < arr.size(); ++i) {
        if (isPrime(arr[i])) {
            return i;
        }
    }
    return -1;
}

int *placeAfterPrime(int arr[], int index, size_t &arraySize, int newElem, const bool isStatic) {
    for (int i = arraySize; i > index + 1; --i) {
        arr[i] = arr[i - 1];
    }
    arr[index + 1] = newElem;
    arraySize++;
    return arr;
}

int *placeAfterPrime(int arr[], int index, size_t &arraySize, int newElem) {
    for (int i = arraySize; i > index + 1; --i) {
        arr[i] = arr[i - 1];
    }
    arr[index + 1] = newElem;
    arraySize++;
    return arr;
}

vector<int> placeAfterPrime(vector<int> &arr, int index, int newElem) {
    arr.insert(arr.begin() + index + 1, newElem);
    return arr;
}

int *deleteElement(int arr[], size_t &arraySize, const bool isStatic) {
    for (int i = 0; i < arraySize; ++i) {
        if (arr[i] % 7 == 0) {
            for (int j = i; j < (arraySize - 1); ++j) {
                arr[j] = arr[j + 1];
            }
            --arraySize;
            --i;
        }
    }
    return arr;
}

int *deleteElement(int *&arr, size_t &arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        if (arr[i] % 7 == 0) {
            for (int j = i; j < (arraySize - 1); ++j) {
                arr[j] = arr[j + 1];
            }
            arr = (int *) realloc(arr, arraySize * sizeof(int));
            --arraySize;
            --i;
        }
    }
    return arr;
}


void deleteElement(vector<int> &arr, const bool isVector) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 7 == 0) {
            arr.erase(arr.begin() + i);
            i--;
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "Russian");
    cout << "Выберите тип массива: \n"
            "1 - Статический массив \n"
            "2 - Динамический массив\n"
            "3 - Vector\n";
    int n;
    cin >> n;

    if (n == 1) {
        int taskType = 0;
        int arr[101] = {0};
        size_t arraySize = 0;
        cout << "Введите размер массива (максимум 50):\n";
        cin >> arraySize;
        cout << "Введите значения элементов массива через пробел: \n";
        arrayInputHandler(arr, arraySize);
        while (taskType != 4) {
            cout << "Выберите задачу: \n"
                    "1 - Найти индекс первого простого числа в массиве\n"
                    "2 - Вставить новый элемент в массив в позицию, следующую за первым простым числом в массиве\n"
                    "3 - Удалить каждый элемент массива, кратный 7 \n"
                    "4 - Выйти\n";
            cin >> taskType;
            if (taskType == 1) {
                if (findPrime(arr, arraySize) == -1) {
                    cout << " В массиве нет простых чисел \n";
                } else {
                    cout << "Первое простое число в массиве имеет индекс " << findPrime(arr, arraySize) << endl;
                }

            } else if (taskType == 2) {
                int newElem;
                cout << "Введите новый элемент: \n";
                cin >> newElem;
                if (findPrime(arr, arraySize) == -1) {
                    cout << " В массиве нет простых чисел \n";
                } else {
                    placeAfterPrime(arr, findPrime(arr, arraySize), arraySize, newElem);
                    cout << "Новый массив: \n";
                    printArray(arr, arraySize);
                }
            } else if (taskType == 3) {
                deleteElement(arr, arraySize, true);
                printArray(arr, arraySize);
            }

        }
    }

    if (n == 2) {
        int taskType = 0;
        size_t arraySize = 0;
        cout << "Введите размер массива:\n";
        cin >> arraySize;
        int *arr = new int[arraySize];
        cout << "Введите значения элементов массива через пробел: \n";
        arrayInputHandler(arr, arraySize);
        while (taskType != 4) {
            cout << "Выберите задачу: \n"
                    "1 - Найти индекс первого простого числа в массиве\n"
                    "2 - Вставить новый элемент в массив в позицию, следующую за первым простым числом в массиве\n"
                    "3 - Удалить каждый элемент массива, кратный 7 \n"
                    "4 - Выйти\n";
            cin >> taskType;
            if (taskType == 1) {
                if (findPrime(arr, arraySize) == -1) {
                    cout << " В массиве нет простых чисел \n";
                } else {
                    cout << "Первое простое число в массиве имеет индекс " << findPrime(arr, arraySize) << endl;
                }
            } else if (taskType == 2) {
                int newElem;
                cout << "Введите новый элемент: \n";
                cin >> newElem;
                if (findPrime(arr, arraySize) == -1) {
                    cout << " В массиве нет простых чисел \n";
                } else {
                    placeAfterPrime(arr, findPrime(arr, arraySize), arraySize, newElem, true);
                    cout << "Новый массив: \n";
                    printArray(arr, arraySize);
                }
            } else if (taskType == 3) {
                deleteElement(arr, arraySize);
                printArray(arr, arraySize);
            }

        }
        delete[] arr;
    }
    if (n == 3) {
        int taskType = 0;

        size_t arraySize = 0;
        const bool isVector = true;
        cout << "Введите размер массива (максимум 50):\n";
        cin >> arraySize;
        cout << "Введите значения элементов массива через пробел: \n";
        vector<int> arr(arraySize);
        arrayInputHandler(arr);
        while (taskType != 4) {
            cout << "Выберите задачу: \n"
                    "1 - Найти индекс первого простого числа в массиве\n"
                    "2 - Вставить новый элемент в массив в позицию, следующую за первым простым числом в массиве\n"
                    "3 - Удалить каждый элемент массива, кратный 7 \n"
                    "4 - Выйти\n";
            cin >> taskType;
            if (taskType == 1) {
                if (findPrime(arr) == -1) {
                    cout << " В массиве нет простых чисел \n";
                } else {
                    cout << "Первое простое число в массиве имеет индекс " << findPrime(arr) << endl;
                }

            } else if (taskType == 2) {
                int newElem;
                cout << "Введите новый элемент: \n";
                cin >> newElem;
                if (findPrime(arr) == -1) {
                    cout << " В массиве нет простых чисел \n";
                } else {
                    placeAfterPrime(arr, findPrime(arr), newElem);
                    cout << "Новый массив: \n";
                    printArray(arr);
                }
            } else if (taskType == 3) {
                deleteElement(arr, isVector);
                printArray(arr);
            }

        }
    }
}