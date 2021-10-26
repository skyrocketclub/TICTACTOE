// TICTACTOE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
               BUILDING THE TIC-TAC-TOE GAME

  ABOUT THE GAME
  1. AT EVERY POINT, THE STRUCTURE POPS UP WITH FIELDS 1 - 9 WRITTEN
  2. THE PLAYER 1 IS ALWAYS X, WHILE THE PLAYER 2 IS ALWAYS O
  3. THE PROGRAM PROMPTS: PLAYER 1 (x) CHOOSE POSITION: 
  4. THEN IT PROMPTS PLAYER 2 TO CHOOSE POSITION ( O )
  5. THEN WHEN PLAYER 1 ENTERS HIS POSITION
        THAT POSITION THAT HE ENTERED CHANGES TO X
        ANOTHER STRUCTURE OF THE GAME IS IMMEDIATELY DISPLAYED...
        THEN THE PLAYER 2 IS PROMPTED IMMEDIATELY AS WELL
        THE SCREEN SHOULD ALWAYS CLEAR FOR BEAUTY SAKE

        HOW TO GO ABOUT THE GAME
    1. FIRST WORK ON THE NUMBERS APPEARING AS THEY SHOULD (GIVE ENOUGH SPACE TO FACILITATE LINE ADDITIONS)
    2. WORK ON THE LINES AS THE LAST THING WHEN THE NUMBERS ARE RESPONSIVE AND IN POSITION
    
    THERE SHOULD BE A FUNCTION THAT HANDLES THE DISPLAY
    THEN THERE SHOULD BE AN UPDATER
        EACH OF THE NUMBERS SHOULD HAVE MAPS WITH KEY AS THE NUMBERS AND VALUE AS (X - 0 OR - P) P MEANING PENDING
        THE WINNER CHECKER SHOULD WORK WITH THIS UPDATER HAN IN HAND TO SEE WHEN THE WINNER WINS
        STALEMATE SHOULD ALSO WORK HERE, WHEN A VICTORY IS NO LONGER FEASIBLE... THIS SHOULD BRING THE GAME TO END, OR
        THE PLAYERS CAN DECIDE TO PLAY TILL THEY FILL ALL THE SPACES AND THE PROGRAM SAYS: NO WINNER...
            REMATCH?
            QUIT...


MAIN MENU
    PLAY A GAME
        PLAYER 1: 
        PLAYER 2:
            AFTER PLAYING YOU CAN
                REMATCH?
                QUIT?s
    ABOUT GAME
    VIEW HIGHSCORES
    QUIT

*/

#include <iostream>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::getline;

int input_validator(int, int);
void home();
void quit();
void play_menu();

char quitter{ '1' };

int main()
{
    home();
}

int input_validator(int min, int max) {
    int num;
    std::string entry;
    bool done{ false };

    do {
        cout << "ENTRY: ";
        cin >> entry;

        std::istringstream validator{ entry };
        if (validator >> num && (num >= min && num <= max)) {
            done = true;
        }
        else {
            cout << "KINDLY ENTER A VALID OPTION (BETWEEN " << min << " - " << max << " )" << endl;
            cin.ignore(std::numeric_limits<std::streamsize> ::max(), '\n');
        }
    } while (!done);
    return num;
}

void home() {
    while (quitter != '0') {
        system("CLS");
        int option;

        cout << "1 - PLAY TIC TAC TOE\n2 VIEW PREVIOUS DUELS\n3 - ABOUT GAME\n4 - QUIT GAME\n";
        option = input_validator(1, 4);
        
        switch (option)
        {
            case '1':
            {

            }
            break;

            case '2':
            {

            }
            break;

            case '3':
            {

            }
            break;

            case '4':
            {
                quit();
            }
            break;

            default:
                break;
        }
    }
}

void quit() {
    system("CLS");
    quitter = '0';
    cout << "\t\t\t================================================================================================================" << endl;
    cout << "\t\t\t|                                                    GOODBYE                                                   |" << endl;
    cout << "\t\t\t================================================================================================================" << endl;

}

void play_menu() {
    system("CLS");
    std::string player1_name, player2_name;

    cout << "\t\t\tSETTLE THE DISPUTES HERE WITH A TIC TAC TOE DUEL\n";
    cout << "\t\t\tPLAYER 1 (X -- FIRST TO PLAY)\nNICK NAME: ";
    getline(cin, player1_name);
    cout << endl;

    cout << "\t\t\tPLAYER 2 (O -- SECOND TO PLAY)\nNICK NAME: ";
    getline(cin, player2_name);

}

