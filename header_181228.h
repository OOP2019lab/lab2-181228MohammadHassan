#pragma once
#include <string>

using namespace std;

class CricketTeam {
private:
	string * membernames;
	int no_of_members;
	char *teamName;
	int ScoreInLast10Matches[10];
	int Rank;
	string captain;
public:
	CricketTeam();
	CricketTeam(string name, int number);
	CricketTeam(const char * fileName);
	~CricketTeam();
	string getCaptain();
	int getRank();
	char* getTeamName();
	int getNoOfMembers();
	void setCaptain(string cap);
	void setRank(int r);
	void setTeamName(char * name);
	void setNoOfMembers(int n);
	void inputTeamMember(string name);
	void inputScore(int score);
	float avgScore();
	void printLatestScore();
	void printTeamInfo();
	bool compare(CricketTeam & second);
};