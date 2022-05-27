#include"Functions.hpp"

int main(){
  int UserInput = 0;
  Introduction();
  cin >> UserInput;
  while(UserInput < 1 || UserInput > 4){
    cout << "That is not an option please enter another option." << endl;
    cin >> UserInput;
  }
}
