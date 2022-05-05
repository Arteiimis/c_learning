#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKET_SIZE 5

typedef struct Node {
    int elem;
    struct Node *list_next;
}Node;

typedef struct BucketManager {
    int nums;
    Node** buckets;
}BucketManager;

typedef struct BucketSpaceManger{
    int index;
    Node* node_space;
}BucketSpaceManager;

BucketSpaceManager* init_bucket_space(int size){
    BucketSpaceManager* space_mgr = (BucketSpaceManager*)malloc(sizeof(BucketSpaceManager));
    if(!space_mgr){
        printf("malloc failed\n");
        goto exit_1;
    }
    space_mgr->index = 0;
    space_mgr->node_space = (Node*)malloc(sizeof(Node)*size);
    if(!space_mgr->node_space){
        printf("malloc failed\n");
        goto exit_2;
    }
    return space_mgr;
    exit_1:
        free(space_mgr);
    exit_2:
        return NULL;
}

BucketManager* init_buckets(int bucket_nums){
    BucketManager* bucket_mgr = (BucketManager*)malloc(sizeof(BucketManager));
    if (!bucket_mgr){
        printf("out of memory,File:%s, Func:%s, Line:%d\n", __FILE__, __func__, __LINE__);
        goto exit_1;
    }
    bucket_mgr->nums = bucket_nums;
    bucket_mgr->buckets = (Node**)calloc(bucket_mgr->nums, sizeof(Node*));
    if (!bucket_mgr->buckets){
        printf("out of memory,File:%s, Func:%s, Line:%d\n", __FILE__, __func__, __LINE__);
        goto exit_2;
    }
    return bucket_mgr;
exit_2:
    free(bucket_mgr);
exit_1:
    return NULL;
}

// Node* get_bucket_space(BucketSpaceManager* space_mgr){
//     if (space_mgr){
//         return &space_mgr->nodes_space[space_mgr->index++];
//     }
//     else{
//         return NULL;
//     }
// }

void release_bucket_space(BucketSpaceManager* space_mgr) {
    if(space_mgr) {
        if(space_mgr -> node_space) {
            free(space_mgr -> node_space);
        }
        free(space_mgr);
    }
}

void release_buckets(BucketManager* bucket_mgr) {
    if(bucket_mgr) {
        if(bucket_mgr -> buckets) {
            free(bucket_mgr -> buckets);
        }
        free(bucket_mgr);
    }
}