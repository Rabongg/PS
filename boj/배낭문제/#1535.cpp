#include <iostream>
#include <algorithm>
#define MAX 21
using namespace std;

int health[MAX];
int pleasure[MAX];
int DP[100];

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void debug() {
  for(int i=0; i<100; i++){
    cout << DP[i] << ' ';
  }
}

void solve(int num) {
  int result = 0;
  for(int i=1; i<=num; i++) {
    int cost = health[i];
    int happy = pleasure[i];
    if(cost < 100){
      for(int j=100; 0<=j; j--){
        if(j+cost < 100)
          DP[j+cost] = DP[j] == 0 ? DP[j+cost] : max(DP[j+cost], DP[j]+happy);
      }
      DP[cost] = max(DP[cost], happy);
    }
  }
  for(int i=0; i<100; i++) 
    result = max(result, DP[i]);
  
  cout << result << '\n';
  // debug();
}

int main() {
  sync();
  int N;
  cin >> N;

  for(int i=1; i<=N; i++)
    cin >> health[i];
  
  for(int i=1; i<=N; i++)
    cin >> pleasure[i];
  
  solve(N);
}