#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for(int i=left; i<=right; i++)
        answer = ceil(sqrt(i)) == floor(sqrt(i)) ? answer - i : answer + i;
    return answer;
}