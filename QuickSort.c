#include<stdio.h>

int partition(int arr[], int st, int end){
	int idx = st-1;
	int pivot = arr[end];
	for(int j=st; j<end; j++){
		if(arr[j] <= pivot){
			idx++;
			int temp = arr[j];
			arr[j] = arr[idx];
			arr[idx] = temp;
		}
	}
	idx++;
	int temp = arr[end];
	arr[end] = arr[idx];
	arr[idx] = temp;
	return idx;
}

void quicksort(int arr[], int st,int end){
	if(st < end){
		int pi = partition(arr, st, end);
		quicksort(arr, st, pi-1);
		quicksort(arr, pi+1, end);
	}
}
int main() {
	int n;
	printf("Enter number of elements: ");
	scanf("%d", &n);

	int arr[n];
	printf("Enter elements: ");
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	quicksort(arr,0,n-1);
	printf("Sorted Array: ");
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}




