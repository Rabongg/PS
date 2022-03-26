#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string s;
  cin >> s;
  int len = s.length();
  int min_length = len;
  
  for(int i=1; i<=len/2; i++) {
    string piece = s.substr(0, i);
    int cnt = 0, flag = 1;
    for(int j=i; j + i <=len; ) {

      if(piece == s.substr(j, i)) {
        cnt += i;
        flag++;
        if(j+i == len)
          cnt-= 1;
      } else {
        piece = s.substr(j, i);
        if(1 < flag && flag <10) {
          cnt -=1;
        } else if(10<= flag && flag <100) {
          cnt -=2;
        } else if(100<= flag && flag <1000) {
          cnt -=3;
        } else if(flag == 1000){
          cnt -=4;
        }
        flag = 1; 
      }

      j+=i;
    }
    min_length = min(min_length, len-cnt);
  }
  cout << min_length << '\n';
}