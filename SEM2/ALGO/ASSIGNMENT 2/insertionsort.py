import random
import time
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
