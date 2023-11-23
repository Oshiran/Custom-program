#include <stdio.h>
#include <stdbool.h>
#include <time.h>

struct MainDish{
    int amt1, amt2, amt3, amt4, amt5;
    float mdtotal;
};

struct Sides{
    int amt1, amt2, amt3, amt4, amt5;
    float sdtotal;
};

struct Drinks{
    int amt1, amt2, amt3, amt4, amt5, amt6;
    float dtotal;
};

struct Burger{
    int BeefAmt, ChknAmt, FishAmt; 
    int BEA1, BEA2, BEA3;
    int CKE1, CKE2, CKE3;
    int FEA1, FEA2, FEA3;
    float Btotal;
};

void flush(){
	while ((getchar()) != '\n');
}

int read_integer_in_range(const char *prompt, int min, int max){
	int input;
	bool status = true;
	while (status){
		printf("%s", prompt);
		if (scanf("%d",&input) !=1){
			flush();
			printf("\nInvalid, Enter a value with %d and %d",min,max);
		}
		else if (input < min || input > max){
			printf("\nInvalid, Enter a value with %d and %d",min,max);
		}
		else{
			status=false;
		}
	}
	return input;
}

void text(int choice){
	switch (choice){
	case 1:
		printf( "\nStart?"
				"\n[1] Yes" 
				"\n[2] No");
		break;
	case 2:
		printf( "\n\nPlease pick an option:"
				"\n[1] Main Dish" 
				"\n[2] Burger"
				"\n[3] Sides" 
				"\n[4] Drinks"
				"\n[5] Done with order");
		break;
	case 3:
		printf( "\n\nPlease pick an option:"
				"\n[1] Spare Ribs\t\t\t[15.00 RM]"
				"\n[2] Spaghetti Bolognese \t[14.50 RM]"
				"\n[3] Fish & Chip \t\t[13.00 RM]"
				"\n[4] Pepporoni Pizza \t\t[22.00 RM]"
				"\n[5] Mac & Cheese \t\t[12.00 RM]"
				"\n[6] Finished");
		break;
	case 4:
        printf("\n\nPlease Pick an option:"
               "\n[1] Mashed Potato\t[8.00 RM]"
               "\n[2] Onion Rings \t[6.00RM]" 
               "\n[3] Garlic Bread\t[3.00RM]" 
               "\n[4] Buttered Corn\t[5.00 RM]" 
               "\n[5] French Fries\t[2.50 RM]" 
               "\n[6] Finished");
		break;
	case 5:
        printf( "\n\nPlease Pick an option:"
            	"\n[1] Soft Drink\t[3.00 RM]"
                "\n[2] Water\t[Free]"
                "\n[3] Ice Tea\t[2.50 RM]"
                "\n[4] Finished");
		break;	
	case 6:
		printf( "\n\nPlease pick your soft drink:"
				"\n[1] Coke"
				"\n[2] Spirte"
				"\n[3] 7up"
				"\n[4] Finished");
		break;
	case 7:
		printf( "\n\nPlease Pick an option:"
                "\n[1] Beef\t[2.50 RM] "
                "\n[2] Chicken\t[3.00 RM]"
                "\n[3] Fish\t[4.00 RM]"
                "\n[4] Back");
		break;
	case 8:
		printf( "\nWould you like to edit your burger(s)?"
				"\n[1]Yes"
				"\n[2]No");
		break;
	case 9:
		printf( "\n\nWhich would you like to edit?"
				"\n[1] Beef Burger"
				"\n[2] Chicken Burger"
				"\n[3] Fish Burger"
				"\n[4] Back");
		break;
	case 10:
		printf( "\n\nPlease pick the following option"
				"\n[1] Patty\t[1.00RM]"
				"\n[2] Cheese\t[0.5RM]"
				"\n[3] Pickle\t[0.00RM]"
				"\n[4] Back");
	case 11:
		printf("\nReturning to main menu");
		break;
	case 12:
		printf("\nInvalid choice");
		break;
	case 13:
		printf("\nBack to drink selection");
		break;
	case 14:
		printf("\nReturning to Burger Selection");
		break;
	case 15:
		printf("\n\nThank you for using Alison Services");
    	printf("\nHave a good day!");
		break;
	default:
		break;
	}
}

