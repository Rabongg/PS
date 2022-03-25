#include <iostream>
#include <algorithm>
#define MAX 2000
using namespace std;


int arr[MAX];
void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  sync();
  int N;
  int ans = 0;
  cin >> N;
  for(int i=0; i<N; i++)
    cin >> arr[i];
  
  sort(arr, arr+N);
  for(int i=0; i<N; i++) {
    int target = arr[i];
    int left = 0, right = N-1;
    while(left < right) {
      int sum = arr[left] + arr[right];
      if(sum == target) {
        if(left != i && right != i) {
          ans++;
          break;
        }
        else {
          if(left == i)
            left++;
          else
            right--;
        }
      }
      else if(sum > target)
        right--;
      else
        left++;
    }
  }
  cout << ans;
}