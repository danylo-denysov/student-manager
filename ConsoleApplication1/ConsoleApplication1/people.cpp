#include "people.h"

int Person::getID()
{
	return this->id;
}

string Person::getName()
{
	return this->name;
}

string Person::getSurname()
{
	return this->surname;
}

int Person::getAge()
{
	return this->age;
}

void Person::setID(int new_id)
{
	try
	{
		if (isValueEmpty(new_id))
		{
			throw MyException();
		}
		this->id = new_id;
	}
	catch (MyException& my_exception)
	{
		cout << my_exception.what();
	}
}

void Person::setName(string new_name)
{
	try
	{
		if (isValueEmpty(new_name))
		{
			throw MyException();
		}
		this->name = new_name;
	}
	catch (MyException& my_exception)
	{
		cout << my_exception.what();
	}
}

void Person::setSurname(string new_surname)
{
	try
	{
		if (isValueEmpty(new_surname))
		{
			throw MyException();
		}
		this->surname = new_surname;
	}
	catch (MyException& my_exception)
	{
		cout << my_exception.what();
	}
}

void Person::setAge(int new_age)
{
	try
	{
		if (isValueEmpty(new_age))
		{
			throw MyException();
		}
		this->age = new_age;
	}
	catch (MyException& my_exception)
	{
		cout << my_exception.what();
	}
}

void Person::display()
{
	cout << "\tID: " << this->id << endl 
		<< "\tName: " << this->name << endl 
		<< "\tSurname: " << this->surname << endl 
		<< "\tAge: " << this->age << endl;
}

ostream& operator<<(ostream& os, Student& my_student)
{
	return os << "\tID: " << my_student.getID() << endl
		<< "\tName: " << my_student.getName() << endl
		<< "\tSurname: " << my_student.getSurname() << endl
		<< "\tAge: " << my_student.getAge() << endl
		<< "\tFaculty: " << my_student.getFaculty() << endl
		<< "\tTerm: " << my_student.getTerm() << endl;
}

istream& operator>>(istream& input, Student& student)
{
	int id;
	string name;
	string surname;
	int age;
	string faculty;
	int term;
	input >> id >> name >> surname >> age >> faculty >> term;
	student.setID(id);
	student.setName(name);
	student.setSurname(surname);
	student.setAge(age);
	student.setFaculty(faculty);
	student.setTerm(term);
	return input;
}

string Student::getFaculty()
{

	return this->faculty;
}

int Student::getTerm()
{
	return this->term;
}

vector<Subject>* Student::getSubjects()
{
	return &subjects;
}

void Student::setFaculty(string new_faculty)
{
	try
	{
		if (isValueEmpty(new_faculty))
		{
			throw MyException();
		}
		this->faculty = new_faculty;
	}
	catch (MyException& my_exception)
	{
		cout << my_exception.what();
	}
}

void Student::setTerm(int new_term)
{
	try
	{
		if (isValueEmpty(new_term))
		{
			throw MyException();
		}
		this->term = new_term;
	}
	catch (MyException& my_exception)
	{
		cout << my_exception.what();
	}
}

void Student::display()
{
	Person::display();
	cout << "\tFaculty: " << this->faculty << endl
		<< "\tTerm: " << this->term << endl;
	for (auto i = subjects.begin(); i != subjects.end(); i++)
	{
		i->display();
	}
	cout << endl;

}

void Student::addSubject(string subject_name)
{
	Subject new_subject(subject_name);
	subjects.push_back(new_subject);
}

void Student::addSubject(Subject& new_subject)
{
	subjects.push_back(new_subject);
}

void Student::removeSubject(string subject_name)
{
	for (auto i = subjects.begin(); i != subjects.end(); i++)
	{
		if (subject_name == i->getSubjectName())
		{
			i = subjects.erase(i);
			break;
		}
	}
}
