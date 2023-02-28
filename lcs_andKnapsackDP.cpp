# include<bits/stdc++.h>
using namespace std;


int LongestCommonSubsequenceLength(string s1, string s2) {
	int** a = new int *[s1.size() + 1];

	for (int i = 0; i <= s1.size(); i++) {
		a[i] = new int[s2.size() + 1];
	}
	//intitalize 0th col 0
	for (int i = 0; i <= s1.size(); i++) {
		a[i][0] = 0;
	}
	//intitalize 0th row 0
	for (int i = 0; i <= s1.size(); i++) {
		a[0][i] = 0;
	}


	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				//if char match of two string
				a[i][j] = 1 + a[i - 1][j - 1];
			} else {

				a[i][j] = max(a[i - 1][j], a[i][j - 1]);
			}
		}
		
	}
	int ans = a[s1.size()][s2.size()];
	delete [] a;
	return ans;
}


//problem is weight is given we have to take weight from weigth profit matrix such that to maximize profit and weights less than equal to given weight
int knapsackDP(int * w, int*p, int maxW, int n) {

	int ** arr = new int*[n + 1];
	for (int i = 0; i <= n; i++) {
		arr[i] = new int[n + 1];
	}

	
	for (int i = 0; i <= n; i++) {
		arr[i][0] = 0;
	}
for (int i = 0; i <= n; i++) {
		arr[0][i] = 0;
	}



	for(int i=1;i<=n;i++){
		for(int j=0;j<=maxW;j++){

			arr[i][j]=arr[i-1][j];
			if(w[i-1]<=maxW){
				arr[i][j]=max(arr[i-1][j],p[i-1]+arr[i-1][j-w[i-1]]);
			}


		}
	}
	int ans=arr[n][n];
	delete [] arr;
	return ans;


}









int main() {

	// cout << LongestCommonSubsequenceLength("lbct", "ct");

	int val[]={5,4,8,6};
	int wt[]={1,2,3,5};
	cout<<knapsackDP(wt,val,5,4);


}