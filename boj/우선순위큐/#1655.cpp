#include <iostream>
#include <queue>
using namespace std;


// pq1 내림차순 pq2 오름차순
priority_queue<int> pq1;
priority_queue<int, vector<int>, greater<int> > pq2;


void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main() {
  int N, num, top;
  sync();
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> num;
    if(i==0) {
      pq1.push(num);
      cout << num << '\n';
    }
    else if(i==1) {
      top = pq1.top();
      if(top > num) {
        pq2.push(top);
        pq1.pop();
        pq1.push(num);
      } else {
        pq2.push(num);
      }
      cout << pq1.top() << '\n';
    } else {
      top = pq1.top();
      if(pq1.size() == pq2.size()){
        if(top >= num) {
          pq1.push(num);
          cout << top << '\n';
        } else {
          pq2.push(num);
          cout << pq2.top() << '\n';
        }
      } else if(pq1.size() > pq2.size()){
          if(top >= num) {
            pq2.push(top);
            pq1.pop();
            pq1.push(num);
          } else {
            pq2.push(num);
          }
          cout << pq1.top() << '\n';
        } else {
          if(top >= num) {
            pq1.push(num);
          } else {
            pq2.push(num);
            pq1.push(pq2.top());
            pq2.pop();
          }
          cout << pq1.top() << '\n';
        }
      }
    }
}