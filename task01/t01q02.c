#include <stdio.h>
#include <string.h>

#define MAX_FLOORS 10

void num_map(int floorNumber, char Floors[MAX_FLOORS][10]){
    if (floorNumber < 0 || floorNumber > MAX_FLOORS){
        printf("You requested to go to the Number is out of range.\n");
    }else
        printf("You requested to go to the %s floor\n", Floors[floorNumber]);
}

void elevator(int currentFloor, int nextFloor){
    if (currentFloor < nextFloor){
        // printf("Elevator is going up\n");
        while (currentFloor < nextFloor){
            currentFloor++;
            printf("Passing Floor %d\n", currentFloor);
        }
    }
    else if (currentFloor > nextFloor){
        // printf("Elevator is going down\n");
        while (currentFloor > nextFloor){
            currentFloor--;
            printf("Passing Floor %d\n", currentFloor);
        }
    }
    printf("Arrived at Floor %d\n", currentFloor);
}

int main(int argc, char *argv[]){
    int currentFloor = 0;
    float nextFloor;
    char Floors[MAX_FLOORS][10] = {"Zeroth", "First", "Second", "Third", "Fourth", "Fifth", "Sixth", "Seventh", "Eighth", "Ninth"};
    printf("Elevator is currently at floor: %d\n", currentFloor);
    while (1){
        printf("Enter the floor number you wish to go to (-1 to exit): \n");
        // int result = scanf("%d", &nextFloor);
        int result = scanf("%f", &nextFloor);
        num_map(nextFloor, Floors);
        if (nextFloor == -1){
            break;
        }
        ////////////// check what to return on input s.a A,B,C... ^,%,$,#.. 2.5, 1.9... //////////////
        if (result == 0) {
            printf("\nInvalid floor number.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }  // Clear input buffer
            continue;
        
        } else if (nextFloor < 0 || nextFloor > MAX_FLOORS || nextFloor - (int)nextFloor != 0) { // Check if 0>input or input>10 or is not an integer
            printf("\nInvalid floor number.\n");
            continue;}
        ////////////////////////////////////////////////////////////////////////////////////////////
        nextFloor = (int)nextFloor;
        elevator(currentFloor, nextFloor);
        currentFloor = nextFloor;
    }

    printf("Elevator simulation ended.\n");
    
    return 0;
}
