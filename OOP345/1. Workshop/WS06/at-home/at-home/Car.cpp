// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:05 March, 2020

#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <locale>
#include <iomanip>

#include "Car.h"

namespace sdds {

    Car::Car(std::istream& is) {
        std::string tmpCond;

        std::getline(is, c_maker, ',');
        c_maker.erase(0, c_maker.find_first_not_of(" "));
        c_maker.erase(c_maker.find_last_not_of(" ") + 1);

        std::getline(is, tmpCond, ',');
        tmpCond.erase(0, tmpCond.find_first_not_of(" "));
        tmpCond.erase(tmpCond.find_last_not_of(" ") + 1);
        if (tmpCond.length() == 0) {
            c_condition = "new";
        }
        else {
            switch (tmpCond[0]) {
            case 'n':
                c_condition = "new";
                break;
            case 'u':
                c_condition = "used";
                break;
            case 'b':
                c_condition = "broken";
                break;
            default:
                throw "Invalid record!";
            }
        }

        is >> top_speed;
        if (is.fail()) {
            throw "Invalid record!";
        }
    }

    std::string Car::condition() const {
        return c_condition;
    }

    std::string Car::maker() const {
        return c_maker;
    }

    double Car::topSpeed() const {
        return top_speed;
    }

    void Car::display(std::ostream& out) const {
        out << "| " << std::setw(10) << maker() << " | " << std::setw(6) << condition() << " | " << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |";
    }

    std::ostream& operator<<(std::ostream& os, const Car& obj) {
        obj.display(os);
        return os;
    }
}