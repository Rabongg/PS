#include <iostream>

using namespace std;

// 나머지를 저장해 놓는 배열
long long rest[33];
int A, B, C;
void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void solve() {
  long long result = 1;
  int digit = 1;
  rest[1] = A >= C ? A%C : A;
  for(int i=2; i<=32; i++){
    rest[i] = rest[i-1] * rest[i-1];
    rest[i] = rest[i] >=C ? rest[i]%C : rest[i];
  }
  while(B) {
    int bit = B & 1;
    result = bit ? result * rest[digit] : result;
    result = result >= C ? result%C : result;
    digit++;
    B = B >> 1;
  }
  cout << result << '\n';
}

// AxB % C = ((A%C) x (B%C)) %C 
int main() {
  sync();
  cin >> A >> B >> C;

  solve();
}