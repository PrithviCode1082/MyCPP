#include <iostream>

using namespace std;


int cross_pattern(char board[9], char symbol, int neg){
    for (int i : {4, 2}) {
        if (board[neg - i] == symbol && board[neg] == symbol && board[neg + i] == symbol) {
            return 1;
        }
    }
    return 0;
}

int horizontal_pattern(char board[9], char symbol){
    for (int i : {0, 3, 6}) {
        if (board[i] == symbol && board[i+1] == symbol && board[i+2] == symbol) {
            return 1;
        }
    }
    return 0;
}

int vertical_pattern(char board[9], char symbol){
    for (int i=0; i<3; i++) {
        if (board[0 + i] == symbol && board[3 + i] == symbol && board[6 + i] == symbol) {
            return 1;
        }
    }
    return 0;
}

int pattern_checker(char board[9], char symbol){
    return vertical_pattern(board, symbol) || horizontal_pattern(board, symbol) || cross_pattern(board, symbol, 4);
}

int checkSpots(char board[9], int flag=0){
    for (int i=0; i<9; i++) {
        if (board[i] == 'X' || board[i] == 'O') continue;
        return 1;
    }
    return flag;
}

void displayer(char *board){
    for (int i=0; i<9; i++) {
        if ((i+1) % 3 == 0) {
            cout << "  " << board[i] << "   ";
            if (i!=8) {
                cout << "\n";
                cout << "-----*-----*------\n";
            }
            continue;
        }
        cout << "  " << board[i] << "  |";
    }
    cout << "\n";
}

int player(char board[9], int &playerInput, string name){
    if (checkSpots(board, 0) == 0) {
        cout << "DRAW!!!\n";
        exit(0);
    }
    cout << name << " : Enter your move: ";
    cin >> playerInput;
    while (board[playerInput - 1] == 'X' || board[playerInput - 1] == 'O') {
        cout << "The spot is already occupied!!! Enter another spot: ";
        cin >> playerInput;
    }
    return playerInput;
}

int main(){
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int player1, player2, result;
    displayer(board);
    while (true) {
        cout << "*************** ROUND **************\n";
        result = player(board, player1, "player1");
        board[result - 1] = 'X';
        if (pattern_checker(board, 'X') == 1) {
            cout << "Player1 " << "WINS!!!\n";
            break;
        } else{
            displayer(board);
            cout << "\n";
        }

        result = player(board, player2, "player2");
        board[player2 - 1] = 'O';
        if (pattern_checker(board, 'O') == 1) {
            cout << "Player2 WINS!!!\n";
            break;
        } else{
            displayer(board);
            cout << "\n";
        }
        cout << "***** STATUS *****\n";
        displayer(board);
        cout << "\n";
        cout << "************************************\n";
    }
    return 0;
}

/*
char board[3][3] = {{'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'}};
int drawIndex = 0;
for (int i = 0; i<3; i++) {
    cout << "  ";
    for (int j=0; j<3; j++) {
        cout << board[i][j];
        if(j != 2) cout << "  |  ";
    }
    cout << endl;
    if (i==2) {
        continue;
    }
    for (int i=0; i<3; i++) {
        cout << "-----*";
    }
    cout << endl;
}
 */
