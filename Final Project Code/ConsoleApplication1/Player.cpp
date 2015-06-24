#include "Player.h"
#include "fstream"
#include <algorithm>

Player::Player()
{
	pPractice = NULL; //initialize everything 
    m_bNeedUpdate = false;
	sessionNumber = 0;
	shooting = 0;
	skills = 0;
	tackling = 0;
};

Player::~Player() //deconstructor
{
	if (pPractice)
	{
		delete pPractice;
		pPractice = NULL;
	}
};

void Player::setUpdateFlag()
{
	m_bNeedUpdate = true;
}

void Player::setShooting(int s)
{
	shooting = s;
}
void Player::setSkills(int s)
{
	skills = s;
}
void Player::SetTackling(int t)
{
	tackling = t;
}

void Player::DoAction(enum practiceType traintype, int practicetime, Player& player) 
{
}

void Player::UpdateTheVector()
{
	sessionNumber++;
	mStatistics.push_back(Statistics(sessionNumber, shooting, skills, tackling));
	shooting = 0; //re-initialize shooting, skills, and tackling after done updating
	skills = 0;
	tackling = 0;
}


void Player::outputStatistics(string stats)
{
	fstream output;

	output.open(stats, ios::out);
	for (unsigned int i = 0; i < mStatistics.size(); i++)
	{
		output << mStatistics[i].get_sessionNumber() << " " << mStatistics[i].get_shooting() << " " << mStatistics[i].get_skills() << " "
			<< mStatistics[i].get_tackling() << endl;
	}

	output.close();
}

// We need this function to define how to sort
// the vector. We will pass this function into the
// third parameter and it will tell it to sort descendingly.
// Statistic object comparison based on Player shooting score
bool descend_statistics_shooting(Statistics& firstStatisticsObj, Statistics& secondStatisticsObj)
{

	if (firstStatisticsObj.get_shooting()>secondStatisticsObj.get_shooting())
		return true;
	else
		return false;
}

// We need this function to define how to sort
// the vector. We will pass this function into the
// third parameter and it will tell it to sort descendingly.
// Statistic object comparison based on Player skill score
bool descend_statistics_skill(Statistics& firstStatisticsObj, Statistics& secondStatisticsObj)
{

	if (firstStatisticsObj.get_skills()>secondStatisticsObj.get_skills())
		return true;
	else
		return false;
}

// We need this function to define how to sort
// the vector. We will pass this function into the
// third parameter and it will tell it to sort descendingly.
// Statistic object comparison based on Player tackling score
bool descend_statistics_tackling(Statistics& firstStatisticsObj, Statistics& secondStatisticsObj)
{

	if (firstStatisticsObj.get_tackling()>secondStatisticsObj.get_tackling())
		return true;
	else
		return false;
}

void Player::outputShootingStatistics(string shoot)
{
	fstream output;

	output.open(shoot, ios::out);

	sort(mStatistics.begin(), mStatistics.end(), descend_statistics_shooting);

	for (unsigned int i = 0; i < mStatistics.size(); i++)
	{
		output << mStatistics[i].get_sessionNumber() << " " << mStatistics[i].get_shooting() << endl;
	}

	output.close();
}
void Player::outputSkillsStatistics(string skills)
{
	fstream output;

	sort(mStatistics.begin(), mStatistics.end(), descend_statistics_skill);

	output.open(skills, ios::out);
	for (unsigned int i = 0; i < mStatistics.size(); i++)
	{
		output << mStatistics[i].get_sessionNumber() << " "<<mStatistics[i].get_skills() << endl;
	}

	output.close();
}
void Player::outputTacklingStatistics(string tackle)
{
	fstream output;

	sort(mStatistics.begin(), mStatistics.end(), descend_statistics_tackling);

	output.open(tackle, ios::out);
	for (unsigned int i = 0; i < mStatistics.size(); i++)
	{
		output << mStatistics[i].get_sessionNumber() << " "<< mStatistics[i].get_tackling() << endl;
	}

	output.close();
}
void Forward::DoAction(enum practiceType traintype, int practicetime, Player& player)
{
	int result;

	switch (traintype)
	{
	case SHOOTING_PRACTICE:
		pPractice = new ShootingPractice;
		result= pPractice->Train(practicetime, *this);
		player.setShooting(shootUpdate(result));
		break;
	case SKILL_PRACTICE:
		pPractice = new SkillPractice;
		result = pPractice->Train(practicetime, *this);
		player.setSkills(SkillUpdate(result));
		break;
	case TACKLE_PRACTICE:
		pPractice = new TacklePractice;
		result = pPractice->Train(practicetime, *this);
		player.SetTackling(tackleUpdate(result));
		break;
	default:
		break;
	}
	if (pPractice)
	{
		delete pPractice;
		pPractice = NULL;
	}
}


