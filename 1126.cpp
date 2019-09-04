#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> Adj[501];
bool vis[501] = {false};
int connected = 0;
void DFS(int root){
	connected++;
	vis[root] = true;
	for (int i = 0; i < Adj[root].size(); i++)
		if (!vis[Adj[root][i]]) DFS(Adj[root][i]);
}
int main()
{
	int n, m, u, v, oddnum = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		scanf("%d%d", &u, &v);
		Adj[u].push_back(v);
		Adj[v].push_back(u);
	}
	DFS(1);
	for (int i = 1; i < n + 1; i++){
		printf("%d%c", Adj[i].size(), i == n ? '\n' : ' ');
		if (Adj[i].size() % 2) oddnum++;
	}
	if (connected != n) printf("Non-Eulerian\n");
	else printf("%s\n", !oddnum ? "Eulerian" : oddnum == 2 ? "Semi-Eulerian" : "Non-Eulerian");
	return 0;
}
