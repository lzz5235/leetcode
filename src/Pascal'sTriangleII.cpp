//Given an index k, return the kth row of the Pascal's triangle.
//
//For example, given k = 3,
//Return [1,3,3,1].
//
//Note:
//Could you optimize your algorithm to use only O(k) extra space?



#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <string>
#include <stdint.h>
#include <assert.h>
#include <set>
#include <unordered_map>
#include <queue>
#include <functional>
using namespace std;

// rowIndex is from 0!
//[
//     [1],       -- 0
//    [1,1],      -- 1
//   [1,2,1],     -- 2
//  [1,3,3,1],    -- 3
// [1,4,6,4,1]    -- 4
//]
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1,1);
		for(int i=2;i<=rowIndex;i++){
			int temp = result[0];
			for(int j=1;j<i;j++){
				int flag = temp+result[j];
				temp  = result[j];
				result[j] = flag; 
			}
		}
		return result;
    }
};

int main()
{
	vector<int> result;
	Solution solute;	
	result = solute.getRow(0);

	result = solute.getRow(1);

	result = solute.getRow(2);

	result = solute.getRow(5);

	return 0;
}