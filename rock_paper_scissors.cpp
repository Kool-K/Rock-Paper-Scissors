#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <ctype.h>
#include <vector>
#include<thread>
#include<chrono>
using namespace std;
bool isValid(string userchoice)
{
	if (userchoice == "rock" || userchoice == "paper" || userchoice == "scissors")
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void toLowerase(string &str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);
}
void getResult(string userchoice, string cchoice)
{
	if (userchoice == cchoice)
	{
		cout << "Hmmm it's a tie! Great minds think alike! Rematch maybe?!" << endl;
	}
	else
	{
		bool Win = (userchoice == "rock" && cchoice == "scissors") ||
		           (userchoice == "paper" && cchoice == "rock") ||
		           (userchoice == "scissors" && cchoice == "paper");

		if (Win)
		{
			cout << "Yay you beat the computer!" << endl;
		}
		else
		{
			cout << "Whoops the computer beat you! Better luck next time" << endl;
		}
	}
}
int main()
{
	string repeat, userchoice, cchoice;
	vector<string> choice = {"Rock", "Paper", "Scissors"};
	srand(time(0)); // initialises the seed at the start of the program

	do
	{
		cout << "Enter!" << endl
		     << "Rock Paper or Scissors!" << endl;
		cin >> userchoice;
		toLowerase(userchoice);
		while (!isValid(userchoice))
		{
			cout << "Invalid Input!" << endl
			     << "Please enter either Rock Paper or Scissors" << endl;
			cin >> userchoice;
			transform(userchoice.begin(), userchoice.end(), userchoice.begin(), ::tolower);
		}
		cout << "Computer is thinking....." << endl;
		cout<<"Hmm..."<<endl;
		for(int i=0; i<3; i++)
		{
			cout<<"."<<endl;
			flush(cout);
			this_thread::sleep_for(chrono::seconds(1));
		}
		int compchoice = rand() % 3;
		cchoice = choice[compchoice];
		cout <<endl<< "Computer plays: " << cchoice << endl;
		toLowerase(cchoice);
		getResult(userchoice, cchoice);
		cout << "Wanna play again? Type 'yes' to play again!" << endl;
		cin >> repeat;
		toLowerase(repeat);
	} while (repeat == "yes");
}
