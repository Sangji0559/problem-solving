#include<iostream>

using namespace std;

long long solution(int k, int d)
{
    // y는 0일 때 점의 수
    long long answer = d / k + 1;

    // x^2 + y^2 = d^2 공식에 맞춰 x = i 일 때 1이상의 y의 개수 구한다.
    for (long long i = 0; i < d; i += k)
        answer += (long long)sqrt((long long)d * d - i * i) / k;

    return answer;
}

int main() {
    int a = 1, b = 100000;
    cout << solution(a, b);
    return 0;
}