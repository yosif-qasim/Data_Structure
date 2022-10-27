#include <iostream>
#include <string>
#define size 3
using namespace std;
class Game{
public:
    string player1 ;
    string player2 ;
    bool current_player;
    int choice;
    int R_input;
    int C_input;
    char Board[size][size] = { '1' , '-' , '-' ,
                               '-' , '5' , '-' ,
                               '-' , '-' , '9' };
    void print_Board(){
        for (int n=0;n<3;n++) {
            for (int x =0 ; x < 3 ; x++) {
                cout << '|' << Board[n][x] << '|';
            }
                cout << endl ;
        }
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
            menu();
            return  ;
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
                break;
        }
    }
    bool check_input(int one , int two){
        if(one > 3 || two >3){
            cout << "Invalid input !!!!!!!!! \n";
            menu();
        }
    }
    void set_O(){
        cout << player1 << " please enter \n \t\t1- cell position \t\t2- undo \t\t3- redo : ";
        cin >> choice ;
        switch (choice) {
            case 1:
                cout << player1 <<" please enter row and col to put ‘O’ : " <<endl;
                cin >> R_input >> C_input;
                check_input(R_input,C_input);
                Board[--R_input][--C_input] = 'O';
                print_Board();
                set_X();
                break;
            case 2:
                undo();
                break;
            case 3:
                redo();
                break;
        }
    }
    void set_X(){
        cout << player2 << " please enter \n \t\t1- cell position \t\t2- undo \t\t3- redo : ";
        cin >> choice ;
        switch (choice) {
            case 1:
                cout << player2 <<" please enter row and col to put ‘x’ : " <<endl;
                cin >> R_input >> C_input;
                check_input(R_input,C_input);
                Board[--R_input][--C_input] = 'x';
                print_Board();
                set_O();
                break;
            case 2:
                undo();
                break;
            case 3:
                redo();
                break;
        }
    }
    void undo(){

    }
    void redo(){

    }
};
int main (){
    Game try1;
    try1.Get_Name();
    try1.start();
}
