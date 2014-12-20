//Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
//Note:
//Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
//The solution set must not contain duplicate quadruplets.
//    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
//
//    A solution set is:
//    (-1,  0, 0, 1)
//    (-2, -1, 1, 2)
//    (-2,  0, 0, 2)

#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<int> temp = num;
		vector<vector<int> > result;

		sort(temp.begin(),temp.end());

		int n = temp.size();
		for(int i=0;i<n-3;i++)
		{
			if(i>0&&temp[i]==temp[i-1]) 
				continue;//注意剪枝,因为已经是排序后的数列了，只比较相同元素的第一个即可!
			for(int j=i+1;j<n-2;j++)
			{
				int a = temp[i];
				int b = temp[j];
				int start = j+1;
				int end = n-1;
				while (start < end )
				{
					int c = temp[start];
					int d = temp[end];
					if(a+b+c+d==target)
					{
						vector<int> vec;
						vec.push_back(a);
						vec.push_back(b);
						vec.push_back(c);
						vec.push_back(d);
						result.push_back(vec);

						while(start<n&&temp[start]==temp[start+1]) 
							start++;
						while (end>0&&temp[end]==temp[end-1]) 
							end--;
					
						start++;
						end--;
					}
					else if(a+b+c+d>target)
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
		}
		sort(result.begin(),result.end());
		result.erase(unique(result.begin(),result.end()),result.end());
		return result;
    }
};

int main()
{
    int a[] = {-1,0,1,2,-1,-4};
	Solution solute;
    vector<int> n(a, a+sizeof(a)/sizeof(int));

    vector<vector<int> > result = solute.fourSum(n,-1);   
    return 0;
}