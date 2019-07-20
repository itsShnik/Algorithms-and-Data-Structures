#include <bits/stdc++.h>
using namespace std;

typedef struct _point{
	int x, y;
}point;

bool compareX(point p1, point p2){
	return p1.x < p2.x;
}

bool compareY(point p1, point p2){
	return p1.y < p2.y;
}

void printArray(point P[], int n){
	for(int i = 0; i< n; i++){
		cout << P[i].x << " " << P[i].y << endl;
 	}
}

float closest(point P[], int n);

float minDistance(point px[], point py[], int n);

float bruteForce(point p[], int n);

float dist(point p1, point p2);

int main(){
	point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}}; 
    int n = sizeof(P) / sizeof(P[0]); 
    cout << "The smallest distance is " << closest(P, n); 
    return 0;
}

float bruteForce(point p[], int n){
	float min = INT_MAX;
	for(int i = 0; i< n; i++){
		for(int j = i + 1; j < n; j++){
			if(dist(p[i], p[j]) < min){
				min = dist(p[i], p[j]);
			}
		}
	}
	return min;
}

float dist(point p1, point p2){
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float closest(point P[], int n){
	point px[n];
	point py[n];

	for(int i = 0; i< n; i++){
		px[i] = P[i];
		py[i] = P[i];
	}

	sort(px, px + n, compareX);
	sort(py, py + n, compareY);

	//printArray(px, n);
	//printArray(py, n);
	return minDistance(px, py, n);
}

float minDistance(point px[], point py[], int n){
	if(n <= 3){
		return bruteForce(px, n);
	}

	 
}