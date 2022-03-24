#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 100
using namespace std;

int row, col;
char cave[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int> > pos;

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void init() {
  for(int i=0; i<row; i++) {
    for(int j=0; j<col; j++) {
      visited[i][j] = false;
    }
  }

  while(!pos.empty())
    pos.pop();
}

void move_cluster() {
  int distance = MAX;
  for(int j=0; j<col; j++) {
    for(int i=row-1; 0<=i; i--) {
      if(visited[i][j]) {
        for(int w=i; w < row; w++) {
          if(!visited[w][j] && cave[w][j] == 'x') {
            distance = min(distance, w-i-1);
            break;
          } else if( w == row-1) {
            distance = min(distance, w-i);
          }
        }
      }
    }
  }
  for(int i=0; i< col; i++) {
    for(int j=row-1; 0<=j; j--) {
      if(visited[j][i]) {
        visited[j][i] = false;
        cave[j][i] = '.';
        cave[j+distance][i] = 'x';
      }
    }
  }
}


void search() {
  while(!pos.empty()) {
    int x = pos.front().first;
    int y = pos.front().second;
    pos.pop();

    if(x == row-1)
      return;
    for(int i=0; i<4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 0 || nx >= row || ny < 0 || ny >= col)
        continue;
      if(cave[nx][ny] == 'x' && !visited[nx][ny]) {
        visited[nx][ny] = true;
        pos.push(make_pair(nx, ny));
      }
    }
  }

  move_cluster();
}

// 짝수면  왼쪽 공격, 홀수면 오른쪽 공격
void solve(int attack, int dir) {
  if(dir % 2 == 0) {
    for(int i=0; i<col; i++) {
      if(cave[attack][i] == 'x') {
        cave[attack][i] = '.';
        if( i + 1 < row && cave[attack][i+1] == 'x'){
          visited[attack][i+1] = true;
          pos.push(make_pair(attack, i+1));
          search();
          init();
        } 
        if (attack+1 < row && cave[attack+1][i] == 'x') {
          visited[attack+1][i] = true;
          pos.push(make_pair(attack+1, i));
          search();
          init();
        }

        if (attack-1 >= 0 && cave[attack-1][i] == 'x') {
          visited[attack-1][i] = true;
          pos.push(make_pair(attack-1, i));
          search();
          init();
        }
        break;
      }
    }
  } else {
    for(int i=col-1; 0<=i; i--) {
      if(cave[attack][i] == 'x') {
        cave[attack][i] = '.';
        if( 0 <= i -1  && cave[attack][i-1] == 'x'){
          visited[attack][i-1] = true;
          pos.push(make_pair(attack, i-1));
          search();
          init();
        } 
        if (attack-1 >= 0 && cave[attack-1][i] == 'x') {
          visited[attack-1][i] = true;
          pos.push(make_pair(attack-1, i));
          search();
          init();
        }
        if (attack+1 < row && cave[attack+1][i] == 'x') {
          visited[attack+1][i] = true;
          pos.push(make_pair(attack+1, i));
          search();
          init();
        }
        break;
      }
    }
  }
}

int main() {
  sync();
  cin >> row >> col;
  int attack_cnt, attack;
  for(int i=0; i<row; i++) {
    for(int j=0; j<col; j++) {
      cin >> cave[i][j];
    }
  }
  cin >> attack_cnt;
  for(int i=0; i<attack_cnt; i++) {
    cin >> attack;
    solve(row-attack, i);
  }

  for(int i=0; i<row; i++) {
    for(int j=0; j<col; j++) {
      cout << cave[i][j];
    }
    cout << endl;
  }
}