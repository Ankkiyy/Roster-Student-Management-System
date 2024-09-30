/*
 * File:	Student.h
 * 
 * Purpose: This file is a part of the 1st open lab assignment, which 
 * includes Student.h, Student.cpp, Roster.h, Roster.cpp, 
 * and main.cpp. This file gives the full definition 
 * of the class Student.
 */

#ifndef __CSCI3110_STUDENT__
#define __CSCI3110_STUDENT__

#include <string>
#include <iostream>
using namespace std;

class Student
{
	public:
		enum ScoreType {CLA, OLA, QUIZ, HOMEWORK, EXAM, BONUS};

		static const int CATEGORY_NUM = BONUS - CLA + 1;

		Student();
    	Student(const Student & s);
    	Student(string id, string name, int cla, int ola, int quiz, int homework, int exam, int bonus);
    	Student& operator = (const Student & s);

		string getID() const;
		void setID(string id);
		void setName(string name); // Added setter
		string getName() const; // Added getter
		void  ComputeTotal();
    	int   GetTotal() const;
    	void  ComputeGrade();
    	char  GetGrade() const;

		void changeScore(ScoreType scoreName, int scoreValue);
		int  getScore(ScoreType scoreName) const;

    	void DisplayInfo() const;
    	friend ostream & operator << (ostream & myout, const Student & s);
    	friend istream & operator >> (istream & myin, Student & s);

	private:
		string id;
    	string name;
		int score[CATEGORY_NUM];
    	int total;
    	char letterGrade;
};

#endif
