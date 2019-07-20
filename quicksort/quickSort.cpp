#include <iostream>
using namespace std;

void printArray(int arr[], int size){
	for(int i = 0; i< size; i++){
		cout << arr[i] << " "; 
	}
	cout << endl;
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int arr[], int low, int high);

int partition(int arr[], int low, int high);

int main(){
	int arr[] = {8, 5, 9, 2, 4, 3, 1, 7, 6};
	printArray(arr, 9);
	quickSort(arr, 0, 8);
	printArray(arr, 9);
}

void quickSort(int arr[], int low, int high){
	if(low < high){
		//cout << "hello" << endl;
		int pi = partition(arr, low, high);
		//cout << "first pi : " << pi << endl;
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i = low - 1;
	//int j = low;
	for(int j = low; j < high; j++){
		if(arr[j] <= pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return i + 1;
}