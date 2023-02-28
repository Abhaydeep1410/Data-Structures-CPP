# include<bits/stdc++.h>
using namespace std;

// tip: to make code prettier use ctrl+alt+f


int fib(int n) {
	int * arr = new int[n + 1];
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];

	}
	int output = arr[n];
	delete [] arr;
	return output;
}


// alpha code : a number is given and codes are given to numbers as 1-a ,2-b .... 26-z , we have to find how many
// number of secreat codes can be generated
// as 23 can be bc and also w
int alphacode(int *input , int size) {
	int* arr = new int[size + 1];
	// if 0 or 1 lenght string
	arr[0] = 1;
	arr[1] = 1;

	for (int i = 2; i <= size; i++) {
		arr[i] = arr[i - 1];

		// taking example like 23 as w
		if (input[i - 2] * 10 + input[i - 1] <= 26) {
			arr[i] = arr[i] + arr[i - 2];
		}
	}
	int ans = arr[size];
	delete [] arr;
	return ans;

}

//longest increasing subsquence//
int longestSub(int *input, int n) {
//4 3 9 7

	int* arr = new int[n + 1];
	arr[0] = 1;
	for (int i = 1; i < n; i++) {
		arr[i] = 1;

		for (int j = i - 1; j >= 0; j--) {
			if (input[j] > input[i]) {
				continue;
			}


			int possibleAns = arr[j] + 1;
			if (possibleAns > arr[i]) {
				arr[i] = possibleAns;
			}
		}
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	return max;;

}



//staircase problem , person wants to take n steps - can take 1,2,3 step at a time
//find how many different ways he can take steps - ex- 4: 112 ,22 ,211,1111..

int staircase(int n) {
	// higher time complexity

	if (n == 0 || n == 1) {
		return 1;
	}
	if (n == 2) {
		return 2;
	}
	return staircase(n - 1) + staircase(n - 2) + staircase(n - 3);
}

int staircaseDP(int n) {
	int * arr = new int[n + 1];
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}

	int max = arr[n];
	delete [] arr;
	return max;

}


//we have to find how many different changes for a coin a person can give
// we have given change coins (denominations)
// ex=  we want 4 rupee exchange , we have 1 ,2 ruppe coin
// ans will be 1111, 112 ,22  (note 112 and 211 and 121 are same)

int coinExchange(int n, int *d, int numberOfDenominations) {

//lets take D0 denomination(chillar coin ) whether its a part of answer or not
	if (n == 0) {
		return 1;
	}
	if (numberOfDenominations == 0) {
		return 0;
	}
	if (n < 0) {
		return 0;
	}
// taking first denomination as a part of answer
	int first = coinExchange(n - d[0], d, numberOfDenominations);

// not taking first denominationas part of out answer
	int second = coinExchange(n, d + 1, numberOfDenominations - 1);
	return first + second;

}

int coinExchangeDP(int n, int *d, int numberOfDenominations, int** arr) {

//lets take D0 denomination(chillar coin ) whether its a part of answer or not
	if (n == 0) {
		return 1;
	}
	if (numberOfDenominations == 0) {
		return 0;
	}
	if (n < 0) {
		return 0;
	}
	if (arr[n][numberOfDenominations] > -1) {
		return arr[n][numberOfDenominations];
	}
// taking first denomination as a part of answer
	int first = coinExchange(n - d[0], d, numberOfDenominations);

// not taking first denominationas part of out answer
	int second = coinExchange(n, d + 1, numberOfDenominations - 1);
	arr[n][numberOfDenominations] = first + second;
	return first + second;

}


int main() {

// cout<<fib(5)<<endl;

	// int arr[] = {2, 5, 1, 1, 4};
// cout<<alphacode(arr,5);

	// int arr2[] = {4, 3, 9, 7, 6, 8, 20};
	// cout << longestSub(arr2, 7) << endl;


// cout<<staircase(8)<<endl;
// cout<<staircaseDP(8)<<endl;


	int d[2] = {1, 2};
	cout << coinExchange(4, d, 2) << endl;
////allocate a 2D array with value -1 here////
	int **array;
	array = new int *[5];
	for (int i = 0; i < 5; i++)
		array[i] = new int[3];


	memset(array, -1, sizeof(array));
	cout << coinExchangeDP(4, d, 2, array);


}





