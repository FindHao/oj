#include <iostream>
#include <cstring>

using namespace std;

const int MAX_NUM = 10 + 5;

int dir[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                 {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
int visited[MAX_NUM][MAX_NUM];
int n, m, x, y;
int num;

void dfs(int cur, int x, int y) {
    if(cur == n * m) {
        num++;
    } else {
        for(int i = 0; i < 8; i++) {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if(tx >= 0 && tx < n
               && ty >= 0 && ty < m
               && !visited[tx][ty]) {
                visited[tx][ty] = 1;
                dfs(cur + 1, tx, ty);
                visited[tx][ty] = 0;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >>  n >> m >> x >> y;
        memset(visited, 0, sizeof(visited));
        num = 0;
        visited[x][y] = 1;
        dfs(1, x, y);
        cout << num << endl;
    }
    return 0;
}