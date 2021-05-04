#include <stdio.h>

int Factorial(int n)
{
	if( n == 0)
		return 1;
	else
	return n*Factorial(n-1);
}

int Fibo(int n)
{
	if(n == 1)
		return 0;
	else if(n == 2)
		return 1;
	else
		return Fibo(n-1) + Fibo(n-2);
}

int BSearchRecur(int ar[], int first, int last, int target)
{
	int mid;
	if( first > last)
		return -1;
	mid = (first + last) /2;

	if(ar[mid] == target)
		return mid;
	else if(target < ar[mid])
		return BSearchRecur(ar, first, mid-1, target);
	else
		return BSearchRecur(ar, mid+1, last, target);
}

void HanoiTowerMove(int num, char from, char by, char to)
{
	if(num == 1)
	{
		printf("원반1을 %c에서 %c로 이동 \n", from, to);
	}
	else {
		HanoiTowerMove(num-1, from, to, by);
		printf("원반%d을 %c에서 %c로 이동 \n", num, from, to);
		HanoiTowerMove(num-1, by, from, to);
	}
}


