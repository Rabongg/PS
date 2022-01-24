#include <iostream>
#include <cmath>
#include <vector>
#define MAX 16

using namespace std;
int N;
int array1[MAX];
int cnt = 0;
bool visited[MAX]={false, };


void back(int a){
  
  int flag = 1;
  if(a==N+1){
    cnt++;
    return;
  }

  
  for(int i=1; i<=N; i++){
    if(a==1){
      array1[a]=i;
      back(a+1);
    }
    for(int j=1; j<=a-1; j++){
      if(i!=array1[j] && abs(a-j)!=abs(i-array1[j])){
        flag=0;
      }
      else{
        flag=1;
        break;
      }
    }
    if(!flag){
      array1[a]=i;
      back(a+1);
    }
  }
}


int main(){
  cin >> N;
  back(1);

  cout << cnt;
}