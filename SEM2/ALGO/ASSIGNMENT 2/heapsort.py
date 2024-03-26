import random
import time
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

    def display(self):
        arr = self.arr
        print("Sorted array:", arr)

