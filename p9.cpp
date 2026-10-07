#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 100

typedef struct {
    char type[20];
    float amount;
    float balanceAfter;
} Transaction;

typedef struct {
    int accountNo;
    char name[50];
    char mobile[15];
    int pin;
    float balance;

    Transaction transactions[MAX_TRANSACTIONS];
    int transactionCount;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

/* Function Prototypes */
int findAccount(int accountNo);
void createAccount();
void login();
void bankingMenu(int index);
void checkBalance(int index);
void deposit(int index);
void withdraw(int index);
void transferMoney(int index);
void changePin(int index);
void accountDetails(int index);
void miniStatement(int index);
void addTransaction(int index, char type[], float amount);


/* Find account by account number */
int findAccount(int accountNo) {

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNo == accountNo) {
            return i;
        }
    }

    return -1;
}


/* Add transaction */
void addTransaction(int index, char type[], float amount) {

    if (accounts[index].transactionCount >= MAX_TRANSACTIONS) {
        return;
    }

    int t = accounts[index].transactionCount;

    strcpy(accounts[index].transactions[t].type, type);
    accounts[index].transactions[t].amount = amount;
    accounts[index].transactions[t].balanceAfter =
        accounts[index].balance;

    accounts[index].transactionCount++;
}


/* Create New Account */
void createAccount() {

    if (accountCount >= MAX_ACCOUNTS) {
        printf("\nAccount limit reached!\n");
        return;
    }

    Account newAccount;

    printf("\n========== CREATE ACCOUNT ==========\n");

    newAccount.accountNo = 1001 + accountCount;

    printf("Generated Account Number: %d\n",
           newAccount.accountNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", newAccount.name);

    printf("Enter Mobile Number: ");
    scanf("%14s", newAccount.mobile);

    printf("Create 4 Digit PIN: ");
    scanf("%d", &newAccount.pin);

    printf("Enter Initial Deposit: ");
    scanf("%f", &newAccount.balance);

    if (newAccount.balance < 0) {
        printf("Invalid amount!\n");
        return;
    }

    newAccount.transactionCount = 0;

    accounts[accountCount] = newAccount;

    if (newAccount.balance > 0) {
        addTransaction(accountCount,
                       "Initial Deposit",
                       newAccount.balance);
    }

    accountCount++;

    printf("\nAccount Created Successfully!\n");
    printf("Your Account Number: %d\n",
           newAccount.accountNo);
}


/* Login */
void login() {

    int accountNo;
    int pin;

    printf("\n========== LOGIN ==========\n");

    printf("Enter Account Number: ");
    scanf("%d", &accountNo);

    int index = findAccount(accountNo);

    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter PIN: ");
    scanf("%d", &pin);

    if (accounts[index].pin != pin) {
        printf("Incorrect PIN!\n");
        return;
    }

    printf("\nLogin Successful!\n");
    printf("Welcome, %s!\n", accounts[index].name);

    bankingMenu(index);
}


/* Check Balance */
void checkBalance(int index) {

    printf("\n========== BALANCE ==========\n");

    printf("Account Number : %d\n",
           accounts[index].accountNo);

    printf("Current Balance: %.2f\n",
           accounts[index].balance);
}


/* Deposit */
void deposit(int index) {

    float amount;

    printf("\n========== DEPOSIT ==========\n");

    printf("Enter Amount: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount!\n");
        return;
    }

    accounts[index].balance += amount;

    addTransaction(index, "Deposit", amount);

    printf("Amount Deposited Successfully!\n");
    printf("New Balance: %.2f\n",
           accounts[index].balance);
}


/* Withdraw */
void withdraw(int index) {

    float amount;

    printf("\n========== WITHDRAW ==========\n");

    printf("Enter Amount: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount!\n");
        return;
    }

    if (amount > accounts[index].balance) {
        printf("Insufficient Balance!\n");
        return;
    }

    accounts[index].balance -= amount;

    addTransaction(index, "Withdrawal", amount);

    printf("Please Collect Your Cash.\n");
    printf("Remaining Balance: %.2f\n",
           accounts[index].balance);
}


