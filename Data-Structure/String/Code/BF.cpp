#include <iostream>
#include <stdlib.h>
#include <cstdio>
#define MaxSize 20

typedef struct
{
	char data[MaxSize];
	int length;
} SqString;
int index(SqString s, SqString t)
{
	int i=0,j=0;
	while(i<s.length && j<t.length)
	{
		if(s.data[i]==t.data[j])
		{
			printf("%d %d %c %c\n",i,j,s.data[i],t.data[j]);
			i++;
			j++;
		}
		else{
			i=i-j+1;
			j=0;
		}
	}
	if(j>=t.length)
	{
		return (i-t.length);
	}
	else
	{
		return -1;
	}
}
void StrAssign(SqString &s,char cstr[])
{
	int i;
	for(i=0;cstr[i]!='\0';i++)
	{
		s.data[i]=cstr[i];
	}
	s.length=i;
}
int main()
{
	SqString S,T;
	char str1[20];
	char str2[20];
	gets(str1);
	gets(str2);
	StrAssign(S,str1);
	StrAssign(T,str2);
	index(S,T);
	return 0;
}
