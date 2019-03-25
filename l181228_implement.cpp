#include "l181228_date.h"
using namespace std;

 static string monthNames[13] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

Date::Date()
{
	day = 1;
	month = 1;
	year = 2000;
}
Date::Date(int m, int d, int y)
{
	bool flag = false;
	if (m > 12 || m < 1 && flag == false)
	{
		month = 1;
		day = 1;
		year = 2000;
		flag = true;
	}
	else if (flag==false)
		month = m;
	if (d >= 30 || d <= 1 && flag==false)
	{
		month = 1;
		day = 1;
		year = 2000;
		flag = true;
	}
	else if (flag==false)
		day = d;
	if (y >= 9999 || y <= 1000 && flag==false)
	{
		month = 1;
		day = 1;
		year = 2000;
		flag = true;
	}
	else if (flag==false)
		year = y;
}
ostream& operator <<(ostream& output, const Date& d)
{
	output << monthNames[d.month] << " " << d.day << " " << d.year << endl;
	return output;

}
bool Date::operator == (const Date& d1)const
{
	bool flag = true;
	if (day != d1.day)
		flag = false;
	if (month != d1.month && flag == true)
		flag = false;
	if (year != d1.year && flag == true)
		flag = false;
	return flag;

}
istream& operator >>(istream& input,  Date& d)
{
	input >> d.month >> d.day >> d.year;
	bool flag = false;
	if (d.month >= 12 || d.month <= 1 && flag == false)
	{
		d.month = 1;
		d.day = 1;
		d.year = 2000;
		flag = true;
	}
	if (d.day >= 30 || d.day <= 1 && flag == false)
	{
		d.month = 1;
		d.day = 1;
		d.year = 2000;
		flag = true;
	}
	if (d.year >= 9999 || d.year <= 1000 && flag == false)
	{
		d.month = 1;
		d.day = 1;
		d.year = 2000;
		flag = true;
	}
	return input;
}

Date Date::operator +(const int& d1)const
{
	Date temp=*this;
	temp.day += d1;
	if (temp.day > 30)
	{
		if (temp.month == 12)
		{
			int mon_add = temp.day / 30;
			temp.day = temp.day % 30;
			temp.month =mon_add;
			temp.year++;
		}
		else
		{
			int mon_add = temp.day / 30;
			temp.day = temp.day % 30;
			temp.month = temp.month + mon_add;
		}

	}
	return temp;
}
Date& Date ::operator--()
{
	if (this->day == 1)
	{
		this->day = 30;
		if (this->month == 1)
		{
			this->month = 12;
			this->year--;
		}
		else
			this->month--;
	}
	else
		this->day--;
	return*this;

}
const Date Date:: operator --(int)
{
	Date temp = *this;
	if (this->day == 1)
	{
		this->day = 30;
		if (this->month == 1)
		{
			this->month = 12;
			this->year--;
		}
		else
			this->month--;
	}
	else
		this->day--;
	return temp;
}
int Date:: operator [](int index)const
{
	if (index == 0)
	{
		return this->day;
	}
	else if (index == 1)
		return this->month;
	else if (index == 2)
		return this->year;
	else if (index == 0)
	{
		cout << "index can only be 0, 1 or 2." << endl;
		return 0;
	}
}