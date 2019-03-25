#include <iostream>
#include <string>
using namespace std;
class Date
{
private:
	int day;
	int month;
	int year;
	static string monthNames[13];
public:
	Date();
	Date(int, int, int);
	friend ostream& operator <<(ostream&, const Date&);
	bool operator == (const Date&)const;
	friend istream& operator >>(istream&,  Date&);
	Date operator +(const int&)const;
	Date& operator--();
	const Date operator --(int);
	int operator [](int)const;

};
