
#include <stdio.h>

int choice, sum=0;
int quantity[9] = {0};

void menu() {
    printf("\n------------------------------\n");
    printf("-------------MENU-------------\n");
    printf("\nBREAKFAST & TIFFINS\n");
    printf("1. Idli Sambhar - Rs. 25/-\n");
    printf("2. Samosa - Rs. 15/-\n");
    printf("3. Masala Dosa - Rs. 40/-\n");
    printf("\nMAIN COURSE\n");
    printf("4. Veg Thali - Rs. 60/-\n");
    printf("5. Chicken Biryani - Rs. 96/-\n");
    printf("6. Noodles - Rs. 30/-\n");
    printf("\nDRINKS\n");
    printf("7. Filter Coffee - Rs. 10/-\n");
    printf("8. Cold Coffee - Rs. 60/-\n");
    printf("9. Soft Drinks - Rs. 20/-\n");
    printf("0. Finish ordering\n");
    printf("\n-------------------------------\n");
}

int order(int choice) {
    int a = 0;
    int q;
    if(choice == 1) {
        a = 25;
    } else if(choice == 2) {
        a = 15;
    } else if(choice == 3) {
        a = 40;
    } else if(choice == 4) {
        a = 60;
    } else if(choice == 5) {
        a = 96;
    } else if(choice == 6) {
        a = 30;
    } else if(choice == 7) {
        a = 10;
    } else if(choice == 8) {
        a = 60;
    } else if(choice == 9) {
        a = 20;
    } else {
        a = 0;
    }

    while(1) {
        printf("Quantity: ");
        scanf("%d", &q);
        if(q <= 0) {
            printf("Invalid choice!!!\n");
            continue;
        }
        break;
    }

    quantity[choice-1] = quantity[choice-1] + q;
    return q*a;
}

void bill_amt() {
    int price[9] = {25, 15, 40, 60, 96, 30, 10, 60, 20};
    int i = 0;
    printf("\n----------FINAL BILL----------\n");
    printf("Items\t\tQuantity\tAmount\n");
    while(i < 9) {
        if(quantity[i] > 0) {
            if(i == 0) {
                printf("%-20s","Idli Sambhar");
            } else if(i == 1) {
                printf("%-20s","Samosa");
            } else if(i == 2) {
                printf("%-20s","Masala Dosa");
            } else if(i == 3) {
                printf("%-20s","Veg Thali");
            } else if(i == 4) {
                printf("%-20s","Chicken Biryani");
            } else if(i == 5) {
                printf("%-20s","Noodles");
            } else if(i == 6) {
                printf("%-20s","Filter Coffee");
            } else if(i == 7) {
                printf("%-20s","Cold Coffee");
            } else if(i == 8) {
                printf("%-20s","Soft Drinks");
            }
        printf("%8d %10d\n", quantity[i], quantity[i]*price[i]);
        }
        i++;
    }

    printf("\n------------------------------\n");
}

int main() {
    int loop = 1;
    int main_choice;
    char a, b, c;
    while(loop) {
        printf("\n\t\tWelcome to CanteenX\n");
        printf("\nWhat do you want to do?\n");
        printf("a. Check the menu\n");
        printf("b. Order\n");
        printf("c. Bill\n");
        printf("d. Exit\n");
        
        printf("\nEnter your choice: ");
        scanf(" %c", &main_choice);

        switch(main_choice) {
            case 'A':
            case 'a': printf("\nYour menu is here...!\n");
                      menu();
                      break;
            case 'B':
            case 'b': while(1) {
                          printf("\nEnter your choice to order: ");
                          scanf("%d", &choice);
                          if(choice == 0) {
                              break;
                          } 
                          if(choice > 9 || choice < 0) {
                              printf("Invalid choice\n");
                              continue;
                          }
                          
                          sum = sum + order(choice);
                      }
                      break;
            case 'C':
            case 'c': bill_amt();
                      printf("TOTAL AMOUNT: Rs. %d/-\n", sum);
                      break;
            case 'D':
            case 'd': loop = 0;
                      break;
            default:  printf("Invalid choice!!\n");
                      continue;
        }
    }
    printf("\nTHANK YOU! VISIT AGAIN!\n");
    return 0;
}
