#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> custom;

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void solve() {
  int result = 1;
  unordered_map<string, int> :: iterator it;
  for(it = custom.begin(); it != custom.end(); it++) {
    result *= (it->second +1);
  }
  cout << result -1 << '\n';
}


int main() {
  sync();
  int T, custom_number;
  cin >> T;
  string cust, type;
  while(T--) {
    cin >> custom_number;
    for(int i=0; i<custom_number; i++) {
      cin >> cust >> type;
      custom[type]++;
    }
    solve();
    custom.clear();
  }
}