#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
using namespace std;
bool checker = 0;

bool prime(long long num) {
    for (long long i = 2; i <= (int)pow(num, 0.5); i++)
        if (num % i == 0)
            return 0;
    return 1;
}


int main()
{
    long long number, i;
    scanf("%lld", &number);
    if (prime(number)) {
        cout << "IT'S PRIME NUMBER.";
        return 0;
    }
    for (i = 2; i <= number; i++)
        while (number % i == 0) // ���⼭ �������� �ɷ�����. ���� i�� ��� ��������, 
        {                       // while���� false�� ���´�. ������ number���� �� i ������ ����� �������� �ʾ����� ����ȴ�. ���࿡�� �������ٸ� while���� number%i�� �ݺ����� �ɷ������� ����ȴ�. �׷��Ƿ� �� i+1�̻��� ����� ������ ���� �Ǵ�.
            number /= i;
            printf("%d * ", i);
        }
    return 0;
}
