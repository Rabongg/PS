#include <iostream>
#include <string.h>
#include <stack>

using namespace std;
string sentence;
stack <char> s;

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void init() {

  while(!s.empty()) {
    s.pop();
  }
}


void solve() {
  for(int i=0; i<sentence.length(); i++) {
    if(sentence[i] == '.') {
      if(s.empty()) {
        cout << "yes" << '\n';
      } else {
        cout << "no" << '\n';
      }
      break;
    } else if(sentence[i] == '[' || sentence[i] == '(') {
      s.push(sentence[i]);
    } else if(sentence[i] == ']') {
      if(s.empty() || s.top() !='[')
        s.push(']');
      else if (s.top()=='[')
        s.pop();
    } else if(sentence[i] == ')') {
      if(s.empty() || s.top() !='(')
        s.push(')');
      else if (s.top()=='(')
        s.pop();
    }
  }
}


int main() {
  sync();
  while(1) {
    getline(cin, sentence);
    if(sentence[0]=='.')
      break;
    solve();
    init();
  }
}