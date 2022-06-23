#include <iostream>

using namespace std;

string s;

void check(int start, int end) {
  while(start < end) {
    if(s[start++] != s[end--]) {
      cout << "IPSELENTI";
      exit(0);
    }
  }
}

int main() {
  cin >> s;
  int len = s.length();
  int start = 0, end = len-1;
  while(start < end) {
    check(start, end);
    end = (len/=2) -1;
  }
  cout << "AKARAKA";
}