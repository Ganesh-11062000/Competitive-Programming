# Competitive-Programming

## Searching

1. Linear Search
```
int linearSearch(int arr[],int n, int val)
{
    for(int i = 0;i < n; i++)
    {
        if(arr[i] == val)
        {
            return i;
        }
    }
    
    return -1;
}
```

2. Binary Search
```
int binarySearch(int arr[],int n,int val)
{
    int low = 0,high = n-1;
    
    while(low <= high)
    {
        int mid = (low + high)/2;
        
        if(arr[mid] == val){
            return mid;
        }
        
        if(arr[mid] < val){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    
    return -1;
}
```

## Sorting

1. Bubble Sort

```
void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-1; j++ )
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
```

2. Selection Sort [ select minimum ]

```
void selectionSort(int arr[], int n)
{
    int minimum, min_index;
    
    for(int i = 0; i < n-1; i++)
    {
        minimum = arr[i];    
        min_index = i;
        
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] < minimum) 
            {
                minimum = arr[j];
                min_index = j;
            }
        }
        
        swap(arr[i],arr[j]);
    }
}
```

3. Insertion Sort

```
void insertionSort(int arr[], int n)
{
    int val;
    
    for(int i = 0; i < n-1; i++)
    {
        val = arr[i+1];
        
        for(j = i; j >= 0; j--)
        {
            if( arr[j] > val)
            {
                arr[j+1] = arr[j];
            }else{
                break;
            }
        }
        
        arr[j+1] = val;
    }
}
```

4. Merge Sort [ lb = lower bound & ub = upper bound]
```
void merge(int arr[], int lb, int mid, int ub)
{
    int temp[1000], i = lb, j = mid+1, k = 0;
    
    while(i <= mid && j <= ub)
    {
        if(arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
        }
    }
    
    while(i <= mid)
    {
        temp[k++] = arr[i++];
    }
    
    while(j <= ub)
    {
        temp[k++] = arr[j++];
    }
    
    k = 0;
    for(i = ub; i <= ub; i++)
    {
        arr[i] = temp[k++];
    } 
}
```

```
void mergeSort(int arr[], int lb, int ub)
{
    if(lb < ub)
    {
        int mid = (lb + ub)/2;
        mergesort(arr,lb,mid);
        mergesort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}
```

5. Quick Sort [ val is pivot element ]

```
int partition(int arr[], int lb, int ub)
{
    int val = arr[lb], down = lb+1, up = ub;
    
    while(down <= up)
    {
        while(down <= up && arr[down] <= val)
        {
            down++;
        }
        
        while(arr[up] > val)
        {
            up--;
        }
        
        if(down < up)
        {
            swap(arr[down],arr[up]);
        }
    }
    
    swap(arr[lb],arr[up]);    //index up is the correct position of pivot element
    
    return up;
}
```

```
void quickSort(int arr[],int lb,int ub)
{
    if(lb < ub)
    {
        int p = partition(arr,lb,ub);
        quickSort(arr,lb,p-1);
        quickSort(arr,p+1,ub);
    }
}
```

6. Counting Sort [ size(auxilary array) >= max(arr) & auxiliary array is initialized to 0]

```
void countingSort(int arr[], int aux[], int sortedArray[], int n)
{
    for(int i = 0; i < n; i++)
    {
        aux[arr[i]]++;
    }
    
    int k = 0,t;
    for(int i = 0; i <= max(arr); i++)
    {
         if(aux[i] != 0){
              t = aux[i];
              while(t--)
              {
                  sortedArray[k++] = i;
              }
         }  
    }
}
```
