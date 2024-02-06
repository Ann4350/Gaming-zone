#ifndef snakegame_H
#define snakegame_H

#define developerName "Tahira Qurat-ul-ain"
#define projectType  "Gaming zone"

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

const int width = 20;
const int height = 10;

bool gameover;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir;

void Setup() {
    gameover = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void DrawFrame() {
    for (int i = 0; i < width +2 ; i++)
        cout << "#";
    cout << endl;
}

void DrawRow(int i) {
    for (int j = 0; j < width; j++) {
        if (j == 0)
            cout << "#";
        if (i == y && j == x)
            cout << "O";
        else if (i == fruitY && j == fruitX)
            cout << "$";
        else {
            bool print = false;
            for (int k = 0; k < nTail; k++) {
                if (tailX[k] == j && tailY[k] == i) {
                    cout << "o";
                    print = true;
                }
            }
            if (!print)
                cout << " ";
        }
        if (j == width - 1)
            cout << "#";
    }
    cout << endl;
}

void Draw() {
    system("cls");
    DrawFrame();
    for (int i = 0; i < height; i++) {
        DrawRow(i);
    }
    DrawFrame();

    cout << "Score:" << score << endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameover = true;
                break;
        }
    }
}

void Algorithm() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }

    if (x >= width) x = 0;
    else if (x < 0) x = width - 1;

    if (y >= height) y = 0;
    else if (y < 0) y = height - 1;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameover = true;

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

void playsnakegame(){ 
        cout << "*********************************************************$**********" << endl;
        cout << "*************************** SNAKE GAME *****************************" << endl;
        cout << "*********************************************************O**********" << endl;
        cout << "********$********Oooo************************************o**********" << endl;
        cout << "*********************oooo********************************o**********" << endl;
        cout << "*********************************************************o**********" << endl;
        
        cout << "---------------------------------------------------------------------" << endl;
    
    srand(time(NULL));
    Setup();
    while (!gameover) {
        Draw();
        Input();
        Algorithm();
    }	
}
#endif
