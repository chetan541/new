
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 20

// Function to perform FCFS disk scheduling
void FCFS(int cylinders[], int n, int head) {
    int total_movement = 0;

    printf("Sequence of service:\n");
    printf("%d ", head);

    // Calculate total movement
    for (int i = 0; i < n; i++) {
        total_movement += abs(head - cylinders[i]);
        printf("%d ", cylinders[i]);
        head = cylinders[i];
    }

    printf("\nTotal movement: %d\n", total_movement);
}

// Function to perform SSTF disk scheduling
void SSTF(int cylinders[], int n, int head) {
    int total_movement = 0;
    int visited[MAX_PROCESSES] = {0};

    printf("Sequence of service:\n");

    // Iterate through all cylinders
    for (int i = 0; i < n; i++) {
        int min_distance = 999999; // Set a large initial value
        int next_cylinder;
        int next_cylinder_index=-1;

        // Find the closest cylinder
        for (int j = 0; j < n; j++) {
            if (!visited[j] && abs(head - cylinders[j]) < min_distance) {
                
                min_distance = abs(head - cylinders[j]);
                next_cylinder = cylinders[j];
                next_cylinder_index=j;
            }
        } 

        total_movement += min_distance;
        printf("%d ", next_cylinder);
        head = next_cylinder;
        visited[next_cylinder_index] = 1;
    }

    printf("\nTotal movement: %d\n", total_movement);
}


// Function to perform SCAN disk scheduling
void SCAN(int cylinders[], int n, int head, int direction) {
    int total_movement = 0;
    int visited[MAX_PROCESSES] = {0};

    printf("Sequence of service:\n");

    // Sort cylinders
      for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (cylinders[j] > cylinders[j + 1]) {
                int temp = cylinders[j];
                cylinders[j] = cylinders[j + 1];
                cylinders[j + 1] = temp;
            }
        }
    }

    int start_index = -1;
    
    if (direction == 0) {

        for (int i = 0; i < n; i++) {
        if (cylinders[i] > head) {
            start_index = i;
            break;
        }
    }
    if(start_index==-1){
        start_index=n;
    }
    

        for (int i = start_index-1; i >= 0; i--) {
            printf("%d ", cylinders[i]);
            total_movement += abs(head - cylinders[i]);
            head = cylinders[i];
            visited[i] = 1;
        }

        if (cylinders[0] != 0) {
        printf("0 ");
        total_movement += head;
        head = 0;
    }


        for (int i = start_index ; i < n; i++) {
            if (!visited[i]) {
                printf("%d ", cylinders[i]);
                total_movement += abs(head - cylinders[i]);
                head = cylinders[i];
                visited[i] = 1;
            }
        }
    } else {

        for (int i = 0; i < n; i++) {
        if (cylinders[i] >= head) {
            start_index = i;
            break;
        }
    }
    if(start_index==-1){
        start_index=n;
    }
    
        for (int i = start_index; i < n; i++) {
            printf("%d ", cylinders[i]);
            total_movement += abs(head - cylinders[i]);
            head = cylinders[i];
            visited[i] = 1;
        }

        printf("%d ", 199);
            total_movement += abs(head - 199);
            head = 199;
            
        
        for (int i = start_index - 1; i >= 0; i--) {
            if (!visited[i]) {
                printf("%d ", cylinders[i]);
                total_movement += abs(head - cylinders[i]);
                head = cylinders[i];
                visited[i] = 1;
            }
        }
    }

    printf("\nTotal movement: %d\n", total_movement);
}

// Function to perform C-SCAN disk scheduling
void CSCAN(int cylinders[], int n, int head) {
    int total_movement = 0;

    printf("Sequence of service:\n");

    // Sort cylinders
      for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (cylinders[j] > cylinders[j + 1]) {
                int temp = cylinders[j];
                cylinders[j] = cylinders[j + 1];
                cylinders[j + 1] = temp;
            }
        }
    }

    int start_index = -1;
    for (int i = 0; i < n; i++) {
        if (cylinders[i] >= head) {
            start_index = i;
            break;
        }
    }
    if(start_index==-1){
        start_index=n;
    }
    

    for (int i = start_index; i < n; i++) {
        printf("%d ", cylinders[i]);
        total_movement += abs(head - cylinders[i]);
        head = cylinders[i];
    }

    printf("%d ", 199);
            total_movement += abs(head - 199);
            head = 199;

    if (cylinders[0] != 0) {
        printf("0 ");
        total_movement += head;
        head = 0;
    }

    for (int i = 0; i < start_index; i++) {
        printf("%d ", cylinders[i]);
        total_movement += abs(cylinders[i]-head);
        head = cylinders[i];
    }
    

    printf("\nTotal movement: %d\n", total_movement);
}

