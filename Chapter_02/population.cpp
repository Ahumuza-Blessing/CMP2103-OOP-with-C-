// (Population projection) UBoS projects population based on the
// following assumptions:
// One birth every 7 seconds
// One death every 13 seconds
// One new immigrant every 45 seconds
// Write a program to display the population for each of the next five years. Assume the current population is 312032486 and one year has 365 days.
#include <iostream>
int main() {
    int population = 312032486;
    const int DAYS_IN_YEAR = 365;
    const int SECONDS_IN_YEAR = DAYS_IN_YEAR * 24 * 60 * 60;
    const int BIRTH_RATE = 7; 
    const int DEATH_RATE = 13;
    const int IMMIGRANT_RATE = 45;
    int births_per_year = SECONDS_IN_YEAR / BIRTH_RATE;
    int deaths_per_year = SECONDS_IN_YEAR / DEATH_RATE;
    int immigrants_per_year = SECONDS_IN_YEAR / IMMIGRANT_RATE;
    int net_popoulation_change_per_year = births_per_year - deaths_per_year + immigrants_per_year;
    std::cout << "Projected population for the next 5 years:\n";
    std::cout <<"-------------------------------------------\n";
    for (int year = 1; year <= 5; ++year){
        population += net_popoulation_change_per_year;
        std::cout << "Year " << year << ": " <<population << "\n";
    }
    return 0;


}

