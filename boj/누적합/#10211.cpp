#include <iostream>
#define MAX 1000

using namespace std;
int arr[MAX];
int tmp[MAX];

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void solve(int N) {
  int max_value = arr[0];
  tmp[0] = arr[0];
  for (int i=1; i<N; i++) {
    tmp[i] = arr[i] > arr[i] + tmp[i-1] ? arr[i] : arr[i] + tmp[i-1];
    max_value = max_value > tmp[i] ? max_value : tmp[i];
  }
  cout << max_value << '\n';
}

int main() {
  sync();
  int T, N;
  cin >> T;
  while (T--)
  {
    cin >> N;
    for(int i=0; i<N; i++) {
      cin >> arr[i];
    }
    solve(N);
  }
}