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
#include <algorithm>
#include <cctype>
#include <map>
#include <vector>
#include <iomanip>
#include <fstream>



using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::getline;
using std::string;
using std::map;
using std::vector;

//FUNCTION PROTOTYPES
int input_validator(int, int);
void home();
void quit();
void play_menu();
string game_session(string, string);
string capitalise(string);
//int count_slots(std:: map<int, char> &);
void display_grid(std::map<int, char> &);
bool change_face(std::map<int, char>&, int, char);
bool check_won(std::map<int, char>&, char);
bool record(string, string, string);
void check_record();
void about();

/*
           
            2 - Implement the score sheet for record purposes...
            3 - Implement the about game...
*/

//UNIVERSAL VARIABLE THAT IS USED OR QUITTING THE PROGRAM.
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
    if (quitter == '1') {
       /* system("CLS");*/
        int option;

        cout << "\t\t\t================================================================================================================" << endl;
        cout << "\t\t\t|                                            TIC - TAC - TOE                                                   |" << endl;
        cout << "\t\t\t================================================================================================================" << endl;

        cout << "1 - PLAY TIC TAC TOE\n2 - VIEW PREVIOUS DUELS\n3 - ABOUT GAME\n4 - QUIT GAME\n";
        option = input_validator(1, 4);
        
        switch (option)
        {
            case 1:
            {
                play_menu();
                home();
            }
            break;

            case 2:
            {
                check_record();
                home();
            }
            break;

            case 3:
            {
                about();
                home();
            }
            break;

            case 4:
            {
                quit();
                home();
            }
            break;

            default:
                break;
        }
    }
   /* else {
        quit();
    }*/
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
    std::string player1_name, player2_name, winner;

    cin.ignore(1, '\n');
    cout << "\t\t\tSETTLE THE DISPUTES HERE WITH A TIC TAC TOE DUEL\n";
    cout << "\t\t\tPLAYER 1 (X -- FIRST TO PLAY)\nNICK NAME: ";
    getline(cin, player1_name);
    player1_name = capitalise(player1_name);
    cout << endl;

    cout << "\t\t\tPLAYER 2 (O -- SECOND TO PLAY)\nNICK NAME: ";
    getline(cin, player2_name);
    player2_name = capitalise(player2_name);

    //Transfers to the game session
   winner = game_session(player1_name, player2_name);

   if (winner == player1_name) {
      bool recorded =  record(player1_name, player2_name, winner);
       cout << "WINNER: " << player1_name << " LOOSER: " << player2_name << endl;

       cout << "WOULD YOU LIKE TO PLAY AGAIN?\n1 - YES\n2 - NO\n";
       int opt = input_validator(1, 2);
       if (opt == 1) {
           system("CLS");
           winner = game_session(player1_name, player2_name);
       }
       else {
           home();
       }
   }

   else if (winner == player2_name) {
       bool recorded = record(player1_name, player2_name, winner);
       cout << "WINNER: " << player2_name << " LOOSER: " << player1_name << endl;

       cout << "WOULD YOU LIKE TO PLAY AGAIN?\n1 - YES\n2 - NO\n";
       int opt = input_validator(1, 2);
       if (opt == 1) {
           system("CLS");
           winner = game_session(player1_name, player2_name);
       }
       else {
           home();
       }
   }
   else {
       bool recorded = record(player1_name, player2_name, winner);
       cout << "WOULD YOU LIKE TO PLAY AGAIN?\n1 - YES\n2 - NO\n";
       int opt = input_validator(1, 2);
       if (opt == 1) {
           system("CLS");
           winner = game_session(player1_name, player2_name);
       }
       else {
           home();
       }
   }

   

}

