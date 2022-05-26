#include<iostream>
using namespace std;

//Function declarations
void Introduction();
void UserDecision(int);
void OpenAccount();
void BWD();
void CloseAccount();
//End of function declarations

void Introduction(){
  cout << "     Welcome to your online banking system. We have been happily serving the community since 1999." << endl << endl;
  cout << "What would you like to do today?" << endl;
  cout << "1. Open an account" << endl;
  cout << "2. Check balance / withdraw / deposit" << endl;
  cout << "3. Close an account" << endl;
  cout << "4. Exit" << endl;
}

void UserDecision(int UserInput){
  switch(UserInput){
    case 1:
      OpenAccount();
    case 2:
      BWD();
    case 3:
      CloseAccount();
    case 4:
      break;
    default:
      break;
  }
}
