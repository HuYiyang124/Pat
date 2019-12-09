#include <stdio.h>
#include <string.h>

int main()
{
	int a, b;
	int sum;
	scanf("%d %d", &a, &b);
	getchar();

	sum = a + b;
	if (sum < 0)
	{
		printf("-");
		sum = -sum;
	}
	char s[20];
	sprintf(s, "%d", sum);
	int len = strlen(s) / 3;
	int duo = strlen(s) % 3;

	duo = (duo == 0 ? 3 : duo);
	if (duo == 3)
		printf("%c%c%c", s[0], s[1], s[2]);
	else if (duo == 2)
		printf("%c%c", s[0], s[1]);
	else
		printf("%c", s[0]);
	for (int i = 1; i < len+1; i++)
	{
		if(s[duo + (i - 1) * 3])
			printf(",%c%c%c", s[duo + (i - 1) * 3], s[duo + (i - 1) * 3 + 1], s[duo + (i - 1) * 3 + 2]);
	}
	getchar();
	return 0;
}
