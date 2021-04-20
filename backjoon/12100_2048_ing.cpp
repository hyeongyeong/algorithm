#include<iostream>
#include<algorithm>


using namespace std;

// 상하좌우
const int dy[4] = {-1,1,0,0};
const int dx[4] = {0,0,-1,1};

const int MAX_TRY = 5;


int N;
char MAP[20][20];
int answer;


/*
    # 1 배열 통째로 돌리고 바꾸는 함수 + 오른쪽에서 왼쪽으로 미는 함수 만들기
    # 2 4가지 배열에 대해 미는 함수 만들기?
*/

void rotateBoard(int dir) {
    
}

int Move(int dir, int cnt) {
    if(cnt > MAX_TRY) return;

    
}

int main() {

    freopen("Input.txt", "r", stdin);

    cin >> N ;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}

    for (int i = 0; i < 4; i++) {
        Move(i, 1);
    }

    cout << answer;

	return 0;
}
