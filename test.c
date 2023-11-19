#include <stdio.h>
#include <stdbool.h>
#include "functions.c"

// void flush() {
//     int c;
//     while ((c = getchar()) != '\n' && c != EOF);
// }

// int read_integer_in_range(const char *prompt, int min, int max) {
//     int input;
//     bool repeat;

//     do {
//         printf("%s", prompt);

//         if (scanf("%d", &input) != 1) {
//             flush();
//             printf("Invalid input. Please enter an integer.\n");
//             repeat = true;
//         } else if (input < min  || input > max) {
//             printf("Please enter a value between %d and %d.\n", min, max);
//             repeat = true;
//         } else {
//             repeat = false;
//         }
//     } while (repeat);

//     return input;
// }


// struct Drink{
//     int SoftDrink;
//     int Water;
//     float IceTea;
//     int amt1, amt2, amt3, amt4, amt5; 
//     float DTotal;
// };

// enum Softdrink {
//     Coke=1,
//     Sprite=2,
//     sevenup=3
// };


// int SoftDrink(){
//     bool status=true;
//     int choice;
//     while (status)
//     {
//         printf("\nPlease your SoftDrink \n[1]Coke \n[2]Sprite \n[3]7Up \n");
//         scanf("%d", &choice);
//         if (choice >= 1 && choice <= 3){
//             printf("\nYou selected %d", choice);
//             status=false;
//             return choice;
//         }
//         else{
//             printf("\nInvalid entered");
//         } 
//     }
// }

// float Drinks()
// {
//     struct Drink D = {3, 0 , 2.50};
//     int choice1, choice2, dtotal;
//     bool status= true;
//     while (status)
//     {
//         printf("\nPlease pick an option \n[1]Soft Drink \n[2]Water \n[3]Ice Tea");
//         scanf("%d", &choice1);
//         if (choice1=1)
//         {
//             CSoftdrink=SoftDrink()

//         }
        
//     }
    
// }


// struct Drinks
// {
//     int amt1, amt2, amt3, amt4, amt5, amt6;
//     float dtotal;
// };

// void DTotal(struct Drinks* dk, const float prices[])
// {
//     dk->amt4= (dk->amt1)+(dk->amt2)+(dk->amt3);
//     dk->dtotal =0.0;

//     dk->dtotal += dk->amt4 * prices[0];
//     dk->dtotal += dk->amt5 * prices[1];
//     dk->dtotal += dk->amt6 * prices[2];
// }

// void DrinkAmt(struct Drinks* dk, const float prices[])
// {
//     bool status=true;
//     int choice,choice2;
//     while (true)
//     {
//         printf( "\nPlease Pick an option:"
//                 "\n[1] Soft Drink"
//                 "\n[2] Water"
//                 "\n[3] Ice Tea"
//                 "\n[4] Finished");
//         printf("\nEnter your choice: ");
//         scanf("%d", &choice);
//         switch (choice)
//         {
//         case 1:
//             while (status)
//             {
//                 printf ("\nPlease pick your soft drink:"
//                         "\n[1] Coke"
//                         "\n[2] Spirte"
//                         "\n[3] 7up"
//                         "\n[4] Finished");
//                 printf("\n Enter your choice: ");
//                 scanf("%d", &choice2);
//                 switch (choice2)
//                 {
//                 case 1:
//                     dk->amt1=read_integer_in_range("\nPlease enter amount: ",0,25);
//                     break;
//                 case 2:
//                     dk->amt2=read_integer_in_range("\nPlease enter amount: ",0,25);
//                     break;
//                 case 3:
//                     dk->amt3=read_integer_in_range("\nPlease enter amount: ",0,25);
//                     break;
//                 case 4:
//                     printf("\nBack to drink selection");
//                     status=false;
//                     break;
//                 default:
//                     printf("Invalid answer");
//                     break;
//                 }
//             }
//             break;
//         case 2:
//             dk->amt5=read_integer_in_range("Please enter amount: ",0,25);
//             break;
//         case 3:
//             dk->amt6=read_integer_in_range("Please enter amount: ",0,25);
//             break;
//         case 4:
//             printf("\nTotal");
//             DTotal(dk, prices);
//             return;
//         default:
//             printf("\nInvalid");
//             break;
//         }
//     }
    
// }

// void main ()
// {
//     struct Drinks dk = {0, 0, 0, 0, 0 ,0};
//     float dkprices[] ={3.00, 0, 2.50};
//     DrinkAmt(&dk, dkprices);
    
