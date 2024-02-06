//#ifndef Jungleblock_H
//#define Jungleblock_H
//
//#define developerName "Shamsia Iqbal"
//#define projectType  "Gaming zone"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

const int SSIZE = 5;

class JungleBlockGame {
private:
    char jungle[SSIZE][SSIZE];
    int playerRow[2], playerCol[2];
    int destinationRow, destinationCol;
    int winningPlayer;
    int currentPlayer;

public:
    JungleBlockGame();

    void printJungle();

    void movePlayer(char direction);

    bool checkWin();

    int getCurrentPlayer() const;

    void switchPlayer();

    void runGameLoop();
};

// Jungle block game implementation
JungleBlockGame::JungleBlockGame() {
    playerRow[0] = 0;
    playerCol[0] = 0;
    playerRow[1] = 0;
    playerCol[1] = 1;
    destinationRow = SSIZE - 1;
    destinationCol = SSIZE - 1;
    winningPlayer = -1;
    currentPlayer = 0;

    for (int i = 0; i < SSIZE; ++i) {
        for (int j = 0; j < SSIZE; ++j) {
            jungle[i][j] = '.';
        }
    }

    jungle[playerRow[0]][playerCol[0]] = '1';
    jungle[playerRow[1]][playerCol[1]] = '2';
    jungle[destinationRow][destinationCol] = '$';
    jungle[1][2] = 'X';
    jungle[2][1] = 'X';
    jungle[3][3] = 'X';
}

void JungleBlockGame::printJungle() {
    for (int i = 0; i < SSIZE; ++i) {
        for (int j = 0; j < SSIZE; ++j) {
            cout << jungle[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void JungleBlockGame::movePlayer(char direction) {
    int currentPlayerRow = playerRow[currentPlayer];
    int currentPlayerCol = playerCol[currentPlayer];

    direction = toupper(direction);

    int newPlayerRow = currentPlayerRow;
    int newPlayerCol = currentPlayerCol;

    switch (direction) {
        case 'U':
            if (currentPlayerRow > 0) {
                newPlayerRow = currentPlayerRow - 1;
            }
            break;
        case 'D':
            if (currentPlayerRow < SSIZE - 1) {
                newPlayerRow = currentPlayerRow + 1;
            }
            break;
        case 'L':
            if (currentPlayerCol > 0) {
                newPlayerCol = currentPlayerCol - 1;
            }
            break;
        case 'R':
            if (currentPlayerCol < SSIZE - 1) {
                newPlayerCol = currentPlayerCol + 1;
            }
            break;
        default:
            cout << "Invalid move! Use U, D, L, R to move." << endl;
            return;
    }

    if (jungle[newPlayerRow][newPlayerCol] == 'X') {
        cout << "Oops! Player " << (getCurrentPlayer() + 1) << " touched an obstacle." << endl;
        return;
    }

    jungle[currentPlayerRow][currentPlayerCol] = '.';
    playerRow[currentPlayer] = newPlayerRow;
    playerCol[currentPlayer] = newPlayerCol;
    jungle[newPlayerRow][newPlayerCol] = (currentPlayer == 0) ? '1' : '2';

    if (playerRow[currentPlayer] == destinationRow && playerCol[currentPlayer] == destinationCol) {
        winningPlayer = currentPlayer;
    }
}

bool JungleBlockGame::checkWin() {
    return winningPlayer != -1;
}

int JungleBlockGame::getCurrentPlayer() const {
    return winningPlayer == -1 ? currentPlayer : winningPlayer;
}

void JungleBlockGame::switchPlayer() {
    currentPlayer = (currentPlayer + 1) % 2;
}

void JungleBlockGame::runGameLoop() {
    while (!checkWin()) {
        printJungle();

        char move;
        cout << "Player " << (getCurrentPlayer() + 1) << ", Enter your move (U/D/L/R): ";
        cin >> move;

        move = toupper(move);

        movePlayer(move);

        switchPlayer();
    }

    cout << "Congratulations! Player " << (getCurrentPlayer() + 1) << " reached the destination first." << endl;
}

// Function to play Jungle Block Game
void playJungleBlockGame() {
	cout << " Instructions: " << endl; cout << " U/u for UP" << endl; cout << " D/d for DOWN" << endl; cout << " L/l for LEFT" << endl; 
	cout << " R/r for RIGHT" << endl;
    JungleBlockGame game;
    game.runGameLoop();
    cout << " Thank you for playing this game.\n Please press 5 to head back to the MENU.\n";
}
//#endif
