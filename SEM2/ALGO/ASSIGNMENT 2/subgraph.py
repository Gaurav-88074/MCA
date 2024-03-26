import matplotlib.pyplot as plt
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

fig, axs = plt.subplots(3, 2, figsize=(12, 10))

axs[0, 0].plot(x_values, y_selectionSort, label='SelectionSort', linestyle='-', marker='x', color='red')
axs[0, 0].set_title('SelectionSort')

axs[0, 1].plot(x_values, y_bubbleSort, label='BubbleSort', linestyle='-.', marker='^', color='blue')
axs[0, 1].set_title('BubbleSort')

axs[1, 0].plot(x_values, y_insertionSort, label='InsertionSort', linestyle=':', marker='s', color='green')
axs[1, 0].set_title('InsertionSort')

axs[1, 1].plot(x_values, y_mergeSort, label='MergeSort', linestyle='-', marker='*', color='orange')
axs[1, 1].set_title('MergeSort')

axs[2, 0].plot(x_values, y_quickSort, label='QuickSort', linestyle='--', marker='v', color='purple')
axs[2, 0].set_title('QuickSort')

axs[2, 1].plot(x_values, y_heapSort, label='HeapSort', linestyle='-.', marker='d', color='magenta')
axs[2, 1].set_title('HeapSort')

for ax in axs.flat:
    ax.set(xlabel='Size of Array', ylabel='Execution Time')
    ax.legend()

plt.tight_layout()
plt.show()
