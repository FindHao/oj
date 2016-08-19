#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int mymap[15][15];
int t;
int n,m;
int startx,starty;
int standx[8]={-1,1,-2,2,-1,1,-2,2};
int standy[8]={2,2,1,1,-2,-2,-1,-1};
int xx,yy;
int mycount;
void dfs(int x,y)
{
    while()
    {
        mycount=1;
        for(int k=0;k<n;k++)
        {
            for(int j=0;j<m;j++)
            {
                if(mymap[k][j]==1)
                {
                    mycount++;
                }
            }
        }

        for(int i=0;i<8;i++)
        {
            xx=x+startx[i];
            yy=y+starty[i];
            if(xx<n && xx>=0 && yy<m && yy>=0 && mymap[xx][yy]==1)
            {
                mymap[xx][yy]=0;
                dfs(xx,yy);
                mymap[xx][yy]=1;
            }
        }
    }
}
int main()
{
    scanf("%d",&t);
    for(int i=0;i < t;i++)
    {
        scanf("%d%d%d%d",n,m,startx,starty);
    }
    dfs(startx,starty);
    return 0;
}