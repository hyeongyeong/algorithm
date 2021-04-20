#include <string>
#include <vector>
#include <iostream>

using namespace std;


vector<int> solution(vector<int> numbers) {
    vector<int> answer = numbers;
    return answer;
}


int main() {
    vector<int>input, output;
    input = {2,1,3,4,1};


    output = solution(input);
    for(const auto itr:output) { 
        cout << itr << " ";
    }

    return 0;
}


