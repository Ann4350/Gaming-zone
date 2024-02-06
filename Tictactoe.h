#ifndef Tictactoe_H
#define Tictactoe_H

#define developerName "Amna Arif"
#define projectType  "Gaming zone"

#include <iostream>
#include <cctype>
#include <limits>
using namespace std;
void playTicTacToe() {

    char ch;
    do {
        system("CLS");
        int i = 0;
        char arr[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

        do {
            cout << endl << endl;
            cout << "**X********O*******************************************************" << endl;
        cout << "****X*********O************** TIC TAC TOE **************************" << endl;
        cout << "O******X*********O**************************___|___|_X_*************" << endl;
        cout << "**O*******X*********O***********************___|_O_|___*************" << endl;
        cout << "*****O*******X********O********************* X |   |   *************" << endl;
        cout << "X******O*******X********O*******************************************" << endl;
        
        cout << "-----------------------------------------------------------------------" << endl;
             cout<<"CHOOSE INPUTS BETWEEN 1-9"<<endl;
             cout<<"Avoid selecting inputs that are already occupied, GOOD LUCK :]"<<endl;
            int a;
            cout<<endl;
            cout << arr[0][0] << "  | " << arr[0][1] << "  | " << arr[0][2] << endl;
            cout << "___|____|___" << endl;
            cout << arr[1][0] << "  | " << arr[1][1] << "  | " << arr[1][2] << endl;
            cout << "___|____|___" << endl;
            cout << arr[2][0] << "  | " << arr[2][1] << "  | " << arr[2][2] << endl;
            cout << "   |    |    " << endl;

            cout<< "\nEnter player 1 (X)" << endl;
            try {
                char input;
                cin >> input;

                if (!(input >= '1' && input <= '9') || arr[(input - '1') / 3][(input - '1') % 3] == 'X' || arr[(input - '1') / 3][(input - '1') % 3] == 'O') {
                    throw 0.0; //("Invalid input. Please enter a valid number between 1 and 9.");
                }

                a = input - '0';
                arr[(a - 1) / 3][(a - 1) % 3] = 'X';
            }
			 catch (double x) {
                cout<<"THIS IS AN INVALID INPUT, TRY AGAIN WITH A VALID INPUT!!"<<endl;
                cin.clear(); // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
                continue;
            }

            if (arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2] || arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2] ||
                arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2] || arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0] ||
                arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1] || arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2] ||
                arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] || arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) {
	cout<<"  \\   \\      ]\\    \\  //    //   //    //  //  //   //"<<endl;
	cout<<" \\   \\    \\    \\   |    //    //     //    //    //"<<endl;
	cout<<"***************Congratulations**************\n   Player 1 won the Game"<<endl;
	cout<<" //   //    //    //   |    \\    \\     \\    \\    \\" <<endl;
	cout<<"   //   //   //     //   \\    \\  \\    \\  \\   \\   \\"<<endl;
	break;
}

            cout << "\nEnter player 2 (O)" << endl;
            try {
                char input;
                cin >> input;

                if (!(input >= '1' && input <= '9') || arr[(input - '1') / 3][(input - '1') % 3] == 'X' || arr[(input - '1') / 3][(input - '1') % 3] == 'O') {
                    throw 0;// ("Invalid input. Please enter a valid number between 1 and 9.");
                }

                a = input - '0';
                arr[(a - 1) / 3][(a - 1) % 3] = 'O';
            } 
			catch (int x) {
                cout <<"INVALID INPUT, PLEASE CHOOSE A VALID INPUT!! "<< endl;
                cin.clear(); // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
                continue;
            }

            if (arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2] || arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2] ||
                arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2] || arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0] ||
                arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1] || arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2] ||
                arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] || arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) {
	cout<<"  \\   \\      ]\\    \\  //    //   //    //  //  //   //"<<endl;
	cout<<" \\   \\    \\    \\   |    //    //     //    //    //"<<endl;
	cout<<"***************Congratulations**************\n   Player 2 won the Game"<<endl;
	cout<<" //   //    //    //   |    \\    \\     \\    \\    \\" <<endl;
	cout<<"   //   //   //     //   \\    \\  \\    \\  \\   \\   \\"<<endl;
	break;
}

            system("CLS");
            i++;
        } while (i < 5);

        cout << "Press Y if you want to continue... " << endl;
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

#endif
