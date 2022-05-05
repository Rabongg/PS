#include <iostream>
#include <stdlib.h>
#define MAX 500000

using namespace std;
int arr[MAX];
int sorted_arr[MAX];
int N, K;

void change(int num, int idx) {
  K--;
  int i;
  sorted_arr[idx] = num;
  if(K==0){
    for(int i=0; i<N; i++) {
      if(i <=idx)
        cout << sorted_arr[i] << " ";
      else
        cout << arr[i] << " ";
    }
    exit(0);
  }
}

void merge(int left, int mid, int right) {

  int i = left, j = mid +1, t = left;
  while(i<=mid && j<=right) {
    if(arr[i] < arr[j]) {
      change(arr[i], t);
      i++;
    } else {
      change(arr[j], t);
      j++;
    }
    t++;
  }

  if (j>right){
    for(; i<=mid; i++) {
      change(arr[i], t);
      t++;
    }
  } else {
    for(; j<=right; j++) {
      change(arr[j], t);
      t++;
    }
  }

  for(i=left; i<=right; i++)
    arr[i] = sorted_arr[i];
}

void merge_sort(int left, int right) {

  if(left < right) {
    int mid = (left +right) / 2;
    merge_sort(left, mid);
    merge_sort(mid+1, right);
    merge(left, mid, right);
  }
}

int main() {
  cin >> N >> K;
  for(int i=0; i<N; i++)
    cin >> arr[i];
  
  merge_sort(0, N-1);

  if(K>0)
    cout << -1;
}