#include "roster.h"
#include <iostream>

int main() {
    Roster roster("CSCI3110");
    roster.readStudentRecord("oneStudent.dat"); // Change the filename to oneStudent.dat

    std::cout << roster;

    return 0;
}
