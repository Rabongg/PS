#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

bool check_visited[20] = {false, };
unordered_map<string, int> ma;
int max_course[11] = {0, };


void init() {
    for(int i=0; i<20; i++)
        check_visited[i] = false;
}


void backTracking(vector<char> order, string ps, int cnt, int target) {
    if(cnt == target) {
        if(ma.find(ps) != ma.end())
            ma[ps]++;
        else
            ma.insert({ps, 1});
        
        max_course[target] = max_course[target] > ma[ps] ? max_course[target] : ma[ps];
        return;
    }
    
    for(int i=0; i < order.size(); i++) {
        if(!check_visited[i] && (ps == "" || order[i] > ps[ps.length()-1])) {
            check_visited[i] = true;
            backTracking(order, ps + order[i], cnt+1, target);
            check_visited[i] = false;
        }
    }
}

void searchCourse(string s, vector<int> course) {
    vector<char> order;
    for(int i=0; i<s.length(); i++)
        order.push_back(s[i]);
    
    sort(order.begin(), order.end());
    
    for(int i=0; i<course.size(); i++){
        init();
        backTracking(order, "", 0, course[i]);
    }
}


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(int i = 0; i < orders.size(); i++) {
        searchCourse(orders[i], course);
    }
    
    for(int i=0; i<course.size(); i++) {
        int course_max = max_course[course[i]];
        if(course_max > 1){
            for (const auto& [key, value]: ma) {
                if(key.length() == course[i] && value == course_max)
                    answer.push_back(key);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}