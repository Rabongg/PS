#include <iostream>
#define MAX 101
using namespace std;

int memory[MAX];
int cost[MAX];
int DP[10001];
int N, M;

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void debug() {
  for(int i=0; i<=1000; i++)
    cout << DP[i] << ' ';
}

int solve() {

  for(int i=1; i<=N; i++) {
    int mem = memory[i];
    int co = cost[i];
    for(int j=10000; co<=j; j--){
      if(DP[j-co]+mem > DP[j])
        DP[j] = DP[j-co] + mem;
    }
  }


  for(int i=0; i<=10000; i++)
    if(DP[i]>=M)
      return i;
}


int main() {
  sync();
  cin >> N >> M;
  for(int i=1; i<=N; i++)
    cin >> memory[i];
  
  for(int i=1; i<=N; i++)
    cin >> cost[i];
  
  cout << solve() <<  '\n';
  debug();
}