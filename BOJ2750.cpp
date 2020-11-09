#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

// Solving BOJ 2750
// testing my C++ quicksort

void quicksort(std::vector<int>& array, int start, int size)
{
    // if the size is no more than 1, the array has been slready sorted
    if(size <= 1) return;
    
    // temporary copy array for pasting
    std::vector<int> less, equal, more;
    int pivot = array[start + (size / 2)];
    
    for(int i = 0; i < size; i++)
    {
        if(array[start + i] < pivot)      less.push_back(array[start + i]);
        else if(array[start + i] > pivot) more.push_back(array[start + i]);
        else                             equal.push_back(array[start + i]);
    }
    
    // pasting before sort
    int index = 0;
    
    for(int i = 0; i < less.size(); i++)
    {
        array[start + index] = less[i];
        index++;
    }
    
    for(int i = 0; i < equal.size(); i++)
    {
        array[start + index] = equal[i];
        index++;
    }
    
    for(int i = 0; i < more.size(); i++)
    {
        array[start + index] = more[i];
        index++;
    }
    
    int lstart = start, lsize = less.size();
    int estart = lstart + lsize, esize = equal.size();
    int mstart = estart + esize, msize = more.size();
    
    less.clear();
    less.resize(0);
    
    equal.clear();
    equal.resize(0);
    
    more.clear();
    more.resize(0);
    
    // recursive call
    quicksort(array, lstart, lsize);
    quicksort(array, mstart, msize);
}

int main(void)
{
    int N, input;
    std::vector<int> inputs;
    
    std::cin >> N;
    for(int i = 0; i < N; i++)
    {
        std::cin >> input;
        inputs.push_back(input);
    }
    
    quicksort(inputs, 0, inputs.size());
    for(int i = 0; i < inputs.size(); i++)
    {
        std::cout << inputs[i] << ' ';
    }
    
    return 0;
}
