#include <bits/stdc++.h>
using namespace std;

#define SZ 2000

const int DR[] = {-1, -1, 0, 1, 1, 0};
const int DC[] = {1, 0, -1, -1, 0, 1};

int A[2*SZ][2*SZ];
int B[2*SZ][2*SZ];
int C[2*SZ][2*SZ];
int P[SZ*SZ];
int L[SZ*SZ];

int getIndex(int a, vector<pair<int, int>>& pos)
{
	if(a >= pos.size()) 
		return 0;
	return B[pos[a].first][pos[a].second];
}

int bfs(int r, int c, int idx)
{
	queue<pair<int, int>> q;
	q.push(pair<int, int>(r, c));
	B[r][c] = idx;
	int res = -1;
	while(!q.empty())
	{
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for(int i = 0; i < 6; ++i)
		{
			int rr = r + DR[i];
			int cc = c + DC[i];
			if(rr < 0 || 2*SZ <= rr || cc < 0 || 2*SZ <= cc)
				continue;
			if(C[r][c] != C[rr][cc])
			{
				res = max(res, B[rr][cc]);
				continue;
			}
			if(B[rr][cc] != -1)
				continue;
			B[rr][cc] = idx;
			q.push(pair<int, int>(rr, cc));
		}
	}
	return res;
}

int main()
{
	int n, m;
	string s;
	cin >> n >> m >> s;
	vector<pair<int, int>> q(m);
	for(int i = 0; i < m; ++i)
		cin >> q[i].first >> q[i].second;
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	vector<pair<int, int>> pos(n);
	int r = SZ;
	int c = SZ;
	A[r][c] = 0;
	C[r][c] = s[0] - '0';
	pos[0] = pair<int, int>(r, c);
	int cnt = 1;
	int z = 0;
	while(cnt < n)
	{
		++z;
		++r;
		for(int i = 0; i < 6; ++i)
			for(int j = 0; j < z; ++j)
			{
				r += DR[i];
				c += DC[i];
				A[r][c] = cnt;
				if(cnt < n) 
				{
					pos[cnt] = pair<int, int>(r, c);
					C[r][c] = s[cnt] - '0';
				}
				++cnt;
			}
	}
	P[0] = bfs(0, 0, 0);
	L[0] = 0;
	cnt = 1;
	for(int i = n - 1; i >= 0; --i)
		if(B[pos[i].first][pos[i].second] == -1)
		{
			P[cnt] = bfs(pos[i].first, pos[i].second, cnt);
			L[cnt] = L[P[cnt]] + 1;
			++cnt;
		}
	vector<int> res(m);
	for(int i = 0; i < m; ++i)
	{
		int a = getIndex(q[i].first, pos);
		int b = getIndex(q[i].second, pos);
		if(L[a] > L[b]) swap(a, b);
		res[i] = 0;
		while(L[a] != L[b])
		{
			b = P[b];
			++res[i];
		}
		while(a != b)
		{
			a = P[a];
			b = P[b];
			res[i] += 2;
		}
	}
	for(int i = 0; i < m; ++i) 
		cout << res[i] << endl;	
	return 0;
}