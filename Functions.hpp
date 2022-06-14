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
void FileUpdate(string, int, string);
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
      break;
    case 2:
      BWD();
      break;
    case 3:
      CloseAccount();
      break;
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
  while(!infile.eof() && Email != ActualEmail){
     infile >> Name >> ActualSecurityPin >> ActualEmail >> Balance;
  }
  if(Email == ActualEmail && SecurityPin == ActualSecurityPin){
    cout << "So nice to see you again " << Name << "! What would you like to do today, checkbalance, withdraw, or deposit? ";
    cin >> Answer;
    if(Answer == "checkbalance" || Answer == "CheckBalance" || Answer == "checkBalance" || Answer == "Checkbalance"){
      cout << "Your current balance is " << Balance << endl;
    }else if(Answer == "withdraw" || Answer == "Withdraw"){
      cout << "How much would you like to withdraw? ";
      cin >> AmountToWithdraw;
      Balance -= AmountToWithdraw;
      cout << "Your requested withdrawal amount was " << AmountToWithdraw << " and your new current balance is " << Balance << ". Have a good day!" << endl;
      FileUpdate(Name, ActualSecurityPin, ActualEmail);
    }else if(Answer == "deposit" || Answer == "Deposit"){
      cout << "How much would you like to Deposit? ";
      cin >> AmountToDeposit;
      Balance += AmountToDeposit;
      cout << "Your requested deposit amount was " << AmountToDeposit << " and your new current balance is " << Balance << ". Have a good day!" << endl;
      FileUpdate(Name, ActualSecurityPin, ActualEmail);
    }else{
      cout << "We are so sorry we did not recognize that answer. Please try again later. Thank You!" << endl;
    }
  }else{
    cout << "The email or password you entered was not recognized please try again or ask an associate for help." << endl;
  }
}

void CloseAccount(){
  string Email, Name, ActualEmail, Answer;
  int SecurityPin, ActualSecurityPin;
  ifstream infile;
  cout << "We are so sorry you would like to close your account with us. If you would ever like to open a new account dont hesitate to do so!" << endl;
  cout << "To verify you can close the account, please enter your email and security pin below." << endl << endl;
  cout << "Email: ";
  cin >> Email;
  cout << "Security Pin: ";
  cin >> SecurityPin;
  infile.open("textfile.txt");
  while(!infile.eof() && Email != ActualEmail){
     infile >> Name >> ActualSecurityPin >> ActualEmail >> Balance;
  }
  infile.close();
  if(Email == ActualEmail && SecurityPin == ActualSecurityPin){
    string DeletedLine;
    ifstream TempIn;
    ofstream TempOut;
    TempIn.open("textfile.txt");
    TempOut.open("Tempfile.txt");
    while(getline(TempIn, DeletedLine)){
      if(DeletedLine.substr(0, Name.size()) != Name)
        TempOut << DeletedLine << endl;
    }
    TempIn.close();
    TempOut.close();
    remove("textfile.txt");
    rename("Tempfile.txt", "textfile.txt");
    cout << "Your account has been close. We are so sad to see you go!";
  }else
    cout << "The email or password you entered was not recognized please try again or ask an associate for help." << endl;
}

void FileUpdate(string name, int SecurityPin, string Email){
  string DeletedLine;
  ifstream TempIn;
  ofstream TempOut;
  TempIn.open("textfile.txt");
  TempOut.open("TempFile.txt");
  while(getline(TempIn, DeletedLine)){
    if(DeletedLine.substr(0, name.size()) != name)
      TempOut << DeletedLine << endl;
  }
  TempIn.close();
  TempOut.close();
  TempOut.open("TempFile.txt", fstream::app);
  TempOut << name << " " << SecurityPin << " " << Email << " " << Balance << endl;
  TempOut.close();
  remove("textfile.txt");
  rename("Tempfile.txt", "textfile.txt");
}