string game_session(string player_1, string player_2) {
    system("CLS");
    cout << "\t\t\t" << player_1 << "\t\tvs\t\t" << player_2 << "\n";
    std::string winner{};
    bool won{ false };
    int num_slots{9},number;
    char input{ 'x' };
    map <int, char> slots{ {1,'P'},{2,'P'},{3,'P'},{4,'P'},{5,'P'},{6,'P'},{7,'P'},{8,'P'},{9,'P'}};
  


    //while num of slots > 0 && won == false
    while (won == false ) {

        display_grid(slots); //display the numbers at first
       
        retry: cout << player_1 << " (X)";
        number = input_validator(1, 9);
        bool changed = change_face(slots, number, 'X');//confirms if your input was successful

        if (changed == true) {
            num_slots--;
            won = check_won(slots,'X');
            if (won == true) {
                /*cout << "WINNER: " << player_1 << " LOOSER: " << player_2 << endl;*/
                display_grid(slots);
                winner = player_1;
                continue;
            }
           
        }
        else {
             //IT MEANS THAT THE NUMBER IS NO LONGER AVAILABLE AND IS NOW A LETTER
            cout << "INVALID OPTION - CHOOSE A NUMBER\n";
            goto retry;
        }




        if (num_slots == 0) {
            cout << endl;
            cout << "GAME OVER - RESULT: DRAW\n";
            display_grid(slots);
            winner = "DRAW";
            won = true;
            break;
        }

        //Go again for o
        display_grid(slots);

        retry2: cout << player_2 << " (O)";
        number = input_validator(1, 9);
        changed = change_face(slots, number, 'O');//confirms if you have changed the number before

        if (changed == true) {
            num_slots--;
            won = check_won(slots,'O');

            if (won == true) {
                /*cout << "WINNER: " << player_2 << " LOOSER: " << player_1 << endl;*/
                display_grid(slots);
                winner = player_2;
                continue;
            }
           
        }


        else {
            //IT MEANS THAT THE NUMBER IS NO LONGER AVAILABLE AND IS NOW A LETTER
            cout << "INVALID OPTION - CHOOSE A NUMBER\n";
            goto retry2;
        }

       
        if (num_slots == 0) {
            cout << endl;
            cout << "GAME OVER - RESULT: DRAW\n";
            display_grid(slots);
            winner = "draw";
            won = true;
            break;
        }
    }

    return winner;
}

string capitalise(string word) {
    std::transform(word.begin(), word.end(), word.begin(), toupper);
    return word;
}

//int count_slots(std::map<int, char> &slots) {
//    //to count howmany slots are still p which is the code word for pending
//    //if the number is 0, it means that a stale_mate has been arrived at
//    // map <int, char> slots{ {1,'P'},{2,'P'},{3,'P'},{4,'P'},{5,'P'},{6,'P'},{7,'P'},{8,'P'},{9,'P'}};
//
//    int number{0};
//    auto it = slots.begin();
//
//    while (it != slots.end()) {
//        if (it->second == 'P')
//            number++;
//        it++;
//    }
//
//    return number;
//}

void display_grid(std::map<int, char> &slots) {
    cout << endl;
    auto it = slots.begin();
    int count{ 1 }, line_count{ 0 };

    while (it != slots.end()) {
        if (count % 3 == 0) {
            if (it->second == 'P') {
                std::cout << std::setw(3) << std::left << it->first << "  ";
            }
            else {
                std::cout << std::setw(3) << std::left << it->second << "  ";
            }
            it++;

            if (line_count == 2) {

            }
            else {
                if (count % 3 == 0) {
                    cout << endl << "------------" << endl;
                    line_count++;
                }
            }


            count++;
        }
        else {
            if (it->second == 'P') {
                std::cout << std::setw(3) << std::left << it->first << "| ";
            }
            else {
                std::cout << std::setw(3) << std::left << it->second << "| ";
            }
            it++;

            if (line_count == 2) {

            }
            else {
                if (count % 3 == 0) {
                    cout << endl << "------------" << endl;
                    line_count++;
                }
            }


            count++;
        }
        
    }
    cout << endl<<endl;
}

bool change_face(std::map<int, char>& slots, int num, char letter) {
    //change the value of the given integer to x or to o
    bool done { false };
    auto it = slots.begin();
    while (it != slots.end()) {
        if (it->first == num) { //if it has not been changed
            if (it->second == 'P') {
                it->second = letter;
                done = true;
            }
            else{}
        }
        it++;
    }
    return done;
}

