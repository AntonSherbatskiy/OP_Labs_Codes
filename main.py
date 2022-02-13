from func import *

if __name__ == "__main__":
    input_text("start_file.txt")                                              # Введення тексту у головний файл
    print("\n-------------START FILE-------------")
    print_text("start_file.txt")                                              # Виведення головного файлу

    distribute_lines("start_file.txt", "first_file.txt", "second_file.txt")   # Розподіл рядків

    print("------------FIRST FILE--------------")
    print_text("first_file.txt")                                              # Виведення файлу із парними рядками
    print("------------SECOND FILE-------------")
    print_text("second_file.txt")                                             # Виведення невідсортованого файлу

    sort_lines("second_file.txt")                                             # Сортування рядків

    print("\n-----SECOND FILE AFTER SORTING------")
    print_text("second_file.txt")                                             # Виведення відсортованого файлу
