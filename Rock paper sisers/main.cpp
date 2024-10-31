//Vishal_Wagh


#include <bits/stdc++.h>
using namespace std;

vector<string> choices = {"rock", "paper", "scissor"};
int hScore = 0;
int Round = 0;

int result(string cGuess, string hGuess, int hScore, int Round) {
    if (hGuess == cGuess) {
        cout << "It's a draw!" << endl;
        cout << "Score: " << hScore << "/" << Round << endl;
    } else if (hGuess == "rock" && cGuess == "scissor") {
        hScore++;
        cout << "You Win!" << endl;
        cout << "Score: " << hScore << "/" << Round << endl;
    } else if (hGuess == "paper" && cGuess == "rock") {
        hScore++;
        cout << "You Win!" << endl;
        cout << "Score: " << hScore << "/" << Round << endl;
    } else if (hGuess == "scissor" && cGuess == "paper") {
        hScore++;
        cout << "You Win!" << endl;
        cout << "Score: " << hScore << "/" << Round << endl;
    } else if (hGuess == "rock" && cGuess == "paper") {
        Round++;
        cout << "You Lost!" << endl;
        cout << "Score: " << hScore << "/" << Round << endl;
    } else if (hGuess == "paper" && cGuess == "scissor") {
        Round++;
        cout << "You Lost!" << endl;
        cout << "Score: " << hScore << "/" << Round << endl;
    } else if (hGuess == "scissor" && cGuess == "rock") {
        Round++;
        cout << "You Lost!" << endl;
        cout << "Score: " << hScore << "/" << Round << endl;
    } return hScore;
}

int main() {
    srand(time(0));
    while (true) {
        cout << "Round- " << Round << endl;
        string hGuess;
        cout << "Please enter your choice (rock, paper, scissor, or q to quit): ";
        cin >> hGuess;

        if (hGuess == "q") {
            cout << "Final result: " << hScore << "/" << Round << endl;
            break;
        } else {
            bool right = false;
            for (string choice : choices) {
                if (hGuess == choice) {
                    right = true;
                    break;
                }}

            if (right) {
                cout << "Your choice: " << hGuess << endl;
                string cGuess = choices[rand() % 3];
                cout << "The computer's choice: " << cGuess << endl;
                hScore = result(cGuess, hGuess, hScore, Round);
                cout << endl;
                Round++;
            } else {
                cout << "Wrong choice, try again!!!" << endl << endl;
            }}}
        return 0;
}
