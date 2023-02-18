#include <bits/stdc++.h>
using namespace std;

#define MAX 250
#define MOD 1000000007

int R[MAX + 1][MAX*MAX/2];

void add(int &r, int v)
{
	r += v;
	if(r >= MOD)
		r -= MOD;
}

int main()
{
	int n;
	cin >> n;
	long long res = 0;
	if(n % 2 == 0)
	{
		R[0][0] = 1;
		for(int i = 0; i < n; ++i)
		{
			int mx = i*(i - 1)/2 + 1;
			for(int j = i; j >= 0; --j)
				for(int k = 0; k < mx; ++k)
					if(R[j][k] != 0)
						add(R[j + 1][k + i], R[j][k]);
		}
		int need = (n/2)*(2*n - 1);
		int mx = n*(n - 1)/2 + 1;
		for(int i = 0; i <= n; ++i)
			for(int j = 0; j < mx; ++j)
				if(R[i][j] != 0)
				{
					int i2 = n - i;
					int j2 = need - j - i2*n;
					if(0 <= j2 && j2 < mx)
					{
						long long l = R[i][j];
						long long r = R[i2][j2];
						res += l*r % MOD;
					}
				}
	}
	cout << (res % MOD) << endl;
	return 0;
}