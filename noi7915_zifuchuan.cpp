//
// Created by find on 16-8-29.
//
// 字符串加密解密
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAXN = 105;
char yuan[MAXN],mi[MAXN],mi2[MAXN];
// [yuanwen] = miwen
int alphabeta[27];
// [mi] = yuan
int jiemi[27];
int main(){
    scanf("%s%s%s", mi,yuan,mi2);
    for (int j = 0; j < 27; ++j) {
        alphabeta[j] = -1;
    }
    int len1 = strlen(mi);
    // 如果都不够26个字母，那肯定是情况2
    if(len1 < 26){
        printf("Failed\n");
        return 0;
    }
    for (int i = 0; i < len1; ++i) {
        for (int j = 0; j < 26; ++j) {
            if(alphabeta[j] == mi[i]-'A' && yuan[i]-'A' != j){
                printf("Failed\n");
                return 0;
            }
        }
        if(alphabeta[yuan[i]-'A'] != mi[i]-'A' && alphabeta[yuan[i]-'A'] != -1){
            printf("Failed\n");
            return 0;
        }
        alphabeta[yuan[i]-'A'] = mi[i]-'A';
    }
    int len2 = strlen(mi2);
    for (int l = 0; l < 26; ++l) {
        if(alphabeta[l] == -1){
            printf("Failed\n");
            return 0;
        }
        jiemi[alphabeta[l]] = l;
    }
    for (int k = 0; k < len2; ++k) {
        printf("%c", jiemi[mi2[k] - 'A']+'A');
    }

    return 0;
}