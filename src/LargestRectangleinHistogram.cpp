//Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
//
//
//Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
//
//
//The largest rectangle is shown in the shaded area, which has area = 10 unit.
//
//For example,
//Given height = [2,1,5,6,2,3],
//return 10.
//https://oj.leetcode.com/problems/largest-rectangle-in-histogram/

//Ex:[2,1,5,6,2,3]
//在栈中维持一个递增的序列
//stk: <1,5,6>
//遇到下一个数字比6小的，就出栈，i-stk.top()-1倒着计算长度，高度为6,5,1
//非常巧妙！



#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
		stack<int> stk; //height index
		height.push_back(0);
		int max_area = 0;
		for(int i=0;i<height.size();){
			if(stk.empty()||height[i]>height[stk.top()])
				stk.push(i++);
			else{
				int temp = stk.top();
				stk.pop();
				max_area = max(max_area,height[temp]*(stk.empty()?i:i-stk.top()-1));
			}
		}
		return max_area;
    }
};

int main()
{
	int high[]={2,1,5,6,2,3};
	int high1[]={5,4,3,2,1};
	vector<int> height(high,high+sizeof(high)/sizeof(high[0]));
	Solution solute;
	int area = solute.largestRectangleArea(height);

	printf("%d\n",area);
	return 0;
}