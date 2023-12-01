#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "functions.c"

//! Finds Main Dish total price by multiplying amount into indiviual amount price
void MdTotal(struct MainDish* md, const float prices[]){
    md->mdtotal = 0.0;
    md->mdtotal += md->amt1 * prices[0];
    md->mdtotal += md->amt2 * prices[1];
    md->mdtotal += md->amt3 * prices[2];
    md->mdtotal += md->amt4 * prices[3];
    md->mdtotal += md->amt5 * prices[4];
}

//! Main Dish function that allows user to choose the Main Dish option and enter amount
//! Validation Check is in place to limit the amount from 0 to 25
void MaindishAmt(struct MainDish* md, const float prices[]){
    int choice;
    while (true){
        text(3);
        MDCurrentDisp(md);
        choice = read_integer_in_range("\nOption: ",1,6);
        switch (choice){
            case 1:
                md->amt1 = read_integer_in_range("\nPlease enter amount: ",0,25);
                break;
            case 2:
                md->amt2 = read_integer_in_range("\nPlease enter amount: ",0,25);
                break;
            case 3:
                md->amt3 = read_integer_in_range("\nPlease enter amount: ",0,25);
                break;
            case 4:
                md->amt4 = read_integer_in_range("\nPlease enter amount: ",0,25);
                break;
            case 5:
                md->amt5 = read_integer_in_range("\nPlease enter amount: ",0,25);
                break;
            case 6:
                //! Return message & Calls the MdTotal function
                text(11);
                MdTotal(md, prices);
                return;
            default:
                text(12);
                break;
        }
    }
}

//! Finds Side Dish total price by multiplying amount into indiviual amount price
void SdTotal(struct Sides* sd, const float prices[]){
    sd->sdtotal = 0.0;
    sd->sdtotal += sd->amt1 * prices[0];
    sd->sdtotal += sd->amt2 * prices[1];
    sd->sdtotal += sd->amt3 * prices[2];
    sd->sdtotal += sd->amt4 * prices[3];
    sd->sdtotal += sd->amt5 * prices[4];
}

//! Side Dish function that allows user to choose the Side Dish option and enter amount
//! Validation Check is in place to limit the amount from 0 to 25
void SideDishAmt(struct Sides* sd, const float prices[]){
    int choice;
    while (true){
        text(4);
        SDCurrentDisp(sd);
        choice=read_integer_in_range("\nOption: ",1,6);
        switch (choice){
        case 1:
            sd->amt1=read_integer_in_range("\nPlease enter amount: ",0,25);
            break;
        case 2:
            sd->amt2=read_integer_in_range("\nPlease enter amount: ",0,25); 
            break;
        case 3:
            sd->amt3=read_integer_in_range("\nPlease enter amount: ",0,25);
            break;
        case 4:
            sd->amt4=read_integer_in_range("\nPlease enter amount: ",0,25);
            break;
        case 5:
            sd->amt5=read_integer_in_range("\nPlease enter amount: ",0,25);
            break;
        case 6:
            //! Return message & Calls the SdTotal function
            text(11);
            SdTotal(sd, prices);
            return;
        default:
            text(12);
            break;
        }
    }
}

//! Finds Drinks total price by multiplying amount into indiviual amount price
//* In this case, amt1 to 3 have the same price, thus amount 4 is the subtotal
void DTotal(struct Drinks* dk, const float prices[]){
    dk->amt4= (dk->amt1)+(dk->amt2)+(dk->amt3);
    dk->dtotal =0.0;
    dk->dtotal += dk->amt4 * prices[0];
    dk->dtotal += dk->amt5 * prices[1];
    dk->dtotal += dk->amt6 * prices[2];
}

//! Side Dish function that allows user to choose the Side Dish option and enter amount
//! Validation Check is in place to limit the amount from 0 to 25
void DrinkAmt(struct Drinks* dk, const float prices[]){
    int choice,choice2;
    while (true){
        text(5);
        DrinkCurrentDisp(dk);
        choice=read_integer_in_range("\nOption: ", 1,4);
        switch (choice){
        case 1:
            text(6);
            choice2=read_integer_in_range("\nOption: ", 1,4);
            switch (choice2){
            case 1:
                dk->amt1=read_integer_in_range("\nPlease enter amount: ",0,25);
                break;
            case 2:
                dk->amt2=read_integer_in_range("\nPlease enter amount: ",0,25);
                break;
            case 3:
                dk->amt3=read_integer_in_range("\nPlease enter amount: ",0,25);
                break;
            case 4:
                text(13);
                break;
            default:
                text(12);
                break;
            }
            break;
        case 2:
            dk->amt5=read_integer_in_range("Please enter amount: ",0,25);
            break;
        case 3:
            dk->amt6=read_integer_in_range("Please enter amount: ",0,25);
            break;
        case 4:
            //! Return message & Calls the DTotal function
            text(11);
            DTotal(dk, prices);
            return;
        default:
            text(12);
            break;
        }
    }
}

