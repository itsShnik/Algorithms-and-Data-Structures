#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> &A){
	for(int i = 0; i < A.size(); i++){
		cout << A[i] << " ";
	}
	cout << endl;
}

int main(){
	int range;//range from 0 to range - 1

	cin >> range;
	//scan the input
	vector<int> A;
	int num;
	cin >> num;
	for(int i = 0; i < num; i++){
		int temp;
		cin >> temp;
		A.push_back(temp);
	}
	printVec(A);
	vector<int> C(range);
	for(int i = 0; i < num; i++){
		C[A[i]]++;
	}
	for(int i = 1; i < C.size(); i++){
		C[i] = C[i] + C[i - 1];
	}
	printVec(C);
	vector<int> B(A.size());
	for(int i = num - 1; i >= 0; i--){
		B[C[A[i]] - 1] = A[i];
		C[A[i]]--;
	}
	printVec(B);
}