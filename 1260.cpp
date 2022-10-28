#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<bool> dfs_visit;
vector<int> edges[1001];
vector<int> dist;
int m, n;

void dfs(int v)
{
	dfs_visit[v] = true;

	cout << v << " ";
	for (int i = 0; i < edges[v].size(); i++)
	{
		if (dfs_visit[edges[v][i]] == false)
			dfs(edges[v][i]);
	}
}

void initVisit()
{
	for (int i = 1; i <= n + 1; i++)
	{
		dfs_visit.push_back(false);
	}
	for (int i = 1; i <= n + 1; i++)
	{
		dist.push_back(-1);
	}
}

void bfs(int s)
{
	queue<int> q;
	int now, k, next;

	q.push(s);
	dist[s] = 0;
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		cout << now << " ";
		for (k = 0; k < edges[now].size(); k++)
		{
			next = edges[now][k];
			if (dist[next] == -1)
			{
				q.push(next);
				dist[next] = dist[now] + 1;
			}
		}
	}
}

void inputEdge(int c)
{
	if (c >= m)
		return;

	int temp1, temp2;
	cin >> temp1 >> temp2;
	edges[temp1].push_back(temp2);
	edges[temp2].push_back(temp1);

	c++;
	inputEdge(c);
}

int main()
{
	int s;
	cin >> n >> m >> s;
	inputEdge(0);
	sort(edges->begin(), edges->end());
	initVisit();
	dfs(s);
	cout << endl;
	bfs(s);

	return 0;
}