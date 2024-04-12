#pragma once
#include <iostream>
#include "menu.h"
#include "people.h"

void fetchStudentsFromFile(vector<Student>& students);

void manageStudents(vector<Student>& students);
	void displayStudents(vector<Student>& students);

	void editStudents(vector<Student>& students);
		void addStudent(vector<Student>& students);
		void deleteStudent(vector<Student>& students);
		void editStudentsData(vector<Student>& students);
		void editSubjectsData(vector<Student>& students);

	void removeAllStudents(vector<Student>& students);

	void saveStudentsToFile(vector<Student>& students);

	//save to file