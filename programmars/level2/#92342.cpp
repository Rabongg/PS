#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> answer;
vector<int> tmp(11);
int target[11] = {0, };
int diff = 0;

void backTracking(int n, int index) {
    if(n == 0) {
        int lion_score = 0, apeach_score = 0;
        for(int i = 0; i<11; i++) {
            if(tmp[i])
                lion_score += (10-i);
            else if (target[i] > 1)
                apeach_score += (10-i);
        }
        
        if(diff < lion_score - apeach_score) {
            diff = lion_score - apeach_score;
            answer = tmp;
        } else if(diff > 0 && (lion_score - apeach_score) == diff) {
            for(int i = 10; 0 <= i; i--) {
                if(answer[i] > tmp[i])
                    return;
                else if(answer[i] < tmp[i])
                    break;
            }
            answer = tmp;
        }
        return;
    }
    
    for(int i = index; i < 11; i++) {
        if(n >= target[i]) {
            tmp[i] = i == 10 ? n : target[i];
            backTracking(n - tmp[i], i + 1);
            tmp[i] = 0;
        }
    }
}


vector<int> solution(int n, vector<int> info) {
    for(int i = 0; i < info.size(); i++) {
        target[i] = info[i] + 1;
    }
    target[10] = 0;
    
    backTracking(n, 0);

    if (answer.empty())
        answer.push_back(-1);
    return answer;
}