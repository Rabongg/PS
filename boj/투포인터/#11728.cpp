#include <iostream>
#include <algorithm>
# define MAX 1000000
using namespace std;

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  sync();
  int n, m;
  int arr1[MAX];
  int arr2[MAX];
  cin >> n >> m;

  for (int i=0; i<n; i++){
    cin >> arr1[i];
  }
  for(int i=0; i<m; i++){
    cin >> arr2[i];
  }
  int a = 0, b =0;
  while(a<n && b<m){
    if (arr1[a] > arr2[b]) {
      cout << arr2[b] << ' ';
      b++;
    } else {
      cout << arr1[a] << ' ';
      a++;
    }
  }
  if(a==n) {
    for(; b<m; b++)
      cout << arr2[b] << ' ';
  } else {
    for(; a<n; a++)
      cout << arr1[a] << ' ';
  }
}