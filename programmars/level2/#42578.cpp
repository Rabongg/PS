#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> clothe;
    for(int i=0; i<clothes.size(); i++) {
        clothe[clothes[i][1]]++;
    }
    for(auto it = clothe.begin(); it != clothe.end(); it++) {
        answer *= (it->second + 1);
    }
    return answer - 1;
}