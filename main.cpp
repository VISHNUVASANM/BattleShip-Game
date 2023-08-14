#include <iostream>
#include <cstring>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <string>

#define SIZE 10

struct Node {
    std::string currentState;
    std::string ship_type;
    char charInput;
    int intInput;
    Node* next;
};

class BattleshipGame {
private:
    char** board;
    Node* head;
    Node* tail;
    int shipsRemaining;

public:
    BattleshipGame() : head(nullptr), tail(nullptr), shipsRemaining(17) {
        srand(time(nullptr));
        board = new char*[SIZE];
        for (int i = 0; i < SIZE; i++) {
            board[i] = new char[SIZE];
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = '-';
            }
        }
        initialization();
    }

    ~BattleshipGame() {
        for (int i = 0; i < SIZE; i++) {
            delete[] board[i];
        }
        delete[] board;
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    char** initialization(){
    int i, j, k, row, col;
    char **board = (char**)malloc(sizeof(char*)*SIZE);
    for (i = 0; i < SIZE; i++){
        board[i] = (char*)malloc(sizeof(char)*SIZE);
    }
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            board[i][j] = '-';
        }
    }

    bool placed1 = false;
    while(placed1 == false){
        row = rand()%10;
        col = rand()%10; 
        if(row+1 < 10 && row-1 >= 0){ 
            if((board[row][col] = '-') && 
                (board[row+1][col] = '-')){
                    board[row][col] = 'D';
                    board[row+1][col] = 'D';
                    placed1 = true; 
            }
            else if((board[row][col] == '-') && 
                (board[row-1][col] == '-')){
                    board[row][col] = 'D'; 
                    board[row-1][col] = 'D';
                    placed1 = true;
            }
        }
    }

    //place the second ship
    bool placed2 = false;
    while (placed2 == false){
        row = rand()%10;
        col = rand()%10;
        if((row+1 < 10 && row+2 < 10) && 
            (row-1 >= 0 && row-2 >= 0) && 
            (col+1 < 10 && col+2 < 10) && 
            (col-1 >= 0 && col-2 >= 0)){
            if((board[row][col] == '-') && 
                (board[row][col+1] == '-') && 
                (board[row][col+2] == '-')){
                    board[row][col] = 'C';
                    board[row][col+1] = 'C';
                    board[row][col+2] = 'C';
                    placed2 = true;
            }
            else if((board[row][col] == '-') && 
                (board[row][col-1] == '-') && 
                (board[row][col-2] == '-')){
                    board[row][col] = 'C';
                    board[row][col-1] = 'C';
                    board[row][col-2] = 'C';
                    placed2 = true;
            }
            else if((board[row][col] == '-') && 
                (board[row+1][col] == '-') && 
                (board[row+2][col] == '-')){
                    board[row][col] = 'C';
                    board[row+1][col] = 'C';
                    board[row+2][col] = 'C';
                    placed2 = true;
            }
            else if((board[row][col] == '-') &&
                (board[row-1][col] == '-') &&
                (board[row-2][col] == '-')){
                    board[row][col] = 'C';
                    board[row-1][col] = 'C';
                    board[row-2][col] = 'C';
                    placed2 = true;
            }
        }
    }

    //place the third ship
    bool placed3 = false;
    while (placed3 == false){
        row = rand()%10;
        col = rand()%10;
        if((row+1 < 10 && row+2 < 10) &&
            (row-1 >= 0 && row-2 >= 0) && 
            (col+1 < 10 && col+2 < 10) && 
            (col-1 >= 0 && col-2 >= 0)){
            if((board[row][col] == '-') && 
                (board[row][col+1] == '-') && 
                (board[row][col+2] == '-')){
                    board[row][col] = 'S';
                    board[row][col+1] = 'S';
                    board[row][col+2] = 'S';
                    placed3 = true;
            }
            else if((board[row][col] == '-') && 
                (board[row][col-1] == '-') && 
                (board[row][col-2] == '-')){
                    board[row][col] = 'S';
                    board[row][col-1] = 'S';
                    board[row][col-2] = 'S';
                    placed3 = true;
            }
            else if((board[row][col] =='-') && 
                (board[row+1][col] == '-') && 
                (board[row+2][col] == '-')){
                    board[row][col] = 'S';
                    board[row+1][col] = 'S';
                    board[row+2][col] = 'S';
                    placed3 = true;
            }
            else if((board[row][col] == '-') && 
                (board[row-1][col] == '-') && 
                (board[row-2][col] == '-')){
                    board[row][col] = 'S';
                    board[row-1][col] = 'S';
                    board[row-2][col] = 'S';
                    placed3 = true;
            }
        }
    }

    bool placed4 = false;
    while (placed4 == false){
        row = rand()%10;
        col = rand()%10;
        if((row+1 < 10 && row+2 < 10 && row+3 < 10) &&
            (row-1 >= 0 && row-2 >= 0 && row-3 >= 0) && 
            (col+1 < 10 && col+2 < 10 && col+3 < 10) && 
            (col-1 >= 0 && col-2 >= 0 && col-3 >= 0)){
            if((board[row][col] == '-') && 
                 (board[row+1][col] == '-') &&
                 (board[row+2][col] == '-') &&
                 (board[row+3][col] == '-')){
                    board[row][col] = 'B';
                    board[row+1][col] = 'B';
                    board[row+2][col] = 'B';
                    board[row+3][col] = 'B';
                    placed4 = true;
            }
            else if((board[row][col] == '-') &&
                 (board[row-1][col] == '-') &&
                 (board[row-2][col] == '-') &&
                 (board[row-3][col] == '-')){
                    board[row][col] = 'B';
                    board[row-1][col] = 'B';
                    board[row-2][col] = 'B';
                    board[row-3][col] = 'B';
                    placed4 = true;
            }
            else if((board[row][col] == '-') &&
                 (board[row][col+1] == '-') &&
                 (board[row][col+2] == '-') &&
                 (board[row][col+3] == '-')){
                    board[row][col] = 'B';
                    board[row][col+1] = 'B';
                    board[row][col+2] = 'B';
                    board[row][col+3] = 'B';
                    placed4 = true;
            }
            else if((board[row][col] == '-') &&
                 (board[row][col-1] == '-') &&
                 (board[row][col-2] == '-') &&
                 (board[row][col-3] == '-')){
                    board[row][col] = 'B';
                    board[row][col-1] = 'B';
                    board[row][col-2] = 'B';
                    board[row][col-3] = 'B';
                    placed4 = true;
            }
        }
    }

    bool placed5 = false;
    while (placed5 == false){
        row = rand()%10;
        col = rand()%10;
        if((row+1 < 10 && row+2 < 10 && row+3 < 10 && row+4 < 10) &&
            (row-1 >= 0 && row-2 >= 0 && row-3 >= 0 && row-4 >= 0) && 
            (col+1 < 10 && col+2 < 10 && col+3 < 10 && col+4 < 10) &&
            (col-1 >= 0 && col-2 >= 0 && col-3 >= 0 && col-4 >= 0)){
            if((board[row][col] == '-') &&
               (board[row+1][col] == '-') &&
               (board[row+2][col] == '-') &&
               (board[row+3][col] == '-') &&
               (board[row+4][col] == '-')){
                    board[row][col] = 'R';
                    board[row+1][col] = 'R';
                    board[row+2][col] = 'R';
                    board[row+3][col] = 'R';
                    board[row+4][col] = 'R';
                    placed5 = true;
            }
            else if((board[row][col] == '-') &&
                 (board[row-1][col] == '-') &&
                 (board[row-2][col] == '-') &&
                 (board[row-3][col] == '-') &&
                 (board[row-4][col] == '-')){
                    board[row][col] = 'R';
                    board[row-1][col] = 'R';
                    board[row-2][col] = 'R';
                    board[row-3][col] = 'R';
                    board[row-4][col] = 'R';
                    placed5 = true;
            }
            else if((board[row][col] == '-') && 
                (board[row][col+1] == '-') && 
                (board[row][col+2] == '-') && 
                (board[row][col+3] == '-') && 
                (board[row][col+4] == '-')){
                    board[row][col] = 'R';
                    board[row][col+1] = 'R';
                    board[row][col+2] = 'R';
                    board[row][col+3] = 'R';
                    board[row][col+4] = 'R';
                    placed5 = true;
            }
            else if((board[row][col] == '-') && 
                (board[row][col-1] == '-') && 
                (board[row][col-2] == '-') && 
                (board[row][col-3] == '-') && 
                (board[row][col-4] == '-')){
                    board[row][col] = 'R';
                    board[row][col-1] = 'R';
                    board[row][col-2] = 'R';
                    board[row][col-3] = 'R';
                    board[row][col-4] = 'R';
                    placed5 = true;
            }
        }
    }
    return board;
}

    void updateState(const char* state, char character, int col) {
        int row;
        char shipType[20];
        row = character % 65;
        if (board[row][col] == '-') {
            strcpy(const_cast<char*>(state), "MISS");
        } else {
            strcpy(const_cast<char*>(state), "HIT!");
            char shipChar = board[row][col];
            if (shipChar == 'R') {
                strcpy(shipType, "Carrier");
            }
            else if(shipChar == 'B'){
                strcpy(shipType,"Battleship");
                printf(" %s", shipType);
            }
            else if(shipChar == 'S'){
                strcpy(shipType,"Submarine");
                printf(" %s", shipType);
            }
            else if(shipChar == 'C'){
                strcpy(shipType,"Cruiser");
                printf(" %s", shipType);
            }
            else if(shipChar == 'D'){
                strcpy(shipType,"Destroyer");
                printf(" %s", shipType);
            }
            else if(shipChar == 'O'){
                printf("Already Hitted!");
            }
            printf(" %c", shipChar);
            board[row][col] = 'O';
        }

        insertNode(&head, &tail, col, row, state, shipType);
    }

   void acceptInput(char& character, int& integer) {
        std::cout << "Enter a letter A-J and number 0-9 ex. B4 - enter Z0 to end" << std::endl;
        int size = scanf(" %c%d", &character, &integer);
        if (size != 2) {
            std::cout << "INVALID INPUT" << std::endl;
            return;
        }
        character = toupper(character);
        if (character == 'Z' && integer == 0) {
            return;
        }
        if (character < 'A' || character > 'J' || integer < 0 || integer > 9) {
            std::cout << "INVALID INPUT" << std::endl;
            acceptInput(character, integer); // Retry input
        }
    }

