#include <bits/stdc++.h>
using namespace std;

int solve(int seq[], int n){
	int arr[n];
	int maxi = 1;

	for(int i = 0; i < n; i++){
		arr[i] = 1;
	}
	for(int i = 1; i < n; i++){
		for(int j = i - 1; j >= 0; j--){
			if(seq[j] < seq[i] && arr[j] + 1 > arr[i]){
				arr[i] = arr[j] + 1;
			}
		}
		maxi = max(maxi, arr[i]);
	}
	return maxi;
}

int main(){
	int seq[] = {2, 8, 6, 4, 5, 11, 7, 9, 13, 15};
	int n = sizeof(seq) / sizeof(seq[1]);
	cout << "The length of longest increasing subsequence is : ";
	cout << solve(seq, n);
	cout << endl;
}