#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>

// Solving BOJ 9663

struct block {
	int index[16];
	int level;
};

bool promising(block& b)
{
	bool swch = true;
	for(int k = 1; k < b.level && swch; k++)
	{
		if(b.index[b.level] == b.index[k] || std::abs(b.index[b.level] - b.index[k]) == std::abs(b.level - k)) swch = false;
		// same column or same row,column distance
		// not promising
	}

	return swch;
}

int main(void)
{
	std::stack<block> blockstk;
	int total = 0;	// total number of the answers
	int N = 0;		// input integer

	block tmp;
	for(int i = 0; i < 15; i++) tmp.index[i] = 0;
	while(!(1 <= N && N < 15)) scanf("%d", &N);

	if(N == 1) total = 1;

	tmp.level = 1;
	for(int i = 1; i <= N; i++)
	{
		tmp.index[tmp.level] = i;
		blockstk.push(tmp);
	}

	while(!blockstk.empty())
	{
		tmp = blockstk.top();
		blockstk.pop();
		tmp.level += 1;
	
		for(int i = 1; i <= N; i++)
		{
			tmp.index[tmp.level] = i;
			if(promising(tmp))
			{
				if(tmp.level == N)
				{
					// for temporary test
					// prints the answers
					/*
					for(int x = 1; x <= N; x++)
						printf("%d ", tmp.index[x]);
					putchar('\n');
					*/
	
					total++;
				}
				else
				{
					// expansion
					blockstk.push(tmp);
				}
			}
		}
	}

	printf("%d\n", total);
	
	return 0;
}