//     printf("\nAmounts: %d %d %d %d %d %d", dk.amt1, dk.amt2, dk.amt3, dk.amt4, dk.amt5,dk.amt6);
//     printf("\nTotal cost of the drinks: $%.2f\n",dk.dtotal);
// }

//! float Bprices[] ={2.00, 3.00, 4.00, 1.00 , 2.00, 2.50, 0.5, 0.0};
//! B->Btotal += ((B->BeefAmt * price[0]) + (B->BEA1 * price[3]) + (B->BEA2 * price[6]) + (B->BEA3 * price[7]));
//! B->Btotal += ((B->ChknAmt * price[1]) + (B->CKE1 * price[4]) + (B->CKE2 * price[6]) + (B->CKE3 * price[7]));
//! B->Btotal += ((B->FishAmt * price[2]) + (B->FEA1 * price[5]) + (B->FEA2 * price[6]) + (B->FEA3 * price[7]));

// void messages (int choice)
// {
//     switch (choice)
//     {
//     case 1:
//         printf("\nYiippe");
//         break;
//     case 2:
//         printf("\nYoppe");
//         break;
//     default:
//         printf("\nInvalid");
//         break;
//     }
// }
// void main ()
// {
//     messages(1);
//     messages(2);
// }

// struct Burger{
//     int BeefAmt, ChknAmt, FishAmt; 
//     int BEA1, BEA2, BEA3;
//     int CKE1, CKE2, CKE3;
//     int FEA1, FEA2, FEA3;
//     float Btotal;
// };

// void BTotal(struct Burger* B, const float price[]){
//     B->Btotal = 0.0;
//     B->Btotal += (B->BeefAmt != 0) ? (B->BeefAmt * price[0]) + (B->BeefAmt * ((B->BEA1 * price[3]) + (B->BEA2 * price[4]) + (B->BEA3 * price[5]))) : 0;
//     B->Btotal += (B->ChknAmt != 0) ? (B->ChknAmt * price[1]) + (B->ChknAmt * ((B->CKE1 * price[3]) + (B->CKE2 * price[4]) + (B->CKE3 * price[5]))) : 0;
//     B->Btotal += (B->FishAmt != 0) ? (B->FishAmt * price[2]) + (B->FishAmt * ((B->FEA1 * price[3]) + (B->FEA2 * price[4]) + (B->FEA3 * price[5]))) : 0;
// }

