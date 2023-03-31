#ifndef SIAOD4_STRUCT_H
#define SIAOD4_STRUCT_H
#include <iomanip>
#include <vector>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>

using namespace std;

struct Student {
    int studentId;
    std::string Name;
    char groupId[11];
    vector<int> marks{0, 0, 0, 0, 0};

};
void readStudentsFromFile(std::vector<Student>& students, const std::string& filename);
std::ostream &operator<<(std::ostream &os, vector <Student> &students);

std::istream &operator>>(std::istream &is, Student &student);

#endif //SIAOD4_STRUCT_H
