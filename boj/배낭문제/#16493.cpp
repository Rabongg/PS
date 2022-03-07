#include <iostream>
#include <algorithm>
#define MAX 21
using namespace std;

int spend[MAX];
int page[MAX];
int DP[MAX][201];

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void solve(int limit, int num) {
  int result = 0;
  for(int i=1; i<=num; i++){
    for(int j=1; j<=limit; j++){
      if(spend[i] <= j) {
        DP[i][j] = max(DP[i-1][j], DP[i-1][j-spend[i]] + page[i]);
      } else {
        DP[i][j] = DP[i-1][j];
      }

      result = max(result, DP[i][j]);
    }
  }
  cout << result;
}

int main() {
  int day, chapter;

  cin >> day >> chapter;
  for(int i=1; i<=chapter; i++)
    cin >> spend[i] >> page[i];

  solve(day, chapter);
}
