#include <iostream>
#include <string>
#define MAX 1000001
using namespace std;

int arr[MAX];
long long cnt[1000];

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  sync();
  int N, M;
  long long answer = 0;
  cin >> N >> M;
  for(int i=1; i<=N; i++) {
    cin >> arr[i];
    arr[i] += arr[i-1];
    arr[i] = arr[i] >= M ? arr[i] % M : arr[i];
  }

  for(int i=1; i<=N; i++) {
    cnt[arr[i]]++;
  }

  for(int i=0; i<M; i++) {
    if (cnt[i] > 1)
      answer += (cnt[i] * (cnt[i] -1) ) / 2;
  }
  answer += cnt[0];
  cout << answer;
}