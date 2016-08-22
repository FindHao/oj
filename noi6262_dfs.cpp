//
// Created by find on 16-8-22.
//6266:取石子游戏 递归。状态扩展只有一种方式。
//

#include <cstdio>
#include <algorithm>

using namespace std;

void dfs(int a,int b,int depth){
    int c = max(a,b),d= min(a,b);

    if((d!=0 && (c % d == 0 || c/d >=2))|| d == 0){
        if(depth % 2 == 0){
            printf("lose\n");
        }else
            printf("win\n");
        return ;
    }
    a = c%d;
    dfs(a,d,depth+1);
}

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    while( m!=0 && n!=0){
        dfs(m,n,1);
        scanf("%d %d",&m,&n);
    }
}