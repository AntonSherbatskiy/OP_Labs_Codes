def input_text(start_file):                                            # Ф-ція для введення рядків
    with open(start_file, "w") as start_file:                          # Відкриття файлу у режимі запису
        while True:
            line = input("""Enter line(enter 'no' to stop): """)       # Змінна для збереження поточного рядка
            if line != "no" and line != "NO":                          # Запис рядка у файл
                start_file.write(line.lower() + '\n')
            else:
                break


def print_text(file):                                                  # Ф-ція для виведення рядків
    with open(file, "r") as fl:                                        # Відкриття файлу у режимі читання
        print(fl.read())                                               # Виведення рядків


def lines_to_array(file):                                              # Ф-ція для створення масиву рядків
    with open(file, "r") as fl:                                        # Відкриття файлу у режимі читання
        arr = []                                                       # Створення допоміжного масиву
        for line in fl:
            arr.append(line.replace('\n', ''))
        if len(arr) == 0:                                              # Перевірка на наявність рядків у файлі
            print('-----------File is empty!-----------')
            exit(0)
    return arr


def distribute_lines(start_file, first_file, second_file):             # Ф-ція для розподілу рядків
    lines_array = lines_to_array(start_file)                           # Створення допоміжного масиву
    with open(first_file, "w") as first_fl:                            # Відкриття файлу у режимі запису
        with open(second_file, "w") as second_fl:                      # Відкриття файлу у режимі читання
            for i in range(len(lines_array)):                          # Розподіл рядків
                line = lines_array[i][:]
                if i % 2 == 0:
                    first_fl.write(line + '\n')
                else:
                    second_fl.write(line + '\n')


def sort_lines(file):                                                  # Ф-ція для сортування рядків
    lines_array = lines_to_array(file)                                 # Створення допоміжного масиву
    if len(lines_array) == 0:                                          # Перевірка на наявність рядків у файлі
        print("File is empty")
    else:
        with open(file, "w+") as file:                                 # Відкриття файлу у режимі читання-запису
            n = int(input("Enter n(can`t be higher than " + str(len(lines_array)) + "): "))
            new_arr = []                                               # Створення допоміжного масиву для сортування
            while n > len(lines_array):                                # Сортування рядків
                n = int(input("Error, n can`t be higher than " + str(len(lines_array)) + ". Enter again: "))
            new_arr[:n] = sorted(lines_array[:n])
            new_arr[n:] = lines_array[n:]
            for line in new_arr:                                       # Запис нових рядків у файл
                file.write(line + "\n")
