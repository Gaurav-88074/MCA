import random
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

    def sort(self):
        n = len(self.arr)
        for i in range(n):
            min_idx = i
            for j in range(i+1, n):
                if self.arr[j] < self.arr[min_idx]:
                    min_idx = j
                self.count+=1
            self.arr[i], self.arr[min_idx] = self.arr[min_idx], self.arr[i]

    def display(self):
        print("Sorted array:", self.arr)

