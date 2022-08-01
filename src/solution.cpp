#include"../inc/solution.hpp"
#include<climits>


int Solution::maxPoints(std::vector<std::vector<int>>& points)
{
    std::vector<std::pair<float,float>> params;  // will hold gradient and y-intercept for lines connecting each pair of points
    for(int i{0}; i<points.size()-1; ++i)
    {
        for(int j{i+1}; j<points.size(); ++j)
        {
            float grad = (points[j][0] == points[i][0])
                        ? INT_MAX
                        : (float) (points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
            float icpt = (points[j][0] == points[i][0])
                        ? INT_MIN
                        : (float) points[i][1] - grad*points[i][0];
            params.push_back(std::make_pair(grad,icpt));
        }
    }
    int maxCount{0};
    for(auto vals : params)
    {
        int thisCount = std::count(params.begin(), params.end(), vals); 
        if(thisCount > maxCount){ maxCount = thisCount; }
    }
    return maxCount;
}