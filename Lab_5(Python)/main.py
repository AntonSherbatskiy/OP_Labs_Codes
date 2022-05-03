from Func import *

if __name__ == "__main__":
    print("\n---------------------------INT2 CONVERT---------------------------")
    int2List = CreateInt2List()

    print("\n\n-------------------------INT8 CONVERT-------------------------")
    int8List = CreateInt8List()

    print("\n\n-------------------------INT2 INCREMENT-----------------------")
    IncrementInt2(int2List)

    print("\n\n------------------------INT8 DECREMENT------------------------")
    DecrementInt8(int8List)

    print(f"\nSmallest number:\t{FindMin(int2List, int8List)}")
