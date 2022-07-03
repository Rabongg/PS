#include <string>
#include <vector>
#include <queue>

using namespace std;

bool check(string a, string b) {
    
    int dif = 0;
    for(int i=0; i<a.length(); i++) {
        if(a[i] == b[i])
            continue;
        dif++;
        if(dif > 1)
            return false;
    }
    return true;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<bool> visited(words.size(), false);
    queue<pair<string, int>> q;
    q.push(make_pair(begin, 0));
    
    while(!q.empty()) {
        string word = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(word == target) {
            answer = cnt;
            return answer;
        }
        
        for(int i = 0; i<words.size(); i++) {
            if(visited[i] || !check(word, words[i]))
                continue;
            
            visited[i] = true;
            q.push(make_pair(words[i], cnt + 1));
        }
    }
    
    return answer;
}