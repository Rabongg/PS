#include <iostream>
#include <string>

using namespace std;


struct TRIE {
  bool isFinish;
  TRIE *Node[10];

  TRIE() 
  {
    isFinish = false;
    for(int i=0; i<10; i++)
      Node[i] = NULL;
  }

  void Insert(char * keyword) {
    if(*keyword == '\0'){
      isFinish = true;
      return;
    }
    
    int num = *keyword - '0';
    if(Node[num] == NULL)
      Node[num] = new TRIE();
    Node[num] -> Insert(keyword + 1);
  }

  bool Find(char * keyword) {
    
    if(*keyword == '\0' || isFinish){
      return true;
    }

    int num = *keyword - '0';
    if(Node[num] == NULL){
      return false;
    }
    return Node[num] -> Find(keyword+1);
  }
};


void sync() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  int T, N;
  sync();
  cin >> T;
  while(T--) {
    TRIE trie;
    int flag = 0;
    char phone_num[11];
    cin >> N;
    for(int i=0; i<N; i++){
      cin >> phone_num;
      if(!flag && !trie.Find(phone_num)){
        trie.Insert(phone_num);
      }
      else{
        flag = 1;
      }
    }
    if(flag)
      cout << "NO" << '\n';
    else cout << "YES" << '\n';
  }
}