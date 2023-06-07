#include "constituency.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void constructConstituency(struct Constituency * const obj,
                                char const *name,
                                unsigned int* const neighbours,
                                unsigned int const numNeighbours){

    obj->name = (char*) malloc(strlen(name)*sizeof(char*));
    obj->neighbours = (int*) malloc(numNeighbours*sizeof(int));
    obj->numNeighbours = numNeighbours;
    memcpy(obj->name, name, strlen(name) * sizeof(char));
    memcpy(obj->neighbours,neighbours, numNeighbours * sizeof(unsigned int));
    
}

void printConstituency(struct Constituency * const obj){
    
    printf("%s | %d neighbours | [ ", obj->name,obj->numNeighbours);
    int i;
    int neighbourCount;
    for (i=0; i<obj->numNeighbours;i++) {
        printf("%d ", obj->neighbours[i]);

    } 
    printf("]\n");
}

void destructConstituency(struct Constituency * const obj){
    if(obj->name != NULL) {
        free(obj->name);
        obj->name = NULL;

        free(obj->neighbours);
        obj->neighbours = NULL;
    }

    obj->numNeighbours = 0;
}

struct Constituency *copyConstituencies(struct Constituency constituencyArr[], const unsigned int numOfConstituencies) {
    struct Constituency *newConstituencyArr = (struct Constituency *) malloc(numOfConstituencies * sizeof(struct Constituency));

    for (int i = 0; i < numOfConstituencies; i++){
        constructConstituency(&newConstituencyArr[i], constituencyArr->name, constituencyArr->neighbours, constituencyArr->numNeighbours);
    }

    return newConstituencyArr;
}
// struct Constituency *copyConstituencies(struct Constituency constituencyArr[], const unsigned int numOfConstituencies){
//     struct Constituency *newConstituencyArr = malloc(numOfConstituencies * sizeof(struct Constituency));
//     if (newConstituencyArr == NULL){
//         return NULL;
//     }
//     int i;
//     char other_name;
//     int other_numNeighbours;
//     int other_neighbours[other_numNeighbours];
//     for(i=0; i<numOfConstituencies; i++){
//         if (constituencyArr[i].name == NULL){
//             return NULL;
//         }else {
//             other_name = (char*)malloc(sizeof(strlen(constituencyArr[i]).name)));
//             memcpy(newConstituencyArr[i].name, constituencyArr[i].name, strlen(constituencyArr[i].name)*sizeof(int));
//             memcpy(newConstituencyArr[i].neighbours, constituencyArr[i].neighbours, constituencyArr[i].numNeighbours * sizeof(int));
//             memcpy(newConstituencyArr[i].numNeighbours, constituencyArr[i].numNeighbours,numOfConstituencies*sizeof(int));
//         }
        
//     }
//     return newConstituencyArr;



// }