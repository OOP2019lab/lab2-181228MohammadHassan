#include "student.h"
#include <algorithm>

using namespace std;

void printarray(student arr[], int size)
{
	for (int i = 0; i < size; i++)
		arr[i].print();
}


student* student::GPAarr(student* in, int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (in[i].getGPA() > 2) count++;
	}
	student* out = new student[count];
	int ptr = 0;
	for (int i = 0; i < size; i++) {
		if (in[i].getGPA() > 2) {
			out[ptr] = in[i];
			out[ptr].quizscore = new float[out[ptr].quizcapacity];
			for (int j = 0; j < out[ptr].quizcapacity; j++) {
				out[ptr].quizscore[j] = in[i].quizscore[j];
			}
			ptr++;
		}
	}
	return out;
}

void sort(student* in, int size) {
	for (int i = 0; i < size - 1; i++) {
		int max = i;
		for (int j = i + 1; j < size; j++) {
			if (in[j].getGPA() > in[max].getGPA()) {
				max = j;
			}
		}
		swap(in[i], in[max]);
	}
}
int main()
{
	student arr[3]={student(3,2),student(3,3),student(4,2.33)};
	arr[0].addquizcsore(1) ;  //score of studentg 1
	arr[0].addquizcsore(4);
	arr[0].addquizcsore(10);
	arr[1].addquizcsore(10);  //score of student 2
	arr[1].addquizcsore(4);
	arr[1].addquizcsore(9);
	arr[2].addquizcsore(9);   //score of student 3
	arr[2].addquizcsore(8);
	arr[2].addquizcsore(7);
	printarray(arr,3);
	system("pause");
}