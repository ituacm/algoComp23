#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
#define INF 1'000'000'000'000'000'000LL

int A[MAX][MAX];
long long R[MAX][MAX];
long long C[MAX][MAX];
long long SR[MAX][MAX];
long long SC[MAX][MAX];

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	int i, j;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> A[i][j];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
		{
			R[i][j] = C[i][j] = -INF;
			SR[i][j] = A[i][j] + (j == 0 ? 0 : SR[i][j - 1]);
			SC[i][j] = A[i][j] + (i == 0 ? 0 : SC[i - 1][j]);
		}
	
	vector<deque<int>> row(n), col(m);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
		{
			while(!row[i].empty() && j - row[i].back() > k) 
				row[i].pop_back();
			while(!col[j].empty() && i - col[j].back() > k) 
				col[j].pop_back();
			if(i == 0 && j == 0) 
				R[i][j] = C[i][j] = 0;
			if(!row[i].empty()) 
				C[i][j] = R[i][row[i].back()] + SR[i][j] - SC[i][j];
			if(!col[j].empty()) 
				R[i][j] = C[col[j].back()][j] + SC[i][j] - SR[i][j];
			while(!row[i].empty() && R[i][row[i].front()] <= R[i][j]) row[i].pop_front();
			if(R[i][j] != -INF) row[i].push_front(j);
			while(!col[j].empty() && C[col[j].front()][j] <= C[i][j]) col[j].pop_front();
			if(C[i][j] != -INF) col[j].push_front(i);
		}

	long long res = max(R[n - 1][m - 1] + SR[n - 1][m - 1], C[n - 1][m - 1] + SC[n - 1][m - 1]);
	cout << res << endl;
	return 0;
}