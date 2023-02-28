# include<bits/stdc++.h>
using namespace std;

int minStepsTo1(int n) {

	int * arr = new int[n + 1];
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	for (int i = 4; i <= n; i++) {
		arr[i] = 1 + min(arr[i - 1], min(arr[i - 2], arr[i - 3]));

	}
	int ans = arr[n];
	delete arr;
	return ans;
}


int staircase(int n) {
	int * arr = new int[n + 1];
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	for (int i = 4; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
	int ans=arr[n];
	delete arr;
	return ans;
}


int longestIncreasingSubseuqnce(int * arr, int n) {
//	4 3 9 7
	int * a = new int[n ];
	a[0] = 1;

	for (int i = 1; i < n; i++) {

		if (arr[i] > arr[i - 1]) a[i] = 1 + a[i - 1];
		else a[i] = a[i - 1];


	}
	int max = 0;
	
	for (int i = 0; i < n; i++) {
		if (a[i] > max)
		{
			max = a[i];
		}
	}

	return max;
}

// 1 2 3 1 2 3 4 2

//  int minCount(int n){
// arr[0]=1;
// arr[1]=2;
// arr[2]=3;

// }


int main() {



	cout << minStepsTo1(4) << endl;
	cout << staircase(1) << endl;
	int arr[] = {4, 3, 9, 7, 6, 8, 20};
	cout << longestIncreasingSubseuqnce(arr, 7) << endl;
}