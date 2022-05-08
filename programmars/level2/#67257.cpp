#include <string>
#include <vector>
#include <cstdlib>
#include <array>


using namespace std;

vector<long long> num;
vector<char> oper;
long long answer = 0;

void solve(array<char, 3> op) {
    vector<long long> temp_num = num;
    vector<char> temp_oper = oper; 

    for(int i=0; i<3; i++) {
        for(int j =0; j< temp_oper.size(); j++) {
            if(op[i] == temp_oper[j]) {
                if(op[i] == '*') {
                    temp_num[j] *= temp_num[j+1];
                } else if(op[i] == '-') {
                    temp_num[j] -= temp_num[j+1];
                } else {
                    temp_num[j] += temp_num[j+1];
                }
                temp_num.erase(temp_num.begin() + j+1);
                temp_oper.erase(temp_oper.begin() + j);
                j--;
            }
        }
    }
    answer = answer > abs(temp_num[0]) ? answer : abs(temp_num[0]);
    temp_oper.clear();
    temp_num.clear();
}

long long solution(string expression) {
    string number = "";
    // * - +
    array<array<char, 3>, 6> arr = {
        '*', '-', '+', '*', '+', '-', '-', '*', '+', '-', '+', '*', '+', '*', '-', '+', '-', '*'
    };
    for(int i=0; i<expression.length(); i++) {
        if(expression[i] == '*' || expression[i] == '-' || expression[i] == '+') {
            num.push_back(stoull(number));
            oper.push_back(expression[i]);
            number = "";
        } else {
            number += expression[i];
        }
    }
    
    num.push_back(stoull(number));
    for(int i=0; i<6; i++)
        solve(arr[i]);
    return answer;
}