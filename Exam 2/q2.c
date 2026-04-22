#include <stdio.h>
#include <stdlib.h>

/*
 * Allocates an array of 'count' integers using calloc.
 */
int* create_range(int start, int step, int count) {
    int* arr = calloc(count, sizeof(int));

    if(arr == NULL || count <= 0) return NULL;

    for(int i = 0; i < count; i++) {
        arr[i] = start + (step * (i));
    }

    return arr;
}

int main() {
    int start, step, count;
    
    // Read input: Start Step Count
    scanf("%d %d %d", &start, &step, &count);
    
    int* arr = create_range(start, step, count);
    
    if (arr != NULL) {
        for (int i=0; i<count; i++) printf("%d ", arr[i]);
        free(arr);
    } else {
        printf("NULL");
    }
    return 0;
}