#include <iostream>
#include <queue>
#include <unordered_map>

#define MAX 500000
using namespace std;


int arr[MAX];
priority_queue<int> pq;
unordered_map<int, int> um;

void swap(int i, int j) {
  int tmp;
  um[arr[i]] = j;
  um[arr[j]] = i;
  tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

int main() {
  int N, K;
  
  cin >> N >> K;

  for(int i=0; i<N; i++) {
    cin >> arr[i];
    pq.push(arr[i]);
    um.insert(make_pair(arr[i], i));
  }

  for(int i=N-1; 0<i; i--) {
    int max_value = i;
    if(arr[max_value] != pq.top()) {
      swap(max_value, um[pq.top()]);
      K--;
      if(K == 0) {
        for(int i=0; i<N; i++)
          cout << arr[i] << " ";
        return 0;
      }
      pq.pop();
    } else {
      pq.pop();
    }
  }

  cout << -1;
}