#include <iostream>
#define MAX 101
using namespace std;

int score_time[3] = {0,};
int teams[MAX];
string times[MAX];

void sync() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void calculateTime(int team, string before_time, string goal_time) {
  score_time[team] += (
    (goal_time[0] -'0')*10*60 + (goal_time[1] -'0')*60 + (goal_time[3] -'0')*10 + (goal_time[4] -'0') 
    - ((before_time[0] -'0')*10*60 + (before_time[1] -'0')*60 + (before_time[3] -'0')*10 + (before_time[4] -'0'))
  );
}


int main() {
  sync();
  int N;
  cin >> N;
  int team;
  string before_time;
  string goal_time;
  for(int i=1; i<=N; i++) {
    cin >> team >> goal_time;
    teams[i] = team == 1 ? 1 : -1;
    times[i] = goal_time;
  }
  for(int i=1; i<=N; i++){
    if(teams[i] + teams[i-1] == 0) {
      if(teams[i] == 1) {
        calculateTime(2, before_time, times[i]);
      } else {
        calculateTime(1, before_time, times[i]);
      }
      teams[i] += teams[i-1];
    } else if(teams[i-1] == 0){
      teams[i] += teams[i-1];
      before_time = times[i];
    } else {
      teams[i] += teams[i-1];
    }
  }

  if(teams[N] > 0)
    calculateTime(1, before_time, "48:00");
  else if(teams[N] <0)
    calculateTime(2, before_time, "48:00");
  
  cout << score_time[1]/600 << (score_time[1]%600)/60 << ":" << (score_time[1]%600)%60/10 << ((score_time[1]%600)%60)%10 << '\n';
  cout << score_time[2]/600 << (score_time[2]%600)/60 << ":" << (score_time[2]%600)%60/10 << ((score_time[2]%600)%60)%10 << '\n';
}