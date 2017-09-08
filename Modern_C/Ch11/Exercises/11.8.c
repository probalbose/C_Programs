int *find_largest(int a[], int n) {
    int *largest, i;
    largest = &a[0];

    for (i = 0; i < n; i++) {
        if (a[i] > *largest)
            largest = &a[i];
    }

    return largest;
}
