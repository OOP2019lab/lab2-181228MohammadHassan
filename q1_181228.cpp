#include "header_181228.h"
#include <iostream>


int main() {
	CricketTeam Pakistan("data.txt");
	CricketTeam otherTeam;
	char tName[500];
	cout << "ENter team name: ";
	cin.getline(tName, 500);
	otherTeam.setTeamName(tName);
	cout << "Enter Captain Name: ";
	cin.getline(tName, 500);
	string temp(tName);
	otherTeam.setCaptain(temp);
	int n;
	cout << "ENter number of members: ";
	cin >> n;
	otherTeam.setNoOfMembers(n);
	cin.ignore();
	for (int i = 0; i < n; i++){
		cout << "Enter member name: ";
		cin.getline(tName, 500);
		otherTeam.inputTeamMember(string(tName));
	}
	cout << "Enter Rank of Team: ";
	int r;
	cin >> r;
	otherTeam.setRank(r);
	cout << "Enter scores in last 10 matches: ";
	int s;
	for (int i = 0; i < 10; i++) {
		cin >> s;
		otherTeam.inputScore(s);
	}
	otherTeam.printTeamInfo();
	system("pause");
}