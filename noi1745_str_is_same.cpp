//
// Created by find on 16-8-27.
//

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int MAXN=0x7f;
char a[MAXN];
char b[MAXN];
char str1[MAXN];
char str2[MAXN];
int mycount1=0;
int mycount2=0;
char* strmov(char *dst, const char*src, char ch){
    int i = -1, j = 0;
    while (src[++i])
        if (src[i] != ch)
            dst[j++] = src[i];
    dst[j] = '\0';
    return dst;
}
int main(){
    cin.getline(a,MAXN);
    cin.getline(b, MAXN);
    strmov(str1,a,' ');
    strmov(str2,b,' ');
    int len1=strlen(str1);
    int len2=strlen(str2);
    if(len1 == len2){
        for(int i=0;i<len2;i++){
            if(str1[i]==str2[i] || int(str1[i])==int(str2[i])+32
               || int(str1[i])+32==int(str2[i])){
                mycount1++;
            }
        }
        if(mycount1==len2){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    } else{
        printf("NO\n");
    }

    return 0;
}
