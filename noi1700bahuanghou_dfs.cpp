// 没有A，输出的顺序有问题。

#include <cstdio>
#include <cstdlib>
#include <cstring>

bool mymap[8][8];
int ans_num = 0;
bool lie[8],zuoxie[20],youxie[20];
int xy_to_zuoxie[8][8]={
        {7,8,9,10,11,12,13,14},
        {6,7,8,9,10,11,12,13},
        {5,6,7,8,9,10,11,12},
        {4,5,6,7,8,9,10,11},
        {3,4,5,6,7,8,9,10},
        {2,3,4,5,6,7,8,9},
        {1,2,3,4,5,6,7,8},
        {0,1,2,3,4,5,6,7}
};
int xy_to_youxie[8][8]={
        {0,1,2,3,4,5,6,7},
        {1,2,3,4,5,6,7,8},
        {2,3,4,5,6,7,8,9},
        {3,4,5,6,7,8,9,10},
        {4,5,6,7,8,9,10,11},
        {5,6,7,8,9,10,11,12},
        {6,7,8,9,10,11,12,13},
        {7,8,9,10,11,12,13,14},
};
int nums = 0;
void dfs(int row){
    if(nums == 8){
        printf("No. %d\n", ans_num++);
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if(j == 7 ){
                    printf("%d\n", mymap[i][j]);
                }else {
                    printf("%d ", mymap[i][j]);
                }
            }
        }
        return ;
    }
    for (int k = row+1 ; k < 8; ++k) {
        bool has = false;
        for (int i = 0; i < 8; ++i) {
            if(!lie[i] && !zuoxie[xy_to_zuoxie[k][i]] && !youxie[xy_to_youxie[k][i]] ){
                has = true;
                mymap[k][i] = 1;
                zuoxie[xy_to_zuoxie[k][i]] = 1;
                youxie[xy_to_youxie[k][i]] = 1;
                lie[i] =1;
                nums++;
                dfs(k);
                nums--;
                lie[i] = 0;
                zuoxie[xy_to_zuoxie[k][i]] = 0;
                youxie[xy_to_youxie[k][i]] = 0;
                mymap[k][i] = 0;
            }
        }
        if( !has){
            break;
        }
    }
}

int main(){
    memset(mymap, 0, sizeof(mymap));
    memset(lie, 0, sizeof(lie));
    memset(zuoxie, 0 ,sizeof(zuoxie));
    memset(youxie, 0 , sizeof(youxie));
    for (int i = 0; i < 8; ++i) {
        int k = 0;
        mymap[k][i] = 1;
        zuoxie[xy_to_zuoxie[k][i]] = 1;
        youxie[xy_to_youxie[k][i]] = 1;
        lie[i] =1;
        nums++;
        dfs(k);
        nums--;
        lie[i] = 0;
        zuoxie[xy_to_zuoxie[k][i]] = 0;
        youxie[xy_to_youxie[k][i]] = 0;
        mymap[k][i] = 0;
    }
    return 0;
}