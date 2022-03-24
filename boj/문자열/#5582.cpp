#include <iostream>
#include <algorithm>

using namespace std;
int check[4000][4000];
void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  sync();
  string word1, word2;
  int cnt = 0;
  cin >> word1 >> word2;
  for(int i=0; i<word1.length(); i++) {
    for(int j=0; j<word2.length(); j++) {
      if(word1[i] == word2[j]) {
        if(i == 0 || j == 0) {
          check[i][j] = 1;
        } else {
          check[i][j] = check[i-1][j-1] + 1;
        }
        cnt = max (cnt, check[i][j]);
      }
    }
  }
  cout << cnt << '\n';
}