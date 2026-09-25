class Human:
    def __init__ (self, Sex, age, name):

        self.Sex = Sex
        self.age = age
        self.name = name
    
    def __str__(self):
        return f"Name: {self.name}, Sex: {self.Sex}, Age: {self.age}"

class Woman(Human):
    def __init__(self, age, name):
        super().__init__("Female", age, name)

class Man(Human):
    def __init__(self, age, name):
        super().__init__("Male", age, name)

class Doctor(Human):
    def __init__(self, age, name):
        super().__init__("Doctor", age, name)

        
Man = Human("Male", 45, "john wiliams")
print(Man)