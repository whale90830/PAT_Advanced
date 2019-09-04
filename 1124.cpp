#include<iostream>
#include<unordered_set>
using namespace std;
int main()
{
	int m, n, s;
	scanf("%d%d%d", &m, &n, &s);
	unordered_set<string> winner;
	string forwards[m+1];
	for (int i = 1; i < m + 1; i++) cin >> forwards[i];
	if (m < s) printf("Keep going...\n");
	for (int i = s; i < m + 1; i = i + n){
		while (winner.find(forwards[i]) != winner.end()) i++;
		cout << forwards[i] << endl;
		winner.insert(forwards[i]);
	}
	return 0;
}
