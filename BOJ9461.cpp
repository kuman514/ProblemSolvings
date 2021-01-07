#include <iostream>
#include <vector>

// Solving BOJ 9461

/*
    p(0) => 1
    p(1) => 1
    p(2) => 1
    p(3) => 2
    p(4) => 2
    p(5) => 3
    
    i => p(i - 5) + p(i - 1)
*/

class padovanSeq
{
    private:
        std::vector<long long> p;
        
    public:
        padovanSeq(): p(std::vector<long long>(6, 1))
        {
            p[3]++; p[4]++; p[5] += 2;
        }
        long long getP(const int n)
        {
            while(p.size() < n)
            {
                int i = p.size();
                p.push_back(p[i - 5] + p[i - 1]);
            }
            
            return p[n - 1];
        }
};

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int testcase;
    std::cin >> testcase;
    
    padovanSeq pvs;
    for(int i = 0; i < testcase; i++)
    {
        int input;
        std::cin >> input;
        std::cout << pvs.getP(input) << '\n';
    }
}
