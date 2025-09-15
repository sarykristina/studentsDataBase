#include <iostream>
#include <vector>
#include <string>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

// Функция для добавления студента в базу данных
void addStudent(std::vector<Student>& database) {
    Student student;
    std::cout << "Введите имя студента: ";
    std::cin >> student.name;
    std::cout << "Введите возраст студента: ";
    std::cin >> student.age;
    std::cout << "Введите специальность студента: ";
    std::cin >> student.major;
    std::cout << "Введите средний балл студента: ";
    std::cin >> student.gpa;

    database.push_back(student);
    std::cout << "Студент добавлен в базу данных.\n";
}

// Функция для вывода всех студентов из базы данных
void displayStudents(const std::vector<Student>& database) {
        if (database.empty()) {
        std::cout << "База данных пуста.\n";
        return;
    }
    
    std::cout << "Список студентов:\n";
     for (size_t i = 0; i < database.size(); i++) {
     const Student& student = database[i];
        std::cout << i + 1 << ". ";
        std::cout << "Имя: " << student.name << "\n";
        std::cout << "Возраст: " << student.age << "\n";
        std::cout << "Специальность: " << student.major << "\n";
        std::cout << "Средний балл: " << student.gpa << "\n\n";
    }
}

void removeStudent(std::vector<Student>& database) {
    if (database.empty()) {
        std::cout << "База данных пуста. Удаление невозможно.\n";
        return;
    }

    displayStudents(database);
    std::cout << "Введите номер студента для удаления: ";
    size_t index;
    std::cin >> index;

    if (index < 1 || index > database.size()) {
        std::cout << "Ошибка: некорректный номер.\n";
        return;
    }

    database.erase(database.begin() + (index - 1));
    std::cout << "Студент успешно удалён из базы данных.\n";
}



int main() {
    std::vector<Student> database;

    int choice;
    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "3. Удалить студента\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        if (!(std::cin >> choice)) {
            std::cout << "Ошибка ввода! Пожалуйста, введите число.\n";
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(database);
                break;
            case 2:
                displayStudents(database);
                break;
             case 3:
                removeStudent(database);
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
