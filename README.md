# Batch51_TEAM10_FareCalculator

**Mini Hackathon | Problem Statement: Campus Shuttle Fare Calculator**

**Team Details**
- **Team Number:** 10
- **Batch:** 51
- **Team Members:** Krishna Sharma(590036247), Nirali Gupta(590043182), Kanishka(590043036)

---

## Objectives

1. To develop a menu-driven Campus Shuttle Fare Calculator using C programming.
2. To calculate travel distance and fare based on selected boarding and destination stops.
3. To provide a 50% fare concession to eligible students.
4. To implement input validation and reduce invalid user entries.
5. To generate a formatted ticket receipt displaying journey and fare details.

## Features

1. **Menu-Driven Interface:** Options to book tickets, view stops, and exit.
2. **Stop Selection:** Allows users to select boarding and destination stops from five predefined locations.
3. **Distance Calculation:** Calculates distance between selected stops, irrespective of travel direction.
4. **Fare Calculation:** Includes a fixed base fare and distance-based charges.
5. **Student Concession:** Provides a 50% discount for student IDs meeting the minimum length requirement.
6. **Input Validation:** Handles invalid inputs and prevents selecting the same stop twice.
7. **Ticket Generation:** Displays a detailed receipt with distance, fare, discount, and final payable amount.

## C Programming Concepts Used

1. **Header Files:** `stdio.h`, `stdlib.h`, `string.h` and `ctype.h` for standard library functions.
2. **Preprocessor Directives:** `#define` for declaring constants and macros.
3. **Variables and Data Types:** Use of `int`, `double` and `char`.
4. **Arrays:** Used to store predefined stop names and distances.
5. **Pointers:** Use of character pointers (`const char *`) for handling strings.
6. **Functions:** Modular programming using user-defined functions.
7. **Function Prototypes:** Declaring functions before the `main()` function.
8. **Conditional Statements:** `if-else` and `switch-case` for decision-making.
9. **Loops:** `while` and `for` loops for repetition and input validation.
10. **String Handling:** Functions like `strlen()`, `strcpy()` and `strcspn()`.
11. **Input/Output Operations:** `printf()`, `scanf()` and `fgets()`.
12. **Operators:** Arithmetic, relational, logical and assignment operators.
13. **Break and Continue:** Used to control loop and switch execution.
14. **Ternary Operator:** Used to select passenger type in the ticket receipt.
15. **Type Casting:** Explicit conversion using `(int)` to display the discount percentage.

## Steps to Compile and Run

**1. Save the Source Code**

Save the program as `campus_shuttle.c`.

**2. Open Terminal**

Navigate to the directory containing the source file.

**3. Compile the Program**

```bash
gcc campus_shuttle.c -o campus_shuttle
```

**4. Execute the Program**

```bash
./campus_shuttle
```

## Program Usage

- Enter `1` to book a shuttle ticket and calculate the fare.
- Enter `2` to view the route stops and distance chart.
- Enter `3` to exit the application.
- Follow the on-screen instructions to enter journey details and student concession information.
THANK YOU 
IF YOU FIND OUR PROJECT HELPFUL GIVE US A STAR
