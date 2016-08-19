#include <cstdio>


int standx[4] = {0,0,-1,1};
int standy[4] = {1,-1,0,0};
int my_map [25][25];
int w,h,startx,starty;
char line[25];
int count;
struct path_node
{
	int x,y;
}path[26];
// 空间复杂度？？
void dfs(int x,int y, struct path_node a_path[26]){
	struct path_node node;
	node.x = x;
	node.y = y;
	a_path[count++] = node;
	// for (int i = 0; i < count; ++i)
	// 	{
	// 		printf("path:::(%d, %d)\n",a_path[i].x, a_path[i].y);
	// 	}
	if(x == 4 && y == 4){
		for (int i = 0; i < count; ++i)
		{
			printf("(%d, %d)\n",a_path[i].x, a_path[i].y);
		}
		return ;
	}
	int xx,yy;
	for (int i = 0; i < 4; ++i)
	{
		xx = x+standx[i];
		yy = y+ standy[i];
		if(xx>=0 && yy >= 0 && xx <h && yy <w && my_map[xx][yy]==0){
			my_map[xx][yy] = 1;
			dfs(xx,yy, a_path);
			count--;
		}
	}
}

int main(int argc, char const *argv[])
{
	w = 5;h=5;
	// 第i行
	for (int i = 0; i < h; ++i)
		for (int j = 0; j <w ; ++j)
			scanf("%d", &my_map[i][j]);
	count = 0;
	my_map[0][0]=1;
	dfs(0,0, path);
	return 0;
}