void MDCurrentDisp(const struct MainDish* md){
    printf("\n\nCurrent Amount:\n[1]-> %d  [2]-> %d [3]-> %d [4]-> %d [5]-> %d", md->amt1, md->amt2, md->amt3, md->amt4, md->amt5);
}

void SDCurrentDisp(const struct Sides* sd){
	printf("\n\nCurrent Amount:\n[1]-> %d  [2]-> %d [3]-> %d [4]-> %d [5]-> %d", sd->amt1, sd->amt2, sd->amt3, sd->amt4, sd->amt5);
}

void DrinkCurrentDisp(const struct Drinks* dk){
	printf("\n\nCurrent Amount:\n[1.1]-> %d  [1.2]-> %d [1.3]-> %d [2]-> %d [3]-> %d", dk->amt1, dk->amt2, dk->amt3, dk->amt5, dk->amt6);
}

void BCurrentDisp1(const struct Burger* B){
	printf("\n\nCurrent Amount:\n[1]-> %d  [2]-> %d [3]-> %d", B->BeefAmt, B->ChknAmt, B->FishAmt);
}

void BCurrentDisp2(const struct Burger* B, int choice){
	switch (choice){
	case 1:
		printf("\n\nCurrent Amount:\n[1]-> %d  [2]-> %d [3]-> %d", B->BEA1, B->BEA2, B->BEA3);
		break;
	case 2:
		printf("\n\nCurrent Amount:\n[1]-> %d  [2]-> %d [3]-> %d", B->CKE1, B->CKE2, B->CKE3);
		break;
	case 3:
		printf("\n\nCurrent Amount:\n[1]-> %d  [2]-> %d [3]-> %d", B->FEA1, B->FEA2, B->FEA3);
		break;
	default:
		break;
	}
}

void MdTotal(struct MainDish* md, const float prices[]){
    md->mdtotal = 0.0;
    md->mdtotal += md->amt1 * prices[0];
    md->mdtotal += md->amt2 * prices[1];
    md->mdtotal += md->amt3 * prices[2];
    md->mdtotal += md->amt4 * prices[3];
    md->mdtotal += md->amt5 * prices[4];
}

void MaindishAmt(struct MainDish* md, const float prices[]){
    int choice;
    while (true){
        text(3);
        MDCurrentDisp(md);
        choice = read_integer_in_range("\nOption: ",1,6);
        switch (choice){
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
    printf("\nYour total is: %0.2f RM", MenuTotal);
}

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

    fprintf(file, "\nRecipt Date and Time: %s", asctime(tm_info));

    fprintf(file, "\n\nMain Dish amount:");
    fprintf(file, "\nSpare Ribs: %d \nSpaghetti Bolognese: %d \nFish & Chip: %d \nPepporoni Pizza: %d \nMac & Cheese %d", md->amt1, md->amt2, md->amt3, md->amt4, md->amt5);
    fprintf(file, "\n\n Main Dish Total: %0.2f RM", md->mdtotal);

    fprintf(file, "\n\nBurger amount:");
    fprintf(file, "\nBeef Burger: %d \nChicken Burger: %d \nFish Burger: %d", B->BeefAmt, B->ChknAmt,B->FishAmt);

    fprintf(file, "\n\nBeef Burger edits \nPatty: %d \nCheese: %d \nPickle: %d", B->BEA1, B->BEA2, B->BEA3);
    fprintf(file, "\nChiken Burger edits \nPatty: %d \nCheese: %d \nPickle: %d", B->CKE1, B->CKE2, B->CKE3);
    fprintf(file, "\nFish Burger edits \nPatty: %d \nCheese: %d \nPickle: %d", B->FEA1, B->FEA2, B->FEA3);

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
                option2 = read_integer_in_range ("\nOption: ",1,5);
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