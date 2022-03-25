#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#define MAX 1000000
using namespace std;

int order[MAX];
string bomb, sentence;
stack<pair<char, int> > s;
stack<pair<char, int> > temp;

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  sync();
  cin >> sentence >> bomb;
  for(int i=0; i < sentence.length(); i++){
    for(int j=0; j < bomb.length(); j++){
      if(sentence[i] == bomb[j]){
        order[i] = j + 1;
        break;
      }
    }
  }

  for(int i=0; i<sentence.length(); i++){
    int len = bomb.length();
    if(order[i] == len){
      len--;
      while(!s.empty() && len) {
        if (s.top().second == len) {
          temp.push(make_pair(s.top().first, s.top().second));
          s.pop();
        } else {
          break;
        }
        len--;
      }

      if (len) {
        while(!temp.empty()){
          s.push(make_pair(temp.top().first, temp.top().second));
          temp.pop();
        }
        s.push(make_pair(sentence[i], order[i]));
      } else {
        while(!temp.empty()) {
          temp.pop();
        }
      }
    } else {
      s.push(make_pair(sentence[i], order[i]));
    }
  }
  if(s.empty())
    cout << "FRULA";
  else {
    string result = "";
    while(!s.empty()){
      result += s.top().first;
      s.pop();
    }
    reverse(result.begin(), result.end());
    cout << result;
  }
}