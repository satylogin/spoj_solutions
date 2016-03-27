#include <iostream>
#include <stdlib.h>

using namespace std;

int _merge_sort(int arr[], int size);
int merge_sort(int arr[], int tmp[], int left, int right);
int merge(int arr[], int tmp[], int left, int mid, int right);

int main()
{
	int t; cin>>t;

	while (t--) {
		int n;
		cin>>n;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin>>arr[i];
		}
		int inv_count = _merge_sort(arr, n);
		cout<<inv_count<<endl;
	}	

	return 0;
}

int _merge_sort(int arr[], int size)
{
	int *tmp = (int *)malloc(sizeof(int) * size);
	return merge_sort(arr, tmp, 0, size-1);
}

int merge_sort(int arr[], int tmp[], int left, int right)
{
	int mid, inv_count = 0;
	if (right > left) {
		int mid = left + (right - left) / 2;
		inv_count = merge_sort(arr, tmp, left, mid);
		inv_count = inv_count + merge_sort(arr, tmp, mid+1, right);
		inv_count = inv_count + merge(arr, tmp, left, mid+1, right);
	}
	return inv_count;
}

int merge(int arr[], int tmp[], int left, int mid, int right)
{
	int i, j, k, inv_count = 0;
	i = left;
	j = mid;
	k = left;
	while ((i <= (mid - 1)) && (j <= right)) {
		if (arr[i] <= arr[j]) {
			tmp[k++] = arr[i++];
		} else {
			tmp[k++] = arr[j++];
			inv_count = inv_count + (mid - i);
		}
	}
	while (i <= (mid - 1)) {
		tmp[k++] = arr[i++];
	}
	while (j <= right) {
		tmp[k++] = arr[j++];
	}
	for (i = left; i <= right; i++) {
		arr[i] = tmp[i];
	}
	return inv_count;
}
