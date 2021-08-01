#include <iostream>
#include <vector>

// Solving BOJ 11444

struct matrix {
    long long n0;
    long long n1;
    long long n2;
    long long n3;
};

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::vector<matrix> fiboMatrix;
    fiboMatrix.push_back({1LL, 1LL, 1LL, 0LL});
    
    /*
        Getting fibonacci using matrix multiply
    
        ( F(n+1) ) = ( 1 1 ) ( F(n)   )
        ( F(n)   )   ( 1 0 ) ( F(n-1) )
        
        ↓
    
        ( F(n+1) F(n)   ) = ( 1 1 ) ** n
        ( F(n)   F(n-1) )   ( 1 0 )
    */
    
    for (int i = 0; i < 60; i++) {
        long long n0 = fiboMatrix[i].n0;
        long long n1 = fiboMatrix[i].n1;
        long long n2 = fiboMatrix[i].n2;
        long long n3 = fiboMatrix[i].n3;
        
        /*
            ( n0 n1 ) * ( n0 n1 ) = ( n0**2+n1*n2 n0*n1+n1*n3 )
            ( n2 n3 )   ( n2 n3 )   ( n0*n2+n2*n3 n1*n2+n3**2 )
        */
        
        fiboMatrix.push_back({
            ((n0 * n0) + (n1 * n2)) % 1000000007LL,
            ((n0 * n1) + (n1 * n3)) % 1000000007LL,
            ((n0 * n2) + (n2 * n3)) % 1000000007LL,
            ((n1 * n2) + (n3 * n3)) % 1000000007LL
        });
    }
    
    long long input;
    std::cin >> input;
    
    // Divide by 2
    std::vector<bool> div2val1;
    long long n = input;
    while (n > 0LL) {
        if (n % 2LL == 0LL) {
            div2val1.push_back(false);
        } else {
            div2val1.push_back(true);
        }
        n /= 2LL;
    }
    
    // Get final values
    matrix finalValue = {1, 0, 0, 1};
    for (int i = 0; i < div2val1.size(); i++) {
        if (div2val1[i]) {
            long long x0 = finalValue.n0;
            long long x1 = finalValue.n1;
            long long x2 = finalValue.n2;
            long long x3 = finalValue.n3;
            
            long long y0 = fiboMatrix[i].n0;
            long long y1 = fiboMatrix[i].n1;
            long long y2 = fiboMatrix[i].n2;
            long long y3 = fiboMatrix[i].n3;
            
            /*
                ( x0 x1 ) * ( y0 y1 ) = ( x0*y0+x1*y2 x0*y1+x1*y3 )
                ( x2 x3 )   ( y2 y3 )   ( x2*y0+x3*y2 x2*y1+x3*y3 )
            */
            
            finalValue = {
                ((x0 * y0) + (x1 * y2)) % 1000000007LL,
                ((x0 * y1) + (x1 * y3)) % 1000000007LL,
                ((x2 * y0) + (x3 * y2)) % 1000000007LL,
                ((x2 * y1) + (x3 * y3)) % 1000000007LL
            };
        }
    }
    
    std::cout << finalValue.n1 << '\n';
    
    return 0;
}
