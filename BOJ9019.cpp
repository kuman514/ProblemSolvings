#include <iostream>
#include <vector>
#include <queue>
#include <string>

// Solving BOJ 9019

struct traceInfo {
    bool visited;
    int from;
    char used;
};

struct queueInfo {
    int current;
    int from;
    char used;
};

inline int MethodD(int curnum)
{
    return (curnum * 2) % 10000;
}

inline int MethodS(int curnum)
{
    return (curnum <= 0) ? 9999 : (curnum - 1);
}

inline int MethodL(int curnum)
{
    return (curnum / 1000) + ((curnum % 1000) * 10);
}

inline int MethodR(int curnum)
{
    return (curnum % 10) * 1000 + (curnum / 10);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        // Get input
        int start, target;
        std::cin >> start >> target;
        
        std::vector<traceInfo> traceData(10000, {false, -1, '\0'});
        std::queue<queueInfo> next;
        
        // Finding the shortest path to the target
        next.push({start, -1, '\0'});
        while(!next.empty())
        {
            queueInfo cur = next.front();
            next.pop();
            
            // Is it already visited?
            if(traceData[cur.current].visited)
            {
                continue;
            }
            else
            {
                traceData[cur.current].visited = true;
                traceData[cur.current].from = cur.from;
                traceData[cur.current].used = cur.used;
            }
            
            if(cur.current == target)
            {
                break;
            }
            
            // Next values
            int valD = MethodD(cur.current);
            if(!traceData[valD].visited)
            {
                next.push({valD, cur.current, 'D'});
            }
            
            int valS = MethodS(cur.current);
            if(!traceData[valS].visited)
            {
                next.push({valS, cur.current, 'S'});
            }
            
            int valL = MethodL(cur.current);
            if(!traceData[valL].visited)
            {
                next.push({valL, cur.current, 'L'});
            }
            
            int valR = MethodR(cur.current);
            if(!traceData[valR].visited)
            {
                next.push({valR, cur.current, 'R'});
            }
        }
        
        // Traceback the route: from start to target
        std::vector<char> result;
        int tracer = target;
        while(tracer != start)
        {
            result.push_back(traceData[tracer].used);
            tracer = traceData[tracer].from;
        }
        
        // Print result
        for(std::vector<char>::reverse_iterator it = result.rbegin(); it != result.rend(); it++)
        {
            std::cout << *it;
        }
        std::cout << '\n';
    }
    
    return 0;
}
