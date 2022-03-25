#include <iostream>
#include <algorithm>
#define MAX 5000
using namespace std;

int N;
int solution[MAX];
int result[3];
long long min_sum = 3000000000;
void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}


int main() {
  sync();
  cin >> N;
  for(int i=0; i<N; i++)
    cin >> solution[i];
  sort(solution, solution+N);
  for(int i=0; i<N-2; i++) {
    long long fix = solution[i];
    long long left = i+1;
    long long right = N-1;
    while(left < right) {
      long long sum = fix + solution[left] + solution[right];
      if (abs(sum) < min_sum) {
        min_sum = abs(sum);
        result[0] = fix;
        result[1] = solution[left];
        result[2] = solution[right];
      }

      if (sum < 0)
        left++;
      else
        right--;
    }
  }

  for(int i=0; i<3; i++)
    cout << result[i] << ' ';
}