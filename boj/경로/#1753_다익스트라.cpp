#include <iostream>
#include <vector>
#include <queue>
#define MAX 20001
using namespace std;
int N, M, K;
vector<pair<int, int>> di[MAX];
int diki[MAX];

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

struct compare{

  bool operator()(pair<int, int>a , pair<int, int> b){
    return a.second > b.second;
  }

};

void solve(){

  priority_queue<pair<int, int>, vector<pair<int, int>>, compare>q;
  q.push({K, 0});
  diki[K]=0;
  while(!q.empty()){
    int a = q.top().first;
    int b = q.top().second;
    q.pop();

    for(int i=0; i<di[a].size(); i++){

      if(diki[di[a][i].first] > b + di[a][i].second){
        diki[di[a][i].first]=b + di[a][i].second;
        q.push({di[a][i].first, b+di[a][i].second});
      }
    }
  }

  for(int i=1; i<=N; i++){
    if(diki[i]==INT32_MAX)
      cout << "INF" << '\n';
    else  
      cout << diki[i] << '\n';
  }
}

void init(){
  for(int i=1; i<=N; i++)
    diki[i]=INT32_MAX;
}

int main(){
  sync();
  int u, v, w;
  cin >> N >> M >> K;

  init();
  for(int i=0; i<M; i++){
    cin >> u >> v >> w;
    di[u].push_back({v, w});
  }

  solve();
}