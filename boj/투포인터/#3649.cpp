#include <iostream>
#include <algorithm>

#define MAX 1000000
using namespace std;

int lego[MAX];
void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void solve(int hole, int lego_num) {
  int left = 0, right = lego_num-1;
  while(left < right) {
    int sum = lego[left] + lego[right];
    if (sum == hole * 10000000) {
      cout << "yes " << lego[left] << ' ' << lego[right] << '\n';
      return;
    }

    if(sum >hole * 10000000)
      right--;
    else
      left++;
  }

  cout << "danger" << '\n';
}

int main() {
  sync();
  int x;
  int lego_num;
  while(1) {
    cin >> x >> lego_num;
    if(cin.eof())
      break;
    for(int i=0; i<lego_num; i++)
      cin >> lego[i];
    sort(lego, lego+lego_num);
    solve(x, lego_num);
  }
}