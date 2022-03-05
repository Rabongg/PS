#include <iostream>

#define MAX 100
using namespace std;

long long path[MAX][MAX]={0, };
int map[MAX][MAX]={0, };

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void solve(int N) {
  path[0][0] = 1;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++) {
      if(path[i][j] == 0 || (i == N-1 && j == N-1)) continue;

      int value = map[i][j];
      int px = i+value;
      int py = j+value;

      if (px < N)
        path[px][j] += path[i][j];
      if (py < N)
        path[i][py] += path[i][j];
    }
  }

  cout << path[N-1][N-1] << '\n';
}

int main() {
  int N;
  sync();
  cin >> N;
  for(int i=0; i< N; i++)
    for(int j=0; j<N; j++)
      cin >> map[i][j];
  
  solve(N);
}
