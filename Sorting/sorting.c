#include <stdio.h>
int l[20], a[20], n, size;

void bubblesort()
{
    int t;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
}

void insertionsort()
{
    int i = 0, j, key;
    while (i < n - 1)
    {
        key = a[i + 1];
        j = i;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        i++;
    }
}

void selectionsort()
{
    int i = 0, j, min, t;
    while (i < n - 1)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        t = a[i];
        a[i] = a[min];
        a[min] = t;
        i++;
    }
}

void quicksort(int l, int r)
{
    int i, j, pivot, t;
    if (l < r)
    {
        i = l;
        j = r+1;
        pivot = a[l];
        do
        {
            do
            {
                i++;
            } while (a[i] <= pivot);
            do
            {
                j--;
            } while (a[j] > pivot);
            if (i < j)
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        } while (i < j);
        t = a[l];
        a[l] = a[j];
        a[j] = t;
        quicksort(l, j - 1);
        quicksort(j + 1, r);
    }
}

void merge(int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low, B[n];
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            B[k] = a[i];
            i++;
        }
        else
        {
            B[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        B[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = a[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
        a[i] = B[i];
}

void mergesort(int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(low, mid);
        mergesort(mid + 1, high);
        merge(low, mid, high);
    }
}

void heapify(int i)
{
    int l = 2 * i + 1, r = 2 * i + 2, largest = i, t;
    if (l < size && a[l] > a[largest])
        largest = l;
    if (r < size && a[r] > a[largest])
        largest = r;
    if (largest != i)
    {
        t = a[i];
        a[i] = a[largest];
        a[largest] = t;
        heapify(largest);
    }
}

void build_maxheap()
{
    int i = size / 2 - 1;
    while (i >= 0)
    {
        heapify(i);
        i--;
    }
}

void heapsort()
{
    int i, t;
    size = n;
    build_maxheap();
    i = n - 1;
    while (i >= 1)
    {
        t = a[0];
        a[0] = a[i];
        a[i] = t;
        size--;
        heapify(0);
        i--;
    }
}

void display()
{
    for (int i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\n");
}

void new ()
{
    for (int i = 0; i < n; i++)
        a[i] = l[i];
}

void main()
{
    int ch, c = 1, i = 0;
    printf("Enter number of elements in array:");
    scanf("%d", &n);
    while (i < n)
    {
        printf("Enter number:");
        scanf("%d", &l[i]);
        i++;
    }
    if (n > 0)
    {
        new ();
        printf("\nArray before sort         : ");
        display();
        bubblesort();
        printf("Array after bubble sort   : ");
        display();
        new ();
        printf("\nArray before sort         : ");
        display();
        insertionsort();
        printf("Array after insertion sort: ");
        display();
        new ();
        printf("\nArray before sort         : ");
        display();
        selectionsort();
        printf("Array after selection sort: ");
        display();
        new ();
        printf("\nArray before sort         : ");
        display();
        quicksort(0, n - 1);
        printf("Array after quick sort    : ");
        display();
        new ();
        printf("\nArray before sort         : ");
        display();
        mergesort(0, n - 1);
        printf("Array after merge sort    : ");
        display();
        new ();
        printf("\nArray before sort         : ");
        display();
        heapsort();
        printf("Array after heap sort     : ");
        display();
    }
    else
        printf("Array is empty");
}
