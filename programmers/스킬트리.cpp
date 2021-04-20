#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;


bool isRightSkillTree(map<char,int> tree, string source) {
    int count = 1;
    for(auto iter:source){
        if(tree[iter] > count) {
            return false;
        } else if (tree[iter] == count) {
            count += 1;
        }
    }   
    return true;

}

void creatSkillMap(map<char,int> &tree, string skill) {
    for(int i=0; i<skill.size(); i++) {
        tree.insert(pair<char,int>(skill[i],i+1));
    }
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char,int> tree;

    creatSkillMap(tree, skill);
    for(const auto iter:skill_trees) {
        answer += isRightSkillTree(tree, iter);
    }

    return answer;
}


int main() {
    string skill = "CBD";
    vector<string> skill_trees = {"BACDE", "CBADF", "AECB", "BDA"};

    int output = solution(skill, skill_trees);
    cout << output << " ";
    
    return 0;
}