//! Finds Drinks total price by multiplying amount into indiviual amount price
void BTotal(struct Burger* B, const float price[]){
    B->Btotal = 0.0;
    B->Btotal += (B->BeefAmt != 0) ? (B->BeefAmt * price[0]) + (B->BeefAmt * ((B->BEA1 * price[3]) + (B->BEA2 * price[4]) + (B->BEA3 * price[5]))) : 0;
    B->Btotal += (B->ChknAmt != 0) ? (B->ChknAmt * price[1]) + (B->ChknAmt * ((B->CKE1 * price[3]) + (B->CKE2 * price[4]) + (B->CKE3 * price[5]))) : 0;
    B->Btotal += (B->FishAmt != 0) ? (B->FishAmt * price[2]) + (B->FishAmt * ((B->FEA1 * price[3]) + (B->FEA2 * price[4]) + (B->FEA3 * price[5]))) : 0;
}

//! Burger function that allows user to choose the Burger option and enter amount
//! Validation Check is in place to limit the amount from 0 to 25
//* Furthermore, an edit option for each burger is in place to allow customization
//* Validation Check is in place to limit the amount from 0 to 5
void BAmt(struct Burger* B, const float prices[]){
    int choice, choice2, choice3, choice4;
    while (true){
        text(7);
        BCurrentDisp1(B);
        choice = read_integer_in_range("\nOption: ",1,4);
        switch (choice){
        case 1:
            B->BeefAmt = read_integer_in_range("\nPlease enter amount: ",0,25);
            break;
        case 2:
            B->ChknAmt = read_integer_in_range("\nPlease enter amount: ",0,25);
            break;
        case 3:
            B->FishAmt = read_integer_in_range("\nPlease enter amount: ",0,25);
            break;
        case 4:
            //! Return message & Calls the BTotal function
            text(11);
            BTotal(B, prices);
            return;
        default:
            text(12);
            break;
        }
        //! Edit Burger option
        text(8);
        choice2=read_integer_in_range("\nOption: ",1,2);
        if (choice2 == 1){
            bool status= true;
            while(status){
                //! Edit Burger Dialogue
                //* Validation Check is in place to ensure that the burger has been ordered first before it can be edited
                text(9);
                BCurrentDisp1(B);
                choice3 = read_integer_in_range("\nOption: ",1,4);
                switch (choice3){
                case 1:
                    if (B->BeefAmt > 0){
                        //! Beef Burger Edit Menu
                        text(10);
                        BCurrentDisp2(B,1);
                        choice4 = read_integer_in_range("\nOption: ",1,4);
                        switch (choice4){
                        case 1:
                            B->BEA1 = read_integer_in_range("\nPlease enter amount: ",0,5);
                            break;
                        case 2:
                            B->BEA2 = read_integer_in_range("\nPlease enter amount: ",0,5);
                            break;
                        case 3:
                            B->BEA3 = read_integer_in_range("\nPlease enter amount: ",0,5);
                            break;
                        case 4:
                            text(14);
                            break;
                        default:
                            text(12);
                            break;
                        }
                    }
                    else{
                        text(12);
                    }
                    break;
                case 2:
                    if (B->ChknAmt > 0){
                        //! Chicken Burger Edit Menu
                        text(10);
                        BCurrentDisp2(B,2);
                        choice4 = read_integer_in_range("\nOption: ",1,4);
                        switch (choice4){
                        case 1:
                            B->CKE1 = read_integer_in_range("\nPlease enter amount: ",0,5);
                            break;
                        case 2:
                            B->CKE2 = read_integer_in_range("\nPlease enter amount: ",0,5);
                            break;
                        case 3:
                            B->CKE3 = read_integer_in_range("\nPlease enter amount: ",0,5);
                            break;
                        case 4:
                            text(14);
                            break;
                        default:
                            text(12);
                            break;
                        }
                    }
                    else{
                        text(12);
                    }
                    break;
                case 3:
                    if (B->FishAmt > 0){
                        //! Fish Burger Edit Menu
                        text(10);
                        BCurrentDisp2(B,3);
                        choice4 = read_integer_in_range("\nOption: ",1,4);
                        switch (choice4){
                        case 1:
                            B->FEA1 = read_integer_in_range("\nPlease enter amount: ",0,5);
                            break;
                        case 2:
                            B->FEA2 = read_integer_in_range("\nPlease enter amount: ",0,5);;
                            break;
                        case 3:
                            B->FEA3 = read_integer_in_range("\nPlease enter amount: ",0,5);
                            break;
                        case 4:
                            text(14);
                            break;
                        default:
                            text(12);
                            break;
                        }
                    }
                    else{
                        text(12);
                    }
                    break;
                case 4:
                    //! Another Return message & Calls the BTotal function
                    text(14);
                    status=false;
                    break;
                default:
                    text(12);
                    break;
                }
            }
        }
        else if (choice2 == 2){
            text(11);
            BTotal(B, prices);
        }
        else{
            text(12);
        }
    }
}

