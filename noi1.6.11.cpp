#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char a[205];
	char b[205];
	int numa[205];
	int numb[205];
	scanf("%s",a);
	scanf("%s",b);
	int lena = strlen(a);
	int lenb = strlen(b);
	for (int i = 0; i < lena; ++i)
	{
		numa[i]=a[lena-1-i]-'0';
	}
	for (int i = 0; i < lenb; ++i)
	{
		numb[i] = b[lenb-1-i] - '0';
	}

	for (int i = 0; i < lenb; ++i)
	{
		if (numa[i] >= numb[i])
		{
			numa[i] -= numb[i];
		}else{
			numa[i+1] -= 1;
			numa[i]+=10;
			numa[i] -= numb[i];
		}
	}
	int anslena=lena;
	for (int i = lena-1; i >0; --i)
	{
		if(numa[i]==0)
			anslena --;
		else{
			break;
		}
	}
	for (int i = anslena-1; i >=0; --i)
	{
		printf("%d",numa[i] );
	}
	return 0;
}