// roster.cpp
#include "roster.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

// Constructor
Roster::Roster(string name) : courseName(name), studentNum(0) {}

// Read student information from a file
void Roster::readStudentRecord(string filename) {
    std::ifstream inFile(filename);
    
    if (!inFile) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::string id, name;
        int cla, ola, quiz, homework, exam, bonus;

        // Read data from the line
        if (iss >> id >> name >> cla >> ola >> quiz >> homework >> exam >> bonus) {
            if (studentNum < MAX_NUM) { // Ensure we do not exceed the maximum number of students
                students[studentNum] = Student(id, name, cla, ola, quiz, homework, exam, bonus);
                studentNum++; // Increment student count
            } else {
                std::cerr << "Maximum student limit reached." << std::endl;
                break; // Exit if maximum number of students is reached
            }
        } else {
            std::cerr << "Error reading line: " << line << std::endl;
        }
    }
    inFile.close();
}

// Get student count
int Roster::GetStudentCount() const {
    return studentNum;
}

// Check if a student ID is valid
bool Roster::isValid(string id) const {
    for (int i = 0; i < studentNum; i++) {
        if (students[i].getID() == id)
            return true;
    }
    return false;
}

// Show one student's information
void Roster::ShowOneStudent(string id) const {
    for (int i = 0; i < studentNum; i++) {
        if (students[i].getID() == id) {
            students[i].DisplayInfo();
            return;
        }
    }
    std::cout << "Student ID not found." << std::endl;
}

// Output all students' information
std::ostream& operator<<(std::ostream& os, const Roster& oneClass) {
    os << "Here is the information for the students in class " << oneClass.courseName << std::endl;
    os << std::left << std::setw(10) << "ID" << std::setw(10) << "Name" << std::setw(6) << "CLA"
       << std::setw(6) << "OLA" << std::setw(6) << "Quiz" << std::setw(10) << "Homework"
       << std::setw(6) << "Exam" << std::setw(6) << "Bonus" << std::endl;

    for (int i = 0; i < oneClass.studentNum; i++) {
        os << oneClass.students[i] << std::endl;
    }
    return os;
}
