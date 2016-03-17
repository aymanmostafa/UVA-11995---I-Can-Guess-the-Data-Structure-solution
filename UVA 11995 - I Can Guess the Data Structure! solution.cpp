//============================================================================
// Name        : ayman.cpp
// Author      : Ayman Mostafa
// Email       : ayman93live@hotmail.com
// Version     : v5.0
//============================================================================

#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>

using namespace std;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()

void fastInOut();
//##########################################################################################
//###################################MAIN FUNCTION##########################################
//##########################################################################################
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
//freopen("output.txt", "wt", stdout);
#endif
	fastInOut();
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
// 11995 - I Can Guess the Data Structure!
	stack<int> s;
	queue<int> q;
	priority_queue<int> d;
	int arr[3], c, x, y, n;
	string ss;
	while (cin >> n) {
		while (!s.empty())
			s.pop();
		while (!d.empty())
			d.pop();
		while (!q.empty())
			q.pop();
		arr[0] = 0, arr[1] = 0, arr[2] = 0;
		c = 0;
		while (n--) {
			cin >> x >> y;
			if (x == 1) {
				s.push(y);
				q.push(y);
				d.push(y);
			} else {
				if (!s.empty() && y == s.top() && arr[0] == c) {
					arr[0]++;
					s.pop();
				}
				if (!q.empty() && y == q.front() && arr[1] == c) {
					arr[1]++;
					q.pop();
				}
				if (!d.empty() && y == d.top() && arr[2] == c) {
					arr[2]++;
					d.pop();
				}
				c++;
			}
		}
		if ((arr[0] == c && arr[1] == c) || (arr[0] == c && arr[2] == c)
				|| (arr[1] == c && arr[2] == c))
			ss = "not sure";
		else if (arr[0] == c)
			ss = "stack";
		else if (arr[1] == c)
			ss = "queue";
		else if (arr[2] == c)
			ss = "priority queue";
		else
			ss = "impossible";
		cout << ss << endl;
	}
}
void fastInOut() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
