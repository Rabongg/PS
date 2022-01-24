#include <iostream>
#include <queue>
#include <vector>

using namespace std;


struct compare{

  bool operator()(pair<int, int>a, pair<int, int>b){
    return a.second > b.second;
  }
};


void setDistance(int n, bool * vistied, int * distance){
  for(int i=1; i<=n; i++){
    vistied[i]=false;
    distance[i]=1000001;
  }
}

long long int MST(int n, vector<pair<int, int>> *v, bool * visited, int * distance){

  long long int Dist =0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
  visited[1]=true;
  distance[1]=0;
  
  for(int i=0; i<v[1].size(); i++){
    distance[v[1][i].first]=v[1][i].second;
    pq.push({v[1][i].first, v[1][i].second});
  }

  while(!pq.empty()){
    int x = pq.top().first;
    pq.pop();
    visited[x]=true;

    for(int i=0; i<v[x].size(); i++){
      if(!visited[v[x][i].first] && distance[v[x][i].first] > v[x][i].second){
        distance[v[x][i].first]=v[x][i].second;
        pq.push({v[x][i].first, v[x][i].second});
      }
    }
  }

  for(int i=1; i<=n; i++){
    Dist +=distance[i];
  }
  return Dist;
}


int main(int argc, char**argv){

  int n, m, a, b, c;
  bool * visited;
  int * distance;

  cin >> n >> m;

  visited = new bool [n+1];
  distance = new int [n+1];
  vector<pair<int, int>> v[n+1];

  // set visitied & distance
  setDistance(n, visited, distance);

  for(int i=0; i<m; i++){
    cin >> a >> b >> c;
    v[a].push_back({b, c});
    v[b].push_back({a, c});
  }

  long long int result = MST(n, v, visited, distance);

  cout << result;
}