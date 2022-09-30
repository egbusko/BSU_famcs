#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int lowerBound(int ind, int* Ma, int left)
{
	int res = ind;
	int mid;
	while (Ma[ind] == Ma[res - 1])	{
		mid = (left + res) / 2;
		if (Ma[mid] == Ma[ind])
			res = mid;
		else
			left = mid;
	}
	return res;
}

int upperBound(int ind, int* M, int right)
{
	int res = ind;
	int mid;
	while (M[ind] == M[res])
	{
		mid = (right + res) / 2;
		if (M[mid] == M[ind])
			res = mid + 1;
		else
			right = mid;
	}
	return res;
}

int* bsearch(int key, int* M, int n)
{
	int* res = new int[3];
	int left = 0, right = n - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (key < M[mid])
			right = mid - 1;
		else if (key > M[mid])
			left = mid + 1;
		else
		{
			res[0] = 1;
			res[1] = lowerBound(mid, M, left);
			res[2] = upperBound(mid, M, right);
			return res;
		}
	}
	res[0] = 0;
	res[1] = left;
	res[2] = left;
	return res;
}


int main()
{
	int num, k, x, y;
	int* M, *ptr = new int[1];
	y = scanf("%d", &num);
	M = new int[num];
	for (int i = 0; i < num; i++)
	{
		y = scanf("%d", &M[i]);
	}
	y = scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		y = scanf("%d", &x);
		ptr = bsearch(x, M, num);
		printf("%d %d %d\n", ptr[0], ptr[1], ptr[2]);
		delete[] ptr;
	}

	delete[] M;
	//system("pause");
	return 0;
}