// Function to perform LOOK disk scheduling
void LOOK(int cylinders[], int n, int head, int direction) {
    int total_movement = 0;
    int visited[MAX_PROCESSES] = {0};

    printf("Sequence of service:\n");

    // Sort cylinders
      for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (cylinders[j] > cylinders[j + 1]) {
                int temp = cylinders[j];
                cylinders[j] = cylinders[j + 1];
                cylinders[j + 1] = temp;
            }
        }
    }

    int start_index = -1;
    
    if (direction == 0) {

        for (int i = 0; i < n; i++) {
        if (cylinders[i] > head) {
            start_index = i;
            break;
        }
    }
    if(start_index==-1){
        start_index=n;
    }
    

        for (int i = start_index-1; i >= 0; i--) {
            printf("%d ", cylinders[i]);
            total_movement += abs(head - cylinders[i]);
            head = cylinders[i];
            visited[i] = 1;
        }
        for (int i = start_index ; i < n; i++) {
            if (!visited[i]) {
                printf("%d ", cylinders[i]);
                total_movement += abs(head - cylinders[i]);
                head = cylinders[i];
                visited[i] = 1;
            }
        }
    } else {

        for (int i = 0; i < n; i++) {
        if (cylinders[i] >= head) {
            start_index = i;
            break;
        }
    }
    if(start_index==-1){
        start_index=n;
    }
    
        for (int i = start_index; i < n; i++) {
            printf("%d ", cylinders[i]);
            total_movement += abs(head - cylinders[i]);
            head = cylinders[i];
            visited[i] = 1;
        }
        for (int i = start_index - 1; i >= 0; i--) {
            if (!visited[i]) {
                printf("%d ", cylinders[i]);
                total_movement += abs(head - cylinders[i]);
                head = cylinders[i];
                visited[i] = 1;
            }
        }
    }

    printf("\nTotal movement: %d\n", total_movement);
}

// Function to perform C-LOOK disk scheduling
void CLOOK(int cylinders[], int n, int head) {
    int total_movement = 0;

    printf("Sequence of service:\n");

    // Sort cylinders
      for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (cylinders[j] > cylinders[j + 1]) {
                int temp = cylinders[j];
                cylinders[j] = cylinders[j + 1];
                cylinders[j + 1] = temp;
            }
        }
    }

    int start_index = -1;
    for (int i = 0; i < n; i++) {
        if (cylinders[i] >= head) {
            start_index = i;
            break;
        }
    }
    if(start_index==-1){
        start_index=n;
    }
    

    for (int i = start_index; i < n; i++) {
        printf("%d ", cylinders[i]);
        total_movement += abs(head - cylinders[i]);
        head = cylinders[i];
    }

    

    for (int i = 0; i < start_index; i++) {
        printf("%d ", cylinders[i]);
        total_movement += abs(cylinders[i]-head);
        head = cylinders[i];
    }
    

    printf("\nTotal movement: %d\n", total_movement);
}



int main() {
    int cylinders[MAX_PROCESSES];
    int n, head, choice;

    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    printf("TRACK SIZE:200\n");
    printf("Enter the cylinder requests:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &cylinders[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Select the scheduling algorithm:\n");
    printf("1. FCFS\n");
    printf("2. SSTF\n");
    printf("3. SCAN\n");
    printf("4. C-SCAN\n");
    printf("5. LOOK\n");
    printf("6. C-LOOK\n");
    while(1){
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Selected algorithm: FCFS\n");
            FCFS(cylinders, n, head);
            break;
        case 2:
            printf("Selected algorithm: SSTF\n");
            SSTF(cylinders, n, head);
            break;
        case 3:
            printf("Selected algorithm: SCAN\n");
            printf("Enter the direction (0 for left, 1 for right): ");
            scanf("%d", &choice);
            SCAN(cylinders, n, head, choice);
            break;
        case 4:
            printf("Selected algorithm: C-SCAN\n");
            
            CSCAN(cylinders, n, head);
            break;
        case 5:
            printf("Selected algorithm: LOOK\n");
            printf("Enter the direction (0 for left, 1 for right): ");
            scanf("%d", &choice);
            LOOK(cylinders, n, head, choice);
            break;
        case 6:
            printf("Selected algorithm: C-LOOK\n");
            
            CLOOK(cylinders, n, head);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }
    if(choice>6){
        break;
    }
    }

    return 0;
}