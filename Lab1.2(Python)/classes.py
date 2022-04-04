class Student:
    def __init__(self, full_name, b_day,  study_form, group, subdivision, av_rating):
        self.full_name = full_name
        self.b_day = b_day
        self.study_form = study_form
        self.group = group
        self.subdivision = subdivision
        self.av_rating = av_rating


def input_data():
    student = Student
    if_continue = ''
    student_list = []

    while if_continue != 'no':
        student.full_name =  input("Enter full name-> ")
        student.b_day    =      input("Enter date of birth('dd.mm.yyyy')-> ")
        student.study_form = input("Enter study form-> ")
        student.group =      input("Enter group-> ")
        student.av_rating =  input("Enter average rating-> ")

        subdivision = ''
        for i in range(len(student.group)):
            if student.group[i].isalpha():
                subdivision += student.group[i].upper()
        student.subdivision = subdivision

        student_list.append(student)

        if_continue = input("Enter 'no' to stop-> ")

    for _ in student_list:
        student.print_info()
