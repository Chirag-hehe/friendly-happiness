#include<iostream>

using namespace std;

char board[3][3]; 
char current_marker;
int player;

void initializeBoard() {
    char start = '1'; 
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) { 
            board[i][j] = start++;
    }
}
}

void display_board(){
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "-----------\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "-----------\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n\n";
}

bool marker(int slot){
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (slot < 1 || slot > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move! That slot is already taken or out of bounds. Try again.\n";
        return false;
    }
    board[row][col] = current_marker;
    return true;
  //  return current_marker;

}

void swapPlayer(){
    current_marker = (current_marker == 'X') ? 'O' : 'X';
    player = (player == 1) ? 2 : 1;
}

int win(){
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
        return player;
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i])
        return player;
    }
        
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
    return player;
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
    return player;

    return 0;
}

int main(){

    cout << "Tic Tac Toe!\n\n";
    while(true){
        cout << "Choose your sign Player 1(X,O):";
        cin >> current_marker;
        if(current_marker == 'X' || current_marker == 'O'){
            break;
    }
    else{
        cout << "Wrong input!\n";
    }
}

    initializeBoard();

    player=1;
    cout << "Player "<< player << " : " << current_marker << endl;
    swapPlayer();
    cout << "Player "<< player << " : " << current_marker << "\n" << endl;


    int move=0,slot;
    while(true){
        for(move=0;move<9;move++){
    display_board();
    swapPlayer();
    cout << "Your move Player " << player <<"("<< current_marker << ")" << ":\n";
    cout << "Enter your slot(1-9) : ";
    cin >> slot;

    if(!marker(slot)){
        move--;
        swapPlayer();
        continue;
    }
    if(win()){
    display_board();
    cout << "Player " << player << "(" << current_marker << ")" << " Wins!!!";
    return 0;
    }
}
    display_board();
    cout << "Its a Draw! \n";
    break;
}
    return 0;
}