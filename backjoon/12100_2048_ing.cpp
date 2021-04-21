#include<iostream>
#include<algorithm>

using namespace std;

const int MAX_TRY = 5;

const int MAX_N = 20;

int N;
// int MAP[MAX_N][MAX_N];

int Answer = 0;

/*
    # 1 배열 통째로 돌리고 바꾸는 함수 + 오른쪽에서 왼쪽으로 미는 함수 만들기
    # 2 4가지 배열에 대해 미는 함수 만들기?
*/


void findMax(int MAP[MAX_N][MAX_N]) {
    for(int i = 0; i<N; i++) {
        for (int j=0; j<N; j++) {
            Answer = max(MAP[i][j], Answer);
        }
    }
}

void printBoard(int MAP[MAX_N][MAX_N]) {
    for(int i = 0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << MAP[i][j] << " " ;
        }
        cout << endl;
    }
}

void copyArray(int (*target)[MAX_N], int src[MAX_N][MAX_N]) {
    for( int i =0; i<N; i++) {
        for(int j = 0; j<N; j++) {
            target[i][j] = src[i][j];
        }
    }
}


void reverseLR(int (*MAP)[MAX_N]) {
    int C_MAP[MAX_N][MAX_N];
    for(int i=0; i<N; i++) {
        for(int j = 0; j<N; j++) {
            C_MAP[i][(N-1)-j] = MAP[i][j];
        }
    }
    copyArray(MAP,C_MAP);
}


void rotateLeft(int (*MAP)[MAX_N]) {
    int C_MAP[MAX_N][MAX_N];
    for(int i=0; i<N; i++) {
        for(int j = 0; j<N; j++) {
            C_MAP[(N-1)-i][j] = MAP[j][i];
        }
    }
    copyArray(MAP,C_MAP);
}

void rotateRight(int (*MAP)[MAX_N]) {
    int C_MAP[MAX_N][MAX_N];
    for(int i=0; i<N; i++) {
        for(int j = 0; j<N; j++) {
            C_MAP[i][(N-1)-j] = MAP[j][i];
        }
    }
    copyArray(MAP,C_MAP);
}

void sumLeftTORight(int (*MAP)[MAX_N]) {
    int cur = 0;
    int sum = 0;
    for(int i = 0; i<N; i++) {
        cur = 0;
        sum = 0;
        for (int j=0; j<N; j++) {
            if(cur == j) {continue;}
            if(MAP[i][j] == 0) {continue;}
            else if(MAP[i][j] == MAP[i][cur]) {
                MAP[i][cur] += MAP[i][j];
                MAP[i][j] = 0;
                cur += 1;
            } else if (cur < j && MAP[i][cur] == 0){
                MAP[i][cur] = MAP[i][j];
                MAP[i][j]= 0;
            } else {
                cur +=1;
            }
            
        }
        
    }
}

void Move(int dir, int cnt, int MAP[MAX_N][MAX_N]) {
    if(cnt > MAX_TRY) return;

    switch (dir)
    {
        case 0: //상
            rotateLeft(MAP);
            // sumLeftTORight(MAP);
            // rotateRight(MAP);
            break;
        case 1: //하
            rotateRight(MAP);
            // sumLeftTORight(MAP);
            // rotateLeft(MAP);
            break;
        case 2: //좌
            // sumLeftTORight(MAP);
            break;
        case 3: //우
            reverseLR(MAP);
            // sumLeftTORight(MAP);
            // reverseLR(MAP);
            break;
    }
    sumLeftTORight(MAP);
    findMax(MAP);

    for(int i=0; i<4; i++) {
        Move(i,cnt+1,MAP);
    }
    
}


int main() {
    int MAP[MAX_N][MAX_N];
    freopen("Input.txt", "r", stdin);

    cin >> N ;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
    if(N==1) {
        cout << MAP[0][0];
        return 0;
    }

    for(int i=0; i<4; i++) {
        Move(i,1,MAP);
    }
    
    cout << Answer;

	return 0;
}
