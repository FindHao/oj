// 棋盘问题
//http://noi.openjudge.cn/ch0205/323/
#include <cstdio>
#include <cstring>

int n,k;
int mymap[10][10];
//int visit[10][10];
int visit_x[10],visit_y[10];
int count ;
void set_state(int y,int state){
//    for (int l = 0; l < n; ++l) {
//        visit[x][l] = state;
//        visit[l][y] = state;
//    }
//    visit_x[x] = state;
    visit_y[y] = state;
}
//第depth层的时候，棋子放在了点（x,y）上
void dfs(int depth,int x){
    if(depth == k){
        count++;
        return;
    }
    if(n-x < k-depth){
        return;
    }
    dfs(depth, x+1);
    for (int j = 0; j < n; ++j) {
        if(mymap[x][j] == 1 && !visit_y[j]){
            set_state(j,1);
            dfs(depth+1,x+1);
            set_state(j,0);
        }
    }


}

int main(){
    scanf("%d%d",&n, &k);
    char temp[10];
    while(n != -1 && k != -1){
        count = 0;
        memset(visit_x,0, sizeof(visit_x));
        memset(visit_y,0, sizeof(visit_y));
        for (int i = 0; i < n; ++i) {
            scanf("%s", &temp);
            for (int j = 0; j < n; ++j) {
                mymap[i][j] = temp[j]=='#'?1:0;
//                if(temp[j]=='#')
//                    mymap[i][j] = 1;
//                else
//                    mymap[i][j] = 0;
            }
        }
        bool has = false;
        // 只循环一行的
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < n; ++j) {
//                if(mymap[i][j] == 1){
//                    set_state(j,1);
//                    dfs(1, i);
//                    set_state(j,0);
//                    has == true;
//                }
//            }
//            if(has)
//                break;
//        }
        dfs(0,0);
        printf("%d\n",count);
        scanf("%d%d",&n, &k);

    }
}