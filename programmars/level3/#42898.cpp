#include <string>
#include <vector>
#include <iostream>
#define MAX 101

using namespace std;

int road[MAX][MAX];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(int i=0; i<puddles.size(); i++)
        road[puddles[i][1]][puddles[i][0]] = -1;
    
    for(int i=1; i<=m; i++){
        if(road[1][i] == -1)
            break;
        road[1][i] = 1;
    }
    
    for(int i=1; i<=n; i++){
        if(road[i][1] == -1)
            break;
        road[i][1] = 1;
    }
    
    for(int i=2; i<=n; i++) {
        for(int j=2; j<=m; j++) {
            if(road[i][j] == -1)
                continue;
            road[i][j] = road[i][j-1] == -1 ? road[i-1][j] == -1 ? 0 : road[i-1][j] : road[i-1][j] == -1 ? road[i][j-1] : road[i][j-1] + road[i-1][j] ;
            
            if(road[i][j] >= 1000000007)
                road[i][j] %= 1000000007;
        }
    }

    answer = road[n][m];
    return answer;
}