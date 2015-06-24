#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "Statistics.h"
#include "Practice.h"
using namespace std;
enum playerRole
{
	DEFENDER = 1, MIDFIELDER, FORWARD
};

class Practice;

class Player
{
public:
	Player();
	~Player();
	void setUpdateFlag();
	void UpdateTheVector();
	void setShooting(int);
	void setSkills(int);
	void SetTackling(int);
	void outputStatistics(string stats);
	void outputShootingStatistics(string shoot);
	void outputSkillsStatistics(string skill);
	void outputTacklingStatistics(string tackle);

	virtual void DoAction(enum practiceType traintype, int practicetime, Player& player);
	
protected:
	

	Practice * pPractice;
	bool m_bNeedUpdate;
	vector<Statistics> mStatistics;
private:
	int sessionNumber;
	int shooting;
	int skills;
	int tackling;
	
};

class Forward : public Player //derived class
{
	int shootUpdate(int r);
	int tackleUpdate(int r);
	int SkillUpdate(int r);
public:
	virtual void DoAction(enum practiceType traintype, int practicetime, Player& player);

};

class Midfielder :public Player //derived class
{
	int shootUpdate(int r);
	int tackleUpdate(int r);
	int SkillUpdate(int r);
public:
	virtual void DoAction(enum practiceType traintype, int practicetime, Player& player);
};

class Defender :public Player //derived class
{
	int shootUpdate(int r);
	int tackleUpdate(int r);
	int SkillUpdate(int r);
public:
	virtual void DoAction(enum practiceType traintype, int practicetime, Player& player);
};

#endif