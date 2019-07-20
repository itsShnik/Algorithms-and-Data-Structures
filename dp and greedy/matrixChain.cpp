#include <bits/stdc++.h>
using namespace std;

void printParenthesis(int i, int j, int n, vector<vector<int> > bracket, char &name){
	if(i == j){
		cout << name;
		name++;
		return;
	}
	cout << "(";
	printParenthesis(i, bracket[i][j], n, bracket, name);
	printParenthesis(bracket[i][j] + 1, j, n, bracket, name);
	cout << ")";
}

void matrixChainOrder(vector<int > p, int n){
	vector<vector<int > > m(n, vector<int>(n, 0));
	vector<vector<int > > bracket(n, vector<int>(n, 0));
	//cost for single matrix = 0
	//else cost = int_max
	//now constructing the bottom to top solution
	int cl; // chain length
	for(cl = 2; cl < n; cl++){
		for(int i = 1; i < n-cl+1; i++){
			int j = i + cl - 1;
			m[i][j] = INT_MAX;
			for(int k = i; k < j; k++){
				int val = m[i][k] + m[k + 1][j] + p[i - 1]*p[k]*p[j];
				if(val < m[i][j]){
					m[i][j] = val;
					bracket[i][j] = k;
				}
			}
		}
	}

	char name = 'A';
	cout << "The order of matrix chain multiplication is : ";
	printParenthesis(1, n - 1, n, bracket, name);
	cout << endl;
	cout << "The min number of multiplications are : " << m[1][n - 1] << endl;

}

int main(){
	vector <int > p{10, 25, 100, 50, 50, 10};
	matrixChainOrder(p, p.size());
	return 0;
}