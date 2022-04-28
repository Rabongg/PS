#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001

using namespace std;

vector<pair<int, int> > v[MAX];
bool visited[MAX];
queue<pair<int, int> >q;



void init(int V) {
  for(int i=1; i<=V; i++)
    visited[i] = false;
}


pair<int, int> solve(int a) {

  int max_node;
  int max_distance = 0;

  visited[a] = true;
  q.push(make_pair(a, 0));

  while(!q.empty()) {
    int node = q.front().first;
    int cost = q.front().second;
    q.pop();

    if (cost > max_distance) {
      max_distance = cost;
      max_node = node;
    }

    for(int i=0; i<v[node].size(); i++) {
      if(visited[v[node][i].first])
        continue;
      
      visited[v[node][i].first] = true;
      q.push(make_pair(v[node][i].first, cost + v[node][i].second));
    }
  }

  return make_pair(max_node, max_distance);
}

int main() {
  int V, num, edge, cost;
  cin >> V;
  pair<int, int> result;
  for(int i=0; i<V; i++) {
    cin >> num;
    while(1) {
      cin >> edge;
      if(edge == -1)
        break;
      cin >> cost;
      v[num].push_back(make_pair(edge, cost));
    }
  }


  result = solve(1);
  init(V);
  result = solve(result.first);

  cout << result.second;
}