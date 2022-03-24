#include <iostream>
#include <stack>
using namespace std;

stack<char> opposite;
void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void printStack() {
  while(!opposite.empty()) {
    cout << opposite.top();
    opposite.pop();
  }
}

int main() {
  sync();
  string sentence;
  getline(cin, sentence);
  int flag = 0;

  for(int i=0; i<sentence.length(); i++) {
    if(flag == 0) {
      if (sentence[i] == '<') {
        flag = 1;
        printStack();
        cout << '<';
      } else if(sentence[i] == ' ') {
        printStack();
        cout << ' ';
      } else {
        opposite.push(sentence[i]);
      }
    } else if(flag == 1) {
      cout << sentence[i];
      if (sentence[i] == '>') {
        flag = 0;
      }
    }
  }
  printStack();
}