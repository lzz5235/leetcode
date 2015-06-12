//Find the total area covered by two rectilinear rectangles in a 2D plane.
//
//Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
//Assume that the total area is never beyond the maximum possible value of int.
//
//Credits:
//Special thanks to @mithmatt for adding this problem, creating the above image and all test cases.

//https://leetcode.com/problems/rectangle-area/

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
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int width = max(0,min(C,G)-max(E,A));
		int height = max(0,min(D,H)-max(B,F));
		int area=0;
		area = (C-A)*(D-B) + (G-E)*(H-F) - width*height;
		return area;
    }
};

int main()
{
	Solution solute;
	int result;
	result = solute.computeArea(-3,0,3,4,0,-1,9,2);
	assert(result==45);
	return 0;
}