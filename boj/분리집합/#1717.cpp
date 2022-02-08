#include <iostream>
#define MAX 1000001
using namespace std;
int N, M;
int arr[MAX];

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int Unionfind(int a){

  if(arr[a] == a)
    return a;
  else 
    return arr[a] = Unionfind(arr[a]);
}

void Union(int a, int b){

  a = Unionfind(a);
  b = Unionfind(b);
  arr[b]=a;
}

void find(int a, int b){

  a = Unionfind(a);
  b = Unionfind(b);

  if(a!=b)
    cout << "NO" << '\n';
  else{
    cout << "YES" << '\n';
  }
}

void initial(){
  for(int i=0; i<=N; i++){
    arr[i]=i;
  }
}

int main(){
  cin >> N >> M;
  sync();
  int a, b, c;
  initial();
  for(int i=0; i<M; i++){
    cin >> a >> b >> c;
    if(a==0){
      if(b > c){
        Union(c, b);
      }else{
        Union(b, c);
      }
    }
    else{
      find(b, c);
    } 
  }
}