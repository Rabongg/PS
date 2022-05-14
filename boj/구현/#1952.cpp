#include <iostream>
#define MAX 101
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool visited[MAX][MAX];

int main() {
  int N, M;
  int cnt = 0, dir = 0, x = 1, y = 1;
  cin >> N >> M;

  visited[x][y] = true;
  while(1) {
    x += dx[dir];
    y += dy[dir];
    if(x < 1 || y < 1 || N < x || M < y || visited[x][y]) {
      x-= dx[dir];
      y-= dy[dir];
      dir = (dir + 1) % 4;
      if(visited[x + dx[dir]][y + dy[dir]])
        break;
      cnt++;
    }
    visited[x][y] = true;
  }
  cout << cnt;
}