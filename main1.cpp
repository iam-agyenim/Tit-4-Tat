/*

Name :  RICHMOND AGYENIM-BOATENG
DATE : #RD DECEMBER, 2002
CPE ASSIGNMENT



*/
#include <iostream>
#include <cstdlib>


using namespace std;
//CLASS FOR THE STRATEGY
class STRATEGY {
private:
    int stratecode;

public:
    STRATEGY() {
        stratecode = 4;// RETURNS RANDOM
    }

    int getstratecode() {
        return stratecode;
    }
    void setstratecode(int strategycode) {//SET STRATEGY
        stratecode = strategycode;
    }

    int evilStrategy() {
        return 1;
    }

    int cooperateStrategy() {
        return 0;
    }

    int titfortatStrategy(int code) {
        return code;
    }

    int randomStrategy() {
        return rand() % 2;
    }

    int cooperateOrDefect(int code) { // VARIOUS STRATEGIES
        switch (stratecode) {
        case 1:
            return evilStrategy();
            break;
        case 2:
            return cooperateStrategy();
            break;
        case 3:
            return titfortatStrategy(code);
            break;
        case 4:
            return randomStrategy();
            break;

        }
        return stratecode;
    }
};
//CLASS FOR PLAYER
class PLAYER {
private:
    int Unique_ID;
    int score;
    int* moves;
    int numMoves;
    int totalMoves;
    int lastmove;
    static int numberofplayers;
    STRATEGY style;

public:
    PLAYER() {//CONSTRUCTOR
        Unique_ID = numberofplayers;
        score = 0;
        numMoves = 0;
        totalMoves = 0;
        lastmove = -1;
        numberofplayers++;
        moves = nullptr;
    }

    ~PLAYER() { //DESTRUCTOR
        delete[] moves;
    }

    void setTotalMoves(int totalmoves) {
        totalMoves = totalmoves;
        moves = new int[totalmoves];
    }

    int getUnique_ID() {
        return Unique_ID;
    }

    int* getmoves() {
        return moves;
    }

    int getScore() {
        return score;
    }

    int getstyle() {
        return style.getstratecode();
    }

    void setscore(int marks) {
        score = score + marks;
    }
    int getLastMove(int i) {
        int lastmove(-1);

        if (moves != nullptr) {
            lastmove = moves[i];
        }
        return lastmove;
    }


    void setstyle(int newStyle) {
        style.setstratecode(newStyle);
    }

    int  MOVES(int lastmove) {
        int myMove = style.cooperateOrDefect(lastmove);

        moves[numMoves] = myMove;
        numMoves++;

        return myMove;
    }
    //PRINT THE MOVES
    void printMoves() {
        cout << "Player ID: " << Unique_ID << endl;
        cout << "Number of moves: ";
        for (int i = 0; i < numMoves; i++) {
            cout << moves[i] << " ";
        }
        cout << endl;
    }
};

int PLAYER::numberofplayers = 0;//INITIALIZATION OF STATIC VARIABLE

// CLASS FOR THE GAME
class Game {
private:
    PLAYER* player;
    int numPlayers;
    int totalMoves;

public:
    Game() {//CONSTRUCTOR
        numPlayers = 0;
        totalMoves = 0;
        player = nullptr;
    }

    ~Game() {//DESTRUCTOR
        delete[] player;
    }

    PLAYER* playerdata() {
        return player;
    }
    //TO ADD PLAYER
    void addPlayer(int numPlayers) {
        if (this->numPlayers > 0) {

            delete[] player;
        }

        this->numPlayers = numPlayers;

        if (numPlayers <= 2) {
            player = new PLAYER[numPlayers];
        }
        else {
            cout << "Cannot add more than two players." << endl;
            cout << "Player number can only be two! Input again ! \n";
            cin >> numPlayers;


            addPlayer(numPlayers);
        }
    }
    //TO DROP PLAYER
    void dropplayer(int playerId) {
        bool isFound = false;

        for (int i = 0; i < numPlayers; i++)
        {
            if (playerId == player[i].getUnique_ID())
            {
                cout << "The player to be removed is found" << endl;
                for (int j = i; j < numPlayers; j++)
                {
                    player[j] = player[j + 1];
                }
                numPlayers--;
                isFound = true;
            }
        }

    }

