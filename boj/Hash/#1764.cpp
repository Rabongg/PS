#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;
unordered_map <string, int> dict;
vector<string> result;

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  int N, M;
  string name;
  cin >> N >> M;
  for(int i=0; i<N+M; i++) {
    cin >> name;
    dict[name]++;
    if(dict[name] > 1)
      result.push_back(name);
  }
  cout << result.size() << '\n';
  sort(result.begin(), result.end());
  for(int i = 0; i< result.size(); i++)
    cout << result[i] << '\n';
}