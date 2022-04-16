#include <iostream>
#include <string>
#define MAX 100000
using namespace std;

int prefix_sum[MAX];

int main() {
  string word;
  cin >> word;
  prefix_sum[0] = word[0] == 'S' ? 2 : word[0] == 'K' ? -1 : 0;
  for(int i=1; i<word.length(); i++) {
    prefix_sum[i] = prefix_sum[i-1] + (word[i] == 'S' ? 2 : word[i] == 'K' ? -1 : 0);
  }

  for(int i=0; i<word.length(); i++)
    cout << prefix_sum[i] << " ";
}