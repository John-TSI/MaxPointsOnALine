#include"../inc/solution.hpp"
#include<map>
#include<tuple>
#include<climits>
#include<algorithm>


int Solution::maxPoints(std::vector<std::vector<int>>& points)
{
    std::map<std::pair<float,float>, int> lineMap{{}};
    std::vector<std::tuple<float,float,int>> tupleVec;
    float grad, icpt;

    for(int i{0}; i<points.size()-1; ++i)
    {
        for(int j{i+1}; j<points.size(); ++j)
        {
            if(points[j][0] == points[i][0]){ grad = INT_MAX; icpt = INT_MIN; }
            else
            { 
                grad = static_cast<float>(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                icpt = points[i][1] - grad*points[i][0]; 
            }

            auto lineParams = std::make_pair(grad, icpt);
            auto tupleParams = std::make_tuple(grad, icpt, points[i][1]);
            if( !lineMap.contains(lineParams) || std::find(tupleVec.begin(), tupleVec.end(), tupleParams) == tupleVec.end() )
            { 
                lineMap[lineParams] += 1; tupleVec.push_back(tupleParams);
            }
        }
    }

    auto maxCountIt = std::max_element
    (
        lineMap.begin(), lineMap.end(), [](const auto& p1, const auto& p2){ return p1.second < p2.second; }
    );
    return maxCountIt->second + 1;
}