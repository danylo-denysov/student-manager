#pragma once
#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "workClasses.h"
#include "MyException.h"

using namespace std;

class Person
{
private:
	int id;
	string name;
	string surname;
	int age;
public:
	Person() : id(0), name("None"), surname("None"), age(0) {}
	Person(int id, string name, string surname, int age) : id(id), name(name), surname(surname), age(age) {}

	int getID(); 
	string getName();
	string getSurname();
	int getAge();

	void setID(int new_id);
	void setName(string new_name);
	void setSurname(string new_surname);
	void setAge(int new_age);

	virtual void display();

};

class Student : public Person
{
private:
	string faculty;
	int term;
	vector<Subject> subjects;
public:
	Student(int id, string name, string surname, int age, string faculty, int term) 
		: Person(id, name, surname, age), faculty(faculty), term(term) {}
	Student(Person& my_person, string faculty, int term) : Person(my_person), faculty(faculty), term(term){}

	string getFaculty();
	int getTerm();
	vector<Subject>* getSubjects();

	void setFaculty(string new_faculty);
	void setTerm(int new_term);

	void display();
	void addSubject(string subject_name);
	void addSubject(Subject& new_subject);
	void removeSubject(string subject_name);

	friend ostream& operator<<(ostream& os, Student& my_student);
	friend istream& operator>>(istream& input, Student& student);
};

