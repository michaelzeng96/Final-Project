#include "GameOptions.h"

#include <algorithm>
using namespace std;
int main()
{
	GameOptions myGame;
	string again;
	do
	{
		
		myGame.turnOffReadProfile();
		myGame.train();
		cout << "Would you like to train again? Type yes or no" << endl;
		cin >> again;
		transform(again.begin(), again.end(), again.begin(), ::tolower);
		cout << endl;
	} while (again == string("yes"));
	
	myGame.outputStatistics("Statistics.txt");
	myGame.outputShootingStatistics("Ranked_Shooting_Stats.txt");
	myGame.outputSkillsStatistics("Ranked_Skills_Stats.txt");
	myGame.outputTacklingStatistics("Ranked_Tackling_Stats.txt");

	myGame.turnOnReadProfile();

	cout << "Your statistics:" << endl;
	myGame.printOutStatistics("Statistics.txt");

	myGame.turnOffReadProfile();

	cout << endl;





		
	 
	

	



	
	return 0;
}