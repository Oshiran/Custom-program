#include <stdio.h>
#include <stdbool.h>

// Structure definition
struct MainDish {
    int amt1, amt2, amt3, amt4, amt5;
    float totalCost; // New member to store the total cost
};

// Function to read an integer within a specified range
int readIntegerInRange(const char* prompt, int min, int max) {
    int input;

    do {
        printf("%s", prompt);
        scanf("%d", &input);

        if (input < min || input > max) {
            printf("Invalid input. Please enter a number between %d and %d.\n", min, max);
        }

    } while (input < min || input > max);

    return input;
}

// Maindish function
void Maindish(struct MainDish* md, const float prices[]) {
    printf("Please pick an option:\n"
           "[1] Spare Ribs\n"
           "[2] Spaghetti Bolognese\n"
           "[3] Fish & Chips\n"
           "[4] Pepporoni Pizza\n"
           "[5] Mac & Cheese\n"
           "[6] Finished\n");

    int choice;
    while (true) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                md->amt1 = readIntegerInRange("\nPlease enter amount: ", 0, 25);
                break;
            case 2:
                md->amt2 = readIntegerInRange("\nPlease enter amount: ", 0, 25);
                break;
            case 3:
                md->amt3 = readIntegerInRange("\nPlease enter amount: ", 0, 25);
                break;
            case 4:
                md->amt4 = readIntegerInRange("\nPlease enter amount: ", 0, 25);
                break;
            case 5:
                md->amt5 = readIntegerInRange("\nPlease enter amount: ", 0, 25);
                break;
            case 6:
                printf("\nFinished\n");
                // Calculate the total cost of the main dish and store it in the struct
                md->totalCost = 0.0;
                md->totalCost += md->amt1 * prices[0];
                md->totalCost += md->amt2 * prices[1];
                md->totalCost += md->amt3 * prices[2];
                md->totalCost += md->amt4 * prices[3];
                md->totalCost += md->amt5 * prices[4];
                return;
            default:
                printf("\nInvalid choice\n");
                break;
        }
    }
}

int main() {
    struct MainDish md;
    // Specify prices for each main dish
    float prices[] = {15.0, 14.50, 13.00, 22.0, 12.0};

    Maindish(&md, prices);

    // Print the amounts selected by the user
    printf("Amounts selected: %d %d %d %d %d\n", md.amt1, md.amt2, md.amt3, md.amt4, md.amt5);

    // Print the total cost stored in the struct
    printf("Total cost of the main dish: $%.2f\n", md.totalCost);

    return 0;
}
