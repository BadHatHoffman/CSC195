// NumberGuess.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<time.h>
using namespace std;

int main()
{

    int guess;
    int max;
    cout << "Enter the maxmum answer value." << endl;
    while (!(cin >> max)) {
        cin.clear();
        cin.ignore(80, '\n');
        cout << "Error, try again. \n" << endl;
    }
    do {
        cout << "Number Guessing Game!\n" <<  "Enter 0 to End Game" << endl;
        srand((unsigned int)time(0));
        int counter = 0;

        int answer;
        answer = (rand() % max) + 1;
        cout << "Answer: " << answer << endl;

        do {
            cout << "Enter Guess: ";
        while(!(cin >> guess)) {
            cin.clear();
            cin.ignore(80, '\n');
            cout << "Error, try again.\n" << endl;
        }
        counter++;
        cin.ignore(80, '\n');
        
            if (guess == 0) {
                cout << "Game Over." << endl;
                break;
            }
            else if (guess == answer) {
                cout << "Correct! You guessed: " << guess << " Play Again!\n\n" << endl;
            }
            else if(guess > answer){
                cout << "Guess is too high. Try again.\n" << endl;
            }
            else if(guess < answer){
                cout << "Guess is too low. Try again.\n" << endl;
        }
    }while (counter < 5 && guess!=answer);
    if (counter == 5) {
        cout << "You used too many tries, start over.\n\n" << endl;
        }
    }while (guess != 0);

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
