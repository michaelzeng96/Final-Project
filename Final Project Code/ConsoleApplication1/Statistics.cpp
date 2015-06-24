#include "Statistics.h"

Statistics::Statistics(int session, int shoot, int skill, int tackle)
{
	sessionNumber = session;
	shooting = shoot;
	skills = skill;
	tackling = tackle;

};

Statistics::~Statistics(){};

int Statistics::get_sessionNumber()
{
	return sessionNumber;
}

int Statistics::get_shooting()
{
	return shooting;
}

int Statistics::get_skills()
{
	return skills;
}

int Statistics::get_tackling()
{
	return tackling;
}

