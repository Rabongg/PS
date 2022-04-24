#include <iostream>
#include <list>

using namespace std;

int main() {
  string s;
  char cmd, ch;
  int N;
  list<char> l;
  list<char>::iterator it;
  cin >> s;
  
  for(int i=0; i<s.length(); i++) {
    l.push_back(s[i]);
  }
  it = l.end();

  cin >> N;
  for(int i=0; i<N; i++) {
    cin >> cmd;
    if(cmd == 'P') {
      cin >> ch;
      l.insert(it, ch);
    } else if(cmd == 'L') {
      if(it != l.begin())
        it--;
    } else if(cmd == 'D') {
      if(it != l.end())
        it++;
    } else {
      if(it != l.begin())
        it = l.erase(--it);
    }
  }

  for (it = l.begin(); it != l.end(); it++) 
    cout << *it;
}