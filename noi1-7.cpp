#include <stdio.h>
#include <stdlib.h>
#include <cstring>
int main(int argc, char const *argv[])
{
	char str[100005];
	scanf("%s", str);
	int len = strlen(str);
	int nums[27];
	for(int i =0;i<len;i++){
		nums[str[i]-'a'] += 1;
	} 
	for (int i = 0; i < len; ++i)
	{
		if (nums[str[i]-'a']==1){
			printf("%c\n", str[i]);
			return 0;
		}
	}
	printf("no\n");

	return 0;
}