#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

int coin[21];
int customer[21];
int DP[MAX+1];


void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void debug(int num) {
  for(int i=1; i<=num*2; i++)
    cout << DP[i] << ' ';
  cout << '\n';
}

// 비교를 
void solve(int limit, int city_num) {

  for(int i=1; i<=city_num; i++){
    int cost = coin[i];
    for(int j=cost; j<=MAX ;j++)
      DP[j] = max(DP[j], DP[j-cost] + customer[i]);
  }

  for(int i=1; i<=MAX; i++)
    if(DP[i] >= limit) {
      cout << i;
      break;
    }
}

int main() {
  int limit_customer, city;
  sync();
  cin >> limit_customer >> city;
  for(int i=1; i<=city; i++)
    cin >> coin[i] >> customer[i];
  
  solve(limit_customer, city);
}