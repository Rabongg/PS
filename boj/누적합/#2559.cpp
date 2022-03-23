#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;


int arr[MAX];
void sync() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  sync();
  int day, section;
  int max_value = -10000000;
  cin >> day >> section;
  for(int i=1; i<=day; i++) {
    cin >> arr[i];
  }
  for(int i=1; i<=day; i++) {
    arr[i] += arr[i-1];
  }

  for(int i=section; i<=day; i++) {
    max_value = max(max_value, arr[i]-arr[i-section]);
  }
  cout << max_value;
}