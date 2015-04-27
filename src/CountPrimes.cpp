//Description:
//
//Count the number of prime numbers less than a non-negative number, n
//
//Hint: The number n could be in the order of 100,000 to 5,000,000.
//
//click to show more hints.
//
//References:
//How Many Primes Are There?
//
//Sieve of Eratosthenes
//
//Credits:
//Special thanks to @mithmatt for adding this problem and creating all test cases.


//http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

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

class Solution {
public:
    int countPrimes(int n) {
		int sum=0;
		int end = (int)sqrt(n-1);
		if (n<2)
			return 0;
		bool *primer_map = new bool[n];
		for(int i=0;i<n;i++)
			primer_map[i] = true;

		for(int i=2;i<=end;i++){
			if(primer_map[i]){
				for(int j=i*i;j<n;j+=i)
					primer_map[j] = false;
			}
		}

		for(int i=2;i<n;i++)
			if(primer_map[i])
				sum++;
		
		return sum;
    }
private:
	bool check_primer(int n){
		int end = (int)sqrt(n);
		for(int i=3;i<end;i+=2){
			if(n%i==0)
				return false;
		}
		return true;
	}
};

int main()
{
	int result;
	Solution solute;
	result = solute.countPrimes(10);
	return 0;
}