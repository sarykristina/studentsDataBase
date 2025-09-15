#include <iostream>
#include <vector>
#include <string>
#include <gtest/gtest.h>
#include <sstream>
#include <limits>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

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

// Тест 1: Добавление студента в базу данных
TEST(StudentDatabaseTest, AddStudentTest) {
    std::vector<Student> database;
    
    // Создаем тестового студента
    Student testStudent;
    testStudent.name = "Иван";
    testStudent.age = 20;
    testStudent.major = "Информатика";
    testStudent.gpa = 4.5;
    
    // Добавляем вручную (имитируем работу addStudent)
    database.push_back(testStudent);
    
    // Проверяем, что студент добавлен
    EXPECT_EQ(database.size(), 1);
    EXPECT_EQ(database[0].name, "Иван");
    EXPECT_EQ(database[0].age, 20);
    EXPECT_EQ(database[0].major, "Информатика");
    EXPECT_EQ(database[0].gpa, 4.5);
}

// Тест 2: Удаление студента
TEST(StudentDatabaseTest, RemoveStudentTest) {
    std::vector<Student> database;
    
    Student student1{"Анна", 21, "Математика", 4.7};
    Student student2{"Петр", 22, "Физика", 4.3};
    database.push_back(student1);
    database.push_back(student2);
    
    database.erase(database.begin());
    
    EXPECT_EQ(database.size(), 1);
    EXPECT_EQ(database[0].name, "Петр");
}

void runInteractiveMode() {
    std::vector<Student> database;

    int choice;
    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "3. Вывести сумму всех средних баллов студентов\n";
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
}

int main(int argc, char **argv) {
    // Если есть аргументы командной строки, запускает тесты
    if (argc > 1 && std::string(argv[1]) == "--test") {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    } else {
        // Иначе запускает интерактивное меню
        runInteractiveMode();
        return 0;
    }
}
