//There are two sorted arrays A and B of size m and n respectively. 
//Find the median of the two sorted arrays. 
//The overall run time complexity should be O(log (m+n)).
// Divide and Conquer Array Binary Search

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
	double find_kth(int A[], int m, int B[], int n,int k){
		//always m<=n
		if(m>n)
			return find_kth(B,n,A,m,k);
		if(m==0)
			return B[k-1];
		if(k==1)
			return min(A[0],B[0]);

		int ia = min(k/2,m),ib=k-ia;
		if(A[ia-1]<B[ib-1])
			return find_kth(A+ia,m-ia,B,n,k-ia);
		else if(A[ia-1]>B[ib-1])
			return find_kth(A,m,B+ib,n-ib,k-ib);
		else
			return A[ia-1];
	}
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int total = m+n;
		if(total%2==1)
			return find_kth(A,m,B,n,total/2+1);
		else
			return (find_kth(A,m,B,n,total/2+1)+find_kth(A,m,B,n,total/2))/2.0;
    }
};

int main()
{
	int A[]={2,3,7,8,10,14};
	int B[]={1,4,6,9,11,13};
	int lengthA=sizeof(A)/sizeof(A[0]);
	int lengthB=sizeof(B)/sizeof(B[0]);
	Solution solute;
	double median = solute.findMedianSortedArrays(A,lengthA,B,lengthB);
	printf("%lf\n",median);
	return 0;
}