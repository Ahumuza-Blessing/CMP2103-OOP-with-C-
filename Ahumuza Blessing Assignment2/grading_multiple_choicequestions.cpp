#include <iostream>
#include <vector>

// Class to represent an individual Student
class Student {
private:
    int id;
    std::vector<char> answers;
    int score;

public:
    // Constructor
    Student(int studentId, const std::vector<char>& studentAnswers) 
        : id(studentId), answers(studentAnswers), score(0) {}

    // Method to grade answers against the key
    void gradeTest(const std::vector<char>& key) {
        score = 0;
        for (size_t i = 0; i < answers.size(); ++i) {
            if (answers[i] == key[i]) {
                score++;
            }
        }
    }

    // Method to display results
    void displayResult() const {
        std::cout << "Student " << id << "'s correct count is " << score << std::endl;
    }
};

int main() {
    // 1. Define the correct answer key
    const std::vector<char> key = {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};

    // 2. Create list of Student objects with data from your table
    std::vector<Student> classroom = {
        Student(0, {'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}),
        Student(1, {'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'}),
        Student(2, {'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'}),
        Student(3, {'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'}),
        Student(4, {'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}),
        Student(5, {'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}),
        Student(6, {'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}),
        Student(7, {'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'})
    };

    // 3. Process and display grades using OOP principles
    for (Student& student : classroom) {
        student.gradeTest(key);
        student.displayResult();
    }

    return 0;
}
