#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<string> sentences;

void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  sync();
  int N, M;
  int cnt = 0;
  string sentence;
  cin >> N >> M;
  for(int i=0; i<N; i++){
    cin >> sentence;
    sentences.insert(sentence);
  }
  for(int i=0; i<M; i++){
    cin >> sentence;
    if(sentences.find(sentence) != sentences.end())
      cnt++;
  }
  cout << cnt;
}