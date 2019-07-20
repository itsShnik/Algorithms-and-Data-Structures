#include <bits/stdc++.h>
using namespace std;

vector<int> dpInc(vector<int> vec){
	vector<int> ret(vec.size(), 1);

	for(int i = 1; i < vec.size(); i++){
		for(int j = i - 1; j >= 0; j--){
			if(vec[j] < vec[i] && ret[j] + 1 > ret[i]){
				ret[i] = ret[j] + 1;
			}
		}
	}

	return ret;
}

vector<int> dpDec(vector<int> vec){
	vector<int> ret(vec.size(), 1);

	for(int i = vec.size() - 2; i >= 0; i--){
		for(int j = i + 1; j < vec.size(); j++){
			if(vec[j] < vec[i] && ret[j] + 1 > ret[i]){
				ret[i] = ret[j] + 1;
			}
		}
	}
	return ret;
}

int findMaxInTwo(vector<int> incVec, vector<int> decVec){
	int maxi = 1;
	for(int i = 0; i < incVec.size(); i++){
		maxi = max(maxi, incVec[i] + decVec[i] - 1);
	}
	return maxi;
}

int main(){
	vector<int> vec{1, 12, 3, 8, 5, 10, 11, 9, 16, 6, 2, 100};
	
	vector<int> incVec = dpInc(vec);
	vector<int> decVec = dpDec(vec);

	int ans = findMaxInTwo(incVec, decVec);
	cout << ans << endl;
}