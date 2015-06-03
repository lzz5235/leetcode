//Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//
//Try to solve it in linear time/space.
//
//Return 0 if the array contains less than 2 elements.
//
//You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
//
//Credits:
//Special thanks to @porker2008 for adding this problem and creating all test cases.


#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <string>
#include <stdint.h>
#include <assert.h>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int> &num) {
        if(num.empty() || num.size() < 2)
            return 0;
        int maxNum = *max_element(num.begin(), num.end());
        int minNum = *min_element(num.begin(), num.end());
        //average gap from minNum to maxNum.
        int gap = (maxNum - minNum - 1) / (num.size() - 1) + 1;
        //number of buckets
        int bucketNum = (maxNum-minNum)/gap+1;
        vector<int> bucketsMin(bucketNum, INT_MAX);
        vector<int> bucketsMax(bucketNum, INT_MIN);
        //put into buckets
        for(int i = 0; i < num.size(); i ++)
        {
            if(num[i] != maxNum && num[i] != minNum)
            {
                int buckInd = (num[i]-minNum)/gap;
                bucketsMin[buckInd] = min(bucketsMin[buckInd], num[i]);
                bucketsMax[buckInd] = max(bucketsMax[buckInd], num[i]);
            }
        }
        int maxGap = INT_MIN;
        int previous = minNum;
        for(int i = 0; i < bucketNum; i ++)
        {
            if(bucketsMin[i] == INT_MAX && bucketsMax[i] == INT_MIN)
                continue;   //empty
            //i_th gap is minvalue in i+1_th bucket minus maxvalue in i_th bucket 
            maxGap = max(maxGap, bucketsMin[i]-previous);
            previous = bucketsMax[i];
        }
        maxGap = max(maxGap, maxNum-previous);
        return maxGap;
    }
};
//class Solution {
//public:
//    int maximumGap(vector<int> &num) {
//        if (num.size() < 2) return 0;
//        // find the minimum and the maximum
//        int imax = num[0];
//        int imin = num[0];
//        for (int x : num) {
//            if (x > imax) imax = x;
//            if (x < imin) imin = x;
//        }
//        // each bucket has at most m numbers
//        int m = (imax - imin) / num.size() + 1;
//        // but we just need the minimum and the maximum of each bucket
//        vector<vector<int>> buckets((imax - imin) / m + 1);
//        for (int x : num) {
//            int i = (x - imin) / m;
//            if (buckets[i].empty()) {
//                buckets[i].reserve(2);
//                buckets[i].push_back(x);
//                buckets[i].push_back(x);
//            } else {
//                if (x < buckets[i][0]) buckets[i][0] = x;
//                if (x > buckets[i][1]) buckets[i][1] = x;
//            }
//        }
//        // calculate the maximal gap
//        int gap = 0;
//        int prev = 0;
//        for (int i = 1; i < buckets.size(); i++) {
//            if (buckets[i].empty()) continue;
//            gap = max(gap, buckets[i][0] - buckets[prev][1]);
//            prev = i;
//        }
//        return gap;
//    }
//};

int main()
{
	int result;
	Solution solute;
	int num[]={6,6,6,6,6,7,7,8,8,8};
	vector<int> nums(num,num+10);
	result = solute.maximumGap(nums);
//	assert(result==4);
	return 0;
}