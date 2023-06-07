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

    struct Constituency * copy = copyConstituencies(constituencies,
    numConstituencies);
    int i;
    for(i = 0; i < numConstituencies; i++) {
        destructConstituency(&constituencies[i]);
    }

   
    int max = 0;
    int min = 0;
    int *neighbourValues = (int*) malloc(numConstituencies * sizeof(int));
    for (i=0; i < numConstituencies; i++) {
        printConstituency(&copy[i]);
        neighbourNum[i] = copy[i].numNeighbours;
        if (neighbourNum[i] > copy[max].numNeighbours){
            max = i;
        } else if (neighbourNum[i] < copy[min].numNeighbours){
            min = i;
        }else {
            max = max;
            min = min;
        }
        
    }
    printf("%s has the most bordering constituencies:\n ", copy[max].name);
    int k;
    for (k=0; k < copy[max].numNeighbours; k++) {
        int val = 0;
        val = copy[max].neighbours[k];
        printf("%s \n", copy[val].name);
    }

    printf("%s has the fewest bordering constituencies:\n ", copy[min].name);
    int j;
    for (j=0; j < copy[min].numNeighbours; j++) {
        int val = 0;
        val = copy[min].neighbours[j];
        printf("%s \n", copy[val].name);
    }

    int l;
    for (l=0; l < numConstituencies; l++) {
        destructConstituency(&copy[l]);
    } 
}