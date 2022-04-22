#include <iostream>
#define MAX 200001
using namespace std;

int cnt[MAX][26];

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}


int main() {
  sync();
  string sentence;
  char alph;
  int num, l, r;

  cin >> sentence;
  for(int i=0; i<sentence.length(); i++) {
    cnt[i+1][sentence[i]-'a'] = 1;
    for(int j=0; j<26; j++) {
      cnt[i+1][j] += cnt[i][j];
    }
  }

  cin >> num;
  while(num--) {
    cin >> alph;
    cin >> l >> r;
    cout << cnt[r+1][alph-'a'] - cnt[l][alph-'a'] << '\n';
  }
}