void insertNode(Node** h, Node** t, int x, int y, const char* state, const char* shipType) {
        Node* temp = new Node;
        temp->charInput = y + 'A';
        temp->intInput = x;
        temp->currentState = state;
        temp->ship_type = shipType;
        temp->next = nullptr;

        if (*h == nullptr) {
            *h = *t = temp;
        } else {
            (*t)->next = temp;
            *t = (*t)->next;
        }
    }

void displayState(const char* state) {
    int i, j;
    std::cout << "\n**** " << state << " ****\n";
    std::cout << "  0 1 2 3 4 5 6 7 8 9\n";

    if (strcmp(state, "GAME OVER!") == 0) {
        return; // Don't display the board if the game is over
    }

    for (i = 0; i < SIZE; i++) {
        std::cout << static_cast<char>(65 + i) << " "; // Convert to character A-J
        for (j = 0; j < SIZE; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}
void playGame() {
        char state[] = "GAME START";
        char flag[] = "GAME OVER!";
        char character;
        int integer;

        do {
            displayState(state);
            acceptInput(character, integer);

            if (character == 'Z' && integer == 0)
                break;

            updateState(state, character, integer);
        } while ((character != 'Z' || integer != 0) && strcmp(state, flag));

        if (shipsRemaining == 0) {
            std::cout << "You Win!" << std::endl;
        }

        displayState(flag);
    }
};

int main() {
    BattleshipGame game;
    game.playGame();
    return 0;
}
