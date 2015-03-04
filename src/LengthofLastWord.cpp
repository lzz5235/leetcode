//Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
//
//If the last word does not exist, return 0.
//
//Note: A word is defined as a character sequence consists of non-space characters only.
//
//For example, 
//Given s = "Hello World",
//return 5.
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
		int len=0;
		int temp=0;
		if(strlen(s)==0)
			return 0;
		while(*s!='\0'){
			if(*s==' '){
				while(*s!=NULL&&*s==' ')
					s++;
			}
			else{
				temp = 0;
				while(*s!=NULL&&*s!=' ')
				{
					temp++;
					s++;
				}
				len = temp;
			}
		}
		return len;
    }
};

int main()
{
	const char *s=" ";
	Solution solute;
	int count = solute.lengthOfLastWord(s);

	printf("%d\n",count);
	return 0;
}