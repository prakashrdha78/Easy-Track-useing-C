#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Transaction {
    char type[20];
    char category[50];
    float amount;
};

void addTransaction() {
    struct Transaction t;
    FILE *fp;

    fp = fopen("easytrack_data.txt", "a");

    if (fp == NULL) {
        printf("File error! Cannot add transaction.\n");
        return;
    }

    printf("\nEnter type Income or Expense: ");
    scanf("%19s", t.type);

    printf("Enter category: ");
    scanf("%49s", t.category);

    printf("Enter amount: ");
    scanf("%f", &t.amount);

    fprintf(fp, "%s %s %.2f\n", t.type, t.category, t.amount);

    fclose(fp);

    printf("\nTransaction added successfully!\n");
}

void viewTransactions() {
    struct Transaction t;
    FILE *fp;

    fp = fopen("easytrack_data.txt", "r");

    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    printf("\n--- All Transactions ---\n");
    printf("Type\t\tCategory\tAmount\n");

    while (fscanf(fp, "%19s %49s %f", t.type, t.category, &t.amount) == 3) {
        printf("%s\t\t%s\t\t%.2f\n", t.type, t.category, t.amount);
    }

    fclose(fp);
}

void showSummary() {
    struct Transaction t;
    FILE *fp;
    float income = 0, expense = 0, balance;

    fp = fopen("easytrack_data.txt", "r");

    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    while (fscanf(fp, "%19s %49s %f", t.type, t.category, &t.amount) == 3) {
        if (strcmp(t.type, "Income") == 0 || strcmp(t.type, "income") == 0) {
            income += t.amount;
        } else if (strcmp(t.type, "Expense") == 0 || strcmp(t.type, "expense") == 0) {
            expense += t.amount;
        }
    }

    fclose(fp);

    balance = income - expense;

    printf("\n--- Money Summary ---\n");
    printf("Total Income  = %.2f\n", income);
    printf("Total Expense = %.2f\n", expense);
    printf("Balance       = %.2f\n", balance);
}

int main() {
    int choice;

    while (1) {
        printf("\n==============================\n");
        printf("     EasyTrack Money Tracker\n");
        printf("==============================\n");
        printf("1. Add Transaction\n");
        printf("2. View Transactions\n");
        printf("3. Show Summary\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTransaction();
                break;

            case 2:
                viewTransactions();
                break;

            case 3:
                showSummary();
                break;

            case 4:
                printf("\nThank you for using EasyTrack!\n");
                exit(0);

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}