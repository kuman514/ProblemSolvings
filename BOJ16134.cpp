#include <iostream>
#include <vector>

// Solving BOJ 16134

const long long mod = 1000000007LL;

long long power(long long val, long long count) {
    // Get squared multiples (mod 1000000007)
    std::vector<long long> mults;
    mults.push_back(val % mod);
    for (int i = 0; i <= 33; i++) {
        mults.push_back((mults[i] * mults[i]) % mod);
    }
    
    // Multiply by binary bits (mod 1000000007)
    long long curVal = 1LL;
    for (int i = 0; count > 0LL; i++) {
        if (count % 2LL == 1LL) {
            curVal *= mults[i];
            curVal %= mod;
        }
        count /= 2LL;
    }
    
    return curVal;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    // Calculate factorials (mod 1000000007)
    std::vector<long long> factorial;
    factorial.push_back(1LL);
    for (int i = 1; i <= 4000000; i++) {
        factorial.push_back((factorial[i - 1] * i) % mod);
    }
    
    int n, r;
    std::cin >> n >> r;
    
    /*
        nCr = n! / (r! * (n - r)!)
        
        If m is prime and a and m is coprime
        a ** m === a (mod m)
        => a ** (m - 1) === 1 (mod m)
        => a ** (m - 2) === a ** (-1) (mod m)
        
        1 / (r! * (n - r)!)
        = (r! * (n - r)!) ** (-1)
        === (r! * (n - r)!) ** (m - 2) (mod m)
        
        Therefore, nCr
        = n! * ((r! * (n - r)!) ** (-1))
        === n! * ((r! * (n - r)!) ** (m - 2)) (mod m)
    */
    
    const long long up = factorial[n];
    const long long down = (factorial[r] * factorial[n - r]) % mod;
    const long long downInv = power(down, mod - 2LL);
    
    std::cout << (up * downInv % mod) << '\n';

    return 0;
}
