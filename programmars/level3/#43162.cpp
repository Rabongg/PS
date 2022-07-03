#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<bool> visited;

void network(int num, vector<vector<int>> computers) {
    queue<int> q;
    visited[num] = true;
    q.push(num);
    
    while(!q.empty()) {
        int n = q.front();
        q.pop();
        
        for(int i=0; i<computers[n].size(); i++) {
            if(visited[i] || computers[n][i] == 0)
                continue;
            visited[i] = true;
            q.push(i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    visited.resize(n, false);
        
    for(int i=0; i<n; i++) {
        if(visited[i])
            continue;
        network(i, computers);
        answer++;
    }
    return answer;
}