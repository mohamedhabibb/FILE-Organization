Library Management System (C++ File Organization)

A console-based library management system written in C++ that demonstrates file organization concepts. All data is stored in plain text files using delimited, variable-length records, and every record can be added, searched, displayed, updated, and deleted.

Features

The program is split into three sections, each supporting full CRUD operations:

Section	Class	Data file	Search key
Books	Book_sections	Book.txt	Book name
Employees	Employee	management.txt	Phone number
Customers	customer	customer.txt	Phone number

Operations available in every section:

Add a new record
Search for a record
Display all records
Update an existing record
Delete a record
File Organization Design

Each record is stored on its own line. Fields inside a record are separated by the | character, and records are separated by a newline (\n).

Book record (Book.txt)

name|Author|size|type

Employee record (management.txt) and Customer record (customer.txt)

name|phone|age|mail|address|job

Example

Clean Code|R. Martin|464 pages|Programming
How update and delete work

Since the data lives in a sequential text file, update and delete use a temporary file:

Read the original file record by record.
Write every record to temp.txt, replacing the matched record (update) or skipping it (delete).
Copy temp.txt back into the original file.
Remove temp.txt.
Requirements
A C++ compiler (g++, clang++, or MSVC)
No external libraries are needed (only the C++ standard library: iostream, fstream, string, string.h)
Build and Run

Using g++ (Linux / macOS / Windows with MinGW):

bash
g++ main.cpp -o library
./library          # on Windows: library.exe

Using Visual Studio / Code::Blocks / Dev-C++: create a new console project, add main.cpp, then build and run.

The data files (Book.txt, management.txt, customer.txt) are created automatically in the working directory the first time you add a record.

Usage

When the program starts, choose a section:

The library Management system
-----------------------------
Enter  1 to go to Books
Enter  2 to go to Management
Enter  3 to go to Customers

Then pick an operation from the section menu:

add_Book: 1
search_Book : 2
display all : 3
update_Book : 4
delete_Book : 5
write your choose :

After each operation, type yes to continue using the section, or anything else to exit.

Project Structure
.
├── main.cpp        # Source code (all classes and main menu)
└── README.md

Generated at runtime:

Book.txt            # Books data
management.txt      # Employees data
customer.txt        # Customers data
Concepts Demonstrated
Sequential file access with fstream (ios::in, ios::out, ios::app)
Delimited fields and variable-length records
Record search, update, and delete using a temporary file
Object-oriented design with one class per entity
Menu-driven console interface
