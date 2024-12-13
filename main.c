#include <stdio.h>
#include <windows.h> //sleep
#include <ctype.h>

int main(void) {
    
    int i, j, k, choice, seatchoice, quantity, snackchoice, seatcount = 0, totalpayment = 0;
    char confirm, emailInput[100];

    int seats[10] = {0}; // 10 seats - 1 and 0 / on off 

    // foods and drinks
    char snacksndrinks[10][20] = {"🍔 Burger", "🍟 Fries", "🍩 Donut", "🍭 Candy", "🥨 Pretzels", "🍪 Cookies", "💦 Water", "🥤 Soda", "☕ Coffee", "🧃 Juice"};
    int snacksanddrinksID[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int snacksanddrinksPrices[10] = {69, 60, 40, 10, 50, 30, 20, 40, 50, 30};

    // user info
    char firstName[10][30], lastName[10][30], email[10][100];

    // user payment
    int userPayment[10] = {0};

    //loading screen
    printf("\033[H\033[J\033[0m");
    printf("************************************************************\n"); 
    printf("\033[96m\t\t 🚅️  Sanki Electric Railways 🚅️ \t\t\033[0m\n"); 
    printf("************************************************************\n");
    printf("Please wait while the program loads...\n");
    Sleep(1000);
    for (i = 0; i <= 50; i++) {
        printf("[");
        for (j = 0; j < i; j++) {
            printf("=");
        }
        for (k = 50; k > i; k--) {
            printf(" ");
        }
        printf("] %d%%", i * 2); // 2% ++
        Sleep(10);
        printf("\r"); //go to first line to overwrite bar
    }
    printf("\n");

    while (1) {
        // menu
        printf("\033[H\033[J\033[0m"); // clears screen
        printf("************************************************************\n"); 
        printf("\033[96m\t\t 🚅️  Sanki Electric Railways 🚅️ \t\t\033[0m\n"); 
        printf("************************************************************\n");
        Sleep(500);
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~ \033[93mMENU\033[0m ~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
        Sleep(100);
        
        printf("------------------------------------------------------------\n");
        Sleep(50);
        printf("\033[93m➿\tDisplay Seating Chart\t\033[92m. . . . . .\t'1'\033[0m\n");
        Sleep(50);
        printf("------------------------------------------------------------\n\n");
        Sleep(100);
        
        printf("------------------------------------------------------------\n");
        Sleep(50);
        printf("\033[93m💺\tReserve Seats      \t\033[92m. . . . . .\t'2'\033[0m\n"); 
        Sleep(50);
        printf("------------------------------------------------------------\n\n");
        Sleep(100);
        
        printf("------------------------------------------------------------\n");
        Sleep(50);
        printf("\033[93m❌\tCancel Reservation\t\033[92m. . . . . .\t'3'\033[0m\n");
        Sleep(50);
        printf("------------------------------------------------------------\n\n");
        Sleep(100);
    
        printf("------------------------------------------------------------\n");
        Sleep(50);
        printf("\033[93m🎫\tTicket Information\t\033[92m. . . . . .\t'4'\033[0m\n");
        Sleep(50);
        printf("------------------------------------------------------------\n\n");
        Sleep(100);
    
        printf("------------------------------------------------------------\n");
        Sleep(50);
        printf("\033[93m👋\tQuit            \t\033[92m. . . . . .\t'5'\033[0m\n");
        Sleep(50);
        printf("------------------------------------------------------------\n\n");
        Sleep(100);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
        Sleep(100);

        printf("\033[93mEnter choice (1 - 5): \033[0m");
        while (scanf(" %d", &choice) != 1 || choice >= 6 || choice <= 0) { // valid input
            printf("\033[91mInvalid choice.\033[92m Please try again (1 - 5): \033[0m");
            while(getchar() != '\n');
        }

        if (choice == 5) {
            printf("Quitting Program...");
            break;
        }

        while (getchar() != '\n'); // clear buffer before each case to prevent some errors
        switch (choice) {
            case 1: // display chart
                // display seat map
                printf("\033[H\033[J\033[0m");
                printf("************************************************************\n"); 
                printf("\033[96m\t\t 🚅️  Sanki Electric Railways 🚅️ \t\t\033[0m\n"); 
                printf("************************************************************\n");
                Sleep(500);
                printf("\n~~~~~~~~~~~~~~~~~~~~~~~ \033[93mSeating Chart\033[0m ~~~~~~~~~~~~~~~~~~~~~~\n\n");
                Sleep(100);
                printf("------------------------------------------------------------\n     ");
                Sleep(50);
                for (i = 0; i < 10; i++) {
                    if (seats[i] == 0) {
                        printf("\033[92m[ %02d: O ] \033[0m", i + 1);
                    } else {
                        printf("\033[91m[ %02d: X ] \033[0m", i + 1);
                    }
                    Sleep(50);
                    if (i + 1 == 5) { // new line after 5th seat
                        printf("\n     ");
                    }
                }
                Sleep(50);
                printf("\n------------------------------------------------------------\n\n");
                Sleep(100);
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

                printf("\nPress enter to continue...");// wait for enter key
                while (getchar() != '\n'); // clear buffer
                break;
            case 2: // reserve seat
                // display seat map
                printf("\033[H\033[J\033[0m");
                // header
                printf("************************************************************\n"); 
                printf("\033[96m\t\t 🚅️  Sanki Electric Railways 🚅️ \t\t\033[0m\n"); 
                printf("************************************************************\n");
                Sleep(500);
                printf("\n~~~~~~~~~~~~~~~~~~~~~~~ \033[93mSeating Chart\033[0m ~~~~~~~~~~~~~~~~~~~~~~\n\n");
                Sleep(100);
                printf("------------------------------------------------------------\n     ");
                Sleep(50);
                for (i = 0; i < 10; i++) {
                    if (seats[i] == 0) {
                        printf("\033[92m[ %02d: O ] \033[0m", i + 1);
                    } else {
                        printf("\033[91m[ %02d: X ] \033[0m", i + 1);
                    }
                    Sleep(50);
                    if (i + 1 == 5) { // new line after 5th seat
                        printf("\n     ");
                    }
                }
                Sleep(50);
                printf("\n------------------------------------------------------------\n\n");
                Sleep(100);
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

                printf("\033[93mSelect a seat to reserve (1 - 10): \033[0m");
                while (scanf(" %d", &seatchoice) != 1 || seatchoice < 0 || seatchoice >= 11 || seats[seatchoice - 1] == 1) {
                    if (seats[seatchoice - 1] == 1) {
                        printf("\033[91mSeat %d is already reserved.\033[92m Please select a different seat (1 - 10): \033[0m", seatchoice);
                    } else {
                    printf("0 to return to menu\n");
                    printf("\033[91mInvalid choice.\033[92m Please try again (1 - 10): \033[0m");
                    while(getchar() != '\n');
                    }
                }
                // go back to menu
                if (seatchoice == 0) {
                    printf("Returning to main menu...\n");
                    Sleep(1000);
                    break;
                }

                // confirmation
                printf("\033[H\033[J\033[0m");
                printf("************************************************************\n"); 
                printf("\033[96m\t\t 🚅️  Sanki Electric Railways 🚅️ \t\t\033[0m\n"); 
                printf("************************************************************\n");
                Sleep(500);
                printf("\033[93mTicket Price: ₱150\n");
                printf("\033[91mData is required for reservation.\n");
                printf("\033[92mThe data will be used for ticket information.\n");
                printf("\033[93mWould you like to proceed? (y/n): \033[0m");
                while (getchar() != '\n');
                while (scanf(" %c", &confirm) != 1 || (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n')) {
                    printf("\033[91mInvalid Input. \033[92mPlease input 'y' for yes or 'n' for no: \033[0m");
                    while (getchar() != '\n');
                }
                
                // if yes
                if (confirm == 'y' || confirm == 'Y') {

                    while (getchar() != '\n');
                    printf("\033[93mFirst Name: \033[0m");
                    fgets(firstName[seatchoice - 1], 30, stdin);
                    firstName[seatchoice - 1][strcspn(firstName[seatchoice - 1], "\n")] = '\0'; // remove newline

                    printf("\033[93mLast Name: \033[0m");
                    fgets(lastName[seatchoice - 1], 30, stdin);
                    lastName[seatchoice - 1][strcspn(lastName[seatchoice - 1], "\n")] = '\0';

                    printf("\033[93mEmail: \033[0m");
                    fgets(email[seatchoice - 1], 100, stdin);
                    email[seatchoice - 1][strcspn(email[seatchoice - 1], "\n")] = '\0';
                    // convert email to all small caps for pass
                    for (int i = 0; email[seatchoice - 1][i]; i++) {
                        email[seatchoice - 1][i] = tolower(email[seatchoice - 1][i]);
                    }

                    // capitalize first letter
                    firstName[seatchoice - 1][0] = toupper(firstName[seatchoice - 1][0]);
                    lastName[seatchoice - 1][0] = toupper(lastName[seatchoice - 1][0]);

                    userPayment[seatchoice - 1] = 150;
                    seatcount++;
                    printf("Reserving seat %d for %s %s...\n", seatchoice, firstName[seatchoice - 1], lastName[seatchoice - 1]);
                    Sleep(1000);
                    seats[seatchoice - 1] = 1;
                    printf("\033[92mSeat %d has been reserved successfully.\033[0m\n", seatchoice);

                    printf("Would you like to order snacks and drinks for your trip? (y/n): ");
                    while (scanf(" %c", &confirm) != 1 || (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n')) {
                        printf("\033[91mInvalid Input. \033[92mPlease input 'y' for yes or 'n' for no: \033[0m");
                        while (getchar() != '\n');
                    }

                    if (confirm == 'y' || confirm == 'Y') {
                        while (1) {
                            // snacks and drinks menu
                             while (getchar() != '\n');
                            printf("\033[H\033[J\033[0m");
                            printf("************************************************************\n"); 
                            printf("\033[96m\t\t 🚅️  Sanki Electric Railways 🚅️ \t\t\033[0m\n"); 
                            printf("************************************************************\n");
                            Sleep(500);
                            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                            Sleep(100);
                            printf("--------------------- \033[93mSnacks and Drinks\033[0m --------------------\n");
                            Sleep(100);
                            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                            Sleep(100);
                            printf("\033[92mPrice\t\033[93mSnacks&Drinks    \t\t\t\t\033[92m'ID'\033[0m\n");

                            //display snack
                            for (i = 0; i < 10; i++) {
                                printf("------------------------------------------------------------\n");
                                Sleep(50);
                                printf("\033[92m₱%d\t\033[93m%s                  \t\033[92m. . . . . .\t'%d'\033[0m\n", snacksanddrinksPrices[i], snacksndrinks[i], snacksanddrinksID[i]);
                                printf("------------------------------------------------------------\n");
                                Sleep(50);
                            }

                            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                            printf("\033[93mEnter your choice: \033[0m");
                            while (scanf("%d", &snackchoice) != 1 || snackchoice < 0 || snackchoice > 10) {
                                printf("0 to return to menu\n");
                                printf("\033[91mInvalid input. \033[92mPlease enter a valid choice: \033[0m");
                                while (getchar() != '\n');
                            }

                            if (snackchoice == 0) {
                                printf("Returning to main menu...");
                                Sleep(1000);
                                break;
                            }
                            
                            printf("\033[93mEnter the quantity: \033[0m");
                            while (scanf("%d", &quantity) != 1 || quantity <= 0 || quantity > 10) {
                                if (quantity > 10) {
                                    printf("\033[91mSorry you can only order up to 10 snacks and drinks: \033[0m");
                                } else {
                                    printf("\033[91mInvalid input. \033[92mPlease enter a positive integer: \033[0m");
                                }
                                while (getchar() != '\n');
                            }

                            // add total payment
                            userPayment[seatchoice - 1] += (snacksanddrinksPrices[snackchoice - 1] * quantity);
                            printf("\033[92mOrder confirmed for %d %s. \033[93mTotal Payment: ₱%d.\033[0m\n", quantity, snacksndrinks[snackchoice - 1], userPayment[seatchoice - 1]);
                            printf("Do you want to order more snacks and drinks? (y/n): "); 
                            while (scanf(" %c", &confirm) != 1 || (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N')) {
                                printf("\033[91mInvalid input. \033[92mPlease enter 'y' for Yes or 'n' for No: \033[0m");
                                while (getchar() != '\n');
                            }
                            if (confirm == 'n' || confirm == 'N') {
                                printf("Thank for you choosing Sanki Electric Railways\n");
                                printf("Returning to main menu...");
                                Sleep(2000);
                                break;
                            }
                        }
                    } else {
                        printf("Thank for you choosing Sanki Electric Railways\n");
                        printf("Returning to main menu...");
                        Sleep(2000);
                    }

                } else {
                    printf("Returning back to main menu...");
                    Sleep(1000);
                }
                while (getchar() != '\n');
                break;
            case 3: // cancel reservation
                // display seat map
                printf("\033[H\033[J\033[0m");
                printf("************************************************************\n"); 
                printf("\033[96m\t\t 🚅️  Sanki Electric Railways 🚅️ \t\t\033[0m\n"); 
                printf("************************************************************\n");
                Sleep(500);
                printf("\n~~~~~~~~~~~~~~~~~~~~~~~ \033[93mSeating Chart\033[0m ~~~~~~~~~~~~~~~~~~~~~~\n\n");
                Sleep(100);
                printf("------------------------------------------------------------\n     ");
                Sleep(50);
                for (i = 0; i < 10; i++) {
                    if (seats[i] == 0) {
                        printf("\033[92m[ %02d: O ] \033[0m", i + 1);
                    } else {
                        printf("\033[91m[ %02d: X ] \033[0m", i + 1);
                    }
                    Sleep(50);
                    if (i + 1 == 5) { // new line after 5th seat
                        printf("\n     ");
                    }
                }
                Sleep(50);
                printf("\n------------------------------------------------------------\n\n");
                Sleep(100);
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

                if (seatcount == 0) {
                    printf("\033[91mNo reservations have been made.\033[0m\n");
                    printf("Returning to main menu...");
                    Sleep(2000);
                    break;
                }

                printf("\033[92mEnter the seat number to cancel reservation (1 - 10): \033[0m");
                while (scanf("%d", &seatchoice) != 1 || seatchoice < 0 || seatchoice >= 11 || seats[seatchoice - 1] == 0) {
                    if (seats[seatchoice - 1] == 0) {
                        printf("\033[91mSeat %d is not reserved.\033[92m Please select a different seat (1 - 10): \033[0m", seatchoice);
                    } else {
                        printf("0 to return to menu\n");
                        printf("\033[91mInvalid choice.\033[92m Please try again (1 - 10): \033[0m");
                    }
                    while (getchar() != '\n');
                }
                if (seatchoice == 0) {
                    printf("Returning to main menu...\n");
                    Sleep(1000);
                    break;
                }

                printf("\033[91mAre you sure you want to cancel the reservation for seat %d? (y/n): \033[0m", seatchoice);
                while (scanf(" %c", &confirm) != 1 || (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n')) {
                    printf("\033[91mInvalid Input. \033[92mPlease input 'y' for yes or 'n' for no: \033[0m");
                    while (getchar() != '\n');
                }

                if (confirm == 'y' || confirm == 'Y') {
                    printf("Enter your email to confirm: ");
                    while (getchar() != '\n');
                    scanf("%s", emailInput);
                    // lowercase
                    for (i = 0; emailInput[i]; i++) {
                        emailInput[i] = tolower(emailInput[i]);
                    }
                    // if true or not == 0 becuz  strcmp return 0 if true
                    if (strcmp(emailInput, email[seatchoice - 1]) == 0) {
                        printf("Reservation for seat %d has been \033[91mcancelled.\033[0m\n", seatchoice);
                        // return to default values
                        seatcount--;
                        seats[seatchoice - 1] = 0;
                        firstName[seatchoice - 1][0] = '\0';
                        lastName[seatchoice - 1][0] = '\0';
                        email[seatchoice - 1][0] = '\0';
                        userPayment[seatchoice - 1] = 0;
                        Sleep(3000);
                    } else {
                        printf("\033[91mEmail does not match. \033[0mReturning to main menu...\n");
                        Sleep(1000);
                    }

                } else {
                    printf("Returning to main menu...\n");
                    Sleep(1000);
                }

                break;
            case 4: // view ticket information
                // display seat map
                printf("\033[H\033[J\033[0m");
                printf("************************************************************\n"); 
                printf("\033[96m\t\t 🚅️  Sanki Electric Railways 🚅️ \t\t\033[0m\n"); 
                printf("************************************************************\n");
                Sleep(500);
                printf("\n~~~~~~~~~~~~~~~~~~~~~~~ \033[93mSeating Chart\033[0m ~~~~~~~~~~~~~~~~~~~~~~\n\n");
                Sleep(100);
                printf("------------------------------------------------------------\n     ");
                Sleep(50);
                for (i = 0; i < 10; i++) {
                    if (seats[i] == 0) {
                        printf("\033[92m[ %02d: O ] \033[0m", i + 1);
                    } else {
                        printf("\033[91m[ %02d: X ] \033[0m", i + 1);
                    }
                    Sleep(50);
                    if (i + 1 == 5) { // new line after 5th seat
                        printf("\n     ");
                    }
                }
                Sleep(50);
                printf("\n------------------------------------------------------------\n\n");
                Sleep(100);
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

                if (seatcount == 0) {
                    printf("\033[91mNo reservations have been made.\033[0m\n");
                    printf("Returning to main menu...");
                    Sleep(2000);
                    break;
                }

                printf("\033[92mEnter the seat number to view ticket information (1 - 10): \033[0m");
                while (scanf("%d", &seatchoice) != 1 || seatchoice < 0 || seatchoice >= 11 || seats[seatchoice - 1] == 0) {
                    if (seats[seatchoice - 1] == 0) {
                        printf("\033[91mSeat %d is not reserved.\033[92m Please select a different seat (1 - 10): \033[0m", seatchoice);
                    } else {
                        printf("0 to return to menu\n");
                        printf("\033[91mInvalid choice.\033[92m Please try again (1 - 10): \033[0m");
                    }
                    while (getchar() != '\n');
                }
                if (seatchoice == 0) {
                    printf("Returning to main menu...\n");
                    Sleep(1000);
                    break;
                }
                // verify
                printf("\033[92mEnter your email to confirm: \033[0m");
                while (getchar() != '\n');
                scanf("%s", emailInput);
                // lowercase
                for (i = 0; emailInput[i]; i++) {
                    emailInput[i] = tolower(emailInput[i]);
                }
                // if true or not == 0 becuz  strcmp return 0 if true
                if (strcmp(emailInput, email[seatchoice - 1]) == 0) {
                    printf("Loading Ticket Information...");
                    Sleep(1000);
                    printf("\033[H\033[J\033[0m");
                    printf("************************************************************\n");
                    printf("\033[96m\t\t 🚅️  Sanki Electric Railways 🚅️ \t\t\033[0m\n");
                    printf("************************************************************\n");
                    Sleep(500);
                    printf("\n~~~~~~~~~~~~~~~~~~~~ \033[93mTicket Information\033[0m ~~~~~~~~~~~~~~~~~~~~\n\n");
                    Sleep(100);
                    printf("------------------------------------------------------------\n     ");
                    Sleep(50);
                    printf("\033[92mSeat Number: \033[0m%d\n", seatchoice);
                    Sleep(50);
                    printf("------------------------------------------------------------\n");
                    Sleep(100);
                    
                    printf("------------------------------------------------------------\n     ");
                    Sleep(50);
                    printf("\033[92mFirst Name: \033[0m%s\n", firstName[seatchoice - 1]);
                    Sleep(50);
                    printf("------------------------------------------------------------\n");
                    Sleep(100);

                    printf("------------------------------------------------------------\n     ");
                    Sleep(50);
                    printf("\033[92mLast Name: \033[0m%s\n", lastName[seatchoice - 1]);
                    Sleep(50);
                    printf("------------------------------------------------------------\n");
                    Sleep(100);

                    printf("------------------------------------------------------------\n     ");
                    Sleep(50);
                    printf("\033[92mEmail: \033[0m%s\n", email[seatchoice - 1]);
                    Sleep(50);
                    printf("------------------------------------------------------------\n");
                    Sleep(100);
                    
                    printf("------------------------------------------------------------\n     ");
                    Sleep(50);
                    printf("\033[92mPayment: \033[93m₱%d\n\033[0m", userPayment[seatchoice - 1]);
                    Sleep(50);
                    printf("------------------------------------------------------------\n");
                    Sleep(100);

                    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    printf("\033[0mPress Enter to continue...");
                    while (getchar() != '\n');
                    getchar();
                } else {
                    printf("\033[91mEmail does not match. \033[0mReturning to main menu...\n");
                    Sleep(1000);
                    break;
                }
            printf("Returning to main menu...\n");
            Sleep(1000);
            break;
        }
    }

    //loading screen
    printf("\033[H\033[J\033[0m");
    printf("************************************************************\n"); 
    printf("\033[96m\t\t 🚅️  Sanki Electric Railways 🚅️ \t\t\033[0m\n"); 
    printf("************************************************************\n");
    // display seat chart
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~ \033[93mSeating Chart\033[0m ~~~~~~~~~~~~~~~~~~~~~~\n\n");
    Sleep(100);
    printf("------------------------------------------------------------\n     ");
    Sleep(50);
    for (i = 0; i < 10; i++) {
        if (seats[i] == 0) {
            printf("\033[92m[ %02d: O ] \033[0m", i + 1);
        } else {
            printf("\033[91m[ %02d: X ] \033[0m", i + 1);
        }
        Sleep(50);
        if (i + 1 == 5) { // new line after 5th seat
            printf("\n     ");
        }
    }
    Sleep(50);
    printf("\n------------------------------------------------------------\n\n");
    Sleep(100);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("\033[93mSummary:\033[0m\n");
    Sleep(2000);
    printf("\033[92mTotal Seats Reserved: \033[93m%d\033[0m\n", seatcount);
    for (i = 0; i < 10; i++) {
        if (seats[i] == 1) {
            printf("Seat %d: %s %s\n", i + 1, firstName[i], lastName[i]);
        }
    }
    Sleep(2000);
    for (i = 0; i < 10; i++) {
        totalpayment += userPayment[i];
    }
    printf("\033[92mTotal Earnings: \033[93m₱%d\n", totalpayment);
    Sleep(2000);
    printf("\033[0mThank you for using \033[96mSanki Electric Railways\033[0m. \033[93mGoodbye!\033[0m\n");
    Sleep(5000);
    printf("Quitting Program...\n");

    for (i = 0; i <= 50; i++) {
        printf("[");
        for (j = 0; j < i; j++) {
            printf("=");
        }
        for (k = 50; k > i; k--) {
            printf(" ");
        }
        printf("] %d%%", i * 2); // 2% per iteration
        Sleep(10);
        printf("\r"); //go to first line to overwrite bar
    }
    printf("\n");
}