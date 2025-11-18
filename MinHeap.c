#include<stdio.h>

void heapify(int arr[], int n, int i) {
     int smallest = i;
     int left = 2 * i + 1;
     int right = 2 * i + 2;
     if (left < n && arr[left] < arr[smallest]){
	     smallest = left;
     }
     if (right < n && arr[right] < arr[smallest]){
	     smallest = right;
     }
     if (smallest != i) {
	     int temp = arr[i];
	     arr[i] = arr[smallest];
	     arr[smallest] = temp;
	     heapify(arr, n, smallest);
     }
}
void heapsort(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--){
		heapify(arr, n, i);
	}
	for (int i = n - 1; i >= 0; i--){
		int temp = arr[0];
	        arr[0] = arr[i];
	        arr[i] = temp;
		heapify(arr,i,0);
	}
}
int main (){
	int n;
	printf("Enter number of elements: ");
	scanf("%d", &n);

	int arr[n];
        printf("Enter elements: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	heapsort(arr, n);
        printf("Sorted Array: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
        printf("\n");
        return 0;
}


