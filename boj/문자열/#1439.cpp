#include <iostream>

using namespace std;

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  sync();
  string sentence;
  cin >> sentence;
  char c = sentence[0];
  int cnt = 0;
  for(int i=1; i<sentence.length(); i++){
    if(c == sentence[i])
      continue;
    cnt++;
    c = sentence[i];
  }

  cnt = cnt % 2 == 0 ? cnt/2 : (cnt/2) + 1;
  cout << cnt;
}