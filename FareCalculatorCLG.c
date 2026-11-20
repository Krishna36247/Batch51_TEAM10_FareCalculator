#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_STOPS 5
#define BASE_FARE 10.00
#define FARE_PER_KM 4.50
#define STUDENT_CONCESSION 0.50
#define MAX_NAME_LEN 64
#define MAX_ID_LEN 20

const char *STOP_NAMES[TOTAL_STOPS] = {
    "Bidholi Campus Main Gate",
    "Kandoli Campus Main Gate",
    "Premnagar",
    "Sudhowala Chowk",
    "Dunga",
};

const double STOP_DISTANCES[TOTAL_STOPS] = {
    0.0,  /* Stop 1: Bidholi Main Gate */
    2.5,  /* Stop 2: Kandholi Main Gate */
    11.8,  /* Stop 3: Premnagar */
    11.2,  /* Stop 4: Sudhowala */
    3.0   /* Stop 5: Dunga */
};

void clearInputBuffer(void);
void displayStops(void);
int getValidStopChoice(const char *prompt);
double calculateDistance(int originIdx, int destIdx);
double computeBaseFare(double distance);
int isStudentEligible(char *studentId);
void printReceipt(int originIdx, int destIdx, double distance, 
                  double baseFare, double discount, double finalFare, 
                  int isStudent, const char *studentId);

int main(void) {
    int running = 1;
    int option;

    while (running) {
        printf("\n=======================================================\n");
        printf("           CAMPUS SHUTTLE SERVICE SYSTEM               \n");
        printf("=======================================================\n");
        printf(" 1. Book Shuttle Ticket / Calculate Fare\n");
        printf(" 2. View Route Stops & Distance Chart\n");
        printf(" 3. Exit System\n");
        printf("-------------------------------------------------------\n");
        printf("Enter your choice (1-3): ");

        if (scanf("%d", &option) != 1) {
            printf("\n[ERROR] Invalid input! Please enter a numerical choice.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (option) {
            case 1: {
                int boardingIdx, destinationIdx;
                double travelDistance, baseFare, discountAmount, finalPayable;
                int isStudent = 0;
                char studentId[MAX_ID_LEN] = "N/A";
                char concessionChoice;

                printf("\n--- STEP 1 & 2: SELECT JOURNEY STOPS ---\n");
                displayStops();

                boardingIdx = getValidStopChoice("Enter Boarding Stop Number (1-5): ") - 1;

                while (1) {
                    destinationIdx = getValidStopChoice("Enter Destination Stop Number (1-5): ") - 1;
                    if (destinationIdx == boardingIdx) {
                        printf("\n[ERROR] Boarding and Destination stops cannot be identical!\n");
                        printf("Please select a different destination stop.\n\n");
                    } else {
                        break;
                    }
                }

                travelDistance = calculateDistance(boardingIdx, destinationIdx);
                baseFare = computeBaseFare(travelDistance);

                printf("\nAre you a student eligible for concession? (y/n): ");
                if (scanf(" %c", &concessionChoice) == 1) {
                    clearInputBuffer();
                    if (concessionChoice == 'y' || concessionChoice == 'Y') {
                        printf("Enter your Student Roll/ID Number (e.g., STU12345): ");
                        if (fgets(studentId, sizeof(studentId), stdin) != NULL) {

                            studentId[strcspn(studentId, "\n")] = '\0';
                        }

                        if (isStudentEligible(studentId)) {
                            isStudent = 1;
                            discountAmount = baseFare * STUDENT_CONCESSION;
                            printf("[SUCCESS] Student ID verified! 50%% concession applied.\n");
                        } else {
                            printf("[NOTICE] Student ID format not recognized. Standard fare applied.\n");
                            discountAmount = 0.0;
                            strcpy(studentId, "INVALID/NONE");
                        }
                    } else {
                        discountAmount = 0.0;
                    }
                } else {
                    clearInputBuffer();
                    discountAmount = 0.0;
                }

                finalPayable = baseFare - discountAmount;

                printReceipt(boardingIdx, destinationIdx, travelDistance,
                             baseFare, discountAmount, finalPayable,
                             isStudent, studentId);
                break;
            }

            case 2:
                displayStops();
                break;

            case 3:
                printf("\nThank you for using Campus Shuttle Service. Have a safe journey!\n");
                running = 0;
                break;

            default:
                printf("\n[ERROR] Invalid option selected! Please choose between 1 and 3.\n");
                break;
        }
    }

    return 0;
}


void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void displayStops(void) {
    int i;
    printf("\n+-----+-----------------------------------+-------------+\n");
    printf("| No. | Stop Name                         | Route Km    |\n");
    printf("+-----+-----------------------------------+-------------+\n");
    for (i = 0; i < TOTAL_STOPS; i++) {
        printf("|  %-2d | %-33s | %5.1f km    |\n", i + 1, STOP_NAMES[i], STOP_DISTANCES[i]);
    }
    printf("+-----+-----------------------------------+-------------+\n");
}

int getValidStopChoice(const char *prompt) {
    int choice;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &choice) == 1) {
            clearInputBuffer();
            if (choice >= 1 && choice <= TOTAL_STOPS) {
                return choice;
            } else {
                printf("[ERROR] Stop number must be between 1 and %d. Try again.\n", TOTAL_STOPS);
            }
        } else {
            printf("[ERROR] Numerical input expected. Try again.\n");
            clearInputBuffer();
        }
    }
}

double calculateDistance(int originIdx, int destIdx) {
    double dist = STOP_DISTANCES[destIdx] - STOP_DISTANCES[originIdx];
    if (dist < 0.0) {
        dist = -dist;
    }
    return dist;
}

double computeBaseFare(double distance) {
    return BASE_FARE + (distance * FARE_PER_KM);
}

int isStudentEligible(char *studentId) {
    if (studentId == NULL || strlen(studentId) < 4) {
        return 0;
    }
    return 1;
}
void printReceipt(int originIdx, int destIdx, double distance, 
                  double baseFare, double discount, double finalFare, 
                  int isStudent, const char *studentId) {
    printf("\n");
    printf("===============================================================\n");
    printf("                    CAMPUS SHUTTLE TICKET                      \n");
    printf("===============================================================\n");
    printf(" Boarding Stop   : %s (Stop %d)\n", STOP_NAMES[originIdx], originIdx + 1);
    printf(" Destination     : %s (Stop %d)\n", STOP_NAMES[destIdx], destIdx + 1);
    printf(" Total Distance  : %.2f km\n", distance);
    printf(" Passenger Type  : %s\n", isStudent ? "Student (Concession Active)" : "Regular Passenger");
    if (isStudent) {
        printf(" Student Roll ID : %s\n", studentId);
    }
    printf("---------------------------------------------------------------\n");
    printf(" Base Boarding Charge : Rs. %6.2f\n", BASE_FARE);
    printf(" Distance Cost        : Rs. %6.2f (@ Rs. %.2f/km)\n", distance * FARE_PER_KM, FARE_PER_KM);
    printf(" Subtotal Fare        : Rs. %6.2f\n", baseFare);
    printf(" Student Concession   : -Rs. %5.2f (%d%% off)\n", discount, (int)(STUDENT_CONCESSION * 100));
    printf("---------------------------------------------------------------\n");
    printf(" TOTAL FARE PAYABLE   : Rs. %6.2f\n", finalFare);
    printf("===============================================================\n");
    printf("        Please show this ticket to the shuttle driver.         \n");
    printf("===============================================================\n\n");
}
