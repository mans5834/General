#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//Function declarations
void Introduction();
void UserDecision(int);
void OpenAccount();
void BWD();
void CloseAccount();
void FileUpdate();
//End of function declarations

double Balance = 0;

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
    default:
      break;
  }
}

void OpenAccount(){
 string Name, Email;
 int SecurityPin = 0;
 ofstream ofile;
 cout << "Hi, we are so happy you would like to open a bank account with us." << endl;
 cout << "To open an account we will need some basic information." << endl << endl;
 cout << "First please enter your name: ";
 cin >> Name;
 cout << "Next we will need you to enter an email address you would like to be associated with your account: ";
 cin >> Email;
 cout << "To log in to your account you will be asked for your email address and security pin. Enter a pin you would like to be associated with your account. Your pin cannot be longer then four digits: ";
 cin >> SecurityPin;
 while(SecurityPin >= 10000 || SecurityPin < 1000){
   cout << "That is not a long enough security pin please enter a four digit security pin: ";
   cin >> SecurityPin;
 }
 ofile.open("textfile.txt", fstream::app);
 ofile << Name << " " << SecurityPin << " " << Email << " "<< Balance << endl;
 ofile.close();
 cout << endl << "Congratulations! You have successfully created an account!" << endl;
 cout << "If you would like to add or withdraw money from your account just open this banking system again." << endl;
 cout << "Thank you!" << endl << endl;
}

void BWD(){
  string Email, Name, ActualEmail, Answer;
  int SecurityPin, ActualSecurityPin;
  double AmountToWithdraw, AmountToDeposit;
  ifstream infile;
  cout << endl << "Email: ";
  cin >> Email;
  cout << "Security Pin: ";
  cin >> SecurityPin;
  infile.open("textfile.txt");
  while(!eof() || Email == ActualEmail){
     infile >> Name >> ActualSecurityPin >> ActualEmail >> Balance;
  }
  if(Email == ActualEmail && SecurityPin == ActualSecurityPin){
    cout << "So nice to see you again " << Name << "! What would you like to do today, check balance, withdraw, or deposit? ";
    cin >> Answer;
    if(Answer == "check balance" || Answer == "Check Balance" || Answer == "check Balance" || Answer == "Check balance"){
      cout << "Your current balance is " << Balance;
    }else if(Answer == "withdraw" || Answer == "Withdraw"){
      cout << "How much would you like to withdraw? ";
      cin >> AmountToWithdraw;
      Balance -= AmountToWithdraw;
      cout << "Your requested withdrawal amount was " << AmountToWithdraw << " and your new current balance is " << Balance << ". Have a good day!" << endl;
      //figure out how to add the new balance to the text file without erasing everything
    }else if(Answer == "deposit" || Answer == "Deposit"){
      cout << "How much would you like to Deposit? ";
      cin >> AmountToDeposit;
      Balance += AmountToDeposit;
      cout << "Your requested deposit amount was " << AmountToDeposit << " and your new current balance is " << Balance << ". Have a good day!" << endl;
      //figure out how to add the new balance to the text file without erasing everthing
    }else{
      cout << "We are so sorry we did not recognize that answer. Please try again later. Thank You!" << endl;
    }
  }else{
    cout << "The email or password you entered was not recognized please try again or ask an associate for help." << endl 
  }
}

void FileUpdate(){
  
}
