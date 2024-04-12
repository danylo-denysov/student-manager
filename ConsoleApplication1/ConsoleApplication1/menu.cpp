#include "menu.h"

void mainMenu()
{
	cout << "(0) Exit" << endl
		<< "(1) Fetch students from file" << endl
		<< "(2) Manage students" << endl;
}

void manageStudentsMenu()
{
	cout << "(0) Go back" << endl
		<< "(1) Display students" << endl //DONE
		<< "(2) Edit students" << endl  // DONE
		<< "(3) Remove all" << endl  // DONE
		<< "(4) Save to file" << endl;
}

void editStudentsMenu()
{
	cout << "(0) Go back" << endl
		<< "(1) Add student" << endl
		<< "(2) Delete student" << endl
		<< "(3) Edit student's data" << endl // DONE
		<< "(4) Edit student's subject data" << endl;  // DONE
}

void studentDataMenu()
{
	cout << "(0) Go back" << endl
		<< "(1) ID" << endl // DONE
		<< "(2) Name" << endl // DONE
		<< "(3) Surname" << endl // DONE
		<< "(4) Age" << endl // DONE
		<< "(5) Faculty" << endl // DONE
		<< "(6) Term" << endl; // DONE
}

void subjectDataMenu()
{
	cout << "(0) Go back" << endl // DONE
		<< "(1) Add subject" << endl // DONE
		<< "(2) Delete subject" << endl // DONE
		<< "(3) Edit subject's name" << endl // DONE
		<< "(4) Edit subject's grades" << endl; // DONE
}

void gradeMenu()
{
	cout << "(0) Go back" << endl  // DONE
		<< "(1) Add grade" << endl  // DONE
		<< "(2) Remove grade" << endl  // DONE
		<< "(3) Edit grade" << endl; // DONE
}
