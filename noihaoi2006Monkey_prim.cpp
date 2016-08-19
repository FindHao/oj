#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cfloat>

using namespace std;

const int MAXN = 1005;
int m;
int monkeys[MAXN];
int n;
//minn[i]存放蓝点i与白点相连的最小边权
double minn[MAXN];
struct node{
    int x;
    int y;
} trees[MAXN];
double distance [MAXN][MAXN];
// 默认1是蓝点，0标记是否加入生成树中
bool u[MAXN];
int main(){
    scanf("%d",&m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &monkeys[i]);
    }
    scanf("%d", &n);
    for (int j = 0; j < n; ++j) {
        scanf("%d %d", &trees[j].x, &trees[j].y);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            //从i到j的距离
            distance[i][j] = abs(sqrt(pow(trees[i].x - trees[j].x, 2) + pow(trees[i].y - trees[j].y, 2)));
            distance[j][i] = distance[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        minn[i] = DBL_MAX;
    }
    memset(u, 1, sizeof(u));
    minn[0] = 0;
    u[0] = false;
    for (int i = 1; i < n; ++i) {
        int k;
        double temp_min = DBL_MAX;
        for (int j = 0; j < n; ++j) {
            if(u[j] && minn[j] < temp_min){
                k = j;
                temp_min = minn[j];
            }
        }
        u[k] = false;
        for (int j = 0; j < n; ++j) {
            if(u[j] && distance[k][j] < minn[j])
                minn[j] = distance[k][j];
        }
    }
    double max_distance_in_tree = 0;
    for (int i = 0; i < n; ++i) {
        if(minn[i] > max_distance_in_tree)
            max_distance_in_tree = minn[i];
    }
    int count = 0;
    for (int l = 0; l < m; ++l) {
        if( monkeys[l] < max_distance_in_tree)
            continue;
        count++;
    }
    printf("%d", count);

    return 0;
}