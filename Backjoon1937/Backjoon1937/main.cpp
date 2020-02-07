#include<iostream>
#include<algorithm>
using namespace std;

int N, ans;
int map[500][500];
int dp[500][500];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

int dfs(int y, int x) {
    bool flag = false;
    for (int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

        if (map[y][x] < map[ny][nx]) {
            flag = true;
            int value = 0;
            if (dp[ny][nx] == 0) {
                value = dfs(ny, nx);
                dp[y][x] = max(value + 1, dp[y][x]);
            }
            else {
                dp[y][x] = max(dp[ny][nx] + 1, dp[y][x]);
            }
        }
    }

    if (!flag) return dp[y][x] = 1;
    else return dp[y][x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> map[y][x];
        }
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (dp[y][x] == 0) {
                ans = max(dfs(y, x), ans);
            }
        }
    }
    cout << ans;
    return 0;
}
