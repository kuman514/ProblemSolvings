#include <iostream>
#include <cstdio>
#include <vector>

// Solving BOJ 1927
// implementing max/min vector heap

class Heap
{
    private:
    std::vector<int> heapTree;
    int isAsc;                      // for min heap (default = false, meaning it's max heap)
    
    public:
    Heap(const bool asc = false) : isAsc((asc) ? -1 : 1)
    {
        heapTree.push_back(0);
    }
    
    void InsertNode(const int &value)
    {
        const int end = heapTree.size();
        int pos = end;
        
        heapTree.push_back(value);
        
        // until the position gets to the root
        while(pos > 1)
        {
            // compare with parent's value
            if(isAsc * heapTree[pos] > isAsc * heapTree[pos / 2])
            {
                // swap with parent
                int swap = heapTree[pos / 2];
                heapTree[pos / 2] = heapTree[pos];
                heapTree[pos] = swap;
            }
            else
            {
                break;
            }
            
            // ascend to parent's position
            pos /= 2;
        }
    }
    
    int Pop(void)
    {
        // if empty, return 0
        if(heapTree.size() <= 1) return 0;
        
        int pos = 1;
        const int end = heapTree.size();
        
        // get the value of the root
        const int popn = heapTree[1];
        
        // move the last node to the root
        heapTree[1] = heapTree[heapTree.size() - 1];
        heapTree.erase(heapTree.end() - 1);
        
        // if empty after pop, end here
        if(heapTree.size() <= 1) return popn;
        
        // until the position gets to the end's parent
        while(pos < end / 2)
        {
            int target;
            
            // compare the descending siblings first
            if(isAsc * heapTree[pos * 2] > isAsc * heapTree[pos * 2 + 1])
            {
                target = pos * 2;
            }
            else
            {
                target = pos * 2 + 1;
            }
    
            // compare with the target
            if(isAsc * heapTree[pos] < isAsc * heapTree[target])
            {
                // swap with the target
                int swap = heapTree[target];
                heapTree[target] = heapTree[pos];
                heapTree[pos] = swap;
            }
            else
            {
                break;
            }
    
            pos = target;
        }

        return popn;
    }
};

int main(void)
{
    int n, input;
    //Heap heap;
    Heap heap(true);
    
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &input);

        if(input == 0)
        {
            printf("%d\n", heap.Pop());
        }
        else if(input > 0)
        {
            heap.InsertNode(input);
        }
    }

    return 0;
}
