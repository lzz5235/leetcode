//Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//
//For example:
//
//    1 -> A
//    2 -> B
//    3 -> C
//    ...
//    26 -> Z
//    27 -> AA
//    28 -> AB 
//Credits:
//Special thanks to @ifanchu for adding this problem and creating all test cases.

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <string>
#include <stdint.h>
#include <assert.h>
#include <set>
using namespace std;

//A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
class Solution {
public:
    string convertToTitle(int n) {
		string symbol[]={"0","A","B","C","D","E","F","G","H","I","J","K","L","M","N"
							,"O","P","Q","R","S","T","U","V","W","X","Y","Z"};
		string result;
		if(n<=0)
			return "";

		int temp = n ;
		while(n){
			int flag = n%26;				
			if(flag==0){
				flag = 26;
				n--;
			}
			result +=symbol[flag];
			n /=26;
		}
		reverse(result.begin(),result.end());
		return result;
    }
};

int main()
{
	string result;
	Solution solute;
	result = solute.convertToTitle(26);
	assert(result==string("Z"));
	result = solute.convertToTitle(27);
	assert(result==string("AA"));
	result = solute.convertToTitle(28);
	assert(result==string("AB"));
	result = solute.convertToTitle(52);
	assert(result==string("AZ"));
	return 0;
}