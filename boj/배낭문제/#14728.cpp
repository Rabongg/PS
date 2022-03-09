#include <iostream>
#define MAX 101
#define LIMIT 10001
using namespace std;

int spend[MAX];
int score[MAX];
int DP[LIMIT] = {0, };

void sync() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void solve(int chapter, int study) {
  int result = 0;
  for(int i=1; i<=chapter; i++) {
    int sp = spend[i];
    int cost = score[i];
    if(sp > study)
      continue;
    for(int j=study; sp<=j; j--){
      if(DP[j-sp]+cost > DP[j])
        DP[j] = DP[j-sp] + cost;
      result = max(result, DP[j]);
    }
  }

  cout << result;
}

int main() {
  sync();
  int chapter, study;
  cin >> chapter >> study;
  for(int i=1; i<=chapter; i++)
    cin >> spend[i] >> score[i];
  
  solve(chapter, study);
}