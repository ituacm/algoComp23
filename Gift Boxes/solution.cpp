#include <iostream>
#include <algorithm>
using namespace std;


struct box {
    int w, h, index;
}boxes[5005];

bool cmp(const box &fir, const box &sec)
{
	if (fir.w ^ sec.w) return fir.w < sec.w;
	return fir.h < sec.h;
}

int chainSizes[5005];
int parents[5005];


int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, w, h; cin >> n >> w >> h;
    int validBoxes = 0;

    for (int i = 1; i <= n; ++i)
	{
		int x , y; cin >> x >> y; parents[i] = -1;
		if (x <= w || y <= h) continue;
		boxes[++validBoxes] = {x, y, i};
	}
	if (validBoxes == 0) {cout << 0 << endl; return 0;}
	sort(boxes + 1, boxes + validBoxes + 1, cmp);

	for (int i = 1; i <= validBoxes; ++i)
	{
		chainSizes[i] = 1;
		for(int j = 1; j < i; ++j)
		{
			if (boxes[j].w < boxes[i].w && boxes[j].h < boxes[i].h && chainSizes[j] + 1 > chainSizes[i])
			{
				chainSizes[i] = chainSizes[j] + 1;
				parents[i] = j;
			}
		}
	}
	int ans = 0, parent = 0;
	for (int i = 1; i <= validBoxes; ++i)
	{
		if (chainSizes[i] > ans)
		{
			ans = chainSizes[i];
			parent = i;
		}
	}
	cout << ans << endl; 

    string mstr = "";
    while(parent != -1) {
        mstr = to_string(boxes[parent].index) + " " + mstr;
        parent = parents[parent];
    }
    cout << mstr << endl;
	return 0;
}
