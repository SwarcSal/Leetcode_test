/*
 * @Descripttion: 
 * @version: v0.1
 * @Author: youngchany
 * @Date: 2020-03-29 20:16:39
 * @LastEditors: youngchany
 * @LastEditTime: 2020-03-29 21:01:17
 */
#include <iostream>
#include <vector>
#include <queue>


// 执行用时 :1512 ms, 在所有 C++ 提交中击败了5.00%的用户
// 内存消耗 :252.3 MB, 在所有 C++ 提交中击败了5.88%的用户
class Solution {
public:
	static constexpr int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
	static constexpr int MAX_N = 100 + 5;

	struct Coordinate {
		int x, y, step;
	};
	
	int n, m;
	vector<vector<int>> a;

	bool vis[MAX_N][MAX_N];

	int findNearestLand(int x, int y) {
		memset(vis, 0, sizeof(vis));
        queue <Coordinate> q;
        q.push({x, y, 0});
		vis[x][y] = 1;
		while(!q.empty()) {
			auto f = q.front(); 
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = f.x + dx[i], ny = f.y + dy[i];
				if (!(nx >= 0 && nx <= n-1 && ny >= 0 && ny <= m-1)) continue;
				if (!vis[nx][ny]) {
					q.push({nx, ny, f.step + 1});
					vis[nx][ny] = 1;
					if (a[nx][ny]) return f.step + 1;
				}
			}
		}
		return -1;
	}

	int maxDistance(vector<vector<int>>& grid) {
		this->n = grid.size();
		this->m = grid.at(0).size();
		a = grid;
		int ans = -1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (!a[i][j]) {
					ans = max(ans, findNearestLand(i, j));
				}
			}
		}

		return ans;
	}
};