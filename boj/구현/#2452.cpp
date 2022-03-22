#include <iostream>
#define MAX 1000001
using namespace std;

int A[MAX];
int result[MAX];
void sync() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  sync();
  int N;
  cin >> N;
  for(int i=1; i<=N; i++)
    cin >> A[i];
  
  result[N]=-1;
  for(int i=N-1; 1<=i; i--){
    if(A[i] == A[i+1])
      result[i] = result[i+1];
    else
      result[i] = i+1;
  }

  for(int i=1; i<=N; i++)
    cout << result[i] << " ";
}