#include <iostream>
#include <vector>

using namespace std;

int main() {
  int num, cnt, answer = 0;
  cin >> num;

  vector<int> arr(num+1, 0);
  vector<int> ord(num+1, 0);

  for(int i=1; i<=num; i++)
    cin >> arr[i];

  for(int i=1; i<=num; i++) {
    cnt = 0;
    for(int j=i-1; 0<=j; j--) {
      if(arr[i] <= arr[j])
        continue;
      cnt = cnt > ord[j] + 1 ? cnt : ord[j] + 1;
    }
    ord[i] = cnt;
    answer = answer > cnt ? answer : cnt;
  }

  cout << answer;
}