#ifndef PRACTICE_H
#define PRACTICE_H


enum practiceType
{
	SHOOTING_PRACTICE = 1, SKILL_PRACTICE, TACKLE_PRACTICE
};

class Player; //forward delcaration

class Practice
{
public:
	Practice();
	~Practice();
	virtual int Train(int, Player&playObj);

private:

};

class ShootingPractice : public Practice
{
	int Train(int, Player&playObj);
};

class SkillPractice :public Practice
{
	int Train(int, Player&playObj);
};

class TacklePractice :public Practice
{
	int Train(int, Player&playObj);
};


#endif