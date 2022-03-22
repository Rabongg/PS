#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> S;

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  int A, B;
  int elem;
  cin >> A >> B;
  for(int i=0; i<A; i++) {
    cin >> elem;
    S.insert(elem);
  }

  for(int i=0; i<B; i++) {
    cin >> elem;
    if(S.find(elem) != S.end()) {
      S.erase(elem);
    } else {
      S.insert(elem);
    }
  }

  cout << S.size() << endl;
}
