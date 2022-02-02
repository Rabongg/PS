#include<iostream>
#include<algorithm>
#include<stack>
#include<cstring>

#define MAX 50
using namespace std;
int v[MAX];
int N, cnt=0;
bool visited[MAX];

void DFS(int a){
  bool cng = false;
  stack<int> s;
  s.push(a);
  while(!s.empty()){
    int t = s.top();
    visited[t] = true;
    bool exist = false;
    for(int i=0; i<N; i++){
      if(v[i]==t && !visited[i]){
        s.push(i);
        visited[i]=true;
        exist = true;
      }
    }
    if(!exist){
      for(int i=0; i<N; i++){
        if(v[i]==t){
          cng = true;
          break;
        }
      }
      if(!cng)
        cnt++;
      cng = false;
      s.pop();
    }
  }
}

void Erase(int a){
  stack<int> s;
  s.push(a);
  while(!s.empty()){
    int t = s.top();
    bool exist = false;
    visited[t]=true;
    v[t]=-2;
    for(int i=0; i<N; i++){
      if(!visited[i] && v[i]==t){
        s.push(i);
        visited[i]=true;
        v[i]=-2;  
        exist = true;
      }
    }
    if(!exist)
      s.pop();
  }
}

int main(){
  int a, b;
  cin >> N;
  for(int i=0; i<N; i++)
    cin >> v[i];

  cin >> b;
  Erase(b);

  memset(visited, false, sizeof(visited));
  for(int i=0; i<N; i++){
    if(v[i]==-1)
      DFS(i);
  }
  cout << cnt << endl;
}