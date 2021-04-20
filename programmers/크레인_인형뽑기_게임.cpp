#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;


int get_popped_doll(stack <int> &s, int grabbed) {
    if(!s.empty() && s.top() == grabbed) {
        s.pop();
        return 2;
    } else {
        s.push(grabbed);
    }
    return 0;
}

int drop_crain(vector<vector<int>> &board, int trail) {
    int grab = 0;

    for(int i=0; i < board.size(); i++) {
        if (board[i][trail-1] != 0) {
            grab = board[i][trail-1];
            board[i][trail-1] = 0;
            break;
        }
    }
    
    return grab; 
}


int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int grabbed = 0;
    stack <int> s;

    for(const auto iter:moves) {
        grabbed = drop_crain(board, iter);
        if (grabbed) {
            answer += get_popped_doll(s, grabbed);
        }
        
    }

    return answer;
}


int main() {
    vector<vector<int>> board;
    vector<int> moves;
    int output;

    board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    moves = {1,5,3,5,1,2,1,4};

    output = solution(board, moves);
    cout << "output : " << output << " ";

    return 0;
}



// moves가 많아지면 비효율적일 듯 -> 초기화 할 때 열 하나씩 vector로 변환해서 drop_crain할 때 pop_back으로 바로 꺼내서 사용하면 더 효율 적일 듯.
