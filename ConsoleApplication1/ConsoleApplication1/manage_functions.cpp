#include "manage_functions.h"

void fetchStudentsFromFile(vector<Student>& students)
{
	students.clear();

	ifstream inputFile("students.txt");
	if (inputFile.is_open())
	{
		string line;
		string subjectName;
		getline(inputFile, line);
		while (!(inputFile.eof()))
		{
			int id;
			string name;
			string surname;
			int age;
			string faculty;
			int term;
			Student A(149090, "Pawid", "Duchala", 22, "Computer Science", 3);

			if (!(subjectName.empty())) line = subjectName;
			//getline(inputFile, line);
			id = stoi(line);
			//inputFile >> id;
			A.setID(id);
			getline(inputFile, name);
			//inputFile >> name;
			A.setName(name);
			getline(inputFile, surname);
			//inputFile >> surname;
			A.setSurname(surname);
			getline(inputFile, line);
			age = stoi(line);
			//inputFile >> age;
			A.setAge(age);
			getline(inputFile, faculty);
			//inputFile >> faculty;
			A.setFaculty(faculty);
			getline(inputFile, line);
			term = stoi(line);
			//inputFile >> term;
			A.setTerm(term);

			bool n = true;
			while (n)
			{
				getline(inputFile, subjectName);
				if (isupper(subjectName[0]))
				{
					n = true;
					getline(inputFile, line);
					istringstream stream(line);
					string token;
					Subject subject(subjectName);
					vector<float>* grades = subject.getGrades();
					while (getline(stream, token, ',')) {
						try {
							float liczba = std::stof(token);
							grades->push_back(liczba);
						}
						catch (const std::invalid_argument& e) {
							std::cerr << "B³¹d konwersji: " << e.what() << std::endl;
							// Mo¿esz zdecydowaæ, jak obs³u¿yæ b³¹d konwersji
						}
					}
					A.addSubject(subject);
				}
				else n = false;
			}


			students.push_back(A);
		}
	}
}

void manageStudents(vector<Student>& students)
{
	int option = 1;

	while (option != 0)
	{
		manageStudentsMenu();
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
				displayStudents(students);
			}
			break;
			case 2:
			{
				editStudents(students);
			}
			break;
			case 3:
			{
				removeAllStudents(students);
			}
			break;
			case 4:
			{
				saveStudentsToFile(students);
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

void editStudents(vector<Student>& students)
{
	int option = 1;

	while (option != 0)
	{
		editStudentsMenu();
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
				addStudent(students);
			}
			break;
			case 2:
			{
				deleteStudent(students);
			}
			break;
			case 3:
			{
				editStudentsData(students);
			}
			break;
			case 4:
			{
				editSubjectsData(students);
			}
			break;
			default:
			{
				cout << "Wrong option" << endl;
			}
			break;
		}
	}

	return;
}

void addStudent(vector<Student>& students)
{
	int id;
	string name;
	string surname;
	int age;
	string faculty;
	int term;

	cout << "ID: " << endl;
	cin >> id;
	cout << "Name: " << endl;
	cin >> name;
	cout << "Surname: " << endl;
	cin >> surname;
	cout << "Age: " << endl;
	cin >> age;
	cout << "Faculty: " << endl;
	cin >> faculty;
	cout << "Term: " << endl;
	cin >> term;

	Student new_student(id, name, surname, age, faculty, term);

	students.push_back(new_student);
}

void deleteStudent(vector<Student>& students)
{
	int student_id;
	cout << "Enter ID of student to remove: " << endl;
	cin >> student_id;
	try
	{
		if (isValueEmpty(student_id)) throw MyException();
	}
	catch (MyException& ex)
	{
		cout << ex.what();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}
	for (auto i = students.begin(); i != students.end(); i++)
	{
		if (student_id == i->getID())
		{
			i = students.erase(i);
			break;
		}
	}
}

