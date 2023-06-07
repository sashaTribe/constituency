#include <stdio.h>
#include <stdlib.h>
#include "constituency.h"
int main(int argc, char *argv []) {
    const int numConstituencies = 5;
    struct Constituency constituencies[numConstituencies];
    int neighbourNum[numConstituencies]; 
    constructConstituency(
    &constituencies[0], "Swansea East",
    (unsigned int[]){1, 2, 3, 4}, 4);

    constructConstituency(
    &constituencies[1], "Swansea West",
    (unsigned int[]){0, 2}, 2);

    constructConstituency(
    &constituencies[2], "Gower",
    (unsigned int[]){0, 1, 3}, 3);

    constructConstituency(
    &constituencies[3], "Neath",
    (unsigned int[]){0, 2, 4}, 3);

    constructConstituency(
    &constituencies[4], "Aberavon",
    (unsigned int[]){0 , 3}, 2);

    int i;
    int max = 0;
    int min = 0;
    // int *neighbourValues = (int*) malloc(numConstituencies * sizeof(int));

    for (i=0; i < numConstituencies; i++) {
        printConstituency(&constituencies[i]);

        neighbourNum[i] = constituencies[i].numNeighbours;
        if (neighbourNum[i] > constituencies[max].numNeighbours){
            max = i;
        } else if (neighbourNum[i] < constituencies[min].numNeighbours){
            min = i;
        }
    }
    printf("%s has the most bordering constituencies:\n ", constituencies[max].name);
    int k;
    for (k=0; k < constituencies[max].numNeighbours; k++) {
        int val = 0;
        val = constituencies[max].neighbours[k];
        printf("%s \n", constituencies[val].name);
    }

    printf("%s has the fewest bordering constituencies:\n ", constituencies[min].name);
    int j;
    for (j=0; j < constituencies[min].numNeighbours; j++) {
        int val = 0;
        val = constituencies[min].neighbours[j];
        printf("%s \n", constituencies[val].name);
    }

   /*  int j;
    int max = neighbourValues[0];
    printf("%d", max);
    for (j=0; j<numConstituencies; j++) {
        if(neighbourValues[j] > max){
            max = neighbourValues[j];
        }
    }
    
    //const constituency maxNeighbour = ;
     */
    int l;
    for (l=0; l < numConstituencies; l++) {
        destructConstituency(&constituencies[l]);
    } 
}