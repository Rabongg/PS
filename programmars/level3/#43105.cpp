#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    for(int i=1; i<triangle.size(); i++) {
        for(int j=0; j<=i; j++) {
            if(j==0) {
                triangle[i][j] += triangle[i-1][j];
            } else if(j==i) {
                triangle[i][j] += triangle[i-1][j-1];
            } else {
                triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
    }    
    for(int i=0; i<triangle.size(); i++) {
        answer = max(answer, triangle[triangle.size()-1][i]);
    }
    return answer;
}