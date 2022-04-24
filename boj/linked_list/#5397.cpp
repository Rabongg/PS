#include <iostream>
#include <list>

using namespace std;


void sync(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void solve(string password) {
  list<char> l;
	list<char>::iterator it;
  it = l.begin();

  for(int i=0; i<password.length(); i++) {
    if(password[i] == '<'){
      if(it != l.begin())
        it--;
    } else if(password[i] == '>') {
      if(it != l.end())
        it++;
    } else if(password[i] == '-') {
      if(it != l.begin())
        it = l.erase(--it);
    }
    else {
      l.insert(it, password[i]);
    }
  }
  for (it = l.begin(); it != l.end(); it++) 
    cout << *it;
	cout << '\n';
}

int main()
{
	sync();
	int T;
	string password;
	cin >> T;

  while(T--) {
    cin >> password;
    solve(password);
  }
}