// void BAmt(struct Burger* B, const float prices[]){
//     int choice, choice2, choice3, choice4;
//     while (true){
//         printf( "\nPlease Pick an option:"
//                 "\n[1] Beef\t[2.50 RM] "
//                 "\n[2] Chicken\t[3.00 RM]"
//                 "\n[3] Fish\t[4.00 RM]"
//                 "\n[4] Back");
//         printf("\nEnter your choice: ");
//         scanf("%d", &choice);
//         switch (choice){
//         case 1:
//             //! Beef
//             B->BeefAmt = read_integer_in_range("\nPlease enter amount: ",0,25);
//             break;
//         case 2:
//             //! Chicken
//             B->ChknAmt = read_integer_in_range("\nPlease enter amount: ",0,25);
//             break;
//         case 3:
//             //! Fish
//             B->FishAmt = read_integer_in_range("\nPlease enter amount: ",0,25);
//             break;
//         case 4:
//             //! Finished
//             printf("\nReturned to Main Menu");
//             BTotal(B, prices);
//             return;
//         default:
//             printf("\nInvalid option");
//             break;
//         }
//         printf( "\nWould you like to edit your burger?"
//                 "\n[1]Yes"
//                 "\n[2]No");
//         printf("\nPlease Enter your choice: ");
//         scanf("%d",&choice2);
//         if (choice2 == 1){
//             bool status= true;
//             while(status){
//                 printf( "\nWhich would you like to edit?"
//                         "\n[1] Beef Burger"
//                         "\n[2] Chicken Burger"
//                         "\n[3] Fish Burger"
//                         "\n[4] Back");
//                 printf( "\nPlease enter your choice: ");
//                 scanf("%d", &choice3);
//                 switch (choice3){
//                 case 1:
//                     if (B->BeefAmt > 0){
//                         printf( "\nPlease pick the following option");
//                         printf( "\n[1] Patty\tCurrent Amount: %d", B->BEA1);
//                         printf( "\n[2] Cheese\tCurrent Amount: %d",B->BEA2);
//                         printf( "\n[3] Pickle\tCurrent Amount: %d", B->BEA3);
//                         printf( "\n[4] Back \nPlease enter your choice: ");
//                         scanf("%d", &choice4);
//                         switch (choice4){
//                         case 1:
//                             B->BEA1 = read_integer_in_range("\nPlease enter amount: ",0,5);
//                             printf("Updated amount to %d", B->BEA1);
//                             break;
//                         case 2:
//                             B->BEA2 = read_integer_in_range("\nPlease enter amount: ",0,5);
//                             printf("Updated amount to %d", B->BEA2);
//                             break;
//                         case 3:
//                             B->BEA3 = read_integer_in_range("\nPlease enter amount: ",0,5);
//                             printf("Updated amount to %d", B->BEA3);
//                             break;
//                         case 4:
//                             printf("\nReturned Back");
//                             break;
//                         default:
//                             printf("\nInvalid Answer");
//                             break;
//                         }
//                     }
//                     else{
//                         printf("\nInvalid option");
//                     }
//                     break;
//                 case 2:
//                     if (B->ChknAmt > 0){
//                         printf( "\nPlease pick the following option");
//                         printf( "\n[1] Patty\tCurrent Amount: %d", B->CKE1);
//                         printf( "\n[2] Cheese\tCurrent Amount: %d",B->CKE2);
//                         printf( "\n[3] Pickle\tCurrent Amount: %d", B->CKE3);
//                         printf( "\n[4] Back \nPlease enter your choice: ");
//                         scanf("%d", &choice4);
//                         switch (choice4){
//                         case 1:
//                             B->CKE1 = read_integer_in_range("\nPlease enter amount: ",0,5);
//                             printf("Updated amount to %d", B->CKE1);
//                             break;
//                         case 2:
//                             B->CKE2 = read_integer_in_range("\nPlease enter amount: ",0,5);
//                             printf("Updated amount to %d", B->CKE2);
//                             break;
//                         case 3:
//                             B->CKE3 = read_integer_in_range("\nPlease enter amount: ",0,5);
//                             printf("Updated amount to %d", B->CKE3);
//                             break;
//                         case 4:
//                             printf("\nReturned Back");
//                             break;
//                         default:
//                             printf("\nInvalid Answer");
//                             break;
//                         }
//                     }
//                     else{
//                         printf("\nInvalid Answer");
//                     }
//                     break;
//                 case 3:
//                     if (B->FishAmt > 0){
//                         printf( "\nPlease pick the following option");
//                         printf( "\n[1] Patty\tCurrent Amount: %d", B->FEA1);
//                         printf( "\n[2] Cheese\tCurrent Amount: %d",B->FEA2);
//                         printf( "\n[3] Pickle\tCurrent Amount: %d", B->FEA3);
//                         printf( "\n[4] Back \nPlease enter your choice: ");
//                         scanf("%d", &choice4);
//                         switch (choice4){
//                         case 1:
//                             B->FEA1 = read_integer_in_range("\nPlease enter amount: ",0,5);
//                             printf("Updated amount to %d", B->FEA1);
//                             break;
//                         case 2:
//                             B->FEA2 = read_integer_in_range("\nPlease enter amount: ",0,5);
//                             printf("Updated amount to %d", B->FEA2);
//                             break;
//                         case 3:
//                             B->FEA3 = read_integer_in_range("\nPlease enter amount: ",0,5);
//                             printf("Updated amount to %d", B->FEA3);
//                             break;
//                         case 4:
//                             printf("\nReturned Back");
//                             break;
//                         default:
//                             printf("\nInvalid Answer");
//                             break;
//                         }
//                     }
//                     else{
//                         printf("\nInvalid Option");
//                     }
//                     break;
//                 case 4:
//                     printf("\nReturned back");
//                     status=false;
//                     break;
//                 default:
//                     printf("\nInvalid Answer");
//                     break;
//                 }
//             }
//         }
//         else if (choice2 == 2){
//             printf( "\nNo need to edit"
//                     "\nReturning to Burger Menu");
//             BTotal(B, prices);
//         }
//         else{
//             printf("\nInvalid choice");
//         }
//     }
    
// }

// void main ()
// {
//     printf("\nStart");
//     struct Burger B = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
//     float Bprices[] ={1.00, 1.50, 2.50, 1.00, 0.5, 0.0};
//     BAmt(&B, Bprices);

//     printf("\nAmounts: %d %d %d, %d %d %d, %d %d %d, %d %d %d", B.BeefAmt, B.ChknAmt, B.FishAmt, B.BEA1, B.BEA2, B.BEA3, B.CKE1, B.CKE2, B.CKE3, B.FEA1, B.FEA2, B.FEA3);
//     printf("\nTotal cost of the main dish: $%.2f", B.Btotal);
// }


// void main()
// {
//     int choice=read_integer_in_range("\nEnter option: ",1,2);
//     printf("%d", choice);
// }


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