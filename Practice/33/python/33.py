def create (lengthA, firstT = 0, stepP = 0):
    arr = [firstT]

    for i in range(1, lengthA):
        arr.append(arr[i - 1] + stepP)
    return arr
def sort (arr):
    z = 0
    i = 0
    j = 0
    for i in range(1, len(arr)):
        z = arr[i];
        j = i - 1
        while j >= 0 and z < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j+1] = z;
        
_print = print

def print(arr):
    _print ("")
    _print (arr)

length = int(input())
first = int(input())
step = int(input())

arr = create (length, first, step)
sort (arr)
print (arr)
    