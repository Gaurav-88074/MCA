import random
import time
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
