#ifndef STATISTICS_H
#define STATISTICS_H

class Statistics
{
public:
	Statistics(int sessions = 0, int shoot=0, int skill=0, int tackle=0);
	~Statistics();
	int get_shooting();
	int get_skills();
	int get_tackling();
	int get_sessionNumber();


private:
	int sessionNumber;
	int shooting;
	int skills;
	int tackling;
};

#endif