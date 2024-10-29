#ifndef DOOR_STRUCT_H
#define DOOR_STRUCT_H
#define DOORS_COUNT 15
#define MAX_ID_SEED 100000
struct door {
    int id, status;
};
void initialize_doors(struct door* doors);
void sort_doors(struct door* doors);
void closing_doors(struct door* doors);
void print_doors(struct door* doors);
#endif
