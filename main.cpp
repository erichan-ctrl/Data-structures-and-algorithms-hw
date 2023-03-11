#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cstring>

using namespace std;
// Функция для удаления повторяющихся слов в строке

string removeDuplicates(string str) {
    unordered_map<string, bool> map;
    string result;

    for (int i = 0; i < str.length(); i++) {
        string word;

        // Извлекаем каждое слово из строки
        while (i < str.length() && str[i] != ' ' && str[i] != ',') {
            word += str[i];
            i++;
        }

        // Если слово уже было встречено ранее, пропускаем его
        if (map.find(word) != map.end()) {
            continue;
        }

        // Добавляем слово в результат и помечаем его как встреченное
        result += word + ' ';
        map[word] = true;
    }

    return result;
}

struct NumberArray {
    int *arr;
    int size;
};

// Функция, проверяющая, число ли символ
bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

NumberArray getNumbers(const char *str) {
    NumberArray numbers{};
    numbers.arr = new int[strlen(str)];
    numbers.size = 0;

    int number = 0;
    bool inNumber = false;
    bool duplicate = false;

    for (int i = 0; str[i]; i++) {
        if (isDigit(str[i])) {
            number = number * 10 + (str[i] - '0'); //  Преобразование символьного представления числа в целочисленное значение
            inNumber = true;
        } else {
            if (inNumber) {
                duplicate = false;
                for (int j = 0; j < numbers.size; j++) {
                    if (numbers.arr[j] == number) {
                        duplicate = true;
                        break;
                    }
                }
                if (!duplicate) {
                    numbers.arr[numbers.size] = number;
                    numbers.size++;
                }
                number = 0;
                inNumber = false;
            }
        }
    }

    // Проверяем последнее число, если оно есть
    if (inNumber) {
        duplicate = false;
        for (int j = 0; j < numbers.size; j++) {
            if (numbers.arr[j] == number) {
                duplicate = true;
                break;
            }
        }
        if (!duplicate) {
            numbers.arr[numbers.size] = number;
            numbers.size++;
        }
    }

    return numbers;
}

// Функция для извлечения чисел из строки
vector<int> extractNumbers(string str) {
    vector<int> numbers;

    for (int i = 0; i < str.length(); i++) {
        string number;

        // Извлекаем каждое число из строки
        while (i < str.length() && isdigit(str[i])) {
            number += str[i];
            i++;
        }

        // Если число не пустое, добавляем его в массив
        if (!number.empty()) {
            numbers.push_back(stoi(number));
        }
    }

    return numbers;
}


int main() {
    char sentence[2048];
    int option = 0;
    cout << "Delete the words that appear there more than once and form an array of numbers that appear in the text.\n"
            "Enter the option:\n"
            "1 - terminal null realisation\n"
            "2 - string realisation\n"
            "3 - exit\n";

    cin >> option;
    while (option != 3) {
        if (option == 1) {

            cout << "Enter sentence (no more than 2048)\n";
            cin.ignore();
            cin.getline(sentence, 2048);

            string uniqueSentence = removeDuplicates(sentence);
            vector<int> numbers = extractNumbers(uniqueSentence);

            // Выводим уникальное предложение и массив чисел
            cout << "Unique sentence: " << uniqueSentence << endl;
            cout << "Numbers: ";
            for (int number: numbers) {
                cout << number << " ";
            }
            cout << endl;
        } else if (option == 2) {
            cout << "Enter sentence\n";
            cin.ignore();
            cin.getline(sentence, 2048);
            string uniqueSentence = removeDuplicates(sentence);
            vector<int> numbers = extractNumbers(uniqueSentence);

            // Выводим уникальное предложение и массив чисел
            cout << "Unique sentence: " << uniqueSentence << endl;
            cout << "Numbers: ";
            for (int number : numbers) {
                cout << number << " ";
            }
            cout << endl;

            return 0;
        }
        return 0;
    }
}