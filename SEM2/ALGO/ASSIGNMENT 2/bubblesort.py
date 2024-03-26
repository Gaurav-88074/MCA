import random
import time
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

    def display(self):
        print("Sorted array:", self.arr)

