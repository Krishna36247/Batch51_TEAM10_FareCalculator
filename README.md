# Batch51_TEAM10_FareCalculator
Mini Hackathon || Problem Statement : Campus Shuttle Fare Calculator
Team Number: 10 || Batch : 51 || Members : Krishna Sharma , Nirali Gupta , Kanishka
Objectives: a) To develop a menu driven Campus Shuttle Fare Calculator using C-Programming.
            b) To calculate travel distance and fare based on selected boarding and destination stops.
            c) To provide a 50% fare concession to eligible students.
            d) To implement input validation and reduce invalid user entries.
            e) To generate a formatted ticket receipt displaying journey and fare details.
Features:   a) Menu-Driven Interface: Options to book tickets, view stops, and exit.
            b) Stop Selection: Allows users to select boarding and destination stops from five predefined locations.
            c) Distance Calculation: Calculates distance between selected stops, irrespective of travel direction.
            d) Fare Calculation: Includes a fixed base fare and distance-based charges.
            e) Student Concession: Provides a 50% discount for student IDs meeting the minimum length requirement.
            f) Input Validation: Handles invalid inputs and prevents selecting the same stop twice.
            g) Ticket Generation: Displays a detailed receipt with distance, fare, discount, and final payable amount.
C Programming Concepts Used in the Program: 
            a) Header Files: stdio.h, stdlib.h, string.h and ctype.h for standard library functions.
            b) Preprocessor Directives: #define for declaring constants and macros.
            c) Variables and Data Types: Use of int, double and char.
            d) Arrays: Used to store predefined stop names and distances.
            e) Pointers: Use of character pointers (const char *) for handling strings.
            f) Functions: Modular programming using user-defined functions.
            g) Function Prototypes: Declaring functions before the main() function.
            h) Conditional Statements: if-else and switch-case for decision-making.
            i) Loops: while and for loops for repetition and input validation.
            j) String Handling: Functions like strlen(), strcpy() and strcspn().
            k) Input/Output Operations: printf(), scanf() and fgets().
            l) Operators: Arithmetic, relational, logical and assignment operators.
            m) Break and Continue: Used to control loop and switch execution.
            n) Ternary Operator: Used to select passenger type in the ticket receipt.
            o) Type Casting: Explicit conversion using (int) to display the discount percentage.
Steps to Compile and Run
1. Save the Source Code: Save the program as campus_shuttle.c.
2. Open Terminal: Navigate to the directory containing the source file.
3. Compile the Program:
   gcc campus_shuttle.c -o campus_shuttle
4. Execute the Program:
  ./campus_shuttle
Program Usage
- Enter 1 to book a shuttle ticket and calculate the fare.
- Enter 2 to view the route stops and distance chart.
- Enter 3 to exit the application.
- Follow the on-screen instructions to enter journey details and student concession information.
