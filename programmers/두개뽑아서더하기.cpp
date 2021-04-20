#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;


set<int> add_two(vector<int>n){
    
    set<int> s;

    for (int i = 0; i < n.size()-1; i++) {
        for (int j = i+1; j<n.size(); j++) {
            s.insert(n.at(i) + n.at(j));
        }
    }

    return s;

}


vector<int> solution(vector<int> numbers) {
    set<int> s = add_two(numbers);
    vector<int> answer;
    answer.assign(s.begin(), s.end());
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


