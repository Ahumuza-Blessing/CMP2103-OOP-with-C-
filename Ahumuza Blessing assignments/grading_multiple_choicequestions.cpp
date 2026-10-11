#include <iostream>

int main() {
    // 1. Define dimensions for students and questions
    const int NUM_STUDENTS = 8;
    const int NUM_QUESTIONS = 10;

    // 2. Two-dimensional array storing all student answers
    char studentAnswers[NUM_STUDENTS][NUM_QUESTIONS] = {
        {'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}, // Student 0
        {'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'}, // Student 1
        {'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'}, // Student 2
        {'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'}, // Student 3
        {'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}, // Student 4
        {'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}, // Student 5
        {'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}, // Student 6
        {'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}  // Student 7
    };

    // 3. One-dimensional array storing the correct answer key
    char answerKey[NUM_QUESTIONS] = {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};

    // 4. Outer loop to iterate through each student
    for (int i = 0; i < NUM_STUDENTS; i++) {
        int correctAnswersCount = 0; // Reset counter for the current student
        
        // Inner loop to grade each of the 10 questions
        for (int j = 0; j < NUM_QUESTIONS; j++) {
            if (studentAnswers[i][j] == answerKey[j]) {
                correctAnswersCount++;
            }
        }
        
        // Display the results
        std::cout << "Student " << i << "'s correct count is " << correctAnswersCount << std::endl;
    }

    return 0;
}
