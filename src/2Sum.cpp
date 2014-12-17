// Given an array of integers, find two numbers such that they add up to a specific target number.

// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

// You may assume that each input would have exactly one solution.

// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2

#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> result;
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> temp = numbers;
		

		sort(temp.begin(),temp.end());

		int n = temp.size();


		int low = 0;
		int high = n-1;
		int length=numbers.size();

		while( low < high)
		{
			if(temp[low]+temp[high]==target)
			{
				for(int i=0;i<length;i++)
				{
					if(numbers[i]==temp[low])
						result.push_back(i+1);
					else if(numbers[i]==temp[high])
						result.push_back(i+1);
					if(result.size()==2)
						break;
				}
				break;
			}
			else if(temp[low]+temp[high] > target)
			{
					high--;
			}
			else
			{ 
					low++;
			}
		}
		return result;
	}
};


int main()
{
    int a[] = {0,4,3,0};
	Solution solute;
    vector<int> n(a, a+sizeof(a)/sizeof(int));

    vector<int> result = solute.twoSum(n,0);   
    return 0;
}