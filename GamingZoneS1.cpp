#include <iostream>
#include <limits>  // Added for numeric_limits
#include "snakegame.h"
#include "Jungleblock.h"
#include "Hangman.h"
#include "Tictactoe.h"
#include "Tooken.h"
// #include "floppybird.h"

using namespace std;

int main()
{
    system("color 2");
    char ch = 'y';

    do {
        cout << "           (`-')  _ <-. (`-')    _     <-. (`-')_                 (`-')             <-. (`-')_  (`-')  _ " << endl;
        cout << "    .->    (OO ).-/    \\(OO )_  (_)       \\( OO) )    .->         ( OO).->    .->      \\( OO) ) ( OO).-/ " << endl;
        cout << " ,---(`-') / ,---.  ,--./  ,-.) ,-(`-'),--./ ,--/  ,---(`-')    ,(_/----.(`-')----. ,--./ ,--/ (,------. " << endl;
        cout << "'  .-(OO ) | \\ /`.\\ |   `.'   | | ( OO)|   \\ |  | '  .-(OO )    |__,    |( OO).-.  '|   \\ |  |  |  .---'" << endl;
        cout << "|  | .-, \\ '-'|_.' ||  |'.'|  | |  |  )|  . '|  |)|  | .-, \\     (_/   / ( _) | |  ||  . '|  |)(|  '--." << endl;
        cout << "|  | '.(_/(|  .-.  ||  |   |  |(|  |_/ |  |\\    | |  | '.(_/     .'  .'_  \\|  |)|  ||  |\\    |  |  .--'" << endl;
        cout << "|  '-'  |  |  | |  ||  |   |  | |  |'->|  | \\   | |  '-'  |     |       |  '  '-'  '|  | \\   |  |  `---." << endl;
        cout << " `-----'   `--' `--'`--'   `--' `--'   `--'  `--'  `-----'      `-------'   `-----' `--'  `--'  `------'" << endl;
        cout << endl;
        cout << "------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;

        string name;
        int ch1;

        cout << "\t\t\t\t /\\/\\/\\/\\MENU/\\/\\/\\/\\  \n";
        cout << "1. Play Tic Tac Toe\n";
        cout << "2. Play Jungle Block Game\n";
        cout << "3. Play Hangman\n";
        cout << "4. Play Snake game\n";
        cout << "5. Exit\n";

        cout << "ENTER YOUR NAME: ";
        cin.ignore();
        getline(cin, name);

        try {
        	  cin.clear();
            cout << "Enter the respective number of the game you want to play: ";
            cin >> ch1;

            if (!(ch1 >= 1 || ch1 <= 5)) {
            	throw 0.0;
            if(ch1>='A'||ch1<='Z')
            {
            	throw 0;
			}
			}
            

            else if (ch1 == 1) {
                system("cls");
                cout << "***WELCOME TO TIC TAC TOE***" << endl;
                cout << "YOUR NAME: " << name << endl;
                Tooken(1, name);
                cout << "You've got 30 mins.....ROCK!!!" << endl;
                system("pause");
                playTicTacToe();
            } else if (ch1 == 2) {
                system("cls");
                cout << "***WELCOME TO JUNGLE BLOCK GAME***" << endl;
                cout << "YOUR NAME: " << name << endl;
                Tooken(2, name);
                cout << "You've got 30 mins.....ROCK!!!" << endl;
                system("pause");
                playJungleBlockGame();
            } else if (ch1 == 3) {
                system("cls");
                cout << "***WELCOME TO HANGMAN GAME***" << endl;
                cout << "YOUR NAME: " << name << endl;
                Tooken(3, name);
                cout << "You've got 30 mins.....ROCK!!!" << endl;
                system("pause");
                playHangman();
            } else if (ch1 == 4) {
                system("cls");
                cout << "***WELCOME TO SNAKE GAME***" << endl;
                cout << "YOUR NAME: " << name << endl;
                Tooken(4, name);
                cout << "You've got 30 mins.....ROCK!!!" << endl;
                system("pause");
                playsnakegame();
            } else if (ch1 == 5) {
                cout << " _______ _______ _______ _______ __  __      ___ ___ _______ _______      _______ _______ ______      ______ _____   _______ ___ ___ _______ _______ _______ " << endl;
                cout << "|_     _|   |   |   _   |    |  |  |/  |    |   |   |       |   |   |    |    ___|       |   __ \\    |   __ \\     |_|   _   |   |   |_     _|    |  |     __|" << endl;
                cout << "  |   | |       |       |       |     <      \\     /|   -   |   |   |    |    ___|   -   |      <    |    __/       |       |\\     / _|   |_|       |    |  |" << endl;
                cout << "  |___| |___|___|___|___|__|____|__|\\__|      |___| |_______|_______|    |___|   |_______|___|__|    |___|  |_______|___|___| |___| |_______|__|____|_______|" << endl;
            } else {
                cout << "Invalid choice! Please enter a valid option.\n" << endl;
            }
        } catch (double x) {
            cout << "Invalid Input! Try again" << endl;
            cout << "Enter the respective number of the game you want to play: ";
            cin >> ch1;
            continue;
        }catch (int x) {
            cout << "Invalid Input! Try again" << endl;
            cout << "Enter the respective number of the game you want to play: ";
            cin >> ch1;
          
            continue;
        }


        cout << "DO YOU WANT TO MAKE A RE-ENTRY? (Y/y to continue, any other key to exit): ";
        cin >> ch;
        cout << "---------------------------------------------------------------------------" << endl;
        system("cls");

    } while (ch == 'y' || ch == 'Y');

    return 0;
}

