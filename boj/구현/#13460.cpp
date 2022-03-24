#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 10
using namespace std;

char maze[MAX][MAX];
int result = 11;
int row, col;
queue<pair<pair<int, int>, int> > red_position;
queue<pair<int, int> > blue_position;


void sync() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}


//dir : 0 : 상, 1 : 하, 2 : 좌, 3 : 우
void move(int r_x, int r_y, int b_x, int b_y, int cnt, int dir) {

  if (dir == 0) {  // 상
    if(r_y == b_y) {   // 둘이 같은 열
      if (r_x > b_x) {  // 파란색이 더 먼저 이동하는 경우
        for(; 0<=b_x; b_x--){
          if(maze[b_x][b_y] != '.') {
            break;
          }
        }
        if (maze[b_x][b_y] == 'O')
          return;
        for(; b_x<=r_x; r_x--){
          if(maze[r_x][r_y] != '.') {
            break;
          }
        }

        if(maze[r_x][r_y] == 'O') {
          result = min(cnt + 1, result);
          return;
        }

        if(b_x == r_x)
          r_x++;
        blue_position.push(make_pair(b_x + 1, b_y));
        red_position.push(make_pair(make_pair(r_x + 1, r_y), cnt + 1));

      } else {  // 빨간색이 더 먼저 이동하는 경우
        for(; 0<=r_x; r_x--){
          if(maze[r_x][r_y] != '.') {
            break;
          }
        }

        for(; r_x<=b_x; b_x--){
          if(maze[b_x][b_y] != '.') {
            break;
          }
        }

        if (maze[b_x][b_y] == 'O')
          return;
        
        if(maze[r_x][r_y] == 'O') {
          result = min(cnt + 1, result);
          return;
        }

        if(b_x == r_x)
          b_x++;
        blue_position.push(make_pair(b_x + 1, b_y));
        red_position.push(make_pair(make_pair(r_x + 1, r_y), cnt + 1));
      }
    } else {
      for(; 0<=b_x; b_x--) {
          if(maze[b_x][b_y] != '.') {
            break;
          }
      }
      if (maze[b_x][b_y] == 'O')
        return;
      for(; 0<=r_x; r_x--){
        if(maze[r_x][r_y] != '.') {
          break;
        }
      }
      if(maze[r_x][r_y] == 'O') {
        result = min(cnt + 1, result);
        return;
      }

      blue_position.push(make_pair(b_x + 1, b_y));
      red_position.push(make_pair(make_pair(r_x + 1, r_y), cnt + 1));
    }
  } else if (dir == 1) { // 하
    if(r_y == b_y) {   // 둘이 같은 열
      if (r_x > b_x) {  // 빨간색이 더 먼저 이동하는 경우
        for(; r_x < row; r_x++){
          if(maze[r_x][r_y] != '.') {
            break;
          }
        }
        for(; b_x<=r_x; b_x++){
          if(maze[b_x][b_y] != '.') {
            break;
          }
        }
        if (maze[b_x][b_y] == 'O')
          return;

        if(maze[r_x][r_y] == 'O') {
          result = min(cnt + 1, result);
          return;
        }

        if(b_x == r_x)
          b_x--;
        blue_position.push(make_pair(b_x - 1, b_y));
        red_position.push(make_pair(make_pair(r_x - 1, r_y), cnt + 1));

      } else {  // 파란색이 더 먼저 이동하는 경우
        for(; b_x < row;  b_x++){
          if(maze[b_x][b_y] != '.') {
            break;
          }
        }
        if (maze[b_x][b_y] == 'O')
          return;
        for(; r_x <=b_x; r_x++){
          if(maze[r_x][r_y] != '.') {
            break;
          }
        }
        
        if(maze[r_x][r_y] == 'O') {
          result = min(cnt + 1, result);
          return;
        }

        if(b_x == r_x)
          r_x--;
        blue_position.push(make_pair(b_x - 1, b_y));
        red_position.push(make_pair(make_pair(r_x - 1, r_y), cnt + 1));
      }
    } else {  // 둘이 다른 열
      for(; b_x < row; b_x++) {
        if(maze[b_x][b_y] != '.') {
          break;
        }
      }
      if (maze[b_x][b_y] == 'O')
        return;

      for(; r_x < row; r_x++){
        if(maze[r_x][r_y] != '.') {
          break;
        }
      }
      if(maze[r_x][r_y] == 'O') {
        result = min(cnt + 1, result);
        return;
      }

      blue_position.push(make_pair(b_x - 1, b_y));
      red_position.push(make_pair(make_pair(r_x - 1, r_y), cnt + 1));
    }
  } else if (dir == 2) { // 좌
    if(r_x == b_x) {  // 같은 행
      if (r_y > b_y) {  // 파란색이 더 먼저 이동하는 경우
        for(; 0<=b_y; b_y--){
          if(maze[b_x][b_y] != '.') {
            break;
          }
        }
        if (maze[b_x][b_y] == 'O')
          return;
        for(; b_y<=r_y; r_y--){
          if(maze[r_x][r_y] != '.') {
            break;
          }
        }

        if(maze[r_x][r_y] == 'O') {
          result = min(cnt + 1, result);
          return;
        }

        if(b_y == r_y)
          r_y++;
        blue_position.push(make_pair(b_x, b_y + 1));
        red_position.push(make_pair(make_pair(r_x, r_y + 1), cnt + 1));

      } else {  // 빨간색이 더 먼저 이동하는 경우
        for(; 0<=r_y; r_y--){
          if(maze[r_x][r_y] != '.') {
            break;
          }
        }

        for(; r_y<=b_y; b_y--){
          if(maze[b_x][b_y] != '.') {
            break;
          }
        }

        if (maze[b_x][b_y] == 'O')
          return;
        
        if(maze[r_x][r_y] == 'O') {
          result = min(cnt + 1, result);
          return;
        }

        if(b_y == r_y)
          b_y++;
        blue_position.push(make_pair(b_x, b_y + 1));
        red_position.push(make_pair(make_pair(r_x, r_y + 1), cnt + 1));
      }
    } else {
      for(; 0<=b_y; b_y--) {
          if(maze[b_x][b_y] != '.') {
            break;
          }
      }
      if (maze[b_x][b_y] == 'O')
        return;

      for(; 0<=r_y; r_y--){
        if(maze[r_x][r_y] != '.') {
          break;
        }
      }
      if(maze[r_x][r_y] == 'O') {
        result = min(cnt + 1, result);
        return;
      }

      blue_position.push(make_pair(b_x, b_y + 1));
      red_position.push(make_pair(make_pair(r_x, r_y + 1), cnt + 1));
    }
  } else if (dir == 3) { // 우
    if(r_x == b_x) {
      if (r_y > b_y) {  // 빨간색이 더 먼저 이동하는 경우
        for(; r_y < col ; r_y++){
          if(maze[r_x][r_y] != '.') {
            break;
          }
        }
        for(; b_y<=r_y; b_y++){
          if(maze[b_x][b_y] != '.') {
            break;
          }
        }

        if (maze[b_x][b_y] == 'O')
          return;

        if(maze[r_x][r_y] == 'O') {
          result = min(cnt + 1, result);
          return;
        }

        if(b_y == r_y)
          b_y--;
        blue_position.push(make_pair(b_x, b_y - 1));
        red_position.push(make_pair(make_pair(r_x, r_y - 1), cnt + 1));

      } else {  // 파란색이 더 먼저 이동하는 경우
        for(; b_y< col; b_y ++){
          if(maze[b_x][b_y] != '.') {
            break;
          }
        }

        if (maze[b_x][b_y] == 'O')
          return;
        
        for(; r_y <= b_y; r_y++){
          if(maze[r_x][r_y] != '.') {
            break;
          }
        }

        if(maze[r_x][r_y] == 'O') {
          result = min(cnt + 1, result);
          return;
        }

        if(b_y == r_y)
          r_y--;
        blue_position.push(make_pair(b_x, b_y - 1));
        red_position.push(make_pair(make_pair(r_x, r_y - 1), cnt + 1));
      }
    } else {
      for(; b_y < col; b_y++) {
        if(maze[b_x][b_y] != '.') {
          break;
        }
      }
      if (maze[b_x][b_y] == 'O')
        return;

      for(; r_y < col; r_y++){
        if(maze[r_x][r_y] != '.') {
          break;
        }
      }
      if(maze[r_x][r_y] == 'O') {
        result = min(cnt + 1, result);
        return;
      }

      blue_position.push(make_pair(b_x, b_y - 1));
      red_position.push(make_pair(make_pair(r_x, r_y - 1), cnt + 1));
    }
  }
}



void solve() {

  while(!red_position.empty()) {
    int r_x = red_position.front().first.first;
    int r_y = red_position.front().first.second;
    int cnt = red_position.front().second;
    int b_x = blue_position.front().first;
    int b_y = blue_position.front().second;
    red_position.pop();
    blue_position.pop();

    if(cnt == 10)
      continue;

    move(r_x, r_y, b_x, b_y, cnt, 0);
    move(r_x, r_y, b_x, b_y, cnt, 1);
    move(r_x, r_y, b_x, b_y, cnt, 2);
    move(r_x, r_y, b_x, b_y, cnt, 3);
  }
}



int main() {
  sync();
  cin >> row >> col;
  for(int i=0; i<row; i++) {
    for(int j=0; j<col; j++) {
      cin >> maze[i][j];
      if(maze[i][j] == 'R') {
        red_position.push(make_pair(make_pair(i, j), 0));
        maze[i][j] = '.';
      } else if(maze[i][j] == 'B') {
        blue_position.push(make_pair(i, j));
        maze[i][j] = '.';
      }
    }
  }

  solve();

  result = result == 11 ? -1 : result;
  cout << result;
}