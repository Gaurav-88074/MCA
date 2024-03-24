import matplotlib.pyplot as plt
import math
from selectionsort import SelectionSort
from bubblesort import BubbleSort
from insertionsort import InsertionSort
from mergesort import MergeSort
from quicksort import QuickSort
from heapsort import HeapSort

def compute(x):
    return x * math.log(x, 2)

x_values = []
y_nlogn = []
y_selectionSort = []
y_bubbleSort = []
y_insertionSort = []
y_mergeSort = []
y_quickSort = []
y_heapSort = []

for size in range(1, 10007, 500):
    x_values.append(size)
    y_nlogn.append(compute(size))
    
    obj = SelectionSort(size)
    obj.sort()
    y_selectionSort.append(obj.getComparisonCount())
    
    obj = BubbleSort(size)
    obj.sort()
    y_bubbleSort.append(obj.getComparisonCount())
    
    obj = InsertionSort(size)
    obj.sort()
    y_insertionSort.append(obj.getComparisonCount())
    
    obj = MergeSort(size)
    obj.sort()
    y_mergeSort.append(obj.getComparisonCount())
    
    obj = QuickSort(size)
    obj.sort()
    y_quickSort.append(obj.getComparisonCount())
    
    obj = HeapSort(size)
    obj.sort()
    y_heapSort.append(obj.getComparisonCount())

plt.plot(x_values, y_nlogn, label='nlogn', linestyle='--', marker='o')
plt.plot(x_values, y_selectionSort, label='SelectionSort', linestyle='-', marker='x')
plt.plot(x_values, y_bubbleSort, label='BubbleSort', linestyle='-.', marker='^')
plt.plot(x_values, y_insertionSort, label='InsertionSort', linestyle=':', marker='s')
plt.plot(x_values, y_mergeSort, label='MergeSort', linestyle='-', marker='*')
plt.plot(x_values, y_quickSort, label='QuickSort', linestyle='--', marker='v')
plt.plot(x_values, y_heapSort, label='HeapSort', linestyle='-.', marker='d')

plt.xlabel('Size of Array')
plt.ylabel('No. of Comparisons')
plt.title('Sorting Algorithms')
plt.legend()
plt.grid(True)  
plt.show()
