#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "structs.c"

void main ()
{
    struct MainDish md = {0, 0, 0, 0, 0};
    struct Sides sd = {0, 0, 0, 0, 0};
    struct Drinks dk = {0, 0, 0, 0, 0, 0};
    struct Burger B = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    
    float mdprices[] = {15.0, 14.50, 13.00, 22.0, 12.0};
    float sdprices[] = {8.00, 6.00, 3.00, 5.00, 2.50};
    float dkprices[] = {3.00, 0, 2.50};
    float Bprices[] = {1.00, 1.50, 2.50, 1.00, 0.5, 0.0};

    int option1, option2;
    bool status=true, status2=true;;
    while (status){
        text(1);
        option1 = read_integer_in_range ("\nOption: ",1,2);
        switch (option1){
        case 1:
            while (status2){
                text(2);
                option2 = read_integer_in_range ("\nOption: ",1,6);
                switch (option2){
                case 1:
                    MaindishAmt(&md, mdprices);
                    break;
                case 2:
                    BAmt(&B, Bprices);
                    break;
                case 3:
                    SideDishAmt(&sd, sdprices);
                    break;
                case 4:
                    DrinkAmt(&dk, dkprices);
                    break;
                case 5:
                    readTextFile();
                    break;
                case 6:
                    MenuTotal(&md, &sd, &dk, &B);
                    Recipt(&md, &sd, &dk, &B);
                    status2=false;
                    status=false;
                    break;
                default:
                    text(12);
                    break;
                }
            }
            break;
        case 2:
            status=false;
            break;
        default:
            text(12);
            break;
        }
    }
    text(15);
}