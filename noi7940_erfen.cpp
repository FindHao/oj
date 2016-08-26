//
// Created by find on 16-8-26.
//

#include <cstdio>
#include <cstdlib>

using namespace std;
const int MAXN = 100005;
int n,m,nums[MAXN];

int binary_search(int value, int left,int right){
    if(left == right) return left;
    int middle = (left+right)/2;
    if(nums[middle] > value){
        return binary_search(value,left,middle);
    }else{
        if(nums[middle] == value)return middle;
        else return binary_search(value, middle+1,right);
    }
}


int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&nums[i]);
    }
    scanf("%d",&m);
    int temp;
    for (int j = 0; j < m; ++j) {
        scanf("%d",&temp);
        int position = binary_search(temp,0,n-1);
        int v1,v2,v3,p1=position,p2=position,p3= position;
        while(p1>0 && nums[p1] == nums[position])p1--;
        while(p2<n-1 && nums[p2]==nums[position])p2++;
        int abs0 = abs(nums[position] - temp);
        int abs1 = abs(nums[p1] - temp);
        int abs2 = abs(nums[p2] - temp);
        if(abs2 < abs0){
            position = p2;
            abs0 = abs2;
        }
        if(abs1 <= abs0){
            position = p1;
            abs0 = abs1;
        }
        printf("%d\n",nums[position]);
    }
    return 0;
}