#include <bits/stdc++.h>
using namespace std;

typedef struct _job{
	int st, fi, wt;
}job;

bool compareFi(job j1, job j2){
	return j1.fi < j2.fi;
}

void printArray(int w[][20],int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << w[i][j] << " " ;
		}
		cout << endl;
	}
}

void WIS(job jobs[], int n){
	int w[n][20] = {0};

	sort(jobs, jobs + n, compareFi);

	for(int i = 0; i< n; i++){
		for(int j = i + 2; j < n; j++){
			if(j - i <= 1){
				w[i][j] = 0;
			}else{
				int max = INT_MIN, a;
				for(int k = i + 1; k < j; k++){
					if(jobs[k].st >= jobs[i].fi && jobs[k].fi <= jobs[j].st){
						a = w[i][k] + w[k][j] + jobs[k].wt;
					}else{
						a = w[i][k] + w[k][j];
					}
					if(a > max){
						max = a;
					}
				}
				w[i][j] = max;
			}
		}
	}
	cout << "The table is : " << endl;
	printArray(w, n);
	cout << "The maximum weight is " << w[0][n - 1];
}
int main(){
	job jobs[] = {{0,0,0}, {3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}, {8, 12, 400}, {9, 104, 248}, {14, 140, 845}, {4, 100, 425}, {INT_MAX, INT_MAX, 0}};
	int n = sizeof(jobs)/ sizeof(jobs[1]);
	WIS(jobs, n);
}