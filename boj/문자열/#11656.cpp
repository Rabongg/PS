#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
string sentence;
vector<string> v;

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void solve() {
  int len = sentence.length();
  for(int i=0; i<len; i++){
    v.push_back(sentence.substr(i, len));
  }
}

int main() {
  sync();
  cin >> sentence;
  solve();
  sort(v.begin(), v.end());
  for(int i=0; i<v.size(); i++)
    cout << v[i] << '\n';

}