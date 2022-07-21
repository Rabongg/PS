#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int cnt[3] = {0, };
    int fir[5] = {1, 2, 3, 4, 5};
    int sec[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int thi[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int max_cnt = 0;

    for(int i = 0; i<answers.size(); i++) {
        if(fir[i % 5] == answers[i]) cnt[0]++;
        if(sec[i % 8] == answers[i]) cnt[1]++;
        if(thi[i % 10] == answers[i]) cnt[2]++;
        
        max_cnt = max_cnt > cnt[0] ? max_cnt : cnt[0];
        max_cnt = max_cnt > cnt[1] ? max_cnt : cnt[1];
        max_cnt = max_cnt > cnt[2] ? max_cnt : cnt[2];
    }
    
    for(int i=0; i<3; i++)
        if(max_cnt == cnt[i])
            answer.push_back(i+1);
    
    return answer;
}