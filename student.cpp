#include "Student.h"

// Default constructor
Student::Student() {
    // Initialize member variables if necessary
}

// Copy constructor
Student::Student(const Student &s) {
    id = s.id;
    name = s.name;
    for (int i = 0; i < CATEGORY_NUM; ++i) {
        score[i] = s.score[i];
    }
}

// Parameterized constructor
Student::Student(string id, string name, int cla, int ola, int quiz, int homework, int exam, int bonus) {
    this->id = id;
    this->name = name;
    score[CLA] = cla;
    score[OLA] = ola;
    score[QUIZ] = quiz;
    score[HOMEWORK] = homework;
    score[EXAM] = exam;
    score[BONUS] = bonus;
    ComputeTotal();
    ComputeGrade();
}

// Assignment operator
Student& Student::operator=(const Student &s) {
    if (this != &s) {
        id = s.id;
        name = s.name;
        for (int i = 0; i < CATEGORY_NUM; ++i) {
            score[i] = s.score[i];
        }
    }
    return *this;
}

// Getter for ID
string Student::getID() const {
    return id;
}

// Setter for ID
void Student::setID(string id) {
    this->id = id;
}

// Setter for Name
void Student::setName(string name) {
    this->name = name;
}

// Getter for Name
string Student::getName() const {
    return name;
}

// Other methods remain unchanged...
void Student::ComputeTotal() {
    total = 0;
    for (int i = 0; i < CATEGORY_NUM; ++i) {
        total += score[i];
    }
}

int Student::GetTotal() const {
    return total;
}

void Student::ComputeGrade() {
    // Example grading logic
    if (total >= 90) letterGrade = 'A';
    else if (total >= 80) letterGrade = 'B';
    else if (total >= 70) letterGrade = 'C';
    else if (total >= 60) letterGrade = 'D';
    else letterGrade = 'F';
}

char Student::GetGrade() const {
    return letterGrade;
}

void Student::changeScore(ScoreType scoreName, int scoreValue) {
    score[scoreName] = scoreValue;
    ComputeTotal(); // Recalculate total after changing a score
}

int Student::getScore(ScoreType scoreName) const {
    return score[scoreName];
}

void Student::DisplayInfo() const {
    cout << "ID: " << id << ", Name: " << name << ", Total: " << total << ", Grade: " << letterGrade << endl;
}

ostream &operator<<(ostream &myout, const Student &s) {
    myout << s.id << " " << s.name << " " << s.score[Student::CLA] << " "
          << s.score[Student::OLA] << " " << s.score[Student::QUIZ] << " "
          << s.score[Student::HOMEWORK] << " " << s.score[Student::EXAM] << " "
          << s.score[Student::BONUS];
    return myout;
}

istream &operator>>(istream &myin, Student &s) {
    // Assuming the input is formatted correctly
    myin >> s.id >> s.name >> s.score[Student::CLA] >> s.score[Student::OLA] 
         >> s.score[Student::QUIZ] >> s.score[Student::HOMEWORK] 
         >> s.score[Student::EXAM] >> s.score[Student::BONUS];
    s.ComputeTotal(); // Recalculate total after input
    s.ComputeGrade(); // Recalculate grade after input
    return myin;
}
