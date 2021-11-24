n = input("Enter n: ")
prime = 2
element = 0

if(int(n) < 0 or int(n) == 0):
    print("Error, it`s not allowed to use negative numbers or 0!")
    exit(0)

while(int(element) < int(n)):
    prime_check = True

    for i in range(2, prime):
        if(prime % i == 0):
            prime_check = False

    if(prime_check == True):
        print(element + 1, (" element = "), prime)
        element = element + 1

    prime = prime + 1