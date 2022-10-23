#include "menu.h"

//todo [1 1 8 1] is not working
ListInArray<int> list;

int main() {
    system("clear");
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
                if (!list.isEmpty())
                    list.clear();
                else
                    std::cout << "List is empty." << std::endl;
                break;
            case 4:
                std::cout << "Is list empty? " << (list.isEmpty() ? "True" : "False") << std::endl;
                break;
            case 5:
                if (!list.isEmpty())
                    checkValue();
                else
                    std::cout << "List is empty." << std::endl;
                break;
            case 6:
                if (!list.isEmpty())
                    getElementMenu();
                else
                    std::cout << "List is empty." << std::endl;
                break;
            case 7:
                if (!list.isEmpty())
                    changeValue();
                else
                    std::cout << "List is empty." << std::endl;
                break;
            case 8:
                if (!list.isEmpty())
                    deleteValueMenu();
                else
                    std::cout << "List is empty." << std::endl;
                break;
            case 9:
                if (!list.isEmpty())
                    list.print();
                else
                    std::cout << "List is empty." << std::endl;
                break;
            default:
                break;
        }
    }
    return 0;
}

