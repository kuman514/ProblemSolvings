#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// Solving BOJ 17114

struct PosInfo {
    int w;
    int v;
    int u;
    int t;
    int s;
    int r;
    int q;
    int p;
    int o;
    int n;
    int m;
};

const PosInfo direction[22] = {
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
};

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    
    // Get sizes
    PosInfo size;
    std::cin >> size.m >> size.n >> size.o >> size.p >> size.q >> size.r >> size.s >> size.t >> size.u >> size.v >> size.w;
    
    // Initialize and get map
    int map[size.w][size.v][size.u][size.t][size.s][size.r][size.q][size.p][size.o][size.n][size.m];
    bool visited[size.w][size.v][size.u][size.t][size.s][size.r][size.q][size.p][size.o][size.n][size.m];
    int remaining = 0;
    std::vector<PosInfo> startTomato;
    for (int iw = 0; iw < size.w; iw++) {
        for (int iv = 0; iv < size.v; iv++) {
            for (int iu = 0; iu < size.u; iu++) {
                for (int it = 0; it < size.t; it++) {
                    for (int is = 0; is < size.s; is++) {
                        for (int ir = 0; ir < size.r; ir++) {
                            for (int iq = 0; iq < size.q; iq++) {
                                for (int ip = 0; ip < size.p; ip++) {
                                    for (int io = 0; io < size.o; io++) {
                                        for (int in = 0; in < size.n; in++) {
                                            for (int im = 0; im < size.m; im++) {
                                                std::cin >> map[iw][iv][iu][it][is][ir][iq][ip][io][in][im];
                                                switch (map[iw][iv][iu][it][is][ir][iq][ip][io][in][im]) {
                                                    case 1:
                                                        startTomato.push_back({iw, iv, iu, it, is, ir, iq, ip, io, in, im});
                                                        // No break since start tomatoes are also the remaining
                                                    case 0:
                                                        remaining++;
                                                        break;
                                                }
                                                visited[iw][iv][iu][it][is][ir][iq][ip][io][in][im] = false;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    // queue => first: pos, second: days
    std::queue< std::pair<PosInfo, int> > next;
    
    // Day 0
    for (int i = 0; i < startTomato.size(); i++) {
        next.push({startTomato[i], 0});
    }
    
    // BFS spread
    int days = 0;
    while (!next.empty()) {
        std::pair<PosInfo, int> cur = next.front();
        next.pop();
        
        if (visited[cur.first.w][cur.first.v][cur.first.u][cur.first.t][cur.first.s][cur.first.r][cur.first.q][cur.first.p][cur.first.o][cur.first.n][cur.first.m]) {
            continue;
        }
        
        // Paint visited
        visited[cur.first.w][cur.first.v][cur.first.u][cur.first.t][cur.first.s][cur.first.r][cur.first.q][cur.first.p][cur.first.o][cur.first.n][cur.first.m] = true;
        remaining--;
        if (days < cur.second) {
            days = cur.second;
        }
        
        // Seek next
        for (int i = 0; i < 22; i++) {
            PosInfo nextPos = {
                cur.first.w + direction[i].w,
                cur.first.v + direction[i].v,
                cur.first.u + direction[i].u,
                cur.first.t + direction[i].t,
                cur.first.s + direction[i].s,
                cur.first.r + direction[i].r,
                cur.first.q + direction[i].q,
                cur.first.p + direction[i].p,
                cur.first.o + direction[i].o,
                cur.first.n + direction[i].n,
                cur.first.m + direction[i].m
            };
            
            // Out of range?
            if (nextPos.w < 0 || nextPos.w >= size.w) {
                continue;
            }
            if (nextPos.v < 0 || nextPos.v >= size.v) {
                continue;
            }
            if (nextPos.u < 0 || nextPos.u >= size.u) {
                continue;
            }
            if (nextPos.t < 0 || nextPos.t >= size.t) {
                continue;
            }
            if (nextPos.s < 0 || nextPos.s >= size.s) {
                continue;
            }
            if (nextPos.r < 0 || nextPos.r >= size.r) {
                continue;
            }
            if (nextPos.q < 0 || nextPos.q >= size.q) {
                continue;
            }
            if (nextPos.p < 0 || nextPos.p >= size.p) {
                continue;
            }
            if (nextPos.o < 0 || nextPos.o >= size.o) {
                continue;
            }
            if (nextPos.n < 0 || nextPos.n >= size.n) {
                continue;
            }
            if (nextPos.m < 0 || nextPos.m >= size.m) {
                continue;
            }
            
            // Not 0?
            if (map[nextPos.w][nextPos.v][nextPos.u][nextPos.t][nextPos.s][nextPos.r][nextPos.q][nextPos.p][nextPos.o][nextPos.n][nextPos.m] != 0) {
                continue;
            }
            
            // Visited?
            if (visited[nextPos.w][nextPos.v][nextPos.u][nextPos.t][nextPos.s][nextPos.r][nextPos.q][nextPos.p][nextPos.o][nextPos.n][nextPos.m]) {
                continue;
            }
            
            next.push({nextPos, cur.second + 1});
        }
    }
    
    std::cout << (remaining == 0 ? days : -1) << '\n';

    return 0;
}