    //PLAY GAME
    void playGame(int N) {
        totalMoves = N;
        for (int i = 0; i < numPlayers; i++) {
            player[i].setTotalMoves(N);
        }
        int myMove, oppmove;

        for (int i = 0; i < N; i++) {

            int lastMove1 = 0, lastMove2 = 0;

            int Default = 0;

            if (i == 0)
            {
                myMove = player[0].MOVES(Default);
                oppmove = player[1].MOVES(Default);
                cout << myMove;
                cout << oppmove;
                cout << endl;
            }

            else
            {
                lastMove1 = player[0].getLastMove(i - 1);
                lastMove2 = player[1].getLastMove(i - 1);


                myMove = player[0].MOVES(lastMove2);
                oppmove = player[1].MOVES(lastMove1);

                cout << myMove;
                cout << oppmove;
                cout << endl;
            }




            if (myMove == 0 && oppmove == 0) {
                // Both cooperate
                player[0].setscore(3);
                player[1].setscore(3);
            }
            else if (myMove == 1 && oppmove == 0) {
                // I defect, opponent cooperate
                player[0].setscore(5);
                player[1].setscore(0);
            }
            else if (myMove == 0 && oppmove == 1) {
                // I cooperate, opponent defect
                player[0].setscore(0);
                player[1].setscore(5);
            }
            else if (myMove == 1 && oppmove == 1) {
                // Both defect
                player[0].setscore(1);
                player[1].setscore(1);
            }
        }
    }

    // RESULTS
    void printResults() {
        cout << "................................................................................................................ \n"
            << "................................................GAME RESULTS!!!!!!!!!............................................ \n"
            << "................................................................................................................. \n"
            << endl;
        cout << "The following the various results for PLAYER 1 and PLAYER 2 \n";
        cout << "GAME RESULTS\n"
            << "Total Moves: " << totalMoves << "\n"
            << "PLAYER 1 score: " << player[0].getScore() << "\n"
            << "PLAYER 2 score: " << player[1].getScore() << "\n";

        player[0].printMoves();
        player[1].printMoves();
    }
};



