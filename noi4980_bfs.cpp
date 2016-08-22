//
// Created by find on 16-8-22.
//拯救棋盘行动
//bfs。地图中增加了x守卫这样一种类型，守卫点需要花两个时间才能走过。在bfs模板的基础上，修改的地方是，队首元素出队列以后，判断是否是x点，如果是，本轮就只增加当前这个点的cost，形成新的状态并入队，不进行方向扩展。﻿
//
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 205;
char mymap[MAXN][MAXN];
bool visited[MAXN][MAXN];
int m,n;
int count;
int startx, starty, destx, desty;
int standx[] = {0,0,1,-1};
int standy[] = {1,-1,0,0};
struct node {
    int x,y,depth;
}myq[MAXN*MAXN+10000];
bool get_position;
void bfs(){
    int head = 0, tail = 1;
    struct node temp;
    temp.x = startx;temp.y = starty;
    temp.depth = 0;
    myq[tail] = temp;
    while (head < tail){
        head++;
        struct node temp = myq[head];
        if(mymap[temp.x][temp.y] == 'x'){
            struct node temp3;
            temp3.x = temp.x;
            temp3.y = temp.y;
            temp3.depth = temp.depth+1;
            myq[++tail] = temp3;
            mymap[temp.x][temp.y] = '@';
        }else{
            for (int i = 0; i < 4; ++i) {
                struct node temp2;
                temp2.x = temp.x + standx[i];
                temp2.y = temp.y + standy[i];
                temp2.depth = temp.depth + 1;
                if(temp2.x >=0 && temp2.x <m && temp2.y >=0 && temp2.y < n && !visited[temp2.x][temp2.y] && mymap[temp2.x][temp2.y] != '#'){
                    if (temp2.x == destx && temp2.y == desty){
                        count = temp2.depth;
                        get_position = true;
                        return;
                    } else{
                        myq[++tail] = temp2;
                        visited[temp2.x][temp2.y] = 1;
                    }

                }
            }
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d", &m,&n);
        get_position = false;
        for (int i = 0; i < m; ++i) {
            scanf("%s", mymap[i]);
            for (int j = 0; j < n; ++j) {
                if(mymap[i][j] == 'r'){
                    startx = i;
                    starty = j;
                }
                if(mymap[i][j] == 'a'){
                    destx = i;
                    desty = j;
                }
            }
        }
        memset(visited, 0, sizeof(visited));
        visited[startx][starty] = 1;
        count = 0;
        bfs();
        if(get_position)
            printf("%d\n", count);
        else
            printf("Impossible\n");
    }
    return 0;
}

