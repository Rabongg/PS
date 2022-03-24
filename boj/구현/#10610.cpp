#include <iostream>
#include <string>

using namespace std;

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  int num[10]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  string s_num;
  sync();
  cin >> s_num;
  int sum_digit = 0;

  for(int i=0; i<s_num.length(); i++){
    num[s_num[i]-'0']++;
    sum_digit += s_num[i]-'0';
  }

  if (num[0] && sum_digit % 3 == 0){
    for(int i=9; 0<=i; i--) {
      while(num[i]) {
        cout << i;
        num[i]--;
      }
    }
  } else {
    cout << -1;
  }
}