import random
import time
import matplotlib.pyplot as plt
class BubbleSort:
    def __init__(self,size) -> None:
        self.arr = self.generateRandomArrayOfSize(size)
        self.count = 0
    def generateRandomArrayOfSize(self,x):
        res = []
        for i in range(x):
            res.append(random.randint(1,100000))
        return res
    def getComparisonCount(self):
        return self.count
    def measure_execution_time(self):
        start_time = time.time()
        self.sort()
        end_time = time.time()
        return end_time - start_time
    def sort(self):
        n = len(self.arr)
        for i in range(n):
            for j in range(0, n-i-1):
                if self.arr[j] > self.arr[j+1]:
                    self.count+=1;
                    self.arr[j], self.arr[j+1] = self.arr[j+1], self.arr[j]
class HeapSort:
    def __init__(self,size) -> None:
        self.arr = self.generateRandomArrayOfSize(size)
        self.count = 0
    def generateRandomArrayOfSize(self,x):
        res = []
        for i in range(x):
            res.append(random.randint(1,100000))
        return res
    def getComparisonCount(self):
        return self.count
    def measure_execution_time(self):
        start_time = time.time()
        self.sort()
        end_time = time.time()
        return end_time - start_time
    def heapify(self,n, i):
        arr = self.arr
        largest = i
        l = 2 * i + 1
        r = 2 * i + 2

        if l < n and arr[l] > arr[largest]:
            self.count+=1
            largest = l

        if r < n and arr[r] > arr[largest]:
            self.count+=1
            largest = r

        if largest != i:
            arr[i], arr[largest] = arr[largest], arr[i]
            self.count+=1
            self.heapify( n, largest)

    def sort(self):
        arr = self.arr
        n = len(arr)

        for i in range(n // 2 - 1, -1, -1):
            self.heapify( n, i)

        for i in range(n - 1, 0, -1):
            arr[i], arr[0] = arr[0], arr[i]
            self.heapify(i, 0)
class InsertionSort:
    def __init__(self,size) -> None:
        self.arr = self.generateRandomArrayOfSize(size)
        self.count = 0
    def generateRandomArrayOfSize(self,x):
        res = []
        for i in range(x):
            res.append(random.randint(1,100000))
        return res
    def getComparisonCount(self):
        return self.count
    def measure_execution_time(self):
        start_time = time.time()
        self.sort()
        end_time = time.time()
        return end_time - start_time
    def sort(self):
        array=self.arr
        for i in range(1, len(array)):
            key = array[i]
            j = i - 1
            while j >= 0 and key < array[j]:
                array[j + 1] = array[j]
                self.count+=1
                j -= 1
            array[j + 1] = key
class MergeSort:
    def __init__(self,size) -> None:
        self.arr = self.generateRandomArrayOfSize(size)
        self.count = 0
    def generateRandomArrayOfSize(self,x):
        res = []
        for i in range(x):
            res.append(random.randint(1,100000))
        return res
    def getComparisonCount(self):
        return self.count
    def measure_execution_time(self):
        start_time = time.time()
        self.sort()
        end_time = time.time()
        return end_time - start_time
    def merge(self, array1, size1, array2, size2):
        res = [None]*(size1+size2)
        p1 = 0
        p2 = 0
        index = 0

        while p1 < size1 and p2 < size2:
            if array1[p1] < array2[p2]:
                res[index] = array1[p1]
                p1 += 1
            else:
                res[index] = array2[p2]
                p2 += 1
            index += 1
            self.count+=1

        while p1 < size1:
            res[index] = array1[p1]
            p1 += 1
            index += 1
            self.count+=1

        while p2 < size2:
            res[index] = array2[p2]
            p2 += 1
            index += 1
            self.count+=1

        return res

    def mergeSort(self, array, start, end):
        if start == end:
            return [array[start]]
        mid = (start + end) // 2
        left = self.mergeSort(array, start, mid)
        right = self.mergeSort(array, mid + 1, end)

        return self.merge(left, len(left), right, len(right))
    def sort(self):
        self.mergeSort(self.arr,0,len(self.arr)-1)
class QuickSort:
    def __init__(self,size) -> None:
        self.arr = self.generateRandomArrayOfSize(size)
        self.count = 0
    def generateRandomArrayOfSize(self,x):
        res = []
        for i in range(x):
            res.append(random.randint(1,100000))
        return res
    def getComparisonCount(self):
        return self.count
    def measure_execution_time(self):
        start_time = time.time()
        self.sort()
        end_time = time.time()
        return end_time - start_time
    def partition(self, array, start, end):
        index = start - 1
        pivot = end
        for i in range(start, end):
            if array[i] < array[pivot]:
                index += 1
                array[index], array[i] = array[i], array[index]
            self.count+=1
        index += 1
        array[index], array[pivot] = array[pivot], array[index]
        self.count+=1
        return index

    def quickSort(self, array, start, end):
        if start < end:
            p = self.partition(array, start, end)
            self.quickSort(array, start, p - 1)
            self.quickSort(array, p + 1, end)
    def sort(self):
        self.quickSort(self.arr,0,len(self.arr)-1)
class SelectionSort:
    def __init__(self,size) -> None:
        self.arr = self.generateRandomArrayOfSize(size)
        self.count = 0
    def generateRandomArrayOfSize(self,x):
        res = []
        for i in range(x):
            res.append(random.randint(1,100000))
        return res
    def getComparisonCount(self):
        return self.count
    def measure_execution_time(self):
        start_time = time.time()
        self.sort()
        end_time = time.time()
        return end_time - start_time
    def sort(self):
        n = len(self.arr)
        for i in range(n):
            min_idx = i
            for j in range(i+1, n):
                if self.arr[j] < self.arr[min_idx]:
                    min_idx = j
                self.count+=1
            self.arr[i], self.arr[min_idx] = self.arr[min_idx], self.arr[i]

x_values = []
y_selectionSort = []
y_bubbleSort = []
y_insertionSort = []
y_mergeSort = []
y_quickSort = []
y_heapSort = []

for size in range(1, 10007, 500):
    x_values.append(size)
    
    obj = SelectionSort(size)
    y_selectionSort.append(obj.measure_execution_time())
    
    obj = BubbleSort(size)
    y_bubbleSort.append(obj.measure_execution_time())
    
    obj = InsertionSort(size)
    y_insertionSort.append(obj.measure_execution_time())
    
    obj = MergeSort(size)
    y_mergeSort.append(obj.measure_execution_time())
    
    obj = QuickSort(size)
    y_quickSort.append(obj.measure_execution_time())
    
    obj = HeapSort(size)
    y_heapSort.append(obj.measure_execution_time())
print("size bubblesort heapsort mergesort quicksort insertionsort selectionsort")
for i in range(len(x_values)):
    size = x_values[i]
    res = f"{size} {y_bubbleSort[i]} {y_selectionSort[i]} {y_mergeSort[i]} {y_quickSort[i]} {y_insertionSort[i]} {y_selectionSort[i]}"
    print(size,y_bubbleSort[i],y_selectionSort[i],y_mergeSort[i],y_quickSort[i],y_insertionSort[i],y_selectionSort[i])
# plt.plot(x_values, y_selectionSort, label='SelectionSort', linestyle='-', marker='x')
# plt.plot(x_values, y_bubbleSort, label='BubbleSort', linestyle='-.', marker='^')
# plt.plot(x_values, y_insertionSort, label='InsertionSort', linestyle=':', marker='s')
# plt.plot(x_values, y_mergeSort, label='MergeSort', linestyle='-', marker='*')
# plt.plot(x_values, y_quickSort, label='QuickSort', linestyle='--', marker='v')
# plt.plot(x_values, y_heapSort, label='HeapSort', linestyle='-.', marker='d')

# plt.xlabel('Size of Array')
# plt.ylabel('Execution Time')
# plt.title('Sorting Algorithms')
# plt.legend()
# plt.grid(True)  
# plt.show()


