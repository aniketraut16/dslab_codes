#include <stdio.h>

void insertionSort(float arr[], int n) {
    int i, j;
    float key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void shellSort(float arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            float temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

int partition(float arr[], int low, int high) {
    float pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] > pivot) {
            i++;
            float temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    float temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(float arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(float arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    float L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(float arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void displayTopFive(float arr[], int n) {
    printf("\nTop five scores:\n");
    for (int i = 0; i < 5; i++) {
        printf("%.2f%%\n", arr[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    float percentages[n];

    printf("Enter the first year percentages of students:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%f", &percentages[i]);
    }

    // Sorting using Insertion Sort
    insertionSort(percentages, n);

    // Displaying sorted array
    printf("\nInsertion Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f%%\n", percentages[i]);
    }

    // Sorting using Shell Sort
    shellSort(percentages, n);

    // Displaying sorted array
    printf("\nShell Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f%%\n", percentages[i]);
    }

    // Sorting using Quick Sort
    quickSort(percentages, 0, n - 1);

    // Displaying sorted array
    printf("\nQuick Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f%%\n", percentages[i]);
    }

    // Sorting using Merge Sort
    mergeSort(percentages, 0, n - 1);

    // Displaying sorted array
    printf("\nMerge Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f%%\n", percentages[i]);
    }

    // Displaying top five scores
    displayTopFive(percentages, n);

    return 0;
}
