#include <iostream>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;

struct compare {
  bool operator()(pair<int, int>a, pair<int, int>b) {
    return a.first < b.first;
  }
};


vector<int> v;
priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pos;
queue<pair<int, int> > res;
queue<pair<int, int> > q;
char map [MAX][MAX];
bool visited[MAX][MAX] = {false, };
int R, C, N;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

// visited, pos, q 초기화
void init () {
  for(int i=1; i<=R; i++)
    for(int j=1; j<=C; j++)
      visited[i][j] = false;
  
  while(!pos.empty()) pos.pop();
  while(!q.empty()) q.pop();
  while(!res.empty()) res.pop();
}

// 공중에 떠 있는 경우 미네랄 움직이기
int shift(int x, int y) {
  for(int i=x+1; i<=R; i++) {
    if(map[i][y] == 'x' && !visited[i][y]) {
      return (i-1) - x;
    } else if(map[i][y] == 'x' && visited[i][y]) {
      break;
    } else if(map[i][y] == '.' && i==R) {
      return R-x;
    } else if(map[i][y] == '.') {
      continue;
    }
  }
  return 100;
}

void checkMinDist() {
  int a=100;
  
  while(!pos.empty()) {
    int x = pos.top().first;
    int y = pos.top().second;
    pos.pop();
    res.push(make_pair(x, y));
    a = min(a, shift(x,y));
  }

  while(!res.empty()) {
    int px = res.front().first;
    int py = res.front().second;
    res.pop();
    map[px][py] = '.';
    map[px+a][py] = 'x';
  }
}

void bfs(int x, int y) {
  q.push(make_pair(x, y));
  pos.push(make_pair(x, y));
  visited[x][y] = true;
  while(!q.empty()) {
    int px = q.front().first;
    int py = q.front().second;
    q.pop();

    if(px == R) {
      init();
      return;
    }
    for(int i=0; i<4; i++) {
      int nx = px + dx[i];
      int ny = py + dy[i];
      if(nx >= 1 && nx <= R && ny >= 1 && ny <= C && map[nx][ny] == 'x' && !visited[nx][ny]) {
        visited[nx][ny] = true;
        q.push(make_pair(nx, ny));
        pos.push(make_pair(nx, ny));
      }
    }
  }
  checkMinDist();
  init();
}

// flag=0이면 창영이 공격으로 인한 부서짐
// flag=1이면 상근이 공격으로 인한 부서짐
void checkFly(int x, int y, int flag) {
  if (flag == 0) {
    if(x-1 >= 1 && map[x-1][y] == 'x') {
      bfs(x-1, y);
    } 
    if(y+1 <= C && map[x][y+1] == 'x') {
      bfs(x, y+1);
    }
    if(x+1 <= R && map[x+1][y] == 'x') {
      bfs(x+1, y);
    }
  } else {
    if(x-1 >= 1 && map[x-1][y] == 'x') {
      bfs(x-1, y);
    } 
    if(y-1 >= 1 && map[x][y-1] == 'x') {
      bfs(x, y-1);
    }
    if(x+1 <= R && map[x+1][y] == 'x') {
      bfs(x+1, y);
    }
  }
}

// 창영이의 공격
void cAttack(int a) {
  for(int i=1; i<=C; i++) {
    if(map[R-a][i] == 'x') {
      map[R-a][i] = '.';
      checkFly(R-a, i, 0);
      break;
    }
  }
}

// 상근이의 공격
void sAttack(int a) {
  for(int i=C; 1<=i; i--) {
    if(map[R-a][i] == 'x') {
      map[R-a][i] = '.';
      checkFly(R-a, i, 1);
      break;
    }
  }
}

void solve() {
  for(int i=0; i<N; i++){
    if(i%2 == 0) {
      cAttack(v[i]-1);
    }
    else {
      sAttack(v[i]-1);
    }
  }
}

// 창영이와 상근이의 싸움(왜 싸울까...)
int main() {
  int num;
  sync();
  int i, j;
  cin >> R >> C;
  for(i=1; i<=R; i++)
    for(j=1; j<=C; j++)
      cin >> map[i][j];

  cin >> N;
  for(i=0; i<N; i++){
    cin >> num;
    v.push_back(num);
  }

  solve();

  for(i=1; i<=R; i++) {
    for(j=1; j<=C; j++)
      cout << map[i][j];
    cout << '\n';
  }
}