#include <iostream>
#include <fstream>

using namespace std;

int CustomerCount = 0;

void Tooken(int ch1, string name)
{
	srand(static_cast<unsigned int>(time(NULL)));
    int ticketNumber = rand() % 1000 + 1;
    
    ofstream openfile;
    openfile.open("GAMING ZONE.txt", ios::app);
    
	openfile << "**********************************************\n";
    openfile << "\t Customer #" << ++CustomerCount << endl;
    openfile << " NAME: " << name << endl;
    openfile << " Ticket: " << ticketNumber << endl;
    
    if(ch1==1)
    {
    	openfile << " Game Played: Tic Tac Toe" << endl;
	}
	else if(ch1==2)
    {
    	openfile << " Game Played: Jungle Block" << endl;
	}
	else if(ch1==3)
    {
    	openfile << " Game Played: Hangman" << endl;
	}
	else if(ch1==4)
    {
    	openfile << " Game Played: Snake" << endl;
	}
	openfile.close();

	cout<<"Your Ticket Number is : " << ticketNumber << endl;
    
}
