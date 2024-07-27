**Overview**

BankingHub is a comprehensive banking management system designed to handle various banking operations such as account management, transactions, and password handling. The system is implemented using C++ and features a Binary Search Tree (BST) for account storage and a hash table for password management.

**Features**

Account Management: Create, edit, and delete bank accounts.

Transactions: Transfer funds between accounts, deposit and withdraw money.

Transaction History: View transaction history for specific accounts.

Password Management: Add, edit, and delete account passwords using a hash table.

Data Persistence: Save and load account and transaction data from text files.


**Components**

BST_Node: Represents a node in the Binary Search Tree, containing account information.

BST_Tree: Manages operations on the BST, including adding, deleting, updating accounts, and handling transactions.

Hashtable: Implements a hash table for efficient password management.

Node: Defines the structure for nodes in the hash table.

Node_1: Extends Node to include account and password details.

**Usage**

Create an Account: Use the add_account function to create a new bank account.

Perform Transactions: Use transfer, withdraw, and deposit functions to manage funds.

View Transaction History: Use the transaction_history function to see past transactions.

Manage Passwords: Add or modify passwords using the hash table functions.


**Files**

server.txt: Stores account details and balances.

transaction.txt: Keeps a record of all transactions.

hashtable.txt: Contains account passwords managed by the hash table.

**Setup**

Compile: Use a C++ compiler to compile the source files.

Run: Execute the compiled program to interact with the banking system.
