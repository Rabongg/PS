#include<iostream>
#define MAX 10000
using namespace std;

int arr[MAX];

void swap(int i, int j) {
  int tmp;
  tmp = arr[j];
  arr[j] = arr[i];
  arr[i] = tmp;
}

int main() {
  int N, K;
  cin >> N >> K;
  for(int i=0; i<N; i++)
    cin >> arr[i];
  
  for(int i=N-1; 0<i; i--) {
    for(int j=0; j<i; j++) {
      if(arr[j] > arr[j+1]) {
        swap(j, j+1);
        K--;
        if(K==0){
          for(int w=0; w<N; w++)
            cout << arr[w] << " ";
          return 0;
        }
      }
    }
  }

  cout << -1;
}