int main() {// VARIABLES DECLARATION AN INITIALIZATION
    
    int Menu_option;
    int numPlayers;
    int Player1_code;
    int Player2_code;
    int MOVES(0);
    int drop_players;
    bool indicator1(false), indicator2(false), indicator3(false), indicator4(false);
    Game game;

    do {// A REPEAT STATEMENT
        srand(time_t(NULL));


        cout << "..................................................ITERATED PRISONER DILEMMA GAME ....................................... " << endl
            << "....................................................................................................................... " << endl
            << "....................................................................................................................... " << endl
            << endl
            << "WELCOME TO THE ITERATED PRISONER DILEMMA GAME \n"
            << "....................................................................................................................... " << endl
            << endl
            << "Select from the following Menu to proceed to the game " << endl;
        //MENU
        cout << "1. NUMBER OF PLAYERS \n"
            << endl
            << "2. GAME STRATEGY FOR PLAYER 1 AND PLAYER 2 \n"
            << endl
            << "3. MOVES TO PLAY GAME \n"
            << endl
            << "4. GAME RESULT  \n"
            << endl
            << "5. DROP PLAYER \n"
            << endl
            << "6. EXIT GAME \n"
            << endl;

        cin >> Menu_option;

        //SELECTION STATEMENT
        switch (Menu_option) {
        case 1: //PLAYER NUMBERS
            cout << "Enter the number of players you want \n";
            cin >> numPlayers;

            game.addPlayer(numPlayers);
            indicator1 = true;
            break;
        case 2:/// STRATEGY
            if (indicator1 == false) {
                cout << "You must choose the number of player before you can proceed to this option \n";
            }
            else {
                do {
                    cout << "Which Strategy do you want to use for PLAYER 1 and PLAYER 2 \n"
                        << "1. Evil Strategy \n"
                        << "2. Cooperate Strategy \n"
                        << "3. TitForTat Strategy \n"
                        << "4. Random Strategy \n";
                    cin >> Player1_code;
                    cin >> Player2_code;
                    if (Player1_code < 1 || Player1_code > 4 || Player2_code < 1 || Player2_code > 4)
                    {
                        cout << "You entered an invalid strategy \n"
                            << "Enter a valid strategy  between 1 to 4 for PLAYER 1 and PLAYER 2 \n";
                        cin >> Player1_code;
                        cin >> Player2_code;
                    }
                } while (Player1_code < 1 && Player2_code < 1 && Player1_code > 4 && Player2_code > 4);
                game.playerdata()[0].setstyle(Player1_code);
                game.playerdata()[1].setstyle(Player2_code);
            }
            indicator2 = true;
            break;
        case 3:// ROUND NUMBER
            if (indicator1 == false || indicator2 == false) {
                cout << "You must choose option 1 , proceed by option 2 of the menu before you can proceed to this option \n";
            }
            else {
                cout << "Enter the number of moves you want to move in the Game \n";
                cin >> MOVES;
                if (MOVES < 1) {
                    cout << "Enter a valid number of moves \n";
                    cin >> MOVES;
                }

                
            }
            indicator3 = true;
            break;
        case 4: //RESULT DISPLAY
            if(indicator1 == false || indicator2 == false || indicator3 == false) {
                cout << "You must choose option 1, proceed by option 2 and 3 , before you can choose this option to print Game results \n";
            }
            else {
                game.playGame(MOVES);
                game.printResults();
            }
            indicator4 = true;
            break;

        case 5: // DROP PLAYER
            if (indicator1 == false || indicator2 == false || indicator3 == false || indicator4 == false ) {
                cout << "You must choose option 1, proceed by option 2 , 3 , before you can choose this option to drop player \n";
            }
            else {//Note: Whenever you drop a player , the user players with teh computer
                // when you both players drop, computer plays for both , and print results.
                cout << "THIS OPTION DROPS PLAYER \n" << endl;
                cout << "..............................................................................................................\n";
                cout << "                                      *NOTE THE FOLLOWING FOR DROP PLAYER*                                      \n";
                cout << "When you drop 1 player, you automatically play against computer \n";
                cout << "When you drop 2 players, computer automatically completes the game with two automatic users \n";
                cout << "How many players do you want to drop \n";
                cin >> drop_players;
                if (drop_players < 1 || drop_players > 2) {
                    cout << "You entered an invalid number of players you can drop \n"
                        << "Enter a valid number for dop players \n";
                    cin >> drop_players;
                }

                game.dropplayer(drop_players);
                cout << "You dropped " << drop_players << " player!!!!!!!!!!!!" << endl;
                cout << "........................................................................................................... \n";
                cout << endl;
                cout << "RESULTS AFTER DROPPING" << drop_players << "FOLLOWS!!!!!!!!";
                cout << endl;
                cout << "........................................................................................................... \n";
                game.printResults();

                
            }
            break;
        case 6: // EXIT
            cout << "............................................THANK YOU FOR PARTICIPATING!!!.............................................. \n"
                << ".......................................................................................................................... \n"
                << "..............................................!!!!!THE GAME EXIT !!!!!................................................ \n";
            exit(3);
        default:
            cout << "..................................................................................................................... \n"
                << endl
                << "                                           YOU ENTERED AN INVALID MENU NUMBER                                          \n"
                << "                                      ENTER THE RIGHT CHOICE TO PROCEED TO THE GAME                                    \n"
                << endl
                << "...................................................................................................................... \n";
            break;
        }


    } while (Menu_option != 6);

    return 0;
}


/******************************************************************************************************************************************************************/





