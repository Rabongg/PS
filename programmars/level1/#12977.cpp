#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

vector<bool> p_number;

void checkP(int num) {
    int lim = (int) sqrt(num);
    
    for(int i=2; i<=lim; i++) {
        if(p_number[i])
            continue;
        for(int j = i+i; j<=num;) {
            p_number[j] = true;
            j+=i;
        }
    }
}

int solution(vector<int> nums) {
    int answer = 0;
    sort(nums.rbegin(), nums.rend());
        
    p_number.resize(nums[0]+nums[1]+nums[2]+1, false);

    checkP(nums[0] + nums[1] + nums[2]);
        
    
    for(int i=0; i<nums.size()-2; i++)
        for(int j=i+1; j<nums.size()-1; j++)
            for(int k=j+1; k<nums.size(); k++)
                if(!p_number[nums[i]+nums[j]+nums[k]])
                    answer++;


    return answer;
}