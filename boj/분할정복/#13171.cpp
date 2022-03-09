#include <iostream>
#define LIMIT 1000000007
using namespace std;

long long  rest[64];
long long A, X;

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void solve() {
  long long result = 1;
  int digit = 1;
  rest[1] = A >= LIMIT ? A%LIMIT : A;
  for(int i=2; i<64; i++){
    long long num = rest[i-1] * rest[i-1];
    rest[i] = num >= LIMIT ? num%LIMIT : num;
  }

  while(X) {
    int bit = X & 1;
    if(bit)
      result *= rest[digit];

    if(result >=LIMIT)
      result %= LIMIT;
    X = X >> 1;
    digit++;
  }

  cout << result << '\n';
}

int main() {
  sync();
  cin >> A >> X;
  solve();
}