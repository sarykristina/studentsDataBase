#include <iostream>
#include <vector>
#include <string>
#include <limits>

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
    std::cout << "Список студентов:\n";
    for (const Student& student : database) {
        std::cout << "Имя: " << student.name << "\n";
        std::cout << "Возраст: " << student.age << "\n";
        std::cout << "Специальность: " << student.major << "\n";
        std::cout << "Средний балл: " << student.gpa << "\n\n";
    }
}

// Функция для удаления студента из базы данных
void deleteStudent(std::vector<Student>& database) {
    if (database.empty()) {
        std::cout << "База данных пуста. Нечего удалять.\n";
        return;
    }
    // Показываем список студентов с номерами
    std::cout << "Текущий список студентов:\n";
    for (size_t i = 0; i < database.size(); i++) {
        std::cout << i + 1 << ". " << database[i].name << "\n";
    }
    
    int index;
    std::cout << "Введите номер студента для удаления (1-" << database.size() << "): ";
    std::cin >> index;
    
    // Проверяем корректность ввода
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка: введите число.\n";
        return;
    }
    
    // Проверяем, что индекс в допустимом диапазоне
    if (index < 1 || index > static_cast<int>(database.size())) {
        std::cout << "Неверный номер студента.\n";
        return;
    }
    
    // Подтверждение удаления
    std::string confirmation;
    std::cout << "Вы уверены, что хотите удалить студента " << database[index-1].name << "? (y/n): ";
    std::cin >> confirmation;
    
    if (confirmation == "y" || confirmation == "Y") {
        // Удаляем студента
        database.erase(database.begin() + index - 1);
        std::cout << "Студент удален из базы данных.\n";
    } else {
        std::cout << "Удаление отменено.\n";
    }
}

int main() {
    std::vector<Student> database;

    int choice;
    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(database);
                break;
            case 2:
                displayStudents(database);
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
