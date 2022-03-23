#include <iostream>
#include <string>
#define MAX 26
using namespace std;
int cnt[MAX];

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  sync();
  string gift, beauty;
  cin >> gift >> beauty;

  for(int i=0; i<gift.size(); i++){
    for(int j=0; j<beauty.size(); j++){
      if(gift[i] == beauty[j])
        cnt[j] = j == 0 ? cnt[j]+ 1 : cnt[j-1] > cnt[j] ? cnt[j]+1 : cnt[j];
    }
  }

  cout << cnt[beauty.size()-1];
}