//
// Created by find on 16-8-26.
//

#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;
int n,m;
const int MAXN = 50005;

int father[MAXN];
int get_father(int v){
    if(father[v] == v)return v;
    return father[v] = get_father(father[v]);
}
bool issame(int a,int b){
    return get_father(a) == get_father(b);
}
void unioned(int a,int b){
    int fa = get_father(a),fb = get_father(b);
    father[fa] = fb;
}


int main(){
    scanf("%d%d", &n,&m);
    int case_no = 1;

    while(n != 0){
        int nums[MAXN],nums_len=1;
        for (int j = 0; j <= n; ++j) {
            father[j] = j;
        }
        int a,b;
        for (int i = 0; i < m; ++i) {
            scanf("%d %d",&a,&b);
            unioned(a,b);
        }
        nums[0] = 1;
        for (int k = 2; k <= n; ++k) {
            bool getit = false;
            for (int i = 0; i < nums_len; ++i) {
                if(issame(nums[i], k)){
                    getit = true;
                    break;
                }
            }
            if(!getit){
                nums[nums_len++] = k;
            }
        }
        printf("Case %d: %d\n",case_no, nums_len);
        case_no++;
        scanf("%d%d", &n,&m);
    }
    return 0;
}