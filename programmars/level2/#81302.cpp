#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

bool BFS(vector<string> place, int x, int y) {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int cnt[5][5] = {0};
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    cnt[x][y] = 1;
    while(!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        
        if(cnt[nx][ny] >2)
            break;
        
        for(int i=0; i<4; i++) {
            int px = nx + dx[i];
            int py = ny + dy[i];
            
            if(px < 0 || py < 0 || 5 <= px || 5 <= py || cnt[px][py] || place[px][py] == 'X')
                continue;
            
            if(place[px][py] == 'P')
                return false;
            
            cnt[px][py] = cnt[nx][ny] + 1;
            q.push(make_pair(px, py));
        }
        
    }
    return true;
}


bool check_distance(int index, vector<vector<string> > places) {
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++) {
            if(places[index][i][j] != 'P')
                continue;
            else if (!BFS(places[index], i, j))
                return false;
        }
    }
    return true;
}


vector<int> solution(vector<vector<string> > places) {
    vector<int> answer;
    for(int i=0; i<places.size(); i++) {
        answer.push_back(check_distance(i, places));
    }
    
    return answer;
}