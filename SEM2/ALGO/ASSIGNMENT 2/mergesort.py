import random
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
