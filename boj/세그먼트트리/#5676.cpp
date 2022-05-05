#include <iostream>
#define MAX (1<<18)
using namespace std;

int arr[MAX];
int N, K, H, G;

void sync() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

// 변경
void update(int node, int num) {
  node += (H-1);
  num = num > 0 ? 1: num == 0 ? 0 : -1;
  arr[node] = num;
  while(node/=2)  arr[node] = arr[node*2] * arr[node*2+1];
}

// 초기화
void init() {
  int a;
  while(G/=2) {
    a = G;
    for(a; a<2*G; a++)
      arr[a] = arr[2*a] * arr[2*a+1];
  }
}

// 쿼리
void query(int left, int right) {
  int result = 1;
  left += (H-1);
  right += (H-1);
  while(left<=right) {
    if(left%2==1) result *= arr[left++];
    if(right%2==0) result *= arr[right--];

    if(result == 0){
      break;
    }

    left /= 2;
    right /= 2;
  }

  if(result > 0)
    cout << '+';
  else if(result == 0) {
    cout << '0';
  } else {
    cout << '-';
  }
}


int main() {
  int num, num1, num2;
  char cmd;
  sync();
  while(cin >> N >> K) {
    G = 1;
    while(G < N)  G<<=1;

    H = G;

    for(int i=0; i<N; i++){
      cin >> num;
      num = num > 0 ? 1: num == 0 ? 0 : -1;
      arr[G+i] = num;
    }
    
    for(int i=N; i<G; i++)
      arr[G+i] = 1;
    
    init();
    for(int i=0; i<K; i++){
      cin >> cmd >> num1 >> num2;
      if(cmd == 'C')
        update(num1, num2);
      else {
        query(num1, num2);
      }
    }
    cout << '\n';
  }
}