//
// Created by find on 16-8-22.
//

#include <cstdio>
#include <cstdlib>
using namespace std;
const double EPSINON = 0.00001;
bool getit;
void dfs(double nums[],int len){
    if(len == 1 && abs(nums[0] - 24)<=EPSINON){
        getit = true;
        return;
    }
    for (int i = 0; i < 4; ++i) {
        
    }
}
int main(){
    double nums[4];
    for (int i = 0; i < 4; ++i) {
        int a;
        scanf("%d",&a );
        nums[i] = 1.0 * a;
    }
    while(abs(nums[0]) > EPSINON){
        dfs(nums, 4);
        if(getit)
            printf("YES\n");
        else
            printf("NO\n");

        for (int i = 0; i < 4; ++i) {
            int a;
            scanf("%d",&a );
            nums[i] = 1.0 * a;
        }
    }
}