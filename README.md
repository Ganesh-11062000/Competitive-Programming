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

# Dynamic Programming

#### DP problems are categorized into two types:
1. Optimization [ maximize or minimize a function ]
2. Combinatorial [ find number of ways to do something ]  

#### Steps to follow:
1. find a recurrence relation
2. find the base case 
3. fill the 1-d or 2-d DP table [ aka memoization ]

#### DP problems can be 1-D or 2-D. How to decide?
1. try to think of a recursive solution
2. note down how many parameters are changing 
3. convert Recursive code (top-down) to DP solution (bottom-up)

#### 1-D DP problem - <br>
find the number of different ways to write N as the sum of 1, 3 and 4.<br>
step 1: Recurrence relation
```
DP[n] = DP[n-1] + DP[n-3] + DP[n-4]
```
step 2: Base case
```
DP[0] = DP[1] = DP[2] = 1, DP[3] = 2
```
step 3: fill the 1-D DP table
```
for(i = 4; i <= N; i++) 
{
    DP[i] = DP[i-1] + DP[i-3] + DP[i-4];
}
return DP[N]
```

#### 2-D DP problem - <br/>
finding the number of ways to reach a particular position from a given starting point in a 2-D grid <br>
Step 1: Recurrence relation
```
MinCost(i,j) = min(MinCost(i-1,j),MinCost(i,j-1)) + Cost[i][j]
```
Step 2: Base case
```
MinCost(0,j) = MinCost(0,j-1) + Cost[0][j]
MinCost(i,0) = MinCost(i-1,0) + Cost[i][0]
```
Step 3: fill the 2-D table
```
for(i = 1; i < X;i++)
{
    for(j = 1;j < Y;j++)
    {
	MinCost[i][j] = min(MinCost[i-1][j],MinCost[i][j-1]) + Cost[i][j];
    }
}
return DP[X-1][Y-1]
```

