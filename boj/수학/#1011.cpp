#include <iostream>

using namespace std;

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void solve(int distance){
  int cnt = 0;
  long long num = 1;
  while(distance >= num * num) {
    num++;
  }
  num--;
  distance -= num*num;
  cnt += ((num) * 2) - 1;
  cnt = distance > 0 ? distance > num ? cnt + 2 : cnt + 1 : cnt ;
  cout << cnt << '\n';
}

int main() {
  sync();
  int T, x, y;
  cin >> T;
  while(T--) {
    cin >> x >> y;
    solve(y-x);
  }
}