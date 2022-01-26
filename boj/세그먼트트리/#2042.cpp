#include <iostream>
#define PIV (1<<21)
using namespace std;
int N, M, K, T, G;
long long tree[PIV];


// a는 번째, b는 바꾸는 값 
void update(int a, long long b){

  a += G-1;
  tree[a] = b;
  while(a/=2){
    tree[a] = tree[a*2] + tree[a*2 +1]; 
  }
}

long long query(int left, int right){
  long long sum=0;

  left+=G-1, right+=G-1;

  while(left<=right){

    if(left%2==1) sum += tree[left++];
    if(right%2==0) sum+= tree[right--];

    left /= 2;
    right /= 2;
  }

  return sum;
}


void init(){

  int a;
  while(T/=2){
    a=T;
    for(a; a<2*T; a++)
      tree[a]=tree[2*a]+tree[2*a+1];
  }
}

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main(){
  sync();
  cin >> N >> M >> K;
  int a, b;
  long long c;
  G = 1;

  while(G<N){
    G=G<<1;
  }

  for(int i=0; i<N; i++){
    cin >> tree[G+i];
  }

  T=G;
  init();

  for(int i=0; i<M+K; i++){
    cin >> a >> b >> c;
    if(a==1)
      update(b, c);
    else 
      cout << query(b, c) << '\n';
  }
}