import sys

def srch(arr):
    return srch_h(arr, 0, len(arr)-1)

def srch_h(arr, low, high):
    mid = (high+low) // 2;
    if mid is arr[mid]:
        return mid
    elif mid < arr[mid] and mid > 0:
        return srch_h(arr, low, mid-1)
    elif mid > arr[mid] and mid < high:
        return srch_h(arr, mid+1, high)
    return -1


def main():
    example1 = [-1, 1, 51, 52, 53, 54]
    example2 = [-100, -99, -98, -97, -96, 5]
    example3 = [1, 2, 3, 4, 5, 100]
    print("srch1:\t", srch(example1))
    print("srch2:\t", srch(example2))
    print("srch3:\t", srch(example3))


if __name__ == "__main__":
    main()