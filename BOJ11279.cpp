#include <iostream>
#include <vector>
#include <algorithm>

// solving BOJ 11279

class Heap
{
    private:
        std::vector<int> arr;
        bool desc;
    
    public:
        Heap(bool DESC) : desc(DESC)
        {
            if(DESC)
            {
                std::make_heap(arr.begin(), arr.end(), std::less<int>());
            }
            else
            {
                std::make_heap(arr.begin(), arr.end(), std::greater<int>());
            }
        }
        
        void push(int val)
        {
            arr.push_back(val);
            
            if(desc)
            {
                std::push_heap(arr.begin(), arr.end(), std::less<int>());
            }
            else
            {
                std::push_heap(arr.begin(), arr.end(), std::greater<int>());
            }
        }
        
        void pop()
        {
            if(arr.empty()) return;
            
            if(desc)
            {
                std::pop_heap(arr.begin(), arr.end(), std::less<int>());
            }
            else
            {
                std::pop_heap(arr.begin(), arr.end(), std::greater<int>());
            }
            
            arr.pop_back();
        }
        
        bool empty()
        {
            return arr.empty();
        }
        
        int size()
        {
            return arr.size();
        }
        
        int top()
        {
            return arr[0];
        }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // Max heap is DESC = TRUE
    Heap maxHeap(true);
    
    int testcase;
    std::cin >> testcase;
    
    for(int i = 0; i < testcase; i++)
    {
        int input;
        std::cin >> input;
        
        switch(input)
        {
            case 0:
                if(maxHeap.empty())
                {
                    std::cout << 0 << '\n';
                }
                else
                {
                    std::cout << maxHeap.top() << '\n';
                    maxHeap.pop();
                }
                break;
            default:
                maxHeap.push(input);
                break;
        }
    }
    
    return 0;
}
