#include "menu.h"

//todo [9 1] is not working
ListInArray<int> list;

int main() {
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

