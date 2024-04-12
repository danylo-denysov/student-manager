#include "workClasses.h"

string Subject::getSubjectName()
{
    return subjectName;
}

void Subject::setSubjectName(string new_subject_name)
{
    this->subjectName = new_subject_name;
}

void Subject::setGrade(int index, float new_grade)
{
    //int count = 0;
    //for (auto i = grades.begin(); i != grades.end(); i++)
    //{
    //    if (count == index)
    //    {
    //        grades[count] = new_grade;
    //    }
    //    count++;
    //}
    grades[index] = new_grade;
}

vector<float>* Subject::getGrades()
{
    return &grades;
}

void Subject::display()
{
    cout << "\tSubject name: " << this->subjectName << endl;
    cout << "\t";
    for (auto i = grades.begin(); i != grades.end(); i++)
    {
        cout << * i << "  ";
    }
    cout << endl;
}

void Subject::addGrade(float new_grade)
{
    grades.push_back(new_grade);
}

void Subject::removeGrade(int index)
{
    int count = 0;
    for (auto i = grades.begin(); i != grades.end(); i++)
    {
        if (count == index)
        {
            i = grades.erase(i);
            break;
        }
        count++;
    }
}
