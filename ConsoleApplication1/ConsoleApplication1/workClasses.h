#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Subject
{
private:
	string subjectName;
	vector<float> grades;
public:
	Subject() : subjectName("None") {}
	Subject(string subjectName) : subjectName(subjectName) {}

	string getSubjectName();

	void setSubjectName(string new_subject_name);
	void setGrade(int index, float new_grade);
	vector<float>* getGrades();

	void display();
	void addGrade(float new_grade);
	void removeGrade(int index);
};