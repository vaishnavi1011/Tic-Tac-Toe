#include<iostream>
#include<math.h>
#include <bits/stdc++.h>
#include<string>
#include<cmath>
#include<time.h>
#include<string.h>
using namespace std;
#define ll long long int
#define rep(a,b,c) for(ll a=b;a<c;a++)
float timer[100];
string p1,p2;
int times=0;
int press;
int w=0;
int again;
clock_t tStart;
vector<char>square{'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
string a,b;
int u=0;
int ttt;
int toss;

class result{
public:
int game_no;
string whoWon;
string whoLose;
result(int gno,string won,string lose){
    game_no=gno;
    whoWon=won;
    whoLose=lose;
}
};

class endGame{
    public:
vector<char>end;
endGame(vector<char>a){
    end=a;
}
};

vector<result>res;
vector<endGame>ending;
void fun1();
void toprintEndGame(vector<char>a);
void board();
bool checkIfWon();
string fun2();
void IntroDetails();
void detailed();
void showStats();

int main(){

IntroDetails();
cout<<"Press [0] to exit the game\n";
cout<<"Press [1] to again play the game\n";
cout<<"Press [2] to show the statistics of all the matches played till now\n";
cin>>again;
if(again==2){
    showStats();
}
if(again==1){
    square[1]='1';
    square[2]='2';
    square[3]='3';
    square[4]='4';
    square[5]='5';
    square[6]='6';
    square[7]='7';
    square[8]='8';
    square[9]='9';
    main();
}
    return 0;
}


void fun1(){
    clock_t tStart = clock();
    cout<<".....HELLO PLAYERS.....\n";
    cout<<"\n";
    cout<<"Lets start the Tic-Tac-Toe game!!!!\n\n";
    cout<<"Player 1 please enter your Name:";
    cin>>p1;
    cout<<"Player 2 please enter your Name:";
    cin>>p2;
    cout<<"Now lets have a toss\n";
    cout<<p1<<" Choose 1 or 2 for toss:\n";
    cin>>toss;
    int r=rand()%2+1;
    cout<<"Toss output is :"<<r<<"\n";
    if(r==toss){
        cout<<"Congratulations!!.. "<<p1<<" You won the toss,so u will take the first chance\n";
        a=p1;
        b=p2;
    }
    else{
        cout<<"Congratulations!!.. "<<p2<<" You won the toss,so u will take the first chance\n";
        a=p2;
        b=p1;
    }
}

void toprintEndGame(vector<char>a){
 cout << "\n==========================";
    cout << "\n\tTic Tac Toe\n";
    cout << "\n==========================\n";
    cout << endl;
    cout << "     ||     ||     \n";
    cout <<"  "<< a[1] <<"  ";
            cout<< "||  "<< a[2] <<"  ||  "<< a[3] << endl;
               cout<< "=====||=====||=====" << endl;
cout << "     ||     ||     \n";
    cout <<"  "<< a[4] <<"  ";
            cout<< "||  "<< a[5] <<"  ||  "<< a[6] << endl;
               cout<< "=====||=====||=====" << endl;
cout << "     ||     ||     \n"; 
    cout <<"  "<< a[7] <<"  ";
            cout<< "||  "<< a[8] <<"  ||  "<< a[9] << endl;   
}

void board()
{
    cout << "\n--------------------------";
    cout << "\n\tTic Tac Toe\n";
    cout << "\n--------------------------\n";
    cout << "Player 1 (X) - Player 2 (O)" << endl
         << endl;
    cout << endl;
    cout << "     ||     ||     \n";
    cout <<"  "<< square[1] <<"  ";
            cout<< "||  "<< square[2] <<"  ||  "<< square[3] << endl;
               cout<< "=====||=====||=====" << endl;
cout << "     ||     ||     \n";
    cout <<"  "<< square[4] <<"  ";
            cout<< "||  "<< square[5] <<"  ||  "<< square[6] << endl;
               cout<< "=====||=====||=====" << endl;
cout << "     ||     ||     \n"; 
    cout <<"  "<< square[7] <<"  ";
            cout<< "||  "<< square[8] <<"  ||  "<< square[9] << endl;   
}


bool checkIfWon(){
    if (square[1] == square[2] && square[2] == square[3])
    return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else
        return 0;
}


string fun2(){
    int t=4;
     board();
cout<<a<<" Choose the number position to play:\n";
cin>>ttt;
if(square[ttt]!='o' && square[ttt]!='x'){
    square[ttt]='x';
}
else{
    cout<<"!!!.....INVALID MOVE.....!!!\n";
}
if(checkIfWon()){
    return a;
}
    while(t--){
 
board();
cout<<b<<" Choose the number position to play:\n";
cin>>ttt;
if(square[ttt]!='o' && square[ttt]!='x'){
    square[ttt]='o';
}
else{
    cout<<"!!!.....INVALID MOVE.....!!!\n";
}
if(checkIfWon()){
    return b;
}
board();
 cout<<a<<" Choose the number position to play:\n";
cin>>ttt;
if(square[ttt]!='o' && square[ttt]!='x'){
    square[ttt]='x';
}
if(checkIfWon()){
    return a;
}
    }
    return "draw";
}


void IntroDetails(){
    times++;
fun1();
string ans=fun2();
if(ans==p1){
    cout<<" "<<p1<<" Won the match....!!!!\n";
}
else if(ans==p2){
    cout<<p2<<" Won the match....!!!!\n";
}
else{
    cout<<"Oops!!  This match is a DRAW......!!!\n";
}
string los;
if(ans==p1){
   los=p2;
}
else if(ans==p2){
    los=p1;
}
else{
    ans="draw";
    los="draw";
}
timer[u+1]=(double)(clock() - tStart)/CLOCKS_PER_SEC;
u++;
result r1(times,ans,los);
res.push_back(r1);
endGame e1(square);
ending.push_back(e1);
}


void detailed(){
int e=times;
cout<<"Detailed view of all the Games played is as follows:\n";
for(int i=1;i<=e;i++){
cout<<"Game Number : "<<i<<"\n";
cout<<"Winner is : "<<res[i-1].whoWon<<" "<<"\n";
cout<<"This match lasted for :"<<timer[i]<<" seconds\n";
cout<<"End Game scene is :";
toprintEndGame(ending[i-1].end);
cout<<"\n";
}

}



void showStats(){
int aWon=0;
int d=0;
cout<<"Game Number"<<"     |    "<<"Winner"<<"     |    "<<"Looser"<<"\n";
    for(int i=0;i<res.size();i++){
        if(res[i].whoWon==a){
            aWon++;
        }
        if(res[i].whoWon!=a && res[i].whoWon!=b){
            d++;
        }
        cout<<"   "<<res[i].game_no<<"                 "<<res[i].whoWon<<"             "<<res[i].whoLose<<"\n";
    }
    cout<<"=>   "<<a<<" won "<<aWon<<" Games\n";
    cout<<"=>   "<<b<<" won "<<times-aWon-d<<" Games\n";
    cout<<"To see the end game positions press 1\n";
    cout<<"press any key to exit\n";
    cin>>press;
    if(press=1){
        detailed();
    }

}
