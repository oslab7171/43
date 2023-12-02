#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student
struct Student {
    char student_name[50];
    int student_roll_no;
    int total_marks;
};

// Function to swap two students
void swap(struct Student* a, struct Student* b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform Heapify in Heap Sort
void heapify(struct Student arr[], int n, int i, int* swapCount) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].student_roll_no > arr[largest].student_roll_no)
        largest = left;

    if (right < n && arr[right].student_roll_no > arr[largest].student_roll_no)
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        (*swapCount)++;
        heapify(arr, n, largest, swapCount);
    }
}

// Function to perform Heap Sort
void heapSort(struct Student arr[], int n, int* swapCount) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, swapCount);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        (*swapCount)++;
        heapify(arr, i, 0, swapCount);
    }
}

// Function to perform partition in Quick Sort
int partition(struct Student arr[], int low, int high, int* swapCount) {
    struct Student pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].student_roll_no < pivot.student_roll_no) {
            i++;
            swap(&arr[i], &arr[j]);
            (*swapCount)++;
        }
    }

    swap(&arr[i + 1], &arr[high]);
    (*swapCount)++;
    return i + 1;
}

// Function to perform Quick Sort
void quickSort(struct Student arr[], int low, int high, int* swapCount) {
    if (low < high) {
        int pi = partition(arr, low, high, swapCount);

        quickSort(arr, low, pi - 1, swapCount);
        quickSort(arr, pi + 1, high, swapCount);
    }
}

// Function to print the array of students
void printArray(struct Student arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("Name: %-20s Roll No: %-5d Marks: %-5d\n", arr[i].student_name, arr[i].student_roll_no, arr[i].total_marks);
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student* students = (struct Student*)malloc(n * sizeof(struct Student));

    printf("Enter student details (Name RollNo Marks) for %d students:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", students[i].student_name, &students[i].student_roll_no, &students[i].total_marks);
    }

    // Copy the array for both sorting algorithms
    struct Student* heapSortArr = (struct Student*)malloc(n * sizeof(struct Student));
    struct Student* quickSortArr = (struct Student*)malloc(n * sizeof(struct Student));
    memcpy(heapSortArr, students, n * sizeof(struct Student));
    memcpy(quickSortArr, students, n * sizeof(struct Student));

    // Perform Heap Sort
    int heapSwapCount = 0;
    heapSort(heapSortArr, n, &heapSwapCount);
    printf("Heap Sort Result:\n");
    printArray(heapSortArr, n);
    printf("Number of swaps performed in Heap Sort: %d\n", heapSwapCount);

    // Perform Quick Sort
    int quickSwapCount = 0;
    quickSort(quickSortArr, 0, n - 1, &quickSwapCount);
    printf("Quick Sort Result:\n");
    printArray(quickSortArr, n);
    printf("Number of swaps performed in Quick Sort: %d\n", quickSwapCount);

    free(students);
    free(heapSortArr);
    free(quickSortArr);

    return 0;
}
