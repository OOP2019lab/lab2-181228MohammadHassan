#include "header_181228.h"
#include <iostream>
#include <fstream>

CricketTeam::CricketTeam() {
	membernames = nullptr;
	no_of_members = 0;
	teamName = nullptr;
	for (int i = 0; i < 10; i++) {
		ScoreInLast10Matches[i] = -1;
	}
	Rank = -1;
}

CricketTeam::CricketTeam(string name, int number) {
	teamName = new char[name.length()];
	no_of_members = number;
	membernames = nullptr;
	Rank = 1;
	for (int i = 0; i < 10; i++) {
		ScoreInLast10Matches[i] = -1;
	}
}

CricketTeam::CricketTeam(const char * fileName) {
	ifstream file;
	char tName[500];
	file.open(fileName);
	file.ignore(5000, ':');
	file.getline(tName, 500);
	teamName = new char[strlen(tName) + 1];
	strcpy_s(teamName, strlen(tName) + 1, tName);
	file >> no_of_members;
	file.ignore();
	membernames = new string[no_of_members];
	for (int i = 0; i < no_of_members; i++) {
		file.getline(tName, 500);
		membernames[i] = string(tName);
	}
	file >> Rank;
	file.ignore(5000, ':');
	file.getline(tName, 500);
	captain = string(tName);
	int i = 0;
	while (!file.eof() && i < 10){
		file >> ScoreInLast10Matches[i];
		i++;
	}
}

CricketTeam::~CricketTeam() {
	delete[] teamName;
	delete[] membernames;
}

string CricketTeam::getCaptain() {
	return captain;
}
int CricketTeam::getRank() {
	return Rank;
}
char* CricketTeam::getTeamName() {
	return teamName;
}
int CricketTeam::getNoOfMembers() {
	return no_of_members;
}
void CricketTeam::setCaptain(string cap) {
	captain = cap;
}
void CricketTeam::setRank(int r) {
	Rank = r;
}
void CricketTeam::setTeamName(char * name) {
	if (teamName == nullptr) {
		teamName = new char[strlen(name) + 1];
		strcpy_s(teamName, strlen(name) + 1, name);
	}
	else {
		strcpy_s(teamName, strlen(name) + 1, name);
	}
}
void CricketTeam::setNoOfMembers(int n) {
	no_of_members = n;
}

void CricketTeam::inputTeamMember(string name) {
	int count = 0;
	if (membernames == nullptr) {
		membernames = new string[no_of_members];
	}
	for (; count < no_of_members && membernames[count].length() != 0; count++);
	if (count < no_of_members) {
		membernames[count] = name;
	}
	else {
		cout << "members array is full!";
	}
}

void CricketTeam::inputScore(int score) {
	int i = 0;
	for (; i < 10 && ScoreInLast10Matches[i] != -1; i++);
	if (i < 10) {
		ScoreInLast10Matches[i] = score;
	}
	else {
		for (int j = 0; j < 9; j++) {
			ScoreInLast10Matches[j] = ScoreInLast10Matches[j + 1];
		}
		ScoreInLast10Matches[9] = score;
	}
}

float CricketTeam::avgScore() {
	int sum = 0, i;
	for (i = 0; i < 10 && ScoreInLast10Matches[i] != -1; i++) {
		sum += ScoreInLast10Matches[i];
	}
	return (float)sum / (i + 1);
}

void CricketTeam::printLatestScore() {
	int i = 0;
	for (; i < 10 && ScoreInLast10Matches[i] != -1; i++);
	cout << "Latest Score is: " << ScoreInLast10Matches[i - 1] << "\n"
		<< "Team Name: " << teamName << "\n"
		<< "Captain Name: " << captain << "\n";
}

void CricketTeam::printTeamInfo() {
	cout << "Team Name: " << teamName << "\n"
		<< "Captain Name: " << captain << "\n";
	cout << "Members: \n";
	for (int i = 0; i < no_of_members && membernames[i].length() > 0; i++) {
		cout << membernames[i] << "\n";
	}
	cout << "Last 10 scores: \n";
	for (int i = 0; i < 10 && ScoreInLast10Matches[i] != -1; i++) {
		cout << ScoreInLast10Matches[i] << " ";
	}
	cout << endl;
}

bool CricketTeam::compare(CricketTeam &second) {
	float avg1 = avgScore();
	float avg2 = second.avgScore();
	return avg2 > avg1;
}