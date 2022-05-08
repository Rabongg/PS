#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

vector<pair<int, int> > pos = {
  make_pair(3, 1), make_pair(0, 0), make_pair(0, 1), make_pair(0, 2),
  make_pair(1, 0), make_pair(1, 1), make_pair(1, 2),
  make_pair(2, 0), make_pair(2, 1), make_pair(2, 2)
};
pair<int, int> left = make_pair(3, 0);
pair<int, int> right = make_pair(3, 2);


char check_distance(int num, string hand) {
    char result;
    if(abs(pos[num].first - left.first) + abs(pos[num].second - left.second) > 
      abs(pos[num].first - right.first) + abs(pos[num].second - right.second)) {
        right = pos[num];
        result = 'R';
    } else if (abs(pos[num].first - left.first) + abs(pos[num].second - left.second) == 
      abs(pos[num].first - right.first) + abs(pos[num].second - right.second)){
        if (hand == "right") {
            right = pos[num];
            result = 'R';
        } else {
            left = pos[num];
            result = 'L';
        }
    } else {
        left = pos[num];
        result = 'L';
    }
    return result;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    for(int i=0; i< numbers.size(); i++) {
        if(numbers[i] % 3 == 1) {
            answer += 'L';
            left = pos[numbers[i]];
        } else if(numbers[i] != 0 && numbers[i] % 3 == 0) {
            answer += 'R';
            right = pos[numbers[i]];
        } else {
            answer += check_distance(numbers[i], hand);
        }
    }
    return answer;
}