#include<iostream>
#define MAX 1000

using namespace std;

int arr[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  int N, M;
  int x = 0 , y = 0, dir = 0;
  int resx = 1, resy = 1;
  sync();
  cin >> N >> M;
  int num =  N * N;
  arr[x][y] = num;
  num--;
  while(num) {
    x += dx[dir];
    y += dy[dir];
    if(arr[x][y] ||  x < 0  || N <= x || y < 0 || N <= y) {
      x -= dx[dir];
      y -= dy[dir];
      dir = (dir + 1 ) % 4;
    } else {
      arr[x][y] = num--;
    }
  
    if(arr[x][y] == M)
      resx = x + 1, resy = y + 1;
  }

  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cout << arr[i][j] << " ";
    }
    cout << '\n';
  }
  cout << resx << " " << resy;
}