#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>

#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 20005 * 50005

int n, m, s, t;
int weight[20005][20005];
bool inqueue[20005];
int dis[20005];
vector<int> adj[20005];
vector<int> w[20005];
void spfa()
{
	queue<int> test;

	test.push(s);
	inqueue[s] = true;
	while(!test.empty())
	{
		int cur = test.front(); test.pop();

		//inqueue[cur] = false;

		for (int i = 0; i < adj[cur].size(); i++)
		{
		    int next = adj[cur][i];
		    int nw = weight[cur][next];
			if (dis[cur] + nw < dis[next])
			{
				dis[next] = dis[cur] + nw;

                    test.push(next);
                    //inqueue[next] = true;

			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	int n_case;
	scanf("%d", &n_case);

		for (int c = 0; c < n_case; c++)
		{
			scanf("%d%d%d%d", &n, &m, &s, &t);
			/// init
			for (int i = 0; i < n; i++)
			{
				//inqueue[i] = false;
				dis[i] = INF;
				adj[i].clear();
				//w[i].clear();
			}
			dis[s] = 0;
			/// read
			for (int i = 0; i < m; i++)
			{
				int x, y, z;
				scanf("%d%d%d", &x, &y, &z);

				weight[x][y] = weight[y][x] = z;
				adj[x].push_back(y);
				//w[x].push_back(z);
				adj[y].push_back(x);
				//w[y].push_back(z);
			}
			/// spfa
			spfa();
			/// output
			if (dis[t] != INF) printf("Case #%d: %d\n", c+1, dis[t]);
			else printf("Case #%d: unreachable\n", c+1);
		}


	return 0;
}
