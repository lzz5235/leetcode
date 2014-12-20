//Follow up for "Remove Duplicates":
//What if duplicates are allowed at most twice?
//
//For example,
//Given sorted array A = [1,1,1,2,2,3],
//
//Your function should return length = 5, and A is now [1,1,2,2,3].

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<3)
			return n;
		int length=2;
		for(int i=2;i<n;i++)
		{
			if(A[length-2]!=A[i])
			{
				A[length]=A[i];
				length++;
			}
		}
		return length;
    }
};

int main()
{
	int a[] = {1,1,1,2,2,3};
	Solution solute;

    int result = solute.removeDuplicates(a,6);   
    return 0;
}