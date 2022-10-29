#include <iostream>
#include <string>
using namespace std;
char Board[3][3] = { '-' , '-' , '-' ,'-' , '-' , '-' ,'-' , '-' , '-' };
class Stack{
public :
    int O_ARR[10] = {0,0,0,0,0,0,0,0,0,0};
    int X_ARR[10] = {0,0,0,0,0,0,0,0,0,0};
    int top_O = -1 ;
    int top_X = -1 ;
    bool isEmpty(){
        if (top_O==-1||top_X==-1){
            return 1;
        }else{
            return 0;
        }
    }
    bool isFull(){
        if(top_O>=9||top_X>=9){
            return 1;
        }else{
            return 0;
        }
    }
     void  push_O(int row , int col){
         if (isFull()==0){
             O_ARR[++top_O]=row;
             O_ARR[++top_O]=col;
         }else{
             cout << "Error stack is full !!!!!!!!!";
         }
     }
    void push_X(int row , int col){
        if (isFull()==0){
            X_ARR[++top_X]=row;
            X_ARR[++top_X]=col;
        }else{
            cout << "Error stack is full !!!!!!!!!";
        }
    }
};

class Game : public Stack {
public:
    string player1 ;
    string player2 ;
    bool current_player;
    int choice;
    int R_input;
    int C_input;
    void print_Board(){
        for (int n=0;n<3;n++) { for (int x =0 ; x < 3 ; x++) { cout << '|' << Board[n][x] << '|'; } cout << endl ;}
    }
    void Get_Name(){
        cout << "Enter first player name : " ;
        cin >> player1 ;
        cout << "Enter second player name :  " ;
        cin >> player2 ;
        cout << "Hello " << player1 << " & " << player2 << " !" << endl;
        cout << " - Player one “" << player1 << "” will play with ‘O’ character \n - and player two “" << player2 << "” will play with ‘X’ character\n";
    }
    void start (){
        int number =0;
        cout << "Which player will start ? \n\t\t 1- "<<player1<<"\t\t2- "<<player2<<endl;
        cin >> number;
        if (number==1){
            current_player = 0;
            cout << player1 << " will start ! \n";
            menu();
        }else if (number==2){
            current_player = 1;
            cout << player2 << " will start ! \n";
            menu();
        }else{
            cout << "Invalid input !!!!!!!!! \n";
            start();
        }
    }
    void menu(){
        switch (current_player) {
            case 0:
                set_O();
                break;
            case 1:
                set_X();
                break;
            default:
                cout << "Invalid input";
                menu();
                break;
        }
    }
    void set_O(){
        current_player = 0  ;
        cout << player1 << " please enter \n \t\t1- cell position \t\t2- undo \t\t3- redo : ";
        cin >> choice ;
        switch (choice) {
            case 1:
                cell_input();
                break;
            case 2:
                undo();
                print_Board();
                set_O();
                break;
            case 3:
                redo();
                print_Board();
                set_X();
                break;
            default: {
                cout << "Invalid input !!!!!!!!! \n";
                set_O();
            }
        }
    }
    void set_X(){
        current_player =1 ;
        cout << player2 << " please enter \n \t\t1- cell position \t\t2- undo \t\t3- redo : ";
        cin >> choice ;
        switch (choice) {
            case 1:
                cell_input();
                break;
            case 2:
                undo();
                print_Board();
                set_X();
                break;
            case 3:
                redo();
                print_Board();
                set_O();
                break;
            default: {
                cout << "Invalid input !!!!!!!!! \n";
                set_X();
            }
        }
    }
    void cell_input(){
        switch (current_player) {
            case 0 :
                cout << player1 <<" please enter row and col to put ‘O’ : " <<endl;
                cin >> R_input >> C_input;
                R_input--; C_input--;
                check_input(R_input,C_input);
                Board[R_input][C_input] = 'O';
                push_O(R_input,C_input);
                print_Board();
                check();
                set_X();
            case 1:
                cout << player2 <<" please enter row and col to put ‘X’ : " <<endl;
                cin >> R_input >> C_input;
                R_input--; C_input--;
                check_input(R_input,C_input);
                Board[R_input][C_input] = 'X';
                push_X(R_input,C_input);
                print_Board();
                check();
                set_O();
        }
    }
    bool check_input(int one , int two){
        one ++ ; two ++ ;
        if (Board[R_input][C_input] == 'X' || Board[R_input][C_input] == 'O') {
            cout << "Invalid position , already taken " << endl;
            cell_input();
        }
        if((one > 3 || one < 1 )||  (two > 3 || two  < 1)){
            cout << "Invalid input !!!!!!!!! \n";
            cell_input();
        }
    }
    void undo(){
        switch (current_player) {
            case 0:
                Board[(O_ARR[(top_O-1)])][(O_ARR[top_O])]= '-';
                break;
            case 1:
                Board[(X_ARR[(top_X-1)])][(X_ARR[top_X])]= '-';
                break;
        }
    }
    void redo(){
        switch (current_player) {
            case 0:
                Board[(O_ARR[(top_O-1)])][(O_ARR[top_O])]= 'O';
                break;
            case 1:
                Board[(X_ARR[(top_X-1)])][(X_ARR[top_X])]= 'X';
                break;

        }
    }
    bool check()
        {
            if (((Board[0][0] == 'X' && Board[0][1] == 'X' && Board[0][2] == 'X')) ||((Board[1][0] == 'X' && Board[1][1] == 'X' && Board[1][2] == 'X')) ||((Board[2][0] == 'X' && Board[2][1] == 'X' && Board[2][2] == 'X')) ||((Board[0][0] == 'X' && Board[1][0] == 'X' && Board[2][0] == 'X')) ||((Board[0][1] == 'X' && Board[1][1] == 'X' && Board[2][1] == 'X')) ||((Board[0][2] == 'X' && Board[1][2] == 'X' && Board[2][2] == 'X')) ||((Board[0][0] == 'X' && Board[1][1] == 'X' && Board[2][2] == 'X')) ||((Board[0][2] == 'X' && Board[1][1] == 'X' && Board[2][0] == 'X')) ||((Board[0][2] == 'X' && Board[1][1] == 'X' && Board[2][0] == 'X')) )
            {   cout << player2 << " is the winner !! " << endl ;
                system("pause");
                return 1;
            }else if (((Board[0][0] == 'O' && Board[1][1] == 'O' && Board[2][2] == 'O')) ||((Board[0][0] == 'O' && Board[0][1] == 'O' && Board[0][2] == 'O')) ||((Board[1][0] == 'O' && Board[1][1] == 'O' && Board[1][2] == 'O')) ||((Board[2][0] == 'O' && Board[2][1] == 'O' && Board[2][2] == 'O')) ||((Board[0][0] == 'O' && Board[1][0] == 'O' && Board[2][0] == 'O')) ||((Board[0][1] == 'O' && Board[1][1] == 'O' && Board[2][1] == 'O')) ||((Board[0][2] == 'O' && Board[1][2] == 'O' && Board[2][2] == 'O'))) {
                cout << player1 << " is the winner !! " << endl ;
                system("pause");
                return 1;
            } else {
                int counter = 0 ;
                for (int n=0;n<3;n++){
                    for (int x =0 ; x < 3 ; x++){
                       if (Board[n][x] != '-'){
                           counter++;
                       }
                    }
                }
                if ( counter == 9 ){
                    cout << "DRAW!!!!";
                    system("pause");
                    return 1;
                }
            }
        }
};
int main (){
    Game try1;
    try1.Get_Name();
    try1.start();
}
