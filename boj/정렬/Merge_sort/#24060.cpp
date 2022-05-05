#include <iostream>
#define MAX 500000

using namespace std;
int arr[MAX];
int sorted_arr[MAX];
int N, K;

void answer(int num) {
  K--;
  if(K==0)
    cout << num;
}

void merge(int left, int mid, int right) {

  int i = left, j = mid +1, t = left;
  while(i<=mid && j<=right) {
    if(arr[i] < arr[j]) {
      answer(arr[i]);
      sorted_arr[t++] = arr[i++];
    } else {
      answer(arr[j]);
      sorted_arr[t++] = arr[j++];
    }
  }

  if (j>right){
    for(; i<=mid; i++) {
      answer(arr[i]);
      sorted_arr[t++] = arr[i];
    }
  } else {
    for(; j<=right; j++) {
      answer(arr[j]);
      sorted_arr[t++] = arr[j];
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