//http://en.wikipedia.org/wiki/3SUM
//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
//Note:
//Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
//The solution set must not contain duplicate triplets.
//    For example, given array S = {-1 0 1 2 -1 -4},
//
//    A solution set is:
//    (-1, 0, 1)
//    (-1, -1, 2)
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
		vector<int> temp = num;
		vector<vector<int> > result;

		sort(temp.begin(),temp.end());

		int n = temp.size();
		for(int i=0;i<n-2;i++)
		{
			if(i>0&&temp[i]==temp[i-1]) 
				continue;//注意剪枝,因为已经是排序后的数列了，只比较相同元素的第一个即可!
			int a = temp[i];
			int start = i+1;
			int end = n-1;
			while (start < end )
			{
				int b = temp[start];
				int c = temp[end];
				if(a+b+c==0)
				{
					vector<int> vec;
					vec.push_back(a);
					vec.push_back(b);
					vec.push_back(c);
					result.push_back(vec);

					while(start<n&&temp[start]==temp[start+1]) 
						start++;
					while (end>0&&temp[end]==temp[end-1]) 
						end--;
					
					start++;
					end--;
				}
				else if(a+b+c>0)
				{
					while (end>0&&temp[end]==temp[end-1]) 
						end--;
					end--;
				}
				else
				{
					while(start<n&&temp[start]==temp[start+1]) 
						start++;
					start++;
				}
			}
		}
		sort(result.begin(),result.end());
		result.erase(unique(result.begin(),result.end()),result.end());
		return result;
	}
};


int main()
{
    int a[] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	Solution solute;
    vector<int> n(a, a+sizeof(a)/sizeof(int));

    vector<vector<int> > result = solute.threeSum(n);   
    return 0;
}