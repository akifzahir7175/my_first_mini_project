#include <stdio.h>

// Global seat arrangement: Movie, Time slot, Row, Col
char arr[4][3][5][10];

// Function Prototypes
void show_interface(int a, int b);
int select_movie();
int select_time();
void initialize();
void display_seats(int p, int q);
void buy_ticket(int p, int q);
void cancel_seat(int p, int q);
void ticket_summary(int p, int q);
void welcome();
void menu();
void movie_name(int a);
void show_time(int a);

// Main Function
int main() {
    int movie, time;
    initialize();

    while (1) {
        welcome();
        movie = select_movie(); 

        if (movie >= 1 && movie <= 4) {
            while (1) {
                welcome();
                movie_name(movie);
                time = select_time();

                if (time == 0) {
                    break;
                }
                else if (time >= 1 && time <= 3) {
                    show_interface(movie, time);
                }
                else {
                    printf("Invalid choice.\n");
                }
            }
        }
        else if (movie == 0) {
            printf("Exiting the program.\n");
            break;
        }
        else {
            printf("Invalid choice.\n");
        }    
    }
    return 0;
}

// Initialize Seats
void initialize() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 5; k++) {
                for (int l = 0; l < 10; l++) {
                    arr[i][j][k][l] = 'O';
                }
            }
        }
    }
}

// Welcome Banner
void welcome() {
    printf("____________Welcome to Daffodil Cineplex_____________\n");
    printf("                        -----Bringing stories of life\n\n\n");
}

// Movie Selection
int select_movie() {
    int m;
    printf("Now Showing: \n\n");
    printf("1. Aynabaji\n");
    printf("2. Utsob\n");
    printf("3. Borbaad\n");
    printf("4. Tandob\n\n");
    printf("0. Exit the Program \n\n");
    printf("Please Select a movie: ");
    scanf("%d", &m);
    return m;
}

// Movie Names
void movie_name(int a) {
    if (a == 1) {
        printf("Aynabaji >\n");
    }
    else if (a == 2) {
        printf("Utsob >\n");
    }
    else if (a == 3) {
        printf("Borbaad >\n");
    }
    else if (a == 4) {
        printf("Tandob >\n");
    }
}

// Time Slot Selection
int select_time() {
    int t;
    printf("Time slots: \n\n");
    printf("1. 10:00 am -- 01:00 pm\n");
    printf("2. 02:00 pm -- 05:00 pm\n");
    printf("3. 06:00 pm -- 09:00 pm\n\n");
    printf("0. Back to movie selection. \n\n");
    printf("Please Select a time slot: ");
    scanf("%d", &t);
    return t;
}

// Show Time
void show_time(int a) {
    if (a == 1) {
        printf(" 10:00 am -- 01:00 pm >\n");
    }
    else if (a == 2) {
        printf(" 02:00 pm -- 05:00 pm >\n");
    }
    else if (a == 3) {
        printf(" 06:00 pm -- 09:00 pm >\n");
    }
}

// Show Interface
void show_interface(int a, int b) {
    int input;
    while (1) {
        movie_name(a);
        show_time(b);

        menu();
        scanf("%d", &input);

        if (input == 1) {
            display_seats(a, b);
        }
        else if (input == 2) {
            buy_ticket(a, b);
        }  
        else if (input == 3) {
            cancel_seat(a, b);
        }
        else if (input == 4) {
            ticket_summary(a, b);
        }
        else if (input == 0) {
            printf("Back to time slot menu.\n");
            break;
        }
        else {
            printf("Invalid choice.\n");
        }
    }
}

// Menu Interface
void menu() {
    printf("\n1. Display Seats\n");
    printf("2. Buy Seats\n");
    printf("3. Cancel Seat\n");
    printf("4. Seats Summary\n");
    printf("0. Go To Movie Time slot\n");
    printf("Enter your Choice: ");
}

// Display Seat Layout
void display_seats(int p, int q) {
    printf("\nSeat Layout (O = Available, X = Booked):\n");
    printf("\n_______________________________________\n\n\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            printf(" %c ", arr[p-1][q-1][i][j]);
        }
        printf("\n");    
    } 
}

// Buy Ticket
void buy_ticket(int p, int q) {
    int x, y;
    printf("Please enter Row number (1-5): ");
    scanf("%d", &x);
    printf("Please enter Col number (1-10): ");
    scanf("%d", &y);

    if (x < 1 || x > 5 || y < 1 || y > 10) {
        printf("Invalid seat selection.\n\n\n");
        return;
    }

    if (arr[p-1][q-1][x-1][y-1] == 'X') {
        printf("Seat already taken.\n\n\n");
    } else {
        arr[p-1][q-1][x-1][y-1] = 'X';
        printf("Purchase Successful!\n\n\n");
    }
}

// Cancel Ticket
void cancel_seat(int p, int q) {
    int x, y;
    printf("Please enter Row number (1-5): ");
    scanf("%d", &x);
    printf("Please enter Col number (1-10): ");
    scanf("%d", &y);

    if (x < 1 || x > 5 || y < 1 || y > 10) {
        printf("Invalid seat selection.\n\n\n");
        return;
    }

    if (arr[p-1][q-1][x-1][y-1] == 'O') {
        printf("Seat not taken yet.\n\n\n");
    } else {
        arr[p-1][q-1][x-1][y-1] = 'O';
        printf("Ticket cancelled successfully!\n\n\n");
    }
}

// Ticket Summary
void ticket_summary(int p, int q) {
    int count = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr[p-1][q-1][i][j] == 'X') {
                count++;
            }
        }
    }
    printf("\nSeat Available: %d\n\n", 50 - count);
    printf("Ticket Sold: %d\n\n", count);
}
