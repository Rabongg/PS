#include <iostream>
#include <map>

using namespace std;

struct TRIE {
  map<string, TRIE *> food;
  bool isFinish;
  
  TRIE() {
    isFinish = false;
  }

  void Insert(int len, string keyword[], int cnt) {
    if(len == cnt) {
      isFinish = true;
      return;
    }
    
    if(food.find(keyword[len]) == food.end())
      food[keyword[len]] = new TRIE();
    food[keyword[len]] -> Insert(len+1, keyword, cnt);
  }

  void Find(int depth) {
    if (isFinish)
      return;

    for(auto iter = food.begin(); iter!=food.end(); iter++) {
      for(int i=0; i<depth; i++)
        cout << '-';
      cout << iter -> first << '\n';
      iter -> second -> Find(depth+2);
    }
  }
};


int main() {
  int N, K, t;
  cin >> N;
  TRIE trie;
  for(int i=0; i<N; i++) {
    cin >> K;
    string *data = new string[K];
    for(int j=0; j<K; j++) {
      cin >> data[j];
    }
    trie.Insert(0, data, K);
    delete[] data;
  }

  trie.Find(0);
}
