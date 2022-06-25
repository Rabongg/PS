#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  string s;
  int ch[26] = {0, };
  int flag = 0;
  char cen;
  string answer = "";
  cin >> s;
  for(int i=0; i<s.length(); i++) {
    ch[s[i]-'A']++;
  }

  for(int i=0; i<26; i++) {
    if(ch[i] % 2 != 0){
      if (flag == 0){
        flag = 1;
        cen = i + 'A';
      }
      else {
        cout << "I'm Sorry Hansoo";
        return 0;
      }
    }
      
    int cnt = ch[i] / 2;
    while(cnt--) {
      answer+= i + 'A';
    }
  }

  cout << answer;
  if(flag == 1)
    cout << cen;
  reverse(answer.begin(), answer.end());
  cout << answer;
}