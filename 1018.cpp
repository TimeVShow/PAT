#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int capacity, n, psta, k;
int now[503];
int map[503][503] = { {0} };
const int maxn = 1e9;
int dis[503];
int cost = maxn;
vector<int> pre[503];
vector<int> path, temp_path;


void input() {
	scanf("%d%d%d%d", &capacity, &n, &psta, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &now[i]);
	}
	int a, b, c;
	for (int i = 0; i < k; i++) {
		scanf("%d%d%d", &a, &b, &c);
		map[a][b] = c;
		map[b][a] = c;
	}
}

void dfs(int num,int tempsum) {
	if (num == 0) {
		temp_path.push_back(0);
		if (abs(tempsum) < abs(cost)) {
			cost = tempsum;
			path = temp_path;
		}else if (-tempsum == cost) {
			cost = tempsum;
			path = temp_path;
		}
		temp_path.pop_back();
	}
	else {
		for (int i = 0; i < pre[num].size(); i++) {
			temp_path.push_back(num);
			dfs(pre[num][i], tempsum + now[num] - capacity / 2);
			temp_path.pop_back();
		}
	}
}

void spfa() {
	queue<int> q;
	bool visit[503];
	for (int i = 0; i <= n; i++) {
		dis[i] = maxn;
		visit[i] = false;
	}
	dis[0] = 0;
	q.push(0);
	while (q.size()) {
		int v = q.front();
		q.pop();
		visit[v] = false;
		for (int u = 1; u <= n; u++) {
			if (map[u][v]) {
				if (dis[u] > dis[v] + map[u][v]) {
					dis[u] = dis[v] + map[u][v];
					pre[u].clear();
					pre[u].push_back(v);
					if (!visit[u]) {
						q.push(u);
						visit[u] = true;
					}
				}else if (dis[u] == dis[v] + map[u][v]) {
					pre[u].push_back(v);
				}
			}
		}
	}
	dfs(psta,0);
}



void output() {
	int send, tback;
	send =  - min(0, cost);
	tback = max(0, cost);
	printf("%d ", send);
	for (int i = path.size() - 1; i > 0; i--) {
		printf("%d->", path[i]);
	}
	printf("%d ", path[0]);
	printf("%d", tback);
}

int main() {
	input();
	spfa();
	output();
	return 0;
}