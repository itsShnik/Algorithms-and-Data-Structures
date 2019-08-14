#include <bits/stdc++.h> 
using namespace std; 

class Point 
{ 
	public: 
	int x, y; 
}; 

//global variables to find the absolute minimum
Point absMinP1, absMinP2;
float absMinD = FLT_MAX;

int compareX(const void* a, const void* b) 
{ 
	Point *p1 = (Point *)a, *p2 = (Point *)b; 
	return (p1->x - p2->x); 
} 

int compareY(const void* a, const void* b) 
{ 
	Point *p1 = (Point *)a, *p2 = (Point *)b; 
	return (p1->y - p2->y); 
} 

float dist(Point p1, Point p2) 
{ 
	float d =  sqrt( (p1.x - p2.x)*(p1.x - p2.x) + 
				(p1.y - p2.y)*(p1.y - p2.y) 
			);

	if(d < absMinD){
		absMinD = d;
		absMinP1.x = p1.x;
	    absMinP2.x = p2.x;
		absMinP1.y = p1.y;
		absMinP2.y = p2.y;	
	}
} 

float bruteForce(Point P[], int n) 
{ 
	float min = FLT_MAX; 
	for (int i = 0; i < n; ++i) 
		for (int j = i+1; j < n; ++j) 
			if (dist(P[i], P[j]) < min) 
				min = dist(P[i], P[j]); 
	return min; 
} 

float min(float x, float y) 
{ 
	return (x < y)? x : y; 
} 


float stripClosest(Point strip[], int size, float d) 
{ 
	float min = d; // Initialize the minimum distance as d 

	qsort(strip, size, sizeof(Point), compareY); 

	for (int i = 0; i < size; ++i) 
		for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j) 
			if (dist(strip[i],strip[j]) < min) 
				min = dist(strip[i], strip[j]); 

	return min; 
} 

float closestUtil(Point P[], int n) 
{ 
	if (n <= 3) 
		return bruteForce(P, n); 

	int mid = n/2; 
	Point midPoint = P[mid]; 

	float dl = closestUtil(P, mid); 
	float dr = closestUtil(P + mid, n - mid); 

	float d = min(dl, dr); 

	Point strip[n]; 
	int j = 0; 
	for (int i = 0; i < n; i++) 
		if (abs(P[i].x - midPoint.x) < d) 
			strip[j] = P[i], j++; 

	return min(d, stripClosest(strip, j, d) ); 
} 

float closest(Point P[], int n) 
{ 
	qsort(P, n, sizeof(Point), compareX); 

	return closestUtil(P, n); 
} 

void writeToSVGFile(Point P[], int n, float d, int coord){
	ofstream cout ("draw.svg");
	//cout.open("draw.svg", ofstream::app);
	cout<<"<svg xmlns=\"http://www.w3.org/2000/svg\">"<<endl
	<<"<rect width=\"100\" height=\"100\" style=\"fill:rgb(255,255,255); stroke-width:0; stroke:rgb(0,0,0)\" />"<<endl;

	for(int i = 0; i < n; i++)
	{
		if((P[i].x ==  absMinP1.x && P[i].y == absMinP1.y) || (P[i].x == absMinP2.x && P[i].y == absMinP2.y)){
			cout<< "<circle cx=\"" << P[i].x <<"\" cy=\""<<P[i].y<< "\" r=\""<< .1 << "\" stroke=\"black\" stroke-width =\"" << 0 << "\" fill=\"#000000\" />" << endl << "<circle cx=\"" << P[i].x <<"\" cy=\""<<P[i].y<< "\" r=\""<< d  << "\" stroke=\"black\" stroke-width =\"0\" fill=\"#fe83cc\" fill-opacity=\"0.4\"/>" << endl;

		}else{
			cout<< "<circle cx=\"" << P[i].x <<"\" cy=\""<<P[i].y<< "\" r=\""<< .1 << "\" stroke=\"black\" stroke-width =\"" << 0 << "\" fill=\"#000000\" />" << endl << "<circle cx=\"" << P[i].x <<"\" cy=\""<<P[i].y<< "\" r=\""<< d  << "\" stroke=\"black\" stroke-width =\"0\" fill=\"#0066ff\" fill-opacity=\"0.4\"/>" << endl;
		}
		if ( coord == 1)
		{
			cout<<"<text x=\""<<P[i].x+1<<"\" y=\""<<P[i].y+1<<"\" font-size=\""<<1<<"\" >"<<"("<<P[i].x<<", "<<P[i].y<<")"<<"</text>"<<endl;
		}
	}

	cout<< "<title>Bar</title>" << endl; 
	
	cout<< "</svg>" << endl;
}

int main() 
{ 
	//change the first line

	//take n as input
	int n;
	cout << "Enter the number of points" << endl;
	cin >> n;
	
	//input whether to print the points in the file
	int coord;
	cout << "Enter 1 if you want to print the coordinates, 0 otherwise" << endl;
	cin >> coord;
	//coord = 0 --> no else yes

	Point P[n];

	//generate n random points
	for(int i = 0; i < n; i++){
		P[i].x = rand() % 100;
		P[i].y = rand() % 100;	
	}

	//calculate the closest pair of points and the minimum distance between them
	float minDist = closest(P, n);

	//write to the svg file
	writeToSVGFile(P, n, minDist/2, coord);	
	
	return 0; 
} 




















