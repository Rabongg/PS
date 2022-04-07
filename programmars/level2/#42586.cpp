#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<int> days;
    vector<int> answer;
    for(int i=0; i<progresses.size(); i++) {
        int progress = progresses[i];
        int speed = speeds[i];
        int day = 0;
        while(progress + speed * day < 100) day++;
        days.push(day);
    }
    
    while(!days.empty()) {
        int dur = days.front();
        days.pop();
        int cnt = 1;
        
        if(days.front() > dur) answer.push_back(cnt);
        else {
            while(!days.empty() && days.front() <= dur) {
                days.pop();
                cnt++;
            }
            answer.push_back(cnt);
        }
    }
    return answer;
}