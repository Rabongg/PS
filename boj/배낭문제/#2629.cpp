#include <iostream>
#define MAX 40001

using namespace std;

int marble[8];
int weight[31];
bool DP[MAX]= {false, };

void sync () {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

// 추를 이용하여 잴 수 있는 무게 전부 계산하기
void setting(int weight_num ) {
  for(int i=1; i<=weight_num; i++){
    int w = weight[i];
    for(int j=MAX-1-w; 1<=j; j--) {
      if(DP[j])
        DP[j+w] = true;
    }
    DP[w] = true;
  }
}


char solve(int marble_weight) {
  for(int i=1; i< MAX; i++) {
    if(i+marble_weight<MAX) 
      if (DP[i] && DP[i+marble_weight])
        return 'Y';
    if(1<=i-marble_weight)
      if (DP[i] && DP[i-marble_weight])
        return 'Y';
  }
  return 'N';
}

int main () {
  sync();
  int marble_num, weight_num;
  cin >> weight_num;
  for(int i=1; i<=weight_num; i++)
    cin >> weight[i];
  cin >> marble_num;
  for(int i=1; i<=marble_num; i++)
    cin >> marble[i];
  
  setting(weight_num);
  for(int i=1; i<=marble_num; i++){
    if(DP[marble[i]])
      cout << 'Y' << ' ';
    else
      cout << solve(marble[i]) << ' ';
  }
}