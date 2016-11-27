#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int a=0;
	scanf("%d",&a );
	char *s=(char *) malloc(a);
	// char *s=(char *) calloc(a,sizeof(char));
	memset(s,0,a);
	int i=0;
	for(i=0;i<a;i++)
	{
		s[i]='a';
	}
	printf("%s\n",s );
	free(s);
	return 0;
}