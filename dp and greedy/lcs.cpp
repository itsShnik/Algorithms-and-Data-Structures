#include <bits/stdc++.h>
using namespace std;

void printVec(vector<vector<int> > vec){
	for(int i = 0; i < vec.size(); i++){
		for(int j = 0; j < vec[i].size(); j++){
			cout << vec[i][j] << " "	;
		}
		cout << endl;
	}
}

void printLCS(string x, string y, vector<vector<int> > trace){
	string lcs = "";
	int m = x.length(), n = y.length();
	int i = m, j = n;
	while(i > 0 && j > 0){
		//cout << "hello, i = " << i << " j = " << j << endl;
		if(trace[i][j] == 2){
			//cout << x[i];
			lcs = x[i - 1] + lcs;
			i--;
			j--;
		}else if(trace[i][j] == 1){
			i--;
		}else if(trace[i][j] == 0){
			j--;
		}else{
			break;
		}
	}
	cout << lcs << endl;
}

void findLCS(string x, string y){
	int m = x.length(), n = y.length();

	vector<vector<int> > tab(m + 1, vector<int> (n + 1, 0));
	vector<vector<int> > trace(m + 1, vector<int> (n + 1, -1));

	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(x[i - 1] == y[j - 1]){
				tab[i][j] = 1 + tab[i - 1][j - 1];
				trace[i][j] = 2;
			}else{
				int a = tab[i - 1][j];
				int b = tab[i][j - 1];
				tab[i][j] = max(a, b);
				if(a < b){
					trace[i][j] = 0;
				}else{
					trace[i][j] = 1;
				}
			}
		}
	}
	//printVec(tab);
	//printVec(trace);
	cout << "The longest common substring is : ";
	printLCS(x, y, trace);

}

int main(){
	string x, y;
	cout << "enter the strings :" << endl;
	cin >> x >> y;

	findLCS(x, y);
}