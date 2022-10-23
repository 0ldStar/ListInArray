//
// Created by loki on 22.10.22.
//
#include "menu.h"

extern ListInArray<int> list;

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
                if (!list.isEmpty()) {
                    fillValueByInd();
                    return;
                } else {
                    std::cout << "List is empty." << std::endl;
                }
            default:
                break;
        }
    }
}

void getElementMenu() {
    int ind = -1;
    while (0 > ind || ind > (int) (list.getLength() - 1)) {
        std::cout << "Enter index[0:" << list.getLength() - 1 << "]:";
        std::cin >> ind;
        system("clear");
    }
    std::cout << std::endl << "Value: " << list[ind] << std::endl;
}

void fillRandom() {
    std::srand(std::time(nullptr)); // use current time as seed for random generator
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
    while (0 > ind || ind > (int) (list.getLength() - 1)) {
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
    while (0 > ind || ind > (int) (list.getLength() - 1)) {
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
    while (0 > ind || ind > (int) (list.getLength() - 1)) {
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