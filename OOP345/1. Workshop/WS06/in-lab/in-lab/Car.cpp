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

    Car::Car()
    {
        // c_tag = "";
        c_maker = "";
        c_condition = "";
        top_speed = 0;
    }

    Car::Car(std::istream& is) {
        std::string tmp = "";
        std::getline(is, tmp);

        size_t fieldOfc_maker = tmp.find(',', 2);
        c_maker = tmp.substr(1, fieldOfc_maker - 1);
        c_maker.erase(0, c_maker.find_first_not_of(" "));
        c_maker.erase(c_maker.find_last_not_of(" ") + 1);

        size_t fieldOfCondition = tmp.find(',', fieldOfc_maker + 1);
        c_condition = tmp.substr(fieldOfc_maker + 1, fieldOfCondition - fieldOfc_maker - 1);
        c_condition.erase(0, c_condition.find_first_not_of(" "));
        c_condition.erase(c_condition.find_last_not_of(" ") + 1);

        size_t fieldOfSpeed = tmp.length();
        top_speed = std::stod(tmp.substr(fieldOfCondition + 1, fieldOfSpeed - fieldOfCondition - 1));

    }

    std::string Car::condition() const {
        std::string tmp = "";
        if (c_condition == "n")
            tmp = "new";
        else if (c_condition == "u")
            tmp = "used";
        else if (c_condition == "b")
            tmp = "broken";

        return tmp;
    }

    std::string Car::maker() const {
        return c_maker;
    }

    double Car::topSpeed() const {
        return top_speed;
    }

    void Car::display(std::ostream& out) const {
        out << "| " << std::setw(10) << std::right << maker() << " | " << std::setw(6) << std::left << condition() << " | " << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |";
    }

    /*std::ostream& operator<<(std::ostream& os, const Car& obj) {
        obj.display(os);
        return os;
    }*/
}