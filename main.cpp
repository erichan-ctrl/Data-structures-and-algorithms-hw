#include "struct.h"


using namespace std;


int main() {
    vector<Student> students;
    int numOfStudents;
    cout << "Enter the number of students" << "\n";
    cin >> numOfStudents;
    for (int i = 0; i < numOfStudents; ++i) {
        cout << "Enter the " << i + 1 << " student \n";
        Student student;
        cin >> student;
        students.push_back(student);
    }
    // вывод информации о студентах

    cout << students << "\n";

    int option = 0;

        cout << "Enter an option:\n"
             << "1 - Generate a list of students whose grade point average is greater than 4.0, inserting values in descending order.\n"
             << "2 - Delete from the table the records of students whose grade point average is less than the specified value \n";
        cin >> option;
        if (option == 1) {
            vector<int> goodStudents;

            for (auto &student: students) {
                double avg = accumulate(student.marks.begin(), student.marks.end(), 0.0) / student.marks.size();
                if (avg > 4.0) {
                    goodStudents.push_back(student.studentId);
                }
            }

            auto max_iter = max_element(goodStudents.begin(), goodStudents.end());
            cout << " Student ID of the good students: ";
            while (max_iter != goodStudents.end()) {
                cout << *max_iter << " "; //разыменованный итератор, который указывает на максимальный элемент вектора
                goodStudents.erase(max_iter);
                max_iter = max_element(goodStudents.begin(), goodStudents.end());
            }
        } else if (option == 2) {
            cout << "Enter the minimum average mark:\n";
            int min_avg_mark;
            cin >> min_avg_mark;
            // Удаляем записи о студентах с низким средним баллом
            auto iter = students.begin();
            while (iter != students.end()) {
                double avg_mark = std::accumulate(iter->marks.begin(), iter->marks.end(), 0.0) /
                                  iter->marks.size(); // доступа к члену структуры для получения итератора на начало вектора
                if (avg_mark < min_avg_mark) {
                    iter = students.erase(iter);
                } else {
                    ++iter;
                }
            }

            cout << students;
        }

    return 0;
}