/* Transfer Money */
void transferMoney(int index) {

    int receiverAccount;
    float amount;

    printf("\n========== MONEY TRANSFER ==========\n");

    printf("Enter Receiver Account Number: ");
    scanf("%d", &receiverAccount);

    int receiverIndex = findAccount(receiverAccount);

    if (receiverIndex == -1) {
        printf("Receiver Account Not Found!\n");
        return;
    }

    if (receiverIndex == index) {
        printf("You cannot transfer money to your own account!\n");
        return;
    }

    printf("Enter Amount: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount!\n");
        return;
    }

    if (amount > accounts[index].balance) {
        printf("Insufficient Balance!\n");
        return;
    }

    accounts[index].balance -= amount;
    accounts[receiverIndex].balance += amount;

    addTransaction(index, "Transfer Sent", amount);
    addTransaction(receiverIndex, "Transfer Received", amount);

    printf("\nTransfer Successful!\n");
    printf("Transferred Amount: %.2f\n", amount);
    printf("Remaining Balance: %.2f\n",
           accounts[index].balance);
}


/* Change PIN */
void changePin(int index) {

    int oldPin;
    int newPin;

    printf("\n========== CHANGE PIN ==========\n");

    printf("Enter Old PIN: ");
    scanf("%d", &oldPin);

    if (oldPin != accounts[index].pin) {
        printf("Incorrect Old PIN!\n");
        return;
    }

    printf("Enter New PIN: ");
    scanf("%d", &newPin);

    accounts[index].pin = newPin;

    printf("PIN Changed Successfully!\n");
}


/* Account Details */
void accountDetails(int index) {

    printf("\n========== ACCOUNT DETAILS ==========\n");

    printf("Account Number : %d\n",
           accounts[index].accountNo);

    printf("Name           : %s\n",
           accounts[index].name);

    printf("Mobile         : %s\n",
           accounts[index].mobile);

    printf("Balance        : %.2f\n",
           accounts[index].balance);
}


/* Mini Statement */
void miniStatement(int index) {

    printf("\n========== MINI STATEMENT ==========\n");

    if (accounts[index].transactionCount == 0) {
        printf("No transactions found.\n");
        return;
    }

    printf("\n%-20s %-15s %-15s\n",
           "Transaction",
           "Amount",
           "Balance");

    printf("-----------------------------------------------\n");

    for (int i = 0;
         i < accounts[index].transactionCount;
         i++) {

        printf("%-20s %-15.2f %-15.2f\n",
               accounts[index].transactions[i].type,
               accounts[index].transactions[i].amount,
               accounts[index].transactions[i].balanceAfter);
    }
}


/* Banking Menu */
void bankingMenu(int index) {

    int choice;

    do {

        printf("\n=================================\n");
        printf("          BANKING MENU\n");
        printf("=================================\n");

        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Transfer Money\n");
        printf("5. Change PIN\n");
        printf("6. Account Details\n");
        printf("7. Mini Statement\n");
        printf("8. Logout\n");

        printf("---------------------------------\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                checkBalance(index);
                break;

            case 2:
                deposit(index);
                break;

            case 3:
                withdraw(index);
                break;

            case 4:
                transferMoney(index);
                break;

            case 5:
                changePin(index);
                break;

            case 6:
                accountDetails(index);
                break;

            case 7:
                miniStatement(index);
                break;

            case 8:
                printf("\nLogged Out Successfully!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while (choice != 8);
}


/* Main Function */
int main() {

    int choice;

    printf("=====================================\n");
    printf("       DYNAMIC BANKING SYSTEM\n");
    printf("=====================================\n");

    do {

        printf("\n========== MAIN MENU ==========\n");

        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                createAccount();
                break;

            case 2:
                login();
                break;

            case 3:
                printf("\nThank You For Using Banking System!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while (choice != 3);

    return 0;
}

