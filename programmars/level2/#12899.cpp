#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    while(n > 0) {
        if(n % 3 == 0) {
            answer = "4" + answer;
            n = (n / 3) - 1;
        } else if( n % 3 == 1) {
            answer = "1" + answer;
            n = n / 3;
        } else {
            answer = "2" + answer;
            n = n / 3;
        }
    }

    return answer;
}