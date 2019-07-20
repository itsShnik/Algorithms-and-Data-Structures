#include <bits/stdc++.h>
using namespace std;

typedef struct _job{
	int st, fi, wt;
}job;

bool compareFi(job j1, job j2){
	return j1.fi < j2.fi;
}

void printArray(int **w,int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << w[i][j] << " " ;
		}
		cout << endl;
	}
}

int prev(job jobs[], int i, int n){
	if(jobs[i].st < jobs[0].fi){
		return -1;
	}
	int lo = 0, hi = n - 1;
	while(lo <= hi){
		int mid = (lo + hi)/ 2;
		if(jobs[mid].fi < jobs[i].st){
			if(jobs[mid + 1].fi < jobs[i].st){
				lo = mid + 1;
			}else{
				return mid;
			}
		}else{
			hi = mid - 1;
		}
	}
}

void WISO(job jobs[], int n){
	//sort the jobs
	sort(jobs, jobs + n, compareFi);

	int w[n + 1] = {0};
	for(int i = 1; i <= n; i++){
		w[i] = max(w[i - 1], jobs[i - 1].wt + w[prev(jobs, i - 1, n) + 1]);
	}
	cout << "The max weight is " << w[n] << endl;
}

int main(){
	job jobs[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}, {8, 12, 400}, {9, 104, 248}, {14, 140, 845}, {4, 100, 425}};
	int n = sizeof(jobs)/ sizeof(jobs[1]);
	WISO(jobs, n);
}