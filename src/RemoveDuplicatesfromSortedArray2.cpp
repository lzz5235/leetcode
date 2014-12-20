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
		int index = 0;
		for (int i = 0; i < n; ++i) {
			if (i > 0 && i < n - 1 && A[i] == A[i - 1] && A[i] == A[i + 1])
				continue;
			A[index++] = A[i];
		}
		return index;
    }
};

int main()
{
	int a[] = {1,1,1,2,2,3};
	Solution solute;

    int result = solute.removeDuplicates(a,6);   
    return 0;
}