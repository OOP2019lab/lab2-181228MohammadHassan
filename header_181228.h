#include<iostream>
using namespace std;

class student
{
private:
	static int counter;
	int id;
	float *quizscore;
	int quizcapacity;
	int quiztaken;
	float GPA;
public:
	student();
	student(int,float);
	student(const student &);
	~student();
	void addquizcsore(float);
	void setGPA(float);
	float getGPA() const;
	void print() const;
	bool compare(student);
	void updatescore(int,float);
	void printarray(student[],int);
	student *GPAarr(student[],int);
};
