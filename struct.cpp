
#include "struct.h"


std::ostream &operator<<(std::ostream &os, vector <Student> &students) {
    os.setf(ios::left);
    os << setw(10) << "ID";
    os << setw(20) << "Name";
    os << setw(10) << "Group";
    os << setw(10) << "Marks" << "\n";
    for (auto student : students) {
        os << std::setw(10) << student.studentId;
        os << std::setw(20) << student.Name;
        os << std::setw(10) << student.groupId;
        for (int i = 0; i < 5; ++i) {
            os << student.marks[i] << " ";
        }
        os << "\n";
    }
    return os;
}

std::istream &operator>>(std::istream &is, Student &student) {
    cout << "Enter student id:";
    is >> student.studentId;
    cout << "Enter student name:";
    is >> student.Name;
    cout << "Enter group id:";
    is >> student.groupId;
    cout << "Enter marks (separated by space):";
    for (int i = 0; i < 5; i++) {
        is >> student.marks[i];
    }
    return is;
}

