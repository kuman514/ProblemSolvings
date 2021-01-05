#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>

// Solving BOJ 9095

int main(void)
{
	int c;
	scanf("%d", &c);

	int n[c], a[c] = {0,};
	for(int i = 0; i < c; i++) scanf("%d", &n[i]);

    std::stack<int> p;
	for(int i = 0; i < c; i++)
	{
		for(int j = 1; j <= 3; j++) p.push(j);

		while(!(p.empty()))
		{
			int s = p.top();
			p.pop();
			
			if(s == n[i])
				a[i] += 1;
			else if(s < n[i])
				for(int j = 1; j <= 3; j++) p.push(s + j);
		}
	}

	for(int i = 0; i < c; i++) printf("%d\n", a[i]);
	
	return 0;
}
