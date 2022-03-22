#include <iostream>
#include <string>

using namespace std;


void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  sync();
  string sentence;
  int cnt = 0;
  int flag = 0;
  getline(cin, sentence);
  for(int i=0; i<sentence.length(); i++) {
    if(sentence[i]!=' ' && flag == 0) {
      cnt++;
      flag=1;
    } else if(sentence[i]==' ') {
      flag=0;
    }
  }
  cout << cnt;
}