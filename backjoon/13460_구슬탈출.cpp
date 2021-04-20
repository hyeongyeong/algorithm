#include<iostream>
#include<algorithm>


using namespace std;

const int MAX_TRY = 10;
const int INF = 987654321;

// 상하좌우
const int dy[4] = {-1,1,0,0};
const int dx[4] = {0,0,-1,1};
char MAP[10][10];
int answer = INF;

class Position {
    public:
            int x;
            int y;
            int nextX;
            int nextY;
            int dist=0;
            int finished = false;
            
            void set(){x = nextX; y=nextY;}
            
            void movedDistance(){dist = abs(x-nextX)+abs(y-nextY);}
            void move(int dir){nextX+=dx[dir];nextY+=dy[dir]; movedDistance();}
            int getDistance(){return dist;}
            
            void finish(){finished = true;}
            bool isFinished(){return finished;}

            Position(int x, int y) : x(x), y(y), nextX(x), nextY(y){};
            Position(){};
            
            void print() {cout<<"x : " << x << ", y : " <<  y << endl;}
            bool isOverlapped(Position c) { return (c.x == x) && (c.y == y);}
};

int inverse_dir(int dir)
{
    if (dir == 0) return 1;
    else if (dir == 1) return 0;
    else if (dir == 2) return 3;
    else if (dir == 3) return 2;
}


// 파란구슬 X, 빨간구슬 0
void Move(Position R, Position B, int cnt, int dir){
    if(cnt > MAX_TRY) {return;}
    if(cnt >= answer) {return;}

    while(1)
    {
        R.move(dir);

        if(MAP[R.nextY][R.nextX] == '#') {
            R.move(inverse_dir(dir));
            break;
        }
        else if(MAP[R.nextY][R.nextX] == 'O') {
            R.finish();
            break;
        }
    }
    R.set();

    while(1)
    {
        B.move(dir);

        if(MAP[B.nextY][B.nextX]=='#') {
            B.move(inverse_dir(dir));
            break;
        }
        else if(MAP[B.nextY][B.nextX] == 'O') {
            B.finish();
            break;
        }
    }
    B.set();

    if(B.isFinished()) {return;}
    else if(R.isFinished()) {answer = min(cnt,answer); return;}
    
    if(R.isOverlapped(B)) {
        if(R.getDistance() > B.getDistance()) {
            R.move(inverse_dir(dir));
            R.set();
        } else {
            B.move(inverse_dir(dir));
            B.set();
        }
    }

    
    for(int i =0; i< 4; i++) {
        if (i == dir) continue;
        if (i == inverse_dir(dir)) continue;

        Move(R, B, cnt + 1, i);
    }

}

int main() {
    int N, M;	//세로, 가로
    Position BLUE;
    Position RED;
    
    freopen("Input.txt", "r", stdin);

    cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
            if(MAP[i][j] == 'B') {
                BLUE = Position(j, i);
                MAP[i][j] = '.';
            }
            else if(MAP[i][j] == 'R') {
                RED = Position(j, i);
                MAP[i][j] = '.';
            }
		}
	}

    for (int i =0; i< 4; i++) {
        Move(RED, BLUE, 1, i);
    }
    answer = answer == INF? -1 : answer;
    cout << answer;

	return 0;
}
