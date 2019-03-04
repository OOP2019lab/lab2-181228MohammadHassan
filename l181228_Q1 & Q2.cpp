#include "student.h"

int main()
{
	student s1;
	s1.addquizcsore(10);
	s1.addquizcsore(3);
	s1.addquizcsore(7);
	s1.addquizcsore(1);
	s1.print();
	student s2(4,2);
	s2.addquizcsore(9);
	s2.addquizcsore(4);
	s2.addquizcsore(6);
	s2.print();
	student s3=s1;   //copy constructor was invoked here because it was implemented here
	s3.updatescore(1,3);
	s3.updatescore(10,3);
	cout<<s1.compare(s2)<<endl;
	s3.setGPA(3);
	s3.print();
	s1.print();
	student arr[3];
	system("pause"); //destructor is invoked here be
}	