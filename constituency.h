#ifndef constituency
#define constituency

struct Constituency {
    char *name;
    unsigned int *neighbours;
    unsigned int numNeighbours;
};
/**
 * @param obj, pointer is constant
 * @param name, pointer can point to any other char value but cannot change the value of the obj 
 * @param neighbours, neighbours are constant
 * @param numNeighbours, cannot be changed through specific reference to point in memory
*/
void constructConstituency(struct Constituency * const obj,
                            char const *name,
                            unsigned int* const neighbours,
                            unsigned int const numNeighbours);
void printConstituency(struct Constituency * const obj);
void destructConstituency(struct Constituency * const obj);
struct Constituency *copyConstituencies(struct Constituency constituencyArr[], const unsigned int numOfConstituencies);
#endif