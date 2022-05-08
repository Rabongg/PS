#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;
int DP[MAX][MAX];

int main() {
  int S;
  // 현재 상태, 움직인 횟수, 클립보드에 복사
  queue<pair<int, pair<int, int> > > q;
  cin >> S;
  q.push(make_pair(1, make_pair(0, 0)));
  DP[1][0]=0;
  while(!q.empty()) {
    int now = q.front().first;
    int cnt = q.front().second.first;
    int clip = q.front().second.second;
    q.pop();

    if(now == S){
      cout << cnt;
      break;
    }

    if(now-1 > 2 && (DP[now-1][clip] >  cnt+1 || !DP[now-1][clip])){
      DP[now-1][clip] = cnt + 1;
      q.push(make_pair(now-1, make_pair(cnt+1, clip)));
    }
    if(now + clip < 1001 && ( DP[now+clip][clip] > cnt + 1 || !DP[now+clip][clip])) {
      DP[now+clip][clip] = cnt + 1;
      q.push(make_pair(now+clip, make_pair(cnt+1, clip)));
    }
    if(DP[now][now] > cnt + 1 || !DP[now][now]){
      DP[now][now] = cnt + 1;
      q.push(make_pair(now, make_pair(cnt+1, now)));
    }
  }
}