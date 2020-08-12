#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
#include <malloc.h>
#include <limits.h>
#include <tuple>
#include<numeric>
using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    bool change = false;
    for (int i = 1; i <= n + 1; i++) {
        change = false;
        for (int j = 1; j <= n - i; j++) {
            if (a[j] > a[j + 1]) {
                change = true;
                swap(a[j], a[j + 1]);
            }
        }
        if (change == false) {
            cout << i << '\n';
            break;
        }
    }
}