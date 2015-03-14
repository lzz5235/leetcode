//Validate if a given string is numeric.
//
//Some examples:
//"0" => true
//" 0.1 " => true
//"abc" => false
//"1 a" => false
//"2e10" => true
//Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
//
//Update (2015-02-10):
//The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

//这道问题最大的难度在于用例，你是否相处足够多的用例

//2e10 -> true
//"." ->false
//"e5" -> false 
//".e3" ->false 
//"e++" -> false 
//"4e+" --> false

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <stdint.h>
#include <assert.h>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
		int count = s.size();
		int i=0;
		while(i<count&&s[i]==' ')
			i++;
		while(count>0&&s[count-1]==' ')
			count--;

		if(count==i||count==0)
			return false;

		if(s[i]=='-'||s[i]=='+')
			i++;
		bool num=false;
		bool dot=false;
		bool e_symbol=false;
		bool number=true;
		bool after_e=false;
		
		while(i<count){
			if(s[i]>='0'&&s[i]<='9'){
				i++;

				num = !e_symbol?true:num;
				after_e = e_symbol?true:after_e;// after e has integer
				continue;
			}
			if(e_symbol==true){// 'e' occured in the end. eg:2e+10    2000e-10  
				number = false;// last serval numbers!
				break;         // should not appear there!
			}

			if(s[i]=='.'&&dot==false){
				dot = true;
				i++;
			}
			else if(s[i]=='e'&&i<count-1){
				if(s[i+1]=='+'||s[i+1]=='-')
					i++;
				e_symbol = true;
				i++;
			}else{
				number=false;
				break;
			}
		}
		return number && num &&!(e_symbol ^ after_e);
    }
};

int main()
{
	Solution solute;
	bool result = solute.isNumber(string("2e+1000"));
	assert(result==true);
	result = solute.isNumber(string("4e+"));
	assert(result==false);
	result = solute.isNumber(string("e++"));
	assert(result==false);
	result = solute.isNumber(string(".e3"));
	assert(result==false);
	return 0;
}