#include"../inc/solution.hpp"
#include<map>
#include<tuple>
#include<climits>
#include<algorithm>


int Solution::maxPoints(std::vector<std::vector<int>>& points)
{
    float grad, icpt;  // gradient and y-intercept of line connnecting two points
    std::map<std::pair<float,float>, int> lineMap{{}};  // maps pairs of line params (grad, icpt) to an occurrence counter
    std::vector<std::tuple<float,float,int>> tupleVec;  // to avoid overcounting, maintain a vector of tuples of grad, icpt, and a y-value

    for(int i{0}; i<points.size()-1; ++i)
    {
        for(int j{i+1}; j<points.size(); ++j)  // consider a line connecting every pair of points in turn
        {
            if(points[j][0] == points[i][0]){ grad = INT_MAX; icpt = INT_MIN; }
            else
            { 
                grad = static_cast<float>(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);  // grad = Δy / Δx
                icpt = points[i][1] - grad*points[i][0];  // icpt = y - (grad * x) for either of the two points
            }

            auto lineParams = std::make_pair(grad, icpt);
            auto tupleParams = std::make_tuple(grad, icpt, points[i][1]);
            // insert lineParams and increment its count only if the tuple containing the y1-value used to extract the params does not exist
            if( std::find(tupleVec.begin(), tupleVec.end(), tupleParams) == tupleVec.end() )
            { 
                lineMap[lineParams] += 1; tupleVec.push_back(tupleParams);  // insert tuple into tupleVec to prevent overcounting
            }
        }
    }

    auto maxCountIt = std::max_element
    (
        // define a custom exeecution policy using a lambda to define how comparisons using < operator should be carried out
        lineMap.begin(), lineMap.end(), [](const auto& p1, const auto& p2){ return p1.second < p2.second; }
    );
    // lineMap has actually counted number of non-overlapping 'sub-lines' on each line, equal to one less than number of distinct points on the line 
    return maxCountIt->second + 1;
}