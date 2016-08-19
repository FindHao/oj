#include <cstdio>

int mymap[8][8];


int standx []= {0, 0, -1, 1};
int standy []= {-1, 1, 0 , 0};
struct node
{
	int x,y;
};
struct node pre[8][8];
void print_path(){
	struct node path[26];
	int x=4,y=4,i=0,x1;
	while(pre[x][y].x != 0 || pre[x][y].y != 0){
	struct node temp;
		temp.x = x;temp.y = y;
		path[i++]=temp;
		x1= pre[x][y].x;
		y= pre[x][y].y;
		x = x1;
		// printf("%d %d \n", x,y);
	}
	struct node temp;
		temp.x = x;temp.y = y;
		path[i++]=temp;
	
	// for (int ii = 0; ii < 5; ++ii)
	// {
	// 	for (int jj = 0; jj < 5; ++jj)

	// {
	// 	printf("(%d,%d) ",pre[ii][jj].x,pre[ii][jj].y);
	// 	}
	// 	printf("\n");
	// }
	printf("(0, 0)\n" );
	// printf("%d\n", i);
	while(i--){
		printf("(%d, %d)\n",path[i].x, path[i].y );
	}
}
void bfs(){

	struct node queue[100];
	int head,tail,xx,yy;
	struct node temp;
	head = 0;
	tail = 0;
	temp.x = 0;temp.y = 0;
	queue[0] = temp;
	mymap[0][0]= 1;
	while (tail<=head){
		temp = queue[tail];
		tail++;
		for (int i = 0; i < 4; ++i)
		{
			xx = temp.x + standx[i];
			yy = temp.y + standy[i];
			if(xx >=0 && xx < 5 && yy >=0 && yy < 5 && mymap[xx][yy]==0){
				if(xx == 4 && yy == 4){
					pre[4][4].x = temp.x;
					pre[4][4].y = temp.y;
					print_path();
					return;
				}else{
					struct node temp2;
					temp2.x = xx;
					temp2.y = yy;
					pre[xx][yy].x = temp.x;
					pre[xx][yy].y = temp.y;
					queue[++head] = temp2;
					mymap[xx][yy]=1;
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			scanf("%d", &mymap[i][j]);
		}
		/* code */
	}
	bfs();

	return 0;
}