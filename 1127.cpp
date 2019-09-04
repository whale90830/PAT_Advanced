#include<iostream>
#include<vector>
using namespace std;
vector<int> in, post, leveldata[31];
void leveltrave(int root, int inL, int inR, int level){
	if (inL > inR) return;
	leveldata[level].push_back(post[root]);
	int k;
	for (k = inL; k <= inR; k++)
		if (in[k] == post[root]) break;
	leveltrave(root-(inR-k)-1, inL, k-1, level+1);
	leveltrave(root-1, k+1, inR, level+1);
}
int main()
{
	int n;
	scanf("%d", &n);
	in.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &in[i]);
	post.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &post[i]);
	leveltrave(n-1, 0, n-1, 0);
	printf("%d", leveldata[0][0]);
	for (int i = 1; i < 31; i++){
		if (i % 2)
			for (int j = 0; j < leveldata[i].size(); j++)
				printf(" %d",leveldata[i][j]);
		else
			for (int j = leveldata[i].size(); j > 0; j--)
				printf(" %d",leveldata[i][j-1]);
	}
	return 0;
}