void Defender::DoAction(enum practiceType traintype, int practicetime, Player& player)
{
	int result;

	switch (traintype)
	{
	case SHOOTING_PRACTICE:
		pPractice = new ShootingPractice;
		result = pPractice->Train(practicetime, *this);
		player.setShooting(shootUpdate(result));
		break;
	case SKILL_PRACTICE:
		pPractice = new SkillPractice;
		result = pPractice->Train(practicetime, *this);
		player.setSkills(SkillUpdate(result));
		break;
	case TACKLE_PRACTICE:
		pPractice = new TacklePractice;
		result = pPractice->Train(practicetime, *this);
		player.SetTackling(tackleUpdate(result));
		break;
	default:
		break;
	}
	if (pPractice)
	{
		delete pPractice;
		pPractice = NULL;
	}
}

void Midfielder::DoAction(enum practiceType traintype, int practicetime, Player& player)
{
	int result;

	switch (traintype)
	{
	case SHOOTING_PRACTICE:
		pPractice = new ShootingPractice;
		result = pPractice->Train(practicetime, *this);
		player.setShooting (shootUpdate(result));
		break;
	case SKILL_PRACTICE:
		pPractice = new SkillPractice;
		result = pPractice->Train(practicetime, *this);
		player.setSkills(SkillUpdate(result));
		break;
	case TACKLE_PRACTICE:
		pPractice = new TacklePractice;
		result = pPractice->Train(practicetime, *this);
		player.SetTackling(tackleUpdate(result));
		break;
	default:
		break;
	}

	if (pPractice)
	{
		delete pPractice;
		pPractice = NULL;
	}
}


int Forward::shootUpdate(int r)
{
	if (m_bNeedUpdate)
	{
		r = r + 2; //Foward and shooting correlate, therefore +2 bonus
		m_bNeedUpdate = false;
	}
	return r;
	
}

int Forward::tackleUpdate(int r)
{
	if (m_bNeedUpdate)
	{
		//Forwards and tackling don't correlate, there no bonus
		m_bNeedUpdate = false;
	}
	return r;
}

int Forward::SkillUpdate(int r)
{
	if (m_bNeedUpdate)
	{
		r = r + 1; //Forwards and skill somewhat correlate, therefore +1 bonus
		m_bNeedUpdate = false;
	}
	return r;
}

int Midfielder::shootUpdate(int r)
{
	if (m_bNeedUpdate)
	{
		r = r + 1; //Midfielders and shooting somewhat correlate, there +1 bonus
		m_bNeedUpdate = false;
	}
	return r;
}

int Midfielder::tackleUpdate(int r)
{
	if (m_bNeedUpdate)
	{
		 //Midfielders and tackling don't correlate, there no bonus
		m_bNeedUpdate = false;
	}
	return r;
}

int Midfielder::SkillUpdate(int r)
{
	if (m_bNeedUpdate)
	{
		r = r + 2; //Midfielders and skill correlate, therefore +2 bonus
		m_bNeedUpdate = false;
	}
	return r;
}
int Defender::shootUpdate(int r)
{
	if (m_bNeedUpdate)
	{
		//Defenders and shooting don't correlate, therefore no bonus
		m_bNeedUpdate = false;
	}
	return r;
}

int Defender::tackleUpdate(int r)
{
	if (m_bNeedUpdate)
	{
		r = r + 2; //Defenders and tackling correlate, therefore +2 bonus
		m_bNeedUpdate = false;
	}
	return r;
}



int Defender::SkillUpdate(int r)
{
	if (m_bNeedUpdate)
	{
		r = r + 1; //Defender and skill somewhat correlate, therefore +1 bonus
		m_bNeedUpdate = false;
	}
	return r;
}