#include <iostream>
#include <map>
using namespace std;

map<string, double> trees;
void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  sync();
  int total=0;
  string tree;
  while(1) {
    getline(cin, tree);
    if(cin.eof() || tree =="\n") break;
    trees[tree]++;
    total++;
  }
  map<string, double> :: iterator it;
  cout << fixed;
  cout.precision(4);
  for(it=trees.begin(); it!=trees.end(); it++) {
    cout << it->first << " " << (it->second /total)*100 << '\n';
  }
}