#include <string>
#include <vector>
#include <iostream>

using namespace std;


int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

long long solution(int w, int h) {
    long long answer;

    answer = ((long)w*h) - ((long)w+h-gcd(h,w)) ;

    return answer;
}


int main() {
    int w = 8;
    int h = 12;
    long long output;


    output = solution(w, h);
    cout << output << endl;
    
    return 0;
}


