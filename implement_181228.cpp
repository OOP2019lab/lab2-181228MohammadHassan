#include "student.h"
#include <iostream>

using namespace std;

int student::counter = 0;
student::student()
{

	id = ++counter;
	quizcapacity = 3;
	quiztaken = 0;
	GPA = -1;
	quizscore = new float[quizcapacity];
}
student::student(int quizcap, float gpa)
{
	id = ++counter;
	quizcapacity = quizcap;
	quiztaken = 0;
	GPA = gpa;
	quizscore = new float[quizcapacity];
}
student::student(const student& s1)
{
	id = s1.id;
	quizcapacity = s1.quizcapacity;
	quiztaken = s1.quiztaken;
	GPA = s1.GPA;
	if (s1.quizscore != nullptr)
	{
		quizscore = new float[quizcapacity];
		for (int i = 0; i < quiztaken; i++)
		{
			quizscore[i] = s1.quizscore[i];
		}
	}
}
student::~student()
{
	delete[]quizscore;
	quizscore = nullptr;
}
void student::addquizcsore(float score)
{
	if (quiztaken < quizcapacity)
	{
		quizscore[quiztaken] = score;
		quiztaken++;
	}
	else
		cout << "sorry,no more quiz score can be added" << endl;
}
void student::setGPA(float gpa)
{
	GPA = gpa;
}
float student::getGPA() const
{
	return GPA;
}
void student::print() const
{
	cout << "ID:" << id << endl;
	cout << "Quizzes Taken :" << quiztaken << endl;
	for (int i = 0; i < quiztaken; i++)
	{
		cout << "quiz " << i << " score :" << quizscore[i] << endl;
	}
	cout << "GPA:" << GPA << endl << endl << endl;
}
bool student::compare(student s1)
{
	if (GPA >= s1.GPA)
		return 1;
	else
		return 0;
}
void student::updatescore(int quiz, float score)
{
	if (quiz <= quiztaken)
	{
		quizscore[quiz - 1] = score;
	}
	else
		cout << "Quiz " << quiz << " not taken" << endl;
}
