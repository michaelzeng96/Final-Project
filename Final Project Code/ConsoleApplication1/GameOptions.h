#ifndef GAMEOPTIONS_H
#define GAMEOPTIONS_H
#include "Practice.h"
#include <string>
#include "Player.h"
#include <iostream>
#include <fstream>
using namespace std;

#define MAX_TRAINING_PERIODS_IN_SESSION 3
class GameOptions
{
    int m_iTrainSessions;
    bool m_bReadProfile;
    struct trainprofile
    {
        int iPracticeTime;
        enum playerRole ePracticeRole;
        enum practiceType ePracticeType;
    };
	struct trainprofile profile[MAX_TRAINING_PERIODS_IN_SESSION];

    void GetTrainingProfile();

public:

	

	GameOptions();
	~GameOptions();
	void printOutStatistics(string filename);
	void train();
	void outputStatistics(string stats);
	void outputShootingStatistics(string shoot);
	void outputSkillsStatistics(string skill);
	void outputTacklingStatistics(string tackle);
    void turnOnReadProfile();
    void turnOffReadProfile();
	

private:
	vector<trainprofile> mTrainingProfileVector;
	Player *pPlayer;
	Player thePlayer;
};

#endif