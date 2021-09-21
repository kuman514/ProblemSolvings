#include &lt;iostream&gt;
#include &lt;vector&gt;

// Solving BOJ 11722

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // Get input
    int n;
    std::cin &gt;&gt; n;
    
    std::vector&lt;int&gt; values;
    for (int i = 0; i &lt; n; i++) {
        int input;
        std::cin &gt;&gt; input;
        values.push_back(input);
    }
    
    // Get longest decreasing
    std::vector&lt;int&gt; longestCount;
    int longest = 0;
    for (int i = 0; i &lt; n; i++) {
        int curLong = 0;
        for (int j = i - 1; j &gt;= 0; j--) {
            if (values[i] &lt; values[j] &amp;&amp; curLong &lt; longestCount[j]) {
                curLong = longestCount[j];
            }
        }
        
        if (longest &lt; curLong + 1) {
            longest = curLong + 1;
        }
        
        longestCount.push_back(curLong + 1);
    }
    
    std::cout &lt;&lt; longest &lt;&lt; '\n';
    
    return 0;
}
