#include <stdlib.h>

void
f()
{
	char * c = (char *) malloc (1024);
	(void)c;
}

void
g()
{
	char * c = (char *) malloc (1024);
	(void)c;
}

int
main()
{
	f();
	g();
	return 0;
}
