#include "Practice.h"
#include "Player.h"

Practice::Practice()
{};

Practice::~Practice()
{};

int Practice::Train(int minutes, Player&playObj)
{
	return 1;
};


int ShootingPractice::Train(int minutes, Player&playObj)
{
	int increment_amount = minutes / 10; //100 minute training period = 10 points (before update based on training types)

	if (increment_amount > 0)
		playObj.setUpdateFlag(); //set update flag

	return increment_amount;
}

int SkillPractice::Train(int minutes, Player&playObj)
{
	int increment_amount = minutes / 10;

	if (increment_amount > 0)
		playObj.setUpdateFlag();

	return increment_amount;
}

int TacklePractice::Train(int minutes, Player&playObj)
{
	int increment_amount = minutes / 10;

	if (increment_amount > 0)
		playObj.setUpdateFlag();
	
	return increment_amount;
}

