#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
queue<int> ans;

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  int K, N, a=0;
  sync();
  cin >> N >> K;
  for(int i=1; i<=N; i++) {
    q.push(i);
  }
  while(!q.empty()) {
    int num = q.front();
    q.pop();
    a++;
    if (a == K) {
      ans.push(num);
      a = 0;
    } else {
      q.push(num);
    }
  }

  cout << "<";
  while(!ans.empty()) {
    if(ans.size() == 1) {
      cout << ans.front();
    } else {
      cout << ans.front() << ", ";
    }
    ans.pop();
  }
  cout << ">";
}