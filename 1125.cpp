#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> seg(n);
	for (int i = 0; i < n; i++) scanf("%d", &seg[i]);
	sort(seg.begin(), seg.end());
	double sum = seg[0];
	for (int i = 1; i < n; i++)
		sum = (sum + seg[i]) / 2.0;
	printf("%d",(int)sum);
	return 0;
}
