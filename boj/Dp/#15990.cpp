#include <iostream>
#define MAX 100001

using namespace std;

long long Dp[4][MAX]={0,};

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void solve(int N) {
  Dp[1][1] = 1;
  Dp[2][1] = 0;
  Dp[3][1] = 0;
  Dp[1][2] = 0;
  Dp[2][2] = 1;
  Dp[3][2] = 0;
  Dp[1][3] = 1;
  Dp[2][3] = 1;
  Dp[3][3] = 1;

  for (int i=4; i<=N; i++){
    Dp[1][i] = Dp[2][i-1] + Dp[3][i-1];
    Dp[2][i] = Dp[1][i-2] + Dp[3][i-2];
    Dp[3][i] = Dp[1][i-3] + Dp[2][i-3];

    if (Dp[1][i] > 1000000009) Dp[1][i] %= 1000000009;
    if (Dp[2][i] > 1000000009) Dp[1][i] %= 1000000009;
    if (Dp[3][i] > 1000000009) Dp[1][i] %= 1000000009;
  }
  cout << (Dp[1][N] + Dp[2][N] + Dp[3][N]) % 1000000009 << '\n';
}

int main() {
  int T, num;
  sync();
  cin >> T;
  while(T--) {
    cin >> num;
    solve(num);
  }
}