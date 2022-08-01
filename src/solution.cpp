#include"../inc/solution.hpp"
#include<climits>


int Solution::maxPoints(std::vector<std::vector<int>>& points)
{
    std::vector<std::pair<int,int>> params;  // will hold gradient and y-intercept for lines connecting each pair of points
    for(int i{0}; i<points.size(); ++i)
    {
        for(int j{i+1}; j<points.size(); ++j)
        {
            int grad = (points[j][0] == points[i][0])
                        ? INT_MAX
                        : (points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
            int icpt = points[i][1] - grad*points[i][0];
            params.push_back(std::make_pair(grad,icpt));
        }
    }
    int maxCount{0};
    for(auto vals : params)
    {
        int thisCount = std::count(params.begin(), params.end(),vals); 
        if(thisCount > maxCount){ maxCount = thisCount; }
    }
    return maxCount;
}