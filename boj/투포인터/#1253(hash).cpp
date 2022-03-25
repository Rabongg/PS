#include <iostream>
#include <unordered_map>
#include <unordered_set>
#define MAX 2000
using namespace std;
unordered_map<int, int> umap;
unordered_set<int> uset;

int arr[MAX];
void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  sync();
  int num;
  int cnt = 0;
  cin >> num;
  for(int i=0; i<num; i++) {
    cin >> arr[i];
  }
  for(int i=0; i<num-1; i++) {
    for(int j=i+1; j<num; j++) {
      if(arr[i] != 0 && arr[j] != 0){
        uset.insert(arr[i]+arr[j]);
      } else {
        if(uset.find(arr[i]+arr[j]) == uset.end()) {
          if (arr[i] == 0){ 
            if(umap.find(arr[j]) != umap.end()){
              if(umap[arr[j]] != j)
                uset.insert(arr[j]);
            } else {
              umap[arr[j]] = j;
            }
          } else if (arr[j] == 0) {
            if(umap.find(arr[i]) != umap.end()){
              if(umap[arr[i]] != i)
                uset.insert(arr[i]);
            } else {
              umap[arr[i]] = i;
            }
          }
        }
      }
    }
  }

  for(int i=0; i<num; i++) {
    if(uset.find(arr[i]) != uset.end()) {
      cnt++;
    }
  }
  cout << cnt;
}