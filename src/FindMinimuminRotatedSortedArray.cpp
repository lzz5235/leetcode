//Find Minimum in Rotated Sorted Array Total Accepted: 27031 Total Submissions: 82764 My Submissions Question Solution 
//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//Find the minimum element.
//
//You may assume no duplicate exists in the array.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
		int begin=0,end=num.size();
		int Minimum=32547;
		if(num.size()==1)
			return num[begin];
		if(num.size()==2)
			return num[0]>num[1]?num[1]:num[0];
		end--;
		while(end-begin>1)
		{
			int mid=(begin+end)/2;
			if(num[begin] < num[mid] && num[mid] <num[end])
				return num[begin];

			if(num[begin] > num[mid])
			{
				end = mid;
			}
			
			if(num[mid] > num[end])
			{
				begin = mid;
			}
		}
		return num[end];
    }
};

int main()
{
	int A[7]={4,5,6,7,0,1,2};
	vector<int> vec(A,A+7);
	Solution solute;
	int Minimum = solute.findMin(vec);

	printf("Minimum=%d\n",Minimum);
}