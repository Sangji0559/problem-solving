#include<iostream>

using namespace std;

long long solution(int k, int d)
{
    // y�� 0�� �� ���� ��
    long long answer = d / k + 1;

    // x^2 + y^2 = d^2 ���Ŀ� ���� x = i �� �� 1�̻��� y�� ���� ���Ѵ�.
    for (long long i = 0; i < d; i += k)
        answer += (long long)sqrt((long long)d * d - i * i) / k;

    return answer;
}

int main() {
    int a = 1, b = 100000;
    cout << solution(a, b);
    return 0;
}