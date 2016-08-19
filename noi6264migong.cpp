//
// Created by find on 16-8-19.
// 没用的水题
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char mymap[45][45];
bool visited[45][45];
int m,n;
int count;
int startx, starty, destx, desty;
int standx[] = {0,0,1,-1};
int standy[] = {1,-1,0,0};
struct node {
    int x,y,depth;
}myq[5000];
void bfs(){
    int head = 0, tail = 1;
    struct node temp;
    temp.x = startx;temp.y = starty;
    temp.depth = 1;
    myq[tail] = temp;
    while (head < tail){
        head++;
        struct node temp = myq[head];
        for (int i = 0; i < 4; ++i) {
            struct node temp2;
            temp2.x = temp.x + standx[i];
            temp2.y = temp.y + standy[i];
            temp2.depth = temp.depth + 1;
            if (temp2.x == destx && temp2.y == desty){
                count = temp2.depth;
                return;
            }
            if(temp2.x >=0 && temp2.x <m && temp2.y >=0 && temp2.y < n && !visited[temp2.x][temp2.y] && mymap[temp2.x][temp2.y] != '#'){
                myq[++tail] = temp2;
                visited[temp2.x][temp2.y] = 1;
            }
        }
    }
}
int main(){
    scanf("%d %d", &m,&n);
    char temp[25];
    for (int i = 0; i < m; ++i) {
        scanf("%s", mymap[i]);
    }
    startx = 0;
    starty = 0;
    destx = m-1;
    desty = n-1;
    memset(visited, 0, sizeof(visited));
    visited[startx][starty] = 1;
    count = 1;
    bfs();
    if(count == 1) count = -1;
    printf("%d\n", count);
}

