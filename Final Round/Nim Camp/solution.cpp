#include <bits/stdc++.h>
using namespace std;

void solve(long long l, long long r)
{
	long long res = -1, cnt = -1;
	if(l % 2 == 0 && r - l + 1 >= 4)
	{
		res = 4;
		cnt = 4*l + 6;
	}
	else if(l % 2 != 0 && r - l >= 4)
	{
		res = 4;
		cnt = 4*l + 10;
	}
	long long a = 1;
	while(a <= l) a *= 2;
	if(a + a/2 <= r)
	{
		res = 3;
		cnt = 2*a + 2*l;
	}
	cout << res << ' ' << cnt << '\n';
}

int main()
{
	int t;
	cin >> t;
	vector<long long> l(t), r(t);
	for(int i = 0; i < t; ++i)
		cin >> l[i] >> r[i];
	for(int i = 0; i < t; ++i)
		solve(l[i], r[i]);
	return 0;
}