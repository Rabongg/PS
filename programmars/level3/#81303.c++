#include <string>
#include <vector>
#include <stack>


using namespace std;

struct Node {
    int idx;
    Node * prev;
    Node * next;
    
    Node(int index) {
        idx = index;
        prev = NULL;
        next = NULL;
    }
};

int find_step(string cmd) {
    string temp = "";
    for(int i=2; i<cmd.length(); i++)
        temp+=cmd[i];
    
    return stoi(temp);
}


string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'O');
    stack<int> dummy;
    vector<Node *> link;
    int step;

    // 초기 linked_list 세팅
    for(int i=0; i<n; i++)  link.push_back(new Node(i));

    for(int i=0; i<n-1; i++) {
        link[i] -> next = link[i+1];
        link[i+1] -> prev = link[i];
    }
    
    
    
    for(int i=0; i<cmd.size(); i++) {
        if(cmd[i][0] == 'C') {
            if(link[k] -> next == NULL) {
                link[k] -> prev -> next = NULL;
                dummy.push(k);
                answer[k] = 'X';
                k = link[k] -> prev -> idx;
            } else if(link[k] -> prev == NULL) {
                link[k] -> next -> prev = NULL;
                dummy.push(k);
                answer[k] = 'X';
                k = link[k] -> next -> idx;
            } else {
                link[k] -> prev -> next = link[k] -> next;
                link[k] -> next -> prev = link[k] -> prev;
                dummy.push(k);
                answer[k] = 'X';
                k = link[k] -> next -> idx;
            }
        } else if(cmd[i][0] == 'Z') {
            int alive = dummy.top();
            dummy.pop();
            answer[alive] = 'O';
            if(link[alive] -> prev != NULL)
                link[alive] -> prev -> next = link[alive];
            if(link[alive] -> next != NULL)
                link[alive] -> next -> prev = link[alive];
        } else if(cmd[i][0] == 'U') {
            step = find_step(cmd[i]);
            while(step--)   k = link[k] -> prev -> idx;
        } else {
            step = find_step(cmd[i]);
            while(step--)   k = link[k] -> next -> idx;
        }
    }
    
    return answer;
}