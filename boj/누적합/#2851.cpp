#include <iostream>
#include <cstdlib>
using namespace std;


int arr[10];
void sync() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  sync();
  int answer = 0;
  int interval;

  for(int i=0; i<10; i++)
    cin >> arr[i];

  interval = abs(100-arr[0]);
  answer = arr[0];
  for(int i=1; i<10; i++) {
    arr[i] +=arr[i-1];
    if(interval >= abs(arr[i]-100)) {
      interval = abs(arr[i]-100);
      answer = arr[i];
    }
  }
  cout << answer;
}