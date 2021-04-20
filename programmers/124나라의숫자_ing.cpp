#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int getTernary(int n, stack<int> &s) {
    int q = n/3;
    int r = n%3;
    s.push(r);
    return q ? getTernary(q,s) : 0;
}

string toOneTowFour(stack<int> s) {
    string answer = "";
    
    while(!s.empty())
    {   
        int second = -1;
        int first = s.top();

        s.pop();

        if(!s.empty()) {second = s.top();}
        
        if(second == 0) {
            s.pop();
            answer +=  to_string(4);
        } else {
            answer +=  to_string(first);
        }
    }
    return answer;
}

string solution(int n) {
    string answer = "";
    stack<int> s;
    
    getTernary(n, s);
    while(!s.empty())
    {
        int w = s.top();
        std::cout << w;
        s.pop();
    }
    answer = toOneTowFour(s);
    return answer;
}


int main() {
    string output;
    int input = 6;

    output = solution(input);
    cout << output << " ";

    return 0;
}


