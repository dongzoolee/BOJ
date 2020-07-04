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
        while (number % i == 0) // 여기서 제곱근을 걸러낸다. 같은 i로 계속 나눠보기, 
        {                       // while에서 false가 나온다. 현재의 number값은 현 i 이전의 값들로 나눠지지 않았음이 보장된다. 만약에라도 나눠졌다면 while문의 number%i의 반복으로 걸려졌음이 보장된다. 그러므로 현 i+1이상의 값들로 나누는 것이 옳다.
            number /= i;
            printf("%d * ", i);
        }
    return 0;
}
