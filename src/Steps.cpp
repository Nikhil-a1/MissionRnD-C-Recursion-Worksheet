/*

	You have N steps to climb .
	You can either take one step or two steps at a time .
	You need to find the total number of ways you can reach N steps .

	Example : For N=4 , You can either reach 4 steps in following ways
	->1111
	->112
	->121
	->211
	->22
	So total number of ways is 5

	Input : A Integer denoting N (number of steps )
	Output : Return an Integer denoting the number of ways to reach N steps

	Example Input : get_steps(5)
	Example Output : Returns 8

	Note : Test Cases would be small <25.

*/
//time complexity o(logn)
#include "stdafx.h"
int fib(int);
int get_steps(int N)
	{
		int sum = 0;
		if (N <= 0)
			return 0;
		else
		{
			sum = fib(N);
			return sum;
		}
	}
	int fib(int N)
	{
		int sum = 0;
		if (N == 0 || N == 1)
			return 1;
		else
			return sum = sum + fib(N - 2) + fib(N - 1);
	}
