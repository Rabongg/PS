#include <iostream>
#define MAX 10000

using namespace std;
int N;
int arr[MAX];

int main() {
  int K;
  cin >> N >> K;
  for(int i=0; i<N; i++) {
    cin >> arr[i];
  }

  // Insertion Sort
  for(int i=1; i<N; i++) {
    int num = arr[i];
    for(int j=i-1; 0<=j; j--) {
      if(arr[j] < num) {
        arr[j+1] = num;
        if(j!= i-1)
          K--;
        break;
      }

      arr[j+1] = arr[j];
      K--;

      if(K == 0) {
        cout << arr[j];
        return 0;
      }
      if(j==0) {
        arr[0] = num;
        K--;
        if(K == 0) {
          cout << arr[j];
          return 0;
        }
      }
    }
    if(K==0) {
      cout << num;
      return 0;
    }
  }

  cout << -1;
}