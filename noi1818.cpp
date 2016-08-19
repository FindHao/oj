#include <cstdio>


int standx[4] = {0,0,-1,1};
int standy[4] = {1,-1,0,0};
int my_map [25][25];
int w,h,startx,starty;
char line[25];
int count;
void dfs(int x,int y){
	count++;
	int xx,yy;
	for (int i = 0; i < 4; ++i)
	{
		xx = x+standx[i];
		yy = y+ standy[i];
		if(xx>=0 && yy >= 0 && xx <h && yy <w && my_map[xx][yy]==1){
			my_map[xx][yy] = 0;
			dfs(xx,yy);
		}
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d %d",&w,&h);
	while(w && h){
		count = 0;
		// 第i行
		for (int i = 0; i < h; ++i)
		{
			scanf("%s", line);
			//第j列
			for (int j = 0; j <w ; ++j)
			{
				switch(line[j]){
					case '.': my_map[i][j]=1;break;
					case '#': my_map[i][j]=0;break;
					case '@': my_map[i][j]=0;startx = i;starty =j; break;
				}
			}
		}
		dfs(startx,starty);
		printf("%d\n",count);
		
		scanf("%d %d",&w,&h);
	}
	
	return 0;
}