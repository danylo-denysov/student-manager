#include <iostream>
#include "manage_functions.h"
using namespace std;

int main()
{
	vector<Student> students;
	//Person x(12312, "Danylo", "Denysov", 19);
	//Student A(x, "Computer science", 3); A.addSubject("Math"); A.addSubject("C++"); A.addSubject("Python");
	//Student B(149090, "Pawid", "Duchala", 22, "Computer Science", 3); B.addSubject("Math"); B.addSubject("C++");
	//Student C(8787, "Gabriela", "Obrzud", 20, "Biology", 1); C.addSubject("Chemistry"); C.addSubject("Organics");
	//Student D(233223, "Arkadiusz", "Knapik", 21, "League of Legends", 6); D.addSubject("Macro movement"); D.addSubject("Mechanics"); D.addSubject("Fight tactics");
	//students.push_back(A);
	//students.push_back(B);
	//students.push_back(C);
	//students.push_back(D);

	int option = 1;

	while (option != 0)
	{
		mainMenu();
		cout << "Option: " << endl;
		cin >> option;

		switch (option)
		{
			case 0:
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			case 1:
			{
				fetchStudentsFromFile(students);
			}
			break;
			case 2:
			{
				manageStudents(students);
			}
			break;
			default:
			{
				cout << "Wrong option" << endl;
			}
			break;
		}
	}
}