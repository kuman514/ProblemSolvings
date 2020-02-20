#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

// solving BOJ 15686

const int house = 1;
const int chicken = 2;

// input the map size and the number of restaurants to survive
int span, survive;

// minimum chicken distance
int minChickenDist = 2000000000;

// will contain the position of spots
// first: row, second: column
std::vector< std::pair< int, int > > chickenSpot;
std::vector< std::pair< int, int > > houseSpot;

void calculateDistance(const int areasSelected, const int spotIndex, const std::vector<int>& minimumRange)
{
    // areasSelected: the number of currently selected chicken spots
    // spotIndex: the index of the current chicken spot
    // minimumRange: each house's nearst distance from any chicken spot
    
    // continue here
    
    // copy array minimumRange
    std::vector<int> curMinRange = minimumRange;
    
    // calculate chicken distances
    for(int i = 0; i < houseSpot.size(); i++)
    {
        int tmpDist = std::abs(chickenSpot[spotIndex].first - houseSpot[i].first) + std::abs(chickenSpot[spotIndex].second - houseSpot[i].second);
        curMinRange[i] = std::min(curMinRange[i], tmpDist);
    }
    
    // compare with the minimum chicken distance
    int distSum = 0;
    for(int i = 0; i < houseSpot.size(); i++)
    {
        distSum += curMinRange[i];
    }
    
    minChickenDist = std::min(minChickenDist, distSum);
    
    // check the number of areas selected
    if(areasSelected >= survive)
    {
        return;
    }
    
    // next chickenSpot
    for(int i = spotIndex + 1; i < chickenSpot.size(); i++)
    {
        calculateDistance(areasSelected + 1, i, curMinRange);
    }
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> span >> survive;
    
    // input spot type
    int spot;
    
    for(int i = 0; i < span; i++)
    {
        for(int j = 0; j < span; j++)
        {
            std::cin >> spot;
            
            if(spot == house)
            {
                houseSpot.push_back({i, j});
            }
            else if(spot == chicken)
            {
                chickenSpot.push_back({i, j});
            }
        }
    }
    
    std::vector<int> initChickenDist;
    
    for(int i = 0; i < houseSpot.size(); i++)
    {
        initChickenDist.push_back(2000000000);
    }
    
    for(int i = 0; i < chickenSpot.size(); i++)
    {
        calculateDistance(1, i, initChickenDist);
    }
    
    std::cout << minChickenDist << '\n';
    
    return 0;
}
