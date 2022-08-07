#include <iostream>
#include <algorithm>

using namespace std;

int check_palindrome(int start, int end, string word, int flag) {
  for(; start<end; start++) {
    if(word[start] != word[end]) {
      if(flag)
        return 2;
      return min(check_palindrome(start+1, end, word, 1), check_palindrome(start, end-1, word, 1));
    }
    end--;
  }
  return flag ? 1 : 0;
}
int main() {
  int num;
  string word;

  cin >> num;
  for(int i=0; i<num; i++) {
    cin >> word;
    cout << check_palindrome(0, word.length()-1, word, 0) << '\n';
  }
}