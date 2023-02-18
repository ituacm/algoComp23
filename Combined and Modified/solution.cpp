#include <bits/stdc++.h>
using namespace std;

int R[10 << 10];

bool check(vector<int>& a, vector<int>& b, vector<int>& zr, vector<int>& nz, int cnt)
{
	int pos = b[0] + cnt;
	int value = a[0]*pos;
	int n = a.size();
	int p_zr = zr.size() - 1, p_nz = 0;
	for(int i = 1; i <= n; ++i)
	{
		if(i == pos)
		{
			if(p_nz >= nz.size() || nz[p_nz] != 0)
				return false;
			R[nz[p_nz]] = i;
			++p_nz;
			continue;
		}
		if(p_nz < nz.size() && nz[p_nz] != 0 && a[nz[p_nz]]*i > value)
		{
			R[nz[p_nz]] = i;
			++p_nz;
			continue;
		}
		if(p_zr >= 0 && a[zr[p_zr]]*i > value)
		{
			R[zr[p_zr]] = i;
			--p_zr;
			continue;
		}
		return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i] >> b[i];
	if(b[0] == 0)
	{
		for(int i = 0; i < n; ++i)
			if(b[i] != 0)
				++b[i];
		b[0] = 1;
	}
	vector<pair<pair<int, int>, int>> w(n);
	for(int i = 0; i < n; ++i)
		w[i] = make_pair(pair<int, int>(b[i], a[i]), i);
	sort(w.begin(), w.end());
	vector<int> zr, nz;
	for(int i = 0; i < n; ++i)
		if(w[i].first.first == 0)
			zr.push_back(w[i].second);
		else
			nz.push_back(w[i].second);
	int cnt = 0;
	for(int i = 0; i < n; ++i)
		if(b[i] == 0)
			++cnt;
	bool res = false;
	for(int i = 0; i <= cnt; ++i)
		if(check(a, b, zr, nz, i))
		{
			res = true;
			break;
		}
	if(!res)
		cout << -1 << endl;
	else
		for(int i = 0; i < n; ++i)
			cout << R[i] << endl;
	return 0;
}