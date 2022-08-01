// https://leetcode.com/problems/max-points-on-a-line/

#include<iostream>
#include"../inc/solution.hpp"

int main()
{
	std::vector<std::vector<int>> points{{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
	Solution sol;
	std::cout << sol.maxPoints(points);
	return 0;
}

