#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int LCS[MAX][MAX];

int main() {
  string s1, s2;
  string answer = "";
  cin >> s1 >> s2;

  for(int i=1; i<=s1.length(); i++) {
    for(int j=1; j<=s2.length(); j++) {
      if(s1[i-1] == s2[j-1]) {
        LCS[i][j] = LCS[i-1][j-1] + 1;
      } else {
        LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
      }
    }
  }
  int len = LCS[s1.length()][s2.length()];
  cout << len << '\n';
  
  for(int i=s1.length(); 0<i && len!=0; i--) {
    for(int j=s2.length(); 0<j && len!=0; j--) {
      if(LCS[i][j] == len && LCS[i-1][j] == (len-1) && LCS[i][j-1] == (len-1)) {
        answer = s2[j-1] +  answer ;
        len--;
        break;
      }
    }
  }
  cout << answer;
}