#include <iostream>
#include <vector>
#include <queue>

#define MAX 10001
using namespace std;
int N;
vector<pair<int, int> > v[MAX];
bool visited[MAX];

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void init() {
  for(int i=1; i<=N; i++)
    visited[i] = false;
}


pair<int, int> bfs(int node) {
  queue<pair<int, int> > q;
  q.push(make_pair(node, 0));
  visited[node] = true;
  int max_dist = 0;
  int max_node = 0;

  while(!q.empty()) {
    int n = q.front().first;
    int dist = q.front().second;
    q.pop();

    if(dist > max_dist) {
      max_dist = dist;
      max_node = n;
    }

    for(int i=0; i<v[n].size(); i++) {
      int dest = v[n][i].first;
      int cost = v[n][i].second;
      if(visited[dest])
        continue;

      visited[dest] = true;
      q.push(make_pair(dest, cost + dist));
    }
  }

  return make_pair(max_node, max_dist);
}


int main() {
  sync();
  int a, b, dist;
  pair<int, int> result;
  cin >> N;
  for(int i=1; i<N; i++) {
    cin >> a >> b >> dist;
    v[a].push_back(make_pair(b, dist));
    v[b].push_back(make_pair(a, dist));
  }

  result = bfs(1);
  init();
  result = bfs(result.first);

  cout << result.second;
}