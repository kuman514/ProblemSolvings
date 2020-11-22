#include <iostream>
#include <vector>
#include <queue>
#include <utility>

// solving BOJ 1926

const int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m;
    std::cin >> n >> m;
    
    // Get input
    std::vector< std::vector<bool> > field(n, std::vector<bool>(m, false));
    std::vector< std::vector<bool> > visited(n, std::vector<bool>(m, false));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int input;
            std::cin >> input;
            
            if(input == 1)
            {
                field[i][j] = true;
            }
            else
            {
                field[i][j] = false;
            }
        }
    }
    
    int count = 0;
    int largest = 0;
    
    // Seek fields in the drawing
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(field[i][j] && !visited[i][j])
            {
                count++;
                int size = 0;
                
                // first: row, second: column
                std::queue< std::pair<int, int> > next;
                next.push({i, j});
                
                while(!next.empty())
                {
                    std::pair<int, int> cur = next.front();
                    next.pop();
                    
                    // If already visited, go just next position
                    if(visited[cur.first][cur.second])
                    {
                        continue;
                    }
                    
                    visited[cur.first][cur.second] = true;
                    size++;
                    
                    for(int d = 0; d < 4; d++)
                    {
                        int nextR = cur.first + direction[d][0];
                        int nextC = cur.second + direction[d][1];
                        
                        if(nextR < 0 || nextR >= n) continue;
                        if(nextC < 0 || nextC >= m) continue;
                        if(visited[nextR][nextC]) continue;
                        
                        if(field[nextR][nextC])
                        {
                            next.push({nextR, nextC});
                        }
                    }
                }
                
                if(size > largest)
                {
                    largest = size;
                }
            }
        }
    }
    
    std::cout << count << '\n' << largest << '\n';
    
    return 0;
}
