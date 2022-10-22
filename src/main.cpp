#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ListInArray.h"

void printFillMenu();

void fillRandom();

void fillValue();

void fillValueByInd();

void getElementMenu();

void checkValue();

void changeValue();

void deleteValueMenu();

ListInArray<int> list;

int main() {
//    list.print();
//    for (int i = 1; i < 6; ++i) {
//        list.push(i);
//    }
//    list.print();
//    std::cout << "Len = " << list.getLength() << " is Empty? " << (list.isEmpty() ? "true" : "false") << std::endl;
//    for (auto l = list.begin(); l != list.end(); l++) {
//        std::cout << *l << " ";
//
//    }
//    std::cout << std::endl;
//    std::cout << list.findElement(1) << std::endl;
//    std::cout << list[4] << std::endl;
//    list.popInd(1);
//    list.pop(1);
//    list.print();
//    list.push(6, 1);
//    list.push(6, 0);
//    list.print();
//    for (auto l = list.begin(); l != list.end(); l++) {
//        std::cout << *l << " ";
//
//    }
//    std::cout << std::endl;

    int command = -1;
    while (command != 10) {
        printf("\tThis is interactive menu for List in Array structure.\n"
               "What you wanna do?\n"
               "1) Fill the list.\n"
               "2) Get list length.\n"
               "3) Clear the list.\n"
               "4) Check is the list empty.\n"
               "5) Check is a value in the list.\n"
               "6) Get value from the list.\n"
               "7) Change value from the list.\n"
               "8) Delete value from the list.\n"
               "9) Print values.\n"
               "10) Exit.\n"
               ":");
        if (scanf("%d", &command) != 1) {
            while (getchar() != '\n') {}
        }
        system("clear");
        switch (command) {
            case 1:
                printFillMenu();
                break;
            case 2:
                std::cout << "List len = " << list.getLength() << std::endl;
                break;
            case 3:
                list.clear();
                break;
            case 4:
                std::cout << "Is list empty?" << (list.isEmpty() ? "true" : "false") << std::endl;
                break;
            case 5:
                checkValue();
                break;
            case 6:
                getElementMenu();
                break;
            case 7:
                changeValue();
                break;
            case 8:
                deleteValueMenu();
                break;
            case 9:
                list.print();
                break;
            default:
                break;
        }
    }
    return 0;
}

void printFillMenu() {
    int command = -1;
    while (command != 4) {
        printf("What you wanna do?\n"
               "1) Fill random value.\n"
               "2) Add new value to the list.\n"
               "3) Add new value to the list by index.\n"
               "4) Back to main menu.\n"
               ":");
        if (scanf("%d", &command) != 1) {
            while (getchar() != '\n') {}
        }
        system("clear");
        switch (command) {
            case 1:
                fillRandom();
                return;
            case 2:
                fillValue();
                return;
            case 3:
                fillValueByInd();
                return;
            default:
                break;
        }
    }
}

void getElementMenu() {
    int ind = -1;
    while (0 < ind || ind > (list.getLength() - 1)) {
        std::cout << "Enter index[0:" << list.getLength() - 1 << "]:";
        std::cin >> ind;
        system("clear");
    }
    std::cout << std::endl << "Value: " << list[ind] << std::endl;
}

void fillRandom() {
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    int random_variable = std::rand();
    for (int i = 0; i < START_LENGTH; ++i) {
        list.push(1 + (int) (std::rand() / ((RAND_MAX + 1u) / 20)));
    }
}

void fillValue() {
    int num;
    std::cout << "Enter value:";
    std::cin >> num;
    std::cout << std::endl;
    list.push(num);
}

void fillValueByInd() {
    int num, ind = -1;
    std::cout << "Enter value:";
    std::cin >> num;
    while (0 < ind || ind > (list.getLength() - 1)) {
        std::cout << std::endl << "Enter index[0:" << list.getLength() - 1 << "]:";
        std::cin >> ind;
        system("clear");
    }
    std::cout << std::endl;
    list.push(num, ind);
}

void checkValue() {
    int num, ind;
    std::cout << "Enter value:";
    std::cin >> num;
    ind = list.findElement(num);
    if (ind != -1) {
        std::cout << std::endl << "Value " << num << " in " << ind << " index." << std::endl;
    } else {
        std::cout << "Value " << num << "doesn't exist in the list" << std::endl;
    }
}

void changeValue() {
    int num, ind = -1;
    std::cout << "Enter value:";
    std::cin >> num;
    while (0 < ind || ind > (list.getLength() - 1)) {
        std::cout << std::endl << "Enter index[0:" << list.getLength() - 1 << "]:";
        std::cin >> ind;
        system("clear");
    }
    std::cout << std::endl;
    list.changeValue(num, ind);
}

void deleteValue() {
    int num;
    std::cout << "Enter value:";
    std::cin >> num;
    std::cout << std::endl;
    list.pop(num);
}

void deleteValueByInd() {
    int ind = -1;
    while (0 < ind || ind > (list.getLength() - 1)) {
        std::cout << std::endl << "Enter index[0:" << list.getLength() - 1 << "]:";
        std::cin >> ind;
        system("clear");
    }
    std::cout << std::endl;
    list.popInd(ind);
}

void deleteValueMenu() {
    int command = -1;
    while (command != 3) {
        printf("What you wanna do?\n"
               "1) Delete value from the list.\n"
               "2) Delete value from the list by index.\n"
               "3) Back to main menu.\n"
               ":");
        if (scanf("%d", &command) != 1) {
            while (getchar() != '\n') {}
        }
        system("clear");
        switch (command) {
            case 1:
                deleteValue();
                return;
            case 2:
                deleteValueByInd();
                return;
            default:
                break;
        }
    }
}
