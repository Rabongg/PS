#include <iostream>
#define MAX 10000
using namespace std;
int arr[MAX];

void swap(int i, int j) {
  int tmp;
  tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

void print_arr(int N) {
  for(int i=0; i<N; i++)
    cout << arr[i] << " ";
}

int main() {
  int N, K;
  
  cin >> N >> K;

  for(int i=0; i<N; i++) {
    cin >> arr[i];
  }

  for(int i=N-1; 0<i; i--) {
    int max_val = i;
    for(int j=i-1; 0<=j; j--) {
      if(arr[max_val] < arr[j]) {
        max_val = j;
      }
    }
    if (max_val != i) {
      swap(i, max_val);
      if(--K == 0) {
        print_arr(N);
        return 0;
      }
    }
  }

  cout << -1;
}