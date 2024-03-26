import matplotlib.pyplot as plt
import math
from selectionsort import SelectionSort
from bubblesort import BubbleSort
from insertionsort import InsertionSort
from mergesort import MergeSort
from quicksort import QuickSort
from heapsort import HeapSort

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

plt.plot(x_values, y_selectionSort, label='SelectionSort', linestyle='-', marker='x')
plt.plot(x_values, y_bubbleSort, label='BubbleSort', linestyle='-.', marker='^')
plt.plot(x_values, y_insertionSort, label='InsertionSort', linestyle=':', marker='s')
plt.plot(x_values, y_mergeSort, label='MergeSort', linestyle='-', marker='*')
plt.plot(x_values, y_quickSort, label='QuickSort', linestyle='--', marker='v')
plt.plot(x_values, y_heapSort, label='HeapSort', linestyle='-.', marker='d')

plt.xlabel('Size of Array')
plt.ylabel('Execution Time')
plt.title('Sorting Algorithms')
plt.legend()
plt.grid(True)  
plt.show()
