#include <iostream>
#include <string>
#include "githubuser.h"
using namespace std;
bool compare(githubuser user1,githubuser user2)
{
	if(user1.firstname==user2.firstname && user1.username==user2.username && user1.email==user2.email && user1.password==user2.password && user1.foldercount==user2.foldercount)
		return 1;
	else 
		return 0;
}
bool exists(githubuser* arr,int size,string username)
{

	bool flag=false;
	for(int i=0;i < size && flag==true;i++)
		{
			if(arr[i].username==arr[size].username)
			{
				cout<<"This username already existd,enter another name"<<endl;
				flag=true;
			}
		}
			return flag;
}
void inputfromuser(githubuser* arr, int size)
{
	bool flag=false;//for checking name enteres again is not repeated
	for(int i=0;i<size;i++)
	{
		flag=false;
		cin>>arr[i].firstname;
		cin>>arr[i].username;
		while(flag==false)
		{
			if(exists(arr,i+1,arr[i].username)==true)
			{
				cin>>arr[i].username;
			}
			else
				flag=true;
		}
		cin>>arr[i].email;
		cin>>arr[i].password;
		cin>>arr[i].foldercount;
	}
}
int users(githubuser* users,int size,string username)
{
	cin>>username;
	bool flag=true;
	int address=0;
	for(int i=0;i<size && flag==true;i++)
	{
		if(users[i].username==username)
		{
			flag=false;
			address=i;
		}
	}
	return address;
}
int main()
{
	githubuser user1,user2;
	cin>>user1.firstname;
	cout<<endl;
	cin>>user1.username;
	cout<<endl;
	cin>>user1.email;
	cout<<endl;
	cin>>user1.password;
	cout<<endl;
	cin>>user1.foldercount;
	cout<<endl;
	cin>>user2.firstname;
	cout<<endl;
	cin>>user2.username;
	cout<<endl;
	cin>>user2.email;
	cout<<endl;
	cin>>user2.password;
	cout<<endl;
	cin>>user2.foldercount;
	if(compare(user1,user2)==1)
	{
		cout<<"same user"<<endl;
	}
	else
		cout<<"diff user"<<endl;
	githubuser *user;
	int size=4;
	user=new githubuser[size];
 	inputfromuser(user,size);
	system("pause");
}