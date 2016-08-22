//
// Created by find on 16-8-22.
//
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAXN = 30005;
int n;
struct disjointset{
    int father[MAXN];
    void initial(){//初始化，每个元素的父亲都是它自己
        for(int i=0;i<=n;father[i]=i,i++);
    }
    int getfather(int v){//这里用了路径压缩
        if(father[v]==v)return v;
        return father[v]=getfather(father[v]);
    }
    bool issame(int a,int b){//判断是不是同一个集合里的
        return getfather(a)==getfather(b);
    }
    void unioned(int u,int v){//合并到同一个集合里
        int fu=getfather(u),fv=getfather(v);
        father[fv]=fu;
    }
} myset;

int main(){
    int m,k,a,b;
    scanf("%d %d",&n,&m);
    while(n!=0){
        myset.initial();
        for (int i = 0; i < m; ++i) {
            scanf("%d",&k);
            scanf("%d",&a);
            for (int j = 1; j < k; ++j) {
                scanf("%d",&b);
                myset.unioned(a,b);
            }
        }
        int count = 1;
        for (int l = 1; l < n; ++l) {
            if(myset.issame(0, l)){
                count++;
            }
        }
        printf("%d\n",count);
        scanf("%d %d",&n,&m);
    }
}