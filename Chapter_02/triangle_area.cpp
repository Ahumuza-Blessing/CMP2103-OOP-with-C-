// Geometry: area of a triangle) Write a program that prompts the user to enter the
// three points (x1, y1), (x2, y2), and (x3, y3) of a triangle and displays its area.
// The formula for computing the area of a triangle is s = (side1 + side2 + side3) / 2
// Area = sqrt(s(s-side1)(s-side2)(s-side3))
// Example: Enter three points for a triangle: 1.5, -3.4, 4.6, 5, 9.5, -3.4 
// The area of the triangle is 33.6
#include <iostream>
#include <cmath> // Required for sqrt() and pow()

using namespace std;

int main() {
    double x1, y1, x2, y2, x3, y3;

    cout << "Enter Vertex 1 (x y) in m: ";
    cin >> x1 >> y1;

    cout << "Enter Vertex 2 (x y) in m: ";
    cin >> x2 >> y2;

    
    cout << "Enter Vertex 3 (x y) in m: ";
    cin >> x3 >> y3;

    // 1. Calculate the lengths of the 3 sides using the distance formula
    double a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    double c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

    // 2. Calculate the semi-perimeter (s)
    double s = (a + b + c) / 2.0;

    // 3. Apply Heron's Formula
    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    // 4. Validate and Output (handling floating-point precision closely to 0)
    if (area < 1e-9) { 
        cout << "Error: The coordinates do not form a valid triangle (points are collinear)." << endl;
    } else {
        cout << "The area of the triangle is: " << area << " m^2" << endl;
    }

    return 0;
}