void editStudentsData(vector<Student>& students)
{
	int student_id = 0;
	cout << "Enter student's id: " << endl;
	try
	{
		cin >> student_id;
		if (isValueEmpty(student_id)) throw MyException();
	}
	catch (MyException& ex)
	{
		cout << ex.what();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}
	auto s = students.begin();
	bool found = false;
	for (auto i = students.begin(); i != students.end(); i++)
	{
		if (student_id == i->getID())
		{
			s = i;
			found = true;
			break;
		}
	}
	if (found == true)
	{

		int option = 1;
		while (option != 0)
		{
			studentDataMenu();

			cout << endl << "Your student: " << endl;
			s->display();
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
				int new_id;
				cout << "Provide new ID: " << endl;
				cin >> new_id;
				s->setID(new_id);
			}
			break;
			case 2:
			{
				string new_name;
				cout << "Provide new name: " << endl;
				cin >> new_name;
				s->setName(new_name);
			}
			break;
			case 3:
			{
				string new_surname;
				cout << "Provide new surname: " << endl;
				cin >> new_surname;
				s->setSurname(new_surname);
			}
			break;
			case 4:
			{
				int new_age;
				cout << "Provide new age: " << endl;
				cin >> new_age;
				s->setAge(new_age);
			}
			break;
			case 5:
			{
				string new_faculty;
				cout << "Provide new faculty: " << endl;
				cin >> new_faculty;
				s->setFaculty(new_faculty);
			}
			break;
			case 6:
			{
				int new_term;
				cout << "Provide new term: " << endl;
				cin >> new_term;
				s->setTerm(new_term);
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
	else
	{
		cout << "No such student" << endl;
	}

	return;
}

void editSubjectsData(vector<Student>& students)
{
	int student_id;
	cout << "Enter student's id: " << endl;
	try
	{
		cin >> student_id;
		if (isValueEmpty(student_id)) throw MyException();
	}
	catch (MyException& ex)
	{
		cout << ex.what();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}
	auto s = students.begin();
	for (auto i = students.begin(); i != students.end(); i++)
	{
		if (student_id == i->getID())
		{
			s = i;
		}
	}

	int option = 1;

	while (option != 0)
	{
		subjectDataMenu();
		cout << endl << "Your student: " << endl;
		s->display();
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
				string subject_name;
				cout << "Provide subject's name to add: " << endl;
				cin >> subject_name;
				s->addSubject(subject_name);
			}
			break;
			case 2:
			{
				string subject_name;
				cout << "Provide subject's name to delete: " << endl;
				cin >> subject_name;
				s->removeSubject(subject_name);
			}
			break;
			case 3:
			{

				string subject_name;
				cout << "Enter subject's name: " << endl;
				cin >> subject_name;

				vector<Subject>* subjects = s->getSubjects();
				auto subject = subjects->begin();
				bool found = false;
				for (auto i = subjects->begin(); i != subjects->end(); i++)
				{
					if (subject_name == i->getSubjectName())
					{
						subject = i;
						found = true;
						break;
					}
				}
				if (found == true)
				{
					string new_name;
					cout << "Provide new subject's name: " << endl;
					cin >> new_name;
					subject->setSubjectName(new_name);
				}
				else
				{
					cout << "No such subject" << endl;
				}
			}
			break;
			case 4:
			{

				string subject_name;
				cout << "Enter subject's name: " << endl;
				cin >> subject_name;

				vector<Subject>* subjects = s->getSubjects();
				auto subject = subjects->begin();
				bool found = false;
				for (auto i = subjects->begin(); i != subjects->end(); i++)
				{
					if (subject_name == i->getSubjectName())
					{
						subject = i;
						found = true;
						break;
					}
				}
				if (found == true)
				{
					int option_grade = 1;
					while (option_grade != 0)
					{

						gradeMenu();
						cout << "Your subject: " << endl;
						subject->display();
						cin >> option_grade;

						switch (option_grade)
						{
						case 0:
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							break;
						}
						break;
						case 1:
						{
							float new_grade;
							cout << "Provide new grade value: " << endl;
							cin >> new_grade;

							subject->addGrade(new_grade);
						}
						break;
						case 2:
						{
							int grade_index;
							cout << "Provide grade's index (starts from 0): " << endl;
							cin >> grade_index;

							subject->removeGrade(grade_index);
						}
						break;
						case 3:
						{
							int grade_index;
							cout << "Provide grade's index (starts from 0): " << endl;
							cin >> grade_index;

							float new_grade;
							cout << "Provide new grade value: " << endl;
							cin >> new_grade;

							subject->setGrade(grade_index, new_grade);
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
				else
				{
					cout << "No such subject" << endl;
				}
			}
			break;
		}
	}
}

void removeAllStudents(vector<Student>& students)
{
	cout << "Are you sure?" << endl;
	cout << "(1) Yes" << endl << "(2) Cancel" << endl;
	int option;
	try
	{
		cin >> option;
		if (isValueEmpty(option)) throw MyException();
	}
	catch (MyException& ex)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		option = 10;
	}
	switch (option)
	{
	case 1:
		students.clear();
	case 2:
		break;
	default:
		break;
	}
}

void saveStudentsToFile(vector<Student>& students)
{
	ofstream outputFile("students_new.txt");
	if (outputFile.is_open())
	{
		for (auto i = students.begin(); i != students.end(); i++)
		{
			outputFile << i->getID() << endl;
			outputFile << i->getName() << endl;
			outputFile << i->getSurname() << endl;
			outputFile << i->getAge() << endl;
			outputFile << i->getFaculty() << endl;
			outputFile << i->getTerm() << endl;

			vector<Subject>* subjects = i->getSubjects();
			for (auto j = subjects->begin(); j != subjects->end(); j++)
			{
				outputFile << j->getSubjectName() << endl;
				vector<float>* grades = j->getGrades();
				for (auto k = grades->begin(); k != grades->end(); k++)
				{
					outputFile << *k << ", ";
				}
				outputFile << endl;
			}
		}
		outputFile.close();
	}
	else
	{
		cout << "Unable to open the file for writing." << endl;
	}

}

void displayStudents(vector<Student>& students)
{
	cout << endl;
	for (auto i = students.begin(); i != students.end(); i++)
	{
		//cout << *i;
		i->display();
	}
}
