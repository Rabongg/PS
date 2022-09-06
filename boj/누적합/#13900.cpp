#include <iostream>
#include <vector>
using namespace std;

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {

  sync();
  long long answer = 0;
  long long sum1 = 0;
  long long sum2 = 0;
  int N;
  cin >> N;
  vector<int> v(N);
  for(int i=0; i<N; i++)
    cin >> v[i];

  for(int i=0; i<N; i++) {
    sum1+=v[i];
    sum2+=v[i] * v[i];
  }

  answer = (sum1 * sum1 - sum2) / 2;
  cout << answer;
}