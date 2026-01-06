#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int main()
{
	FILE* pf = fopen("File.txt", "r");
	if (NULL == pf)
	{
		printf("%s", strerror(errno));
		return 1;
	}
	int ch = fgetc(pf);
	printf("%c\n", ch);

	fclose(pf);
	pf = NULL;

	return 0;
}