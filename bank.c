// Source : https://www.programiz.com/c-programming/c-file-input-output
// C program to implement
// the above approach
#include <string.h>
#include <pthread.h>  // POSIX thread
#include <stdio.h>    // C I/O library
#include <stdlib.h>   // C standard library
#include <sys/wait.h> // declarations for waiting
#include <unistd.h>   // UNIX standard symbolic constants and types


//////Added from Ian
//////Added from Ian



/**
 * An account is a structure that represents a bank account.
 * @property {int} balance - The amount of money in the account.
 */
typedef struct __account {
    int balance;
} account;

/**
 * The type of transaction.
 */
typedef enum __transaction_t { Withdraw, Deposit, Unknown } transaction_t;

/**
 * A transaction is a structure that contains a transaction type and an amount.
 * @property {transaction_t} transactionType - The type of transaction.
 * @property {int} amount - The amount of the transaction.
 */
typedef struct __transaction {
    transaction_t transactionType;
    int amount;
} transaction;

/**
 * A transactionQueue is a struct that contains a long and a pointer to a transaction.
 * @property {long} size - The number of transactions in the queue.
 * @property {transaction} transactions - an array of transactions
 */
typedef struct __transactionQueue {
    long size;
    transaction *transactions;

} transactionQueue;

/**
 * ExecuteTransactionsStruct is a struct that contains a pointer to an account and a pointer to a
 * transactionQueue.
 * @property {account} transactingAccount - The account that is currently being transacted.
 * @property {transactionQueue} currentTransactionQueue - A queue of transactions that are to be
 * executed.
 */
typedef struct __executeTransactionsStruct {
    account *transactingAccount;
    transactionQueue *currentTransactionQueue;

} executeTransactionsStruct;

void *parseTransactions( void *voidFileName );
transaction createTransaction( char *transactionRecord );
void *executeTransactions( void *voidExecuteTransactionsStruct );
void processTransaction( account *transactingAccount, transaction *currentTransaction );
int deposit( int amount );
int withdraw( int amount );



/*
    The definitions below are just used as example code.
    Your code will have to actually read data from files to get the data
    ! Remove them!
*/
#define IS_WITHDRAWAL 1
#define AMOUNT_READ 1
#define THERE_IS_DATA_IN_FILE_1 1
#define THERE_IS_DATA_IN_FILE_2 1



//////Added from Ian
//////Added from Ian

int readFiles(){
  FILE* ptr; //first file pointer
  FILE* ptr2; //second file pointer
	char ch;
  char ch2;

	// Opening file in reading mode
	ptr = fopen("Husband.txt", "r");
  

	if (NULL == ptr) {
		printf("file can't be opened \n\n");
	}

	printf("\n\ncontent of this file are \n\n");

	// Printing what is written in file
	// character by character using loop.
	do {
		ch = fgetc(ptr);
		printf("%c", ch);

		// Checking if character is not EOF.
		// If it is EOF stop eading.
	} while (ch != EOF);



  
	// Opening file in reading mode

  ptr2 = fopen("Wife.txt", "r");

	if (NULL == ptr2) {
		printf("\nfile can't be opened \n\n");
	}

	printf("\n\ncontent of this file are \n\n");

	// Printing what is written in file
	// character by character using loop.
	do {
		ch2 = fgetc(ptr2);
		printf("%c", ch2);

		// Checking if character is not EOF.
		// If it is EOF stop eading.
	} while (ch2 != EOF);

	// Closing the file
	fclose(ptr2);
  fclose(ptr);
	return 0;
}



// Driver code
int main(int argc, char *argv[])
{
	readFiles();

	//    account *theirAccount;

	printf( "\t\nOpening Balance : 0\n" );


    // Major step 1
    // Print the opening account balance
    //   in the format specified
    printf( "\t\n<Account Balance as specified>\n" );


    // Major step 2
    // Read and process transactions in separate threads
    // ...


    // Major step 4
    // Print the closing account balance 
    //   in the format specified
    printf( "\t\n<Account Balance as specified..>\n" );


    return 0;
}


///Aded from Ian



//Adde
