#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1000001
#define MAX_VALUE 30

using namespace std;

int arr[MAX];

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  int N;
  vector<int> answer;
  sync();
  cin >> N;

  fill(arr, arr+N, MAX_VALUE);

  for(int i = N; 1 < i; i--) {
    if(i % 3 == 0 && arr[i/3] > arr[i] + 1) {
      arr[i/3] = arr[i] + 1;
    }

    if(i % 2 == 0 && arr[i/2] > arr[i] + 1) {
      arr[i/2] = arr[i] + 1;
    }

    if(arr[i-1] > arr[i] + 1) {
      arr[i-1] = arr[i] + 1;
    }
  }

  int cnt = arr[1];
  int num = 1;
  cout << cnt << '\n';

  answer.reserve(cnt + 1);
  answer.push_back(num);
  while(cnt--) {
    if(num * 2 <= N && arr[num * 2] == cnt) {
      answer.push_back(num * 2);
      num *= 2;
    } else if(num * 3 <= N && arr[num * 3] == cnt) {
      answer.push_back(num * 3);
      num *= 3;
    } else {
      answer.push_back(++num);
    }
  }
  reverse(answer.begin(), answer.end());
  for(int i = 0; i < answer.size(); i++) {
    cout << answer[i] << " ";
  }
}