#include <stdio.h>
int main ()
{
	int a=3,b=6;
	int t=0;
	t=a;
	a=b;
	b=t;
	printf ("a=3 b=6\n");
	printf ("a=%d b=%d\n",a,b);
	return 0;
}

