#include<iostream>
#define endl '\n'
using namespace std;
int ans = 0;
int n, m, k;
char map[10][10];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool is_inside(int x, int y) { return (x >= 1 && x <= m && y >= 1 && y <= n); }
bool visited[10][10] = { 0, };

void dfs(int x, int y, int cnt)
{
    if (x == m && y == 1 && cnt == k)
    {
        ans++;
        return;
    }
    if (cnt > k) return;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (is_inside(nx, ny) && !visited[nx][ny] && map[nx][ny] != 'T')
        {
            visited[nx][ny] = true;
            dfs(nx, ny, cnt + 1);
            visited[nx][ny] = false;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;

    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= m; x++)
        {
            cin >> map[x][y];
        }
    }
    visited[1][n] = true;
    dfs(1, n, 1);
    cout << ans << endl;


}