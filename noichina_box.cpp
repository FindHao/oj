#include <cstdio>
#include <string>

using namespace std;

string aim = "AAAA00BBBB";
struct node{
    string str;
    int depth;
}queue[100000];
void bfs(string start){
    int head=0,tail=1;
    struct node temp_node;
    temp_node.depth = 0;
    temp_node.str = start;
    queue[tail] = temp_node;
    while(head < tail){
        head++;
        struct node temp_node2;
        temp_node2 = queue[head];
        int zero_opsition = temp_node2.str.find("00");
        for (int i = 0; i < 9; ++i) {
            if(i == zero_opsition || i == zero_opsition -1) {
                //检测是不是目标状态
                if(temp_node2.str.compare(aim) == 0 ){
                    printf("%d\n", temp_node2.depth);
                    return;
                }
                continue;
            }
            string filter = temp_node2.str.substr(i, 2);
            string new_str = temp_node2.str;
            new_str = new_str.replace(zero_opsition,2, filter);
            new_str = new_str.replace(i, 2, "00");

            //检测是不是目标状态s
            if(new_str.compare(aim) == 0){
                printf("%d\n", temp_node2.depth + 1);
                return;
            }
            tail++;
            struct node temp_node3;
            temp_node3.str = new_str;
            temp_node3.depth = temp_node2.depth + 1;
            queue[tail] = temp_node3;
        }
    }
}

int main(){
    string start = "AB00ABABAB";
//    scanf("%s", start);
    bfs(start);
}