//! Using all the totals from their respective structs, sums to find the total
void MenuTotal(struct MainDish* md, struct Sides* sd, struct Drinks* dk, struct Burger* B){
    float MenuTotal= md->mdtotal + sd->sdtotal + dk->dtotal + B->Btotal;
    printf("\nYour total is: %0.2f RM", MenuTotal);
}

//! Receipt generation
//* Filename made automatically using date and time imported from <time.h>
void Recipt(struct MainDish* md, struct Sides* sd, struct Drinks* dk, struct Burger* B){
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char filename[255];
    strftime(filename, sizeof(filename), "receipt_%Y%m%d%H%M%S.txt", tm_info);
    FILE *file = fopen(filename, "w");
    
    float MenuTotal= md->mdtotal + sd->sdtotal + dk->dtotal + B->Btotal;

    if (file == NULL){
        printf("\nError with opening file");
        return;
    }

    //! Print to file
    fprintf(file, "\nRecipt Date and Time: %s", asctime(tm_info));

    fprintf(file, "\n\nMain Dish amount:");
    fprintf(file, "\nSpare Ribs: %d \nSpaghetti Bolognese: %d \nFish & Chip: %d \nPepporoni Pizza: %d \nMac & Cheese %d", md->amt1, md->amt2, md->amt3, md->amt4, md->amt5);
    fprintf(file, "\n\n Main Dish Total: %0.2f RM", md->mdtotal);

    fprintf(file, "\n\nBurger amount:");
    fprintf(file, "\nBeef Burger: %d \nChicken Burger: %d \nFish Burger: %d", B->BeefAmt, B->ChknAmt,B->FishAmt);
    fprintf(file, "\nBeef Burger edits \nPatty: %d \tCheese: %d \tPickle: %d", B->BEA1, B->BEA2, B->BEA3);
    fprintf(file, "\nChicken Burger edits \nPatty: %d \tCheese: %d \tPickle: %d", B->CKE1, B->CKE2, B->CKE3);
    fprintf(file, "\nFish Burger edits \nPatty: %d \tCheese: %d \tPickle: %d", B->FEA1, B->FEA2, B->FEA3);
    fprintf(file, "\n\nBurger Total: %0.2f RM", B->Btotal);

    fprintf(file, "\n\nSide Dish amount:");
    fprintf(file, "\nMashed Potato: %d \nOnion Rings: %d \nGarlic Bread: %d \nButtered Corn: %d \nFrench Fries: %d", sd->amt1,sd->amt2, sd->amt3, sd->amt4, sd->amt5);
    fprintf(file, "\n\nSide Dish Total: %0.2f RM", sd->sdtotal);

    fprintf(file, "\n\nDrinks amount:");
    fprintf(file, "\nCoke: %d \nSprite: %d \n7up: %d \nWater: %d \nIce Tea: %d \n", dk->amt1, dk->amt2, dk->amt3 , dk->amt5, dk->amt6);
    fprintf(file, "\n\nDrinks Total: %0.2f RM", dk->dtotal);

    fprintf(file, "\n\nTotal cost: %0.2f RM", MenuTotal);

    fclose(file);
    printf("\nRecipt Generated and saved to %s", filename);   
}

//! Read Receipt
void readTextFile() {
    const int MAX_FILENAME_LENGTH = 256;
    char filename[MAX_FILENAME_LENGTH];
    char buffer[256];

    //* Enter file name and validates if the file exists
    printf("Enter file name: ");
    scanf("%s", filename);

    while (getchar() != '\n');

    FILE *file = fopen(filename, "r");

    if (file == NULL){
        perror("Error opening file");
        return;
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL){
        printf("%s", buffer);
    }

    fclose(file);
}
