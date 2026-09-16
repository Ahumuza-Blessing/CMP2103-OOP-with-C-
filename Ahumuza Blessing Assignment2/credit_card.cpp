#include <iostream>

// Function prototypes as required by the problem statement
bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int getDigit(int number);
int sumOfOddPlace(long long number);
bool prefixMatched(long long number, int d);
int getSize(long long d);
long long getPrefix(long long number, int k);

int main() {
    long long cardNumber;
    std::cout << "Enter a credit card number as an integer: ";
    std::cin >> cardNumber;

    // Output updated to display the phrase instead of the raw number itself
    if (isValid(cardNumber)) {
        std::cout << "Credit card number is valid" << std::endl;
    } else {
        std::cout << "Credit card number is invalid" << std::endl;
    }

    return 0;
}

// Return true if the card number is valid
bool isValid(long long number) {
    int size = getSize(number);
    
    // Check length constraint (between 13 and 16 digits)
    if (size < 13 || size > 16) {
        return false;
    }
    
    // Check if prefix matches Visa (4), MasterCard (5), Amex (37), or Discover (6)
    if (!prefixMatched(number, 4) && 
        !prefixMatched(number, 5) && 
        !prefixMatched(number, 37) && 
        !prefixMatched(number, 6)) {
        return false;
    }
    
    // Perform Mod 10 Luhn check
    int totalSum = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
    return (totalSum % 10 == 0);
}

// Get the result from Step 2 (Double every second digit from right to left)
int sumOfDoubleEvenPlace(long long number) {
    int sum = 0;
    int position = 1; // 1-based index from right to left
    
    while (number > 0) {
        int digit = number % 10;
        if (position % 2 == 0) { // Even positions from right
            sum += getDigit(digit * 2);
        }
        number /= 10; // Process one digit at a time to handle internal zeros safely
        position++;
    }
    return sum;
}

// Return this number if it is a single digit, otherwise, return the sum of the two digits
int getDigit(int number) {
    if (number < 10) {
        return number;
    }
    return (number % 10) + (number / 10);
}

// Return sum of odd place digits in number from right to left
int sumOfOddPlace(long long number) {
    int sum = 0;
    int position = 1; // 1-based index from right to left
    
    while (number > 0) {
        int digit = number % 10;
        if (position % 2 != 0) { // Odd positions from right
            sum += digit;
        }
        number /= 10; // Process one digit at a time
        position++;
    }
    return sum;
}

// Return true if the digit d is a prefix for number
bool prefixMatched(long long number, int d) {
    int dSize = getSize(d);
    return getPrefix(number, dSize) == d;
}

// Return the number of digits in d
int getSize(long long d) {
    int count = 0;
    if (d == 0) return 1;
    while (d > 0) {
        count++;
        d /= 10;
    }
    return count;
}

// Return the first k number of digits from number. 
// If the number of digits in number is less than k, return number.
long long getPrefix(long long number, int k) {
    int size = getSize(number);
    if (size <= k) {
        return number;
    }
    
    long long prefix = number;
    for (int i = 0; i < (size - k); i++) {
        prefix /= 10;
    }
    return prefix;
}
