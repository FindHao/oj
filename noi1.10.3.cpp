#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
int a[505];
struct stu
{
	int number;
	char name[100];
}student[25],temp;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%s %d", student[i].name, &student[i].number);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (student[j + 1].number < student[j].number)
			{
				temp = student[j + 1];
				student[j + 1] = student[j];
				student[j] = temp;
			}else{
				if(student[j + 1].number == student[j].number && strcmp(student[j+1].name, student[j].name) > 0){
					temp = student[j + 1];
					student[j + 1] = student[j];
					student[j] = temp;
				}
			}

		}
			
	}
	for (int i = n-1; i >=0; i--)
	{
		printf("%s %d\n", student[i].name, student[i].number);
	}
	return 0;
}