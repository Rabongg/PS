#include <iostream>

using namespace std;

void sync() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  int N, M, cnt = 0, answer = 0;
  string S;
  char ch = 'I';
  sync();
  cin >> N >> M >> S;

  N += (N+1);
  for(int i=0; i<S.length(); i++) {
    if(S[i] == ch) {
      ch = ch == 'I' ? 'O' : 'I';
      cnt++;
    } else {
      if (cnt >= N) {
        cnt -= N;
        answer++;
        answer += (cnt / 2);
      }
  
      if (S[i] == 'I') {
        cnt = 1;
        ch = 'O';
      } else {
        cnt = 0;
        ch = 'I';
      }
    }
  }

  if(cnt >= N) {
    cnt -= N;
    answer++;
    answer += (cnt / 2);
  }

  cout << answer;
}