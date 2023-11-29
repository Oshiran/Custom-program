#include <stdio.h>
#include <stdbool.h>

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
				"\n[5] Read Recipt"
				"\n[6] Done with order");
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

