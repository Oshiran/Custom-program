#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "structs.c"

void main ()
{
    //! Initilize all structs as 0 (exception being the default customization for Burger which is 1)
    struct MainDish md = {0, 0, 0, 0, 0};
    struct Sides sd = {0, 0, 0, 0, 0};
    struct Drinks dk = {0, 0, 0, 0, 0, 0};
    struct Burger B = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    
    //! Establish all the price
    float mdprices[] = {15.0, 14.50, 13.00, 22.0, 12.0};
    float sdprices[] = {8.00, 6.00, 3.00, 5.00, 2.50};
    float dkprices[] = {3.00, 0, 2.50};
    float Bprices[] = {1.00, 1.50, 2.50, 1.00, 0.5, 0.0};

    //! Establish all variables that will be used in main
    int option1, option2;
    bool status=true, status2=true;;
    while (status){
        text(1);
        option1 = read_integer_in_range ("\nOption: ",1,2);
        switch (option1){
        case 1:
            while (status2){
                text(2);
                option2 = read_integer_in_range ("\nOption: ",1,7);
                
                //! Depending on their choice a switch function is used
                switch (option2){
                case 1:
                    //! Main Dish function
                    MaindishAmt(&md, mdprices);
                    break;
                case 2:
                    //! Burger function
                    BAmt(&B, Bprices);
                    break;
                case 3:
                    //! Side Dish function
                    SideDishAmt(&sd, sdprices);
                    break;
                case 4:
                    //! Drink function
                    DrinkAmt(&dk, dkprices);
                    break;
                case 5:
                    //! Read Receipt function
                    readTextFile();
                    break;
                case 6:
                    //! Totals all menu items to calculate price and uses Recipt function to automatically create a receipt
                    MenuTotal(&md, &sd, &dk, &B);
                    Recipt(&md, &sd, &dk, &B);
                    break;
                case 7:
                    //! Exit the program by breaking all loops
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
    //! Thank you message for using the system 
    text(15);
}