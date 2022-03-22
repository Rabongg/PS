#include <iostream>
#include <stack>
#define MAX 21
#define LIMIT 301
using namespace std;

int DP[MAX][LIMIT];
int result[MAX][LIMIT];
int path[MAX][LIMIT];
stack<int> ans;

void sync() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void solve(int money, int company) {

  for(int i=1; i<=company; i++) {
    for(int j=0; j<=money; j++) {
      for(int w=0; w<=j; w++) {
        if(result[i][j] < result[i-1][j-w]+DP[i][w]){
          result[i][j] = result[i-1][j-w]+DP[i][w];
          path[i][j] = w;
        }
      }
    }
  }

  cout << result[company][money] << '\n';

  while(company) {
    ans.push(path[company][money]);
    money-= path[company][money];
    company--;
  }

  while(!ans.empty()) {
    cout << ans.top() << ' ';
    ans.pop();
  }
}

int main() {
  sync();
  int money, company;
  int amount;
  cin >> money >> company;
  for(int i=1; i<=money; i++) {
    cin >> amount;
    for(int j=1; j<=company; j++) {
      cin >> DP[j][amount];
    }
  }
  if (company == 1) {
    cout << DP[1][money] << '\n';
    cout << money;
  }
  else
    solve(money, company);
}