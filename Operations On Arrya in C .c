#include <stdio.h>
// insert at specific pos
void insert_at_pos(int *arr, int element, int pos, int *arr_size) {
    arr_size++;
    // shifting elements>=arr[pos] to right side
    for (int i = arr_size - 1; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = element;
}
// binary search
int binary_search(int *arr, int *arr_size, int target) {
    // array must be in sorted order
    int start = 0, end = arr_size - 1;
    while (end > start + 1) {
        // F F F F F T T T T T T T
        // start stores F , end stores T
        int mid = start + (end - start) / 2;
        if (arr[mid] >= target) {
            end = mid;
        } else {
            start = mid;
        }
    }
    return end;
}
// printing array
void print(int *arr, int *arr_size) {
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// modify an element
void modify(int *arr, int *arr_size, int element, int pos) {
    arr[pos - 1] = element;
}
// swap
void swap(int *a, int *b) {
    int temp = a;
    a = b;
    b = temp;
}
// sorting an array

void sort_array(int *arr, int *arr_size) {
    // bubble sort
    for (int i = 0; i < arr_size - 1; i++) {
        for (int j = i + 1; j < arr_size; j++) {
            if (arr[j] < arr[i]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}
// deleting an element at specifi pos

void del_at_pos(int *arr, int *arr_size, int pos) {
    for (int i = pos - 1; i < arr_size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr_size--;
}
// finding smallest element
int smallest(int *arr, int *arr_size) {
    int minimum = arr[0];
    for (int i = 1; i < arr_size; i++) {
        if (arr[i] < minimum) minimum = arr[i];
    }
    return minimum;
}

// finding largest element

int largest(int *arr, int *arr_size) {
    int maximum = arr[0];
    for (int i = 1; i < arr_size; i++) {
        if (arr[i] > maximum) maximum = arr[i];
    }
    return maximum;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int element;
    scanf("%d", &element);
    int pos;
    scanf("%d", &pos);
    int target;
    scanf("%d", &target);
    // binary serach
    int binaryserach = binary_search(arr, n, target);
    printf("%d", binaryserach);

    // inserting at pos
    insert_at_pos(arr, element, pos, n);

    // printing
    print(arr, n);

    // modify
    modify(arr, n, element, pos);

    // sort
    sort_array(arr, n);

    // del at pos
    del_at_pos(arr, n, pos);

    // smallest
    int minimum = smallest(arr, n);
    printf("%d", minimum);
    // maximum
    int maximum = largest(arr, n);
    printf("%d", maximum);

    return 0;
}
// by Chandramani Dev Pathak, 3rd sem , Roll number -> 2204280100058