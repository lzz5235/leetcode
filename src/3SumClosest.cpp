////http://en.wikipedia.org/wiki/3SUM
//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
//    For example, given array S = {-1 2 1 -4}, and target = 1.
//
//    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define INT_MAX 2147483647

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        vector<int> temp = num;

		sort(temp.begin(),temp.end());

		int n = temp.size();
		int Closest=INT_MAX;
		int result=0;

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
				if(a+b+c==target)
				{
					return target;
				}
				else
				{
					if(abs(a+b+c-target)<Closest)
					{
						Closest=abs(a+b+c-target);
						result=a+b+c;
					}
					if(a+b+c-target>0)
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
		return result;
    }
};


int main()
{
    int a[] = {-1,2,1,-4};
	Solution solute;
    vector<int> n(a, a+sizeof(a)/sizeof(int));

    int result = solute.threeSumClosest(n,1);   
    return 0;
}