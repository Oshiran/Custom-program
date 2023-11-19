#include <stdio.h>
#include <stdbool.h>
#include "functions.c"

void MdTotal(struct MainDish* md, const float prices[]) {
    md->mdtotal = 0.0;
    md->mdtotal += md->amt1 * prices[0];
    md->mdtotal += md->amt2 * prices[1];
    md->mdtotal += md->amt3 * prices[2];
    md->mdtotal += md->amt4 * prices[3];
    md->mdtotal += md->amt5 * prices[4];
}

void MaindishAmt(struct MainDish* md, const float prices[]){
    int choice;
    while (true) {
        text(3);
        MDCurrentDisp(md);
        choice = read_integer_in_range("\nOption: ",1,6);
        switch (choice) {
            case 1:
                md->amt1 = read_integer_in_range("\nPlease enter amount: ", 0, 25);
                break;
            case 2:
                md->amt2 = read_integer_in_range("\nPlease enter amount: ", 0, 25);
                break;
            case 3:
                md->amt3 = read_integer_in_range("\nPlease enter amount: ", 0, 25);
                break;
            case 4:
                md->amt4 = read_integer_in_range("\nPlease enter amount: ", 0, 25);
                break;
            case 5:
                md->amt5 = read_integer_in_range("\nPlease enter amount: ", 0, 25);
                break;
            case 6:
                text(11);
                MdTotal(md, prices);
                return;
            default:
                text(12);
                break;
        }
    }
}

void SdTotal(struct Sides* sd, const float prices[]){
    sd->sdtotal = 0.0;
    sd->sdtotal += sd->amt1 * prices[0];
    sd->sdtotal += sd->amt2 * prices[1];
    sd->sdtotal += sd->amt3 * prices[2];
    sd->sdtotal += sd->amt4 * prices[3];
    sd->sdtotal += sd->amt5 * prices[4];
}

void SideDishAmt(struct Sides* sd, const float prices[]){
    int choice;
    while (true)
    {
        text(4);
        SDCurrentDisp(sd);
        choice=read_integer_in_range("\nOption: ",1,6);
        switch (choice)
        {
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
            text(11);
            SdTotal(sd, prices);
            return;
        default:
            text(12);
            break;
        }
    }
}

void DTotal(struct Drinks* dk, const float prices[]){
    dk->amt4= (dk->amt1)+(dk->amt2)+(dk->amt3);
    dk->dtotal =0.0;
    dk->dtotal += dk->amt4 * prices[0];
    dk->dtotal += dk->amt5 * prices[1];
    dk->dtotal += dk->amt6 * prices[2];
}

void DrinkAmt(struct Drinks* dk, const float prices[]){
    int choice,choice2;
    while (true)
    {
        text(5);
        DrinkCurrentDisp(dk);
        choice=read_integer_in_range("\nOption: ", 1,4);
        switch (choice)
        {
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
            text(11);
            DTotal(dk, prices);
            return;
        default:
            text(12);
            break;
        }
    }
}

void BTotal(struct Burger* B, const float price[]){
    B->Btotal = 0.0;
    B->Btotal += (B->BeefAmt != 0) ? (B->BeefAmt * price[0]) + (B->BeefAmt * ((B->BEA1 * price[3]) + (B->BEA2 * price[4]) + (B->BEA3 * price[5]))) : 0;
    B->Btotal += (B->ChknAmt != 0) ? (B->ChknAmt * price[1]) + (B->ChknAmt * ((B->CKE1 * price[3]) + (B->CKE2 * price[4]) + (B->CKE3 * price[5]))) : 0;
    B->Btotal += (B->FishAmt != 0) ? (B->FishAmt * price[2]) + (B->FishAmt * ((B->FEA1 * price[3]) + (B->FEA2 * price[4]) + (B->FEA3 * price[5]))) : 0;
}

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
            text(11);
            BTotal(B, prices);
            return;
        default:
            text(12);
            break;
        }
        text(8);
        choice2=read_integer_in_range("\nOption: ",1,2);
        if (choice2 == 1){
            bool status= true;
            while(status){
                text(9);
                BCurrentDisp1(B);
                choice3 = read_integer_in_range("\nOption: ",1,4);
                switch (choice3){
                case 1:
                    if (B->BeefAmt > 0){
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

void MenuTotal(struct MainDish* md, struct Sides* sd, struct Drinks* dk, struct Burger* B){
    float MenuTotal= md->mdtotal + sd->sdtotal + dk->dtotal + B->Btotal;
    printf("Your total is: $%0.2f", MenuTotal);
}

// void main()
// {
//     struct MainDish md = {0, 0, 0, 0, 0};
//     struct Sides sd = {0, 0, 0, 0, 0};
//     struct Drinks dk = {0, 0, 0, 0, 0, 0};
//     struct Burger B = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    
//     float mdprices[] = {15.0, 14.50, 13.00, 22.0, 12.0};
//     float sdprices[] = {8.00, 6.00, 3.00, 5.00, 2.50};
//     float dkprices[] = {3.00, 0, 2.50};
//     float Bprices[] = {1.00, 1.50, 2.50, 1.00, 0.5, 0.0};

//     MaindishAmt(&md, mdprices);
//     SideDishAmt(&sd, sdprices);
//     DrinkAmt(&dk, dkprices);
//     BAmt(&B, Bprices);
    

//   // Printing the amounts for demonstration
//     printf("\nAmounts: %d %d %d %d %d", md.amt1, md.amt2, md.amt3, md.amt4, md.amt5);
//     printf("\nAmounts: %d %d %d %d %d", sd.amt1, sd.amt2, sd.amt3, sd.amt4, sd.amt5);
//     printf("\nAmounts: %d %d %d %d %d %d", dk.amt1, dk.amt2, dk.amt3, dk.amt4, dk.amt5,dk.amt6);
//     printf("\nAmounts: %d %d %d, %d %d %d, %d %d %d, %d %d %d", B.BeefAmt, B.ChknAmt, B.FishAmt, B.BEA1, B.BEA2, B.BEA3, B.CKE1, B.CKE2, B.CKE3, B.FEA1, B.FEA2, B.FEA3);

//     // Print the total cost stored in the struct for demonstration
//     printf("\nTotal cost of the main dish: $%.2f\n", md.mdtotal);
//     printf("\nTotal cost of the side dish: $%.2f\n", sd.sdtotal);
//     printf("\nTotal cost of the drinks: $%.2f\n",dk.dtotal);
//     printf("\nTotal cost of the burger: $%.2f\n", B.Btotal);

//     MenuTotal(&md, &sd, &dk, &B);
// }