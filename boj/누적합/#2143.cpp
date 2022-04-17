#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1001

using namespace std;

int A[MAX];
int B[MAX];
vector<int> A_sum;
vector<int> B_sum;

void sync() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void getAllSum(int n, int m) {
  for(int i=1; i<=n; i++) {
    for(int j=i; j<=n; j++) {
      A_sum.push_back(A[j]-A[j-i]);
    }
  }

  for(int i=1; i<=m; i++) {
    for(int j=i; j<=m; j++) {
      B_sum.push_back(B[j]-B[j-i]);
    }
  }
}


int main() {
  sync();
  int T, n, m;
  long long cnt = 0;
  cin >> T;
  cin >> n;
  for(int i=1; i<=n; i++) {
    cin >> A[i];
    A[i] += A[i-1];
  }
  cin >> m;
  for(int i=1; i<=m; i++) {
    cin >> B[i];
    B[i] += B[i-1];
  }

  getAllSum(n, m);

  // sort
  sort(B_sum.begin(), B_sum.end());

  for(int i=0; i<A_sum.size(); i++) {
    cnt += (
      (upper_bound(B_sum.begin(), B_sum.end(), T-A_sum[i]) - B_sum.begin()) - 
      (lower_bound(B_sum.begin(), B_sum.end(), T-A_sum[i]) - B_sum.begin())
    );
  }

  cout << cnt;
}