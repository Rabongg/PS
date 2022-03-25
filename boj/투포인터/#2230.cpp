#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  sync();
  int N, M;
  int arr[MAX];
  cin >> N >> M;
  for(int i=0; i<N; i++)
    cin >> arr[i];
  
  sort(arr, arr+N);
  int a = 0, b = 1, result = 2000000000;
  while(b < N) {
    int sub = arr[b] - arr[a];
    if(sub < M)
      b++;
    else {
      result = min(result, sub);
      a++;
      if(a==b)
        b++;
    }
  }
  cout << result;
}