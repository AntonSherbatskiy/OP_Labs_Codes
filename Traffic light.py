time = float(input("Укажіть час після початку чергової години роботи світлофора: "))

while time > 6:
    time -= 6
if 4 < time <= 6:
    print("Червоний колір")
if 3 < time <= 4:
    print("Жовтий колір")
if 0 < time <= 3:
    print("Зелений колір")