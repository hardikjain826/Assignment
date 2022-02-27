/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(float *arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(float* arr, int l, int r)
{
	if (l < r) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(float* A, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

typedef struct chumma
{
    char name[15];
    float cg;
} student;

student* read_line(FILE *ptr, student* arr){

    char line[25];
    student* sdnt = malloc(sizeof(student));

    fscanf(ptr, "%s", line);
    sscanf(line, "%s,%f", sdnt->name, sdnt->cg);

    return sdnt;
}

void cleanup(student* arr, int size)
{
        free(arr);
}


/* Driver code */
int main()
{
	student* arr = malloc(sizeof(student) * 512);
    FILE *ptr;
    FILE *temp;
    ptr=fopen("gradesheet.txt","w+");

    read_line(ptr, arr);
	

    

	printf("\nSorted array is \n");
	mergeSort(arr, 0, 511);
	printArray(arr, 512);




///
    copy_file=fopen("sorted.txt","w+");



///











	return 0;
}
