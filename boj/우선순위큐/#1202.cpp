#include <iostream>
#include <queue>

using namespace std;
int N, K;

struct comp{
  bool operator()(pair<int, int>a, pair<int, int>b){
    return a.first > b.first;
  }
};

struct com{
  bool operator()(pair<int, int>a, pair<int, int>b){
    return a.second < b.second; 
  }
};
priority_queue<int,  vector<int>, greater<int>> q;
priority_queue<pair<int, int>, vector<pair<int, int>>, comp> wq;
priority_queue<pair<int, int>, vector<pair<int, int>>, com> vq;

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void solve(){
  long long value=0;
  while(!q.empty()){
    int a = q.top();
    q.pop();
    for(int i=0; i<wq.size(); i++){
      int b = wq.top().first;
      int c = wq.top().second;
      if(b>a)
        break;
      wq.pop();
      vq.push({b, c});
    }
    
    if(!vq.empty()){
      value+=vq.top().second;
      vq.pop();
    }
  }

  cout << value;
}


int main(){
  cin >> N >> K;
  int a, b;

  for(int i=0; i<N; i++){
    cin >> a >> b;
    wq.push({a, b});
  }

  for(int i=0; i<K; i++){
    cin >> a;
    q.push(a);
  }

  solve();
}