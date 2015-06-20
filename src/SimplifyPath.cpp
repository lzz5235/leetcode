//Given an absolute path for a file (Unix-style), simplify it.
//
//For example,
//path = "/home/", => "/home"
//path = "/a/./b/../../c/", => "/c"
//click to show corner cases.
//
//Corner Cases:
//Did you consider the case where path = "/../"?
//In this case, you should return "/".
//Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
//In this case, you should ignore redundant slashes and return "/home/foo".


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

// .. 上级目录
// . 当前目录
// /a/./b/../../c/  意味着存在..就把所有目录的当前项弹出。
//  . 意味着目录当前目录，只需要清空即可，目录已经保存在所有目录中。

class Solution {
public:
    string simplifyPath(string path) {
        string ret, curDir;
        vector<string> allDir;
        
        path.push_back('/');
        for(int i=0; i<path.size(); i++) {
            if(path[i]=='/') {
                if(curDir.empty()) {
                    continue;
                }
                else if(curDir==".") {
                    curDir.clear();
                }
                else if(curDir=="..") {
                    if(!allDir.empty())
                        allDir.pop_back();
                    curDir.clear();
                }
                else {
                    allDir.push_back(curDir);
                    curDir.clear();
                }
            }
            else {
                curDir.push_back(path[i]);
            }
        }
        
        
        for(int i=0; i<allDir.size(); i++) 
            ret.append("/"+allDir[i]);
        if(ret.empty()) ret = "/";
        return ret;
    }
};

int main()
{
	string result;
	Solution solute;	
	result = solute.simplifyPath(string("/home/"));
	assert(result == string("/home"));
	result = solute.simplifyPath(string("/a/./b/../../c/"));
	assert(result == string("/c"));
	result = solute.simplifyPath(string("/../"));
	assert(result == string("/"));
	result = solute.simplifyPath(string("/home//foo/"));
	assert(result == string("/home/foo"));
	return 0;
}