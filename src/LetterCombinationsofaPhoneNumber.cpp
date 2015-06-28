//Given a digit string, return all possible letter combinations that the number could represent.
//
//A mapping of digit to letters (just like on the telephone buttons) is given below.
//
//
//
//Input:Digit string "23"
//Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//Note:
//Although the above answer is in lexicographical order, your answer could be in any order you want.
//
//Hide Tags Backtracking String




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
#include <map>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
		vector<string> result;
		unordered_map<char,string> m;
		string str;
		m['0']="";
		m['1']="";
		m['2']="abc";
		m['3'] = "def"; 
		m['4'] = "ghi"; 
		m['5'] = "jkl"; 
		m['6'] = "mno"; 
		m['7'] = "pqrs"; 
		m['8'] = "tuv"; 
		m['9'] = "wxyz";
		if(digits.size()==0)
			return result;
		DFS(digits,result,m,0,str);
		return result;
    }
private:
	void DFS(string &digits,vector<string> &result,unordered_map<char,string> &m,int step,string str){
		if(step>=digits.size()){
			result.push_back(str);
			return;
		}
//		int distance = digits[step];
		string temp = m[digits[step]];
		for(int i=0;i<temp.size();i++){
			DFS(digits,result,m,step+1,str+temp[i]);
		}
	}
};


int main()
{
	vector<string> result;
	Solution solute;
	result = solute.letterCombinations(string("23"));

	return 0;
}