bool check_won(std::map<int, char>& slots, char letter) {


    //Define a vactor of maps with 9 maps
       //Display
       /*
               1   2   3

               4   5   6

               7   8   9

               to win (the values of the maps of the following must be the same... either (' X ' or ' O ')
        (1 == 4 == 7) || (2 == 5 == 8) || (3 == 6 == 9) || (1 == 2 == 3) || ( 4 == 5 == 6 ) || (7 == 8 == 9 ) || (1 == 5 == 9) || (3 == 5 == 7)

       */
    bool won{ false };

    auto it1 = slots.find(1);
    auto it2 = slots.find(4);
    auto it3 = slots.find(7);

    if (it1->second == it2->second && it1->second  == it3->second && it1-> second == letter) {
        won = true;
    }

    it1 = slots.find(2);
    it2 = slots.find(5);
    it3 = slots.find(8);

    if (it1->second == it2->second && it1->second == it3->second && it1->second == letter) {
        won = true;
    }

    it1 = slots.find(3);
    it2 = slots.find(6);
    it3 = slots.find(9);

    if (it1->second == it2->second && it1->second == it3->second && it1->second == letter) {
        won = true;
    }

    it1 = slots.find(1);
    it2 = slots.find(2);
    it3 = slots.find(3);

    if (it1->second == it2->second && it1->second == it3->second && it1->second == letter) {
        won = true;
    }

    it1 = slots.find(4);
    it2 = slots.find(5);
    it3 = slots.find(6);

    if (it1->second == it2->second && it1->second == it3->second && it1->second == letter) {
        won = true;
    }

    it1 = slots.find(7);
    it2 = slots.find(8);
    it3 = slots.find(9);

    if (it1->second == it2->second && it1->second == it3->second && it1->second == letter) {
        won = true;
    }

    it1 = slots.find(1);
    it2 = slots.find(5);
    it3 = slots.find(9);

    if (it1->second == it2->second && it1->second == it3->second && it1->second == letter) {
        won = true;
    }

    it1 = slots.find(3);
    it2 = slots.find(5);
    it3 = slots.find(7);

    if (it1->second == it2->second && it1->second == it3->second && it1->second == letter) {
        won = true;
    }
    return won;
}

bool record(string player1, string player2, string winner) {
    bool status{ false };

    std::ofstream out_file("record.txt", std::ios::app);
    if (!out_file) {
        cerr << "ERROR OPENING FILE" << endl;
    }
    else {
        out_file << player1 << "#" << player2 << "#" << winner << endl;
        status = true;
    }
    out_file.close();
    return status;
}

void check_record() {
    system("CLS");
    std::ofstream out_file("record.txt", std::ios::app);
    out_file.close();
    vector<string> games;

    std::ifstream in_file("record.txt");
    if (!in_file) {
        cerr << "ERROR OPENING FILE\n";
    }
    else {
        string line;
        int line_count{ 0 };
        while (getline(in_file, line)) {
            games.push_back(line);
            line_count++;
        }
        //When there are no lines at the moment
        if (line_count == 0) {
            cout << endl << "RECORDS ARE EMPTY  -- SET THE RECORDS NOW WITH THOSE WHO DARE TO CHALLENGE YOU\n";

            cout << "\n\n\t\tWOULD YOU LIKE TO PLAY?\n1 - YES\n2 - NO\n";
            int opt = input_validator(1, 2);
            if (opt == 1) {
                play_menu();
            }
        }
        else {
            cout << std::setw(20) << std::left << "PLAYER 1" << std::setw(20) << std::left << "PLAYER 2" << std::setw(24) << "WINNER" << endl<<endl;
            for (size_t i{ 0 }; i < games.size(); i++) {
                string current = games.at(i);
                std::stringstream s_stream{ current };
                vector<string> line;
                string substr;

                while (s_stream.good()) {
                    getline(s_stream, substr, '#');
                    line.push_back(substr);
                }
                cout << std::setw(20) << std::left << line.at(0) << std::setw(20) << std::left << line.at(1) << std::setw(24) << line.at(2) << endl;
                
            }
        }
    }
    in_file.close();
}

void about() {

}
