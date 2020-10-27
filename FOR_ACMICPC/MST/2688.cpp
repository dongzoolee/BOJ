#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
#include <deque>
#include <limits.h>
#include <set>
#include <numeric>
using namespace std;
using ll = long long;
set<int> getDifference(const set<int>& set0, const set<int>& set1)
{
	set<int> returnset;
	bool istrue;
	for (set<int>::const_iterator it = set0.begin(); it != set0.end(); ++it)
	{
		istrue = true;
		for (set<int>::const_iterator it2 = set1.begin(); it2 != set1.end(); ++it2)
		{
			if (*it2 == *it)
			{
				istrue = false;
			}
		}
		if (istrue == true)
		{
			returnset.insert(*it);
		}
	}
	return returnset;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	set<int>s1;
	set<int>s2;
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);

	s2.insert(3);
	s2.insert(4);
	s2.insert(5);
	set<int>ret = getDifference(s1, s2);
	for (set<int>::const_iterator it = ret.begin(); it != ret.end(); ++it) {
		cout << *it << '\n';
	}
}