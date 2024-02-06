#ifndef Hangman_H
#define Hangman_H

#define developerName "Tahira Qurat-ul-ain"
#define projectType  "Gaming zone"

#include <iostream>
#include <cstdlib>
#include <ctime>   

using namespace std;

void playHangman() {
    const int MAX_TRIES = 6;
    string wordList[] = {"jerry", "man", "book", "wire", "guess", "laptop", "monster", "cartoon", "soul"};
    srand(time(0));
    int randomIndex = rand() % 9;
    string word = wordList[randomIndex]; 

    string guessedLetters;
    int incorrectGuess = 0;

    // Provides a hint
    string hint = "";
    if (word == "jerry") {
        hint = "I'm the name of a cartoon character.(Childhood one)";
    } 
    else if (word == "man"){
        hint = "I'm referring to a mature individual.";
    } 
    else if (word == "wire"){
        hint = "You can find me in cables.";
    } 
    else if (word == "cartoon") {
        hint = "I'm what Doraemon, Tom & Jerry etc, are.";
    } 
    else if (word == "laptop" ) {
        hint = "I'm an electronic.";
    } 
    else if ( word == "monster") {
        hint = "I Destroy lives.";
    }
    else if (word == "soul"){
    	hint = " I'm the 'Thing that a human is vassel of.";
	}
	else if (word == "book"){
		hint = "I give humans knowledge, even though they don't read me now-a-days";
	}
	else if (word == " guess"){
		hint = "I'm What you're doing right now,";
	}

    cout << "Hint: " << hint << endl;

    // Game loop
    while (incorrectGuess < MAX_TRIES) {
        system("cls"); // Clear the screen

        // Draws hangman
        cout << "*******************************************************************" << endl;
        cout << "*************************** Hangman********************************" << endl;
        cout << "********************************************************|---\\******" << endl;
        cout << "********************************************************|****O*****" << endl;
        cout << "********************************************************|***/|\\/***" << endl;
        cout << "********************************************************___*/*\\****" << endl;
        
        cout << "-----------------------------------------------------------------------" << endl;
        cout << "  |----\\    " << endl;
        cout << "  |     " << ((incorrectGuess >= 1) ? " O" : " ") << endl;
        cout << "  |     ";
        if (incorrectGuess >= 4) cout << "/";
        else cout << " ";
        if (incorrectGuess >= 2) cout << "|";
        else cout << " ";
        if (incorrectGuess >= 5) cout << "\\";
        else cout << " ";
        cout << endl;
        cout << "  |    ";
        if (incorrectGuess >= 3) cout << "|";
        else cout << " ";
        cout << endl;
        cout << "  |   ";
        if (incorrectGuess >= 6) cout << "/";
        else cout << " ";
        if (incorrectGuess >= 6) cout << "\\";
        else cout << " ";
        cout << endl;
        cout << "-----" << endl;
        cout << endl;

        // Draw the word with hidden letters
        cout << "THE WORD :=>\n";

        for (int i = 0; i < word.length(); i++) {
            char letter = word[i];
            if (guessedLetters.find(letter) != string::npos) {
                cout << letter << " ";
            } else {
                cout << "_ ";
            }
        }
        cout << endl;
        cout << endl;

        // Display the hint again
        cout << "Hint: " << hint << endl;

        // Check if the word is fully guessed
        bool wordGuessed = true;
        for (int i = 0; i < word.length(); i++) {
            char letter = word[i];
            if (guessedLetters.find(letter) == string::npos) {
                wordGuessed = false;
                break;
            }
        }

        if (wordGuessed) {
        	cout << "**********************************************************************" << endl;
            cout << "****************Congratulations! You guessed the word.****************" << endl;
            cout << "**********************************************************************" << endl;
            break;
        }

        // Get the user's guess
        char guess;
        cout << "\nEnter your guess (lowercase letters only) : ";
        cin >> guess;

        // Update the guessed letters
        guessedLetters += guess;

        // Check if the guess is incorrect
        if (word.find(guess) == string::npos) {
            incorrectGuess++;
        }
    }

    if (incorrectGuess == MAX_TRIES) {
        //system("cls"); // Clear the screen
        cout << "Game over! You ran out of attempts." << endl;
        cout << "The word was: " << word << endl;
    }

}
#endif
