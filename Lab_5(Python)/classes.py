class TIntNumber:
    Number = 0

    def __init__(self, binary_number):
        self.binary_number = binary_number

    def inc(self):
        self.Number += 1

    def dec(self):
        self.Number -= 1


class TIntNumber2(TIntNumber):

    def __init__(self, binary_number):
        super().__init__(binary_number)

        exponent = 0
        number = 0
        for i in range(len(binary_number) - 1, -1, -1):
            if binary_number[i] == '1':
                number += 2 ** exponent

            exponent += 1
        self.Number = number

    def ShowData(self):
        print(f"Int2: {self.binary_number}  Int10:  {self.Number}")

    def dec(self):
        super().dec()
        self.binary_number = bin(self.Number)

    def inc(self):
        super().inc()
        self.binary_number = bin(self.Number)


class TIntNumber8(TIntNumber):
    Number = 0

    def __init__(self, binary_number):
        super().__init__(binary_number)

        for i in range(len(binary_number)):
            self.Number += 8 ** (len(binary_number) - i - 1) * int(binary_number[i])

    def ShowData(self):
        print(f"Int8:  {self.binary_number}  Int10:  {self.Number}")

    def dec(self):
        super().dec()
        self.binary_number = oct(self.Number)

    def inc(self):
        super().inc()
        self.binary_number = oct(self.Number)
