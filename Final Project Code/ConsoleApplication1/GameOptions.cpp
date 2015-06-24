#include "GameOptions.h"


GameOptions::GameOptions()
{
	m_iTrainSessions = 0;
};

GameOptions::~GameOptions(){};

void GameOptions::GetTrainingProfile()
{
    m_iTrainSessions = 0;

	cout << "You will train a total of 3 times every session." << endl<<endl<<endl;
	for (int i = 0; i < MAX_TRAINING_PERIODS_IN_SESSION; i++)
    {
		cout << "Training #" << i + 1 << endl;
		cout << "How many minutes do you want to train?" << endl; 
		cin >> profile[i].iPracticeTime;
		do
		{
			if (profile[i].iPracticeTime < 0) //practice time must be greater than 0
			{
				cout << "Practice time can't be less than 0!" << endl;
				cin >> profile[i].iPracticeTime;
			}
		} while (profile[i].iPracticeTime < 0);
		cout << "Which group do you want to train with today? 1 for defender, 2 for midfielder, 3 for forward." << endl;
		int x = 0;
		cin >> x;
		do
		{
			if (x < 1 || x > 3) //practice must be 1, 2 or 3
			{
				cout << "Must be 1, 2, or 3. 1 for defender, 2 for midfielder, 3 for forward." << endl;
				cin >> x;
			}
		} while (x < 1 || x > 3);
		profile[i].ePracticeRole = (enum playerRole)x;
		cout << "Do you want to practice shooting, skills, or tackling? 1 for shooting, 2 for skills, 3 for tackling." << endl;
		cin >> x;
		do
		{
			if (x < 1 || x > 3) //practice must be 1, 2 or 3
			{
				cout << "Must be 1, 2, or 3. 1 for defender, 2 for midfielder, 3 for forward." << endl;
				cin >> x;
			}
		} while (x < 1 || x > 3);
		profile[i].ePracticeType = (enum practiceType)x;
		cout << endl;
    }

	m_iTrainSessions++; //increment number of sessions after done


}



void GameOptions::turnOnReadProfile()
{
    m_bReadProfile = true;
}

void GameOptions::turnOffReadProfile()
{
    m_bReadProfile = false;
}

void GameOptions::printOutStatistics(string filename)
{ 
	if (m_bReadProfile)
	{
		//Read and print out statistics 
		fstream input;
		input.open(filename, ios::in);

		if (!input.fail())
		{
			int session;
			int shootingrank;
			int skillrank;
			int tacklerank;
			while (!input.eof()) //end of file?
			{
				input >> session;
				input >> shootingrank;
				input >> skillrank;
				input >> tacklerank;
				if (!input.eof()) //if statement put here to prevent a third print out stats
				{
					cout << "Session #: " << session << " " << "Shooting Rank: " << shootingrank << " "
						<< "Skill Rank: " << skillrank << " " << "Tackle Rank: " << tacklerank << endl;
				}
			}

		}
		else
			cout << "File does not exist" << endl;
		input.close();
	}
}

void GameOptions::train()
{
	if (!m_bReadProfile)
	{
		GetTrainingProfile();
		if (m_iTrainSessions > 0)
		{
			for (int i = 0; i < MAX_TRAINING_PERIODS_IN_SESSION; i++)
			{
				if (profile[i].iPracticeTime > 0)
				{
					switch (profile[i].ePracticeRole)
					{
					case DEFENDER: 
						pPlayer = new Defender; 
						pPlayer->DoAction(profile[i].ePracticeType, profile[i].iPracticeTime, thePlayer);
						break;
					case MIDFIELDER:
						pPlayer = new Midfielder;
						pPlayer->DoAction(profile[i].ePracticeType, profile[i].iPracticeTime, thePlayer);
						break;
					case FORWARD:
						pPlayer = new Forward;
						pPlayer->DoAction(profile[i].ePracticeType, profile[i].iPracticeTime, thePlayer);
						break;
					default:
						break;
					}
				}
				if (pPlayer)
				{
					delete pPlayer;
					pPlayer = NULL;
				}
			}

			thePlayer.UpdateTheVector();

			m_iTrainSessions--;
		}
	}
	else
	{ 

		int i = 0; //the initial index for the profile vector

		while (m_iTrainSessions > 0)
		{
			for (int j = 0; j < MAX_TRAINING_PERIODS_IN_SESSION; j++)
			{
				if (mTrainingProfileVector[i].iPracticeTime > 0)
				{
					switch (mTrainingProfileVector[i].ePracticeRole)
					{
					case DEFENDER:
						pPlayer = new Defender;
						pPlayer->DoAction(mTrainingProfileVector[i].ePracticeType, mTrainingProfileVector[i].iPracticeTime, thePlayer);
						break;
					case MIDFIELDER:
						pPlayer = new Midfielder;
						pPlayer->DoAction(mTrainingProfileVector[i].ePracticeType, mTrainingProfileVector[i].iPracticeTime, thePlayer);
						break;
					case FORWARD:
						pPlayer = new Forward;
						pPlayer->DoAction(mTrainingProfileVector[i].ePracticeType, mTrainingProfileVector[i].iPracticeTime, thePlayer);
						break;
					default:
						break;
					}
				}

				i++; //incremt the profile vector index
				if (pPlayer)
				{
					delete pPlayer;
					pPlayer = NULL;
				}
			}

			thePlayer.UpdateTheVector();

			m_iTrainSessions--;
		}
	}
}

void GameOptions::outputStatistics(string stats)
{
	thePlayer.outputStatistics(stats);
}

void GameOptions::outputShootingStatistics(string shoot)
{
	thePlayer.outputShootingStatistics(shoot);
}

void GameOptions::outputSkillsStatistics(string skill)
{
	thePlayer.outputSkillsStatistics(skill);
}

void GameOptions::outputTacklingStatistics(string tackle)
{
	thePlayer.outputTacklingStatistics(tackle);
}