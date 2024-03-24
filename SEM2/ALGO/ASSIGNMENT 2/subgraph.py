import matplotlib.pyplot as plt
from selectionsort import SelectionSort
from bubblesort    import BubbleSort
from insertionsort import InsertionSort
from mergesort     import MergeSort
from quicksort     import QuickSort
from heapsort      import HeapSort
import math

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


fig, axs = plt.subplots(3, 2, figsize=(12, 10))


axs[0, 0].plot(x_values, y_nlogn, label='nlogn', color='black')
axs[0, 0].set_title('nlogn')


axs[0, 1].plot(x_values, y_selectionSort, label='SelectionSort', color='red')
axs[0, 1].set_title('SelectionSort')


axs[1, 0].plot(x_values, y_bubbleSort, label='BubbleSort', color='blue')
axs[1, 0].set_title('BubbleSort')


axs[1, 1].plot(x_values, y_insertionSort, label='InsertionSort', color='green')
axs[1, 1].set_title('InsertionSort')


axs[2, 0].plot(x_values, y_mergeSort, label='MergeSort', color='orange')
axs[2, 0].set_title('MergeSort')


axs[2, 1].plot(x_values, y_quickSort, label='QuickSort', color='purple')
axs[2, 1].set_title('QuickSort')

axs[2, 1].plot(x_values, y_heapSort, label='HeapSort', color='magenta')
axs[2, 1].set_title('HeapSort')

for ax in axs.flat:
    ax.set(xlabel='Size of Array', ylabel='No. of Comparisons')
    ax.legend()

plt.tight_layout()
plt.show()
