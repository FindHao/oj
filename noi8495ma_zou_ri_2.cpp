#include<cstdio>
#include<cstdlib>
using namespace std;
int mymap[15][15];
int t;
int n,m;
int startx,starty;
int standx[8]={-1,1,-2,2,-1,1, -2, 2};
int standy[8]={ 2,2, 1,1,-2,-2,-1,-1};
int mycount;
void dfs(int x, int y)
{
    //判断地图是不是全部都走过了。
    bool get_all = true;
     for(int k=0;k<n;k++)
     {
         for(int j=0;j<m;j++)
         {
             if(mymap[k][j]==1)
             {
                 get_all = false;
             }
         }
     }
    //如果地图全部都走过了
     if (get_all == true)
     {
        mycount++;
    }else{
        for(int i=0;i<8;i++)
        {
            // 为什么xx，yy要在这里int，而不是像你一样声明成全局变量
            int xx=x+standx[i];
            int yy=y+standy[i];
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
        scanf("%d%d%d%d",&n,&m,&startx,&starty);
        mycount = 0;
        // 初始化地图
        for( int j = 0; j<n; j++){
            for(int k = 0; k <m ; k++){
                mymap[j][k] = 1;
            }
        }
        // 置起点不可再走
        mymap[startx][starty] = 0;
        // dfs的位置
        dfs(startx,starty);
        printf("%d\n", mycount);
    }
    return 0;
}