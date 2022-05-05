#include <iostream>
#include <stdlib.h>
#define MAX 500000
using namespace std;
int N;
int arr[MAX];
int comp[MAX];
int sorted_arr[MAX];

void compare(int idx) {
  for(int i=0; i<N; i++) {
    if(i<idx) {
      if(comp[i] != sorted_arr[i])
        return;
    } else {
      if(comp[i] != arr[i])
        return;
    }
  }
  cout << 1;
  exit(0);
}

void merge(int left, int mid, int right) {
  int i = left, j=mid+1, t=left;
  while(i<=mid && j<=right) {
    if(arr[i] < arr[j]) {
      sorted_arr[t++] = arr[i++];
      compare(t);
    } else {
      sorted_arr[t++] = arr[j++];
      compare(t);
    }
  }

  if(i > mid) {
    for(;j<=right; j++) {
      sorted_arr[t++] = arr[j];
      compare(t);
    }
  } else {
    for(;i<=mid; i++) {
      sorted_arr[t++] = arr[i];
      compare(t);
    }
  }

  for(t=left; t<=right; t++)
    arr[t] = sorted_arr[t];
}

void merge_sort(int left, int right) {

  if(left < right) {
    int mid = (left + right)/2;
    merge_sort(left, mid);
    merge_sort(mid+1, right);
    merge(left, mid, right);
  }
}

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  sync();
  cin >> N;
  for(int i=0; i<N; i++)
    cin >> arr[i];
  
  for(int i=0; i<N; i++)
    cin >> comp[i];

  merge_sort(0, N-1);

  cout << 0;
}