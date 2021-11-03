time = float(input("Укажіть час після початку чергової години роботи світлофора: "))
col = ""

a = time % 6

if a > 4 and a <= 6:
    col = "Червоний"
elif a > 3 and a <= 4:
    col = "Жовтий"
elif a >= 0 and a <= 3:
    col = "Зелений"

print(col)
