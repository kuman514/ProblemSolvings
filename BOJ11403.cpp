#include <iostream>
#include <cstdio>

// Solving BOJ 11403

int main(void)
{
	int N;
	do
	{
		scanf("%d", &N);
	}
	while(N < 1 || N > 100);

	bool matrix[N][N];
	int anyway[N][N];
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			char c;
			while((c = getchar()) != '0' && c != '1');
			matrix[i][j] = static_cast<bool>(c - '0');
			anyway[i][j] = matrix[i][j];
		}
	}

	for(int a = 0; a < N; ++a)
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				for(int k = 0; k < N; ++k)
					anyway[i][j] += anyway[i][k] * matrix[k][j];

	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
        	{
			putchar((anyway[i][j] != 0) ? '1' : '0');
            		putchar(' ');
        	}
        	putchar('\n');
	}

	return 0;
}
