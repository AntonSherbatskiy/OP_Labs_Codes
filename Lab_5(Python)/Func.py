from classes import TIntNumber2, TIntNumber8


def CreateInt2List():
    int2List = []

    while True:
        line = input("Enter INT2 number(press ctrl + X to stop)-> ")

        if line.lower() != 'no':
            int2 = TIntNumber2(line)
            int2List.append(int2)
            print(f"INT2: {int2.binary_number} --> {int2.Number}\n")
        else:
            break

    return int2List


def CreateInt8List():
    int8List = []

    while True:
        line = input('Enter INT8 number(press CTRL + X to stop)-> ')

        if line.lower() != 'no':
            int8 = TIntNumber8(line)
            print(f"INT8: {int8.binary_number} --> {int8.Number}\n")
            int8List.append(int8)
        else:
            break

    return int8List


def IncrementInt2(int2List):
    for i in range(len(int2List)):
        int2List[i].inc()
        int2List[i].ShowData()


def DecrementInt8(int8List):
    for i in range(len(int8List)):
        int8List[i].dec()
        int8List[i].ShowData()


def FindMin(int2List, int8List):
    minNum = int2List[0].Number

    for item in int2List:
        if item.Number < minNum:
            minNum = item.Number

    for item in int8List:
        if item.Number < minNum:
            minNum = item.Number

    return minNum
