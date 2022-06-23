#include <iostream>

using namespace std;

int main() {
  string s;
  getline(cin, s);
  for(int i=1; i<s.length(); i++) {
    if(s[i] == '2' && (s[i-1] == 'D' || s[i-1] == 'd')){
      cout << "D2";
      return 0;
    }
  }

  cout << "unrated";
}