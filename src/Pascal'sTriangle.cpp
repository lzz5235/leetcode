//Given numRows, generate the first numRows of Pascal's triangle.
//
//For example, given numRows = 5,
//Return
//
//[
//     [1],
//    [1,1],
//   [1,2,1],
//  [1,3,3,1],
// [1,4,6,4,1]
//]
//Hide Tags Array



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

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result;
		vector<int> temp;
		if(numRows==0)
			return result;
		
		temp.push_back(1);
		result.push_back(temp);
		
		if(numRows==1)			
			return result;
		for(int i=2;i<=numRows;i++){
			temp = result.back();
			vector<int>  new_temp;
			new_temp.push_back(1);
			int len = temp.size();
			for(int j=1;j<len;j++){
				int add = temp[j] + temp[j-1];
				new_temp.push_back(add);
			}
			new_temp.push_back(1);
			result.push_back(new_temp);
		}
        return result;
    }
};

int main()
{
	vector<vector<int>> result;
	Solution solute;	
	result = solute.generate(0);

	result = solute.generate(1);

	result = solute.generate(2);

	result = solute.generate(5);

	return 0;
}