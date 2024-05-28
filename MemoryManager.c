// #include <stdio.h>
// #include <string.h>
// #include "includeclass/objectsStruct.h"

// #define VIRTUAL_MEMORY 1024 //bytes
// #define V_MEMORY_FREE   128 //bytes
// #define USING             0
// #define NOT_USING         1
// #define IS_NULL         (-1)
// #define ADDR_NOT_FOUND  (-2)

// typedef unsigned char VIRTUALMEMORYy;

// typedef struct{
//     void *address;
//     u32  size;
//     u32  index;
//     u8   state;
// }MemoryRegister;

// VIRTUALMEMORYy MEMORY[VIRTUAL_MEMORY];
// VIRTUALMEMORYy *nextaddress = MEMORY;
// MemoryRegister memoryRegister[VIRTUAL_MEMORY];
// u32 nRegisters = 0;

// u32 FREE_ADDRESS[V_MEMORY_FREE];
// u8 nRegistersFree = 0;

// void* memoryAlloc(u32 size){
//     void *ptr = NULL;

//     if(nRegistersFree){
//         u32 i = 0;
//         for(; i < nRegistersFree; i++){
//             u32 memfree_size = memoryRegister[FREE_ADDRESS[i]].size;
//             if(memfree_size >= size){
//                 memoryRegister[FREE_ADDRESS[i]].state = USING;

//                 if(memfree_size == size){
//                     nRegistersFree--;
//                     FREE_ADDRESS[i] = 0;
//                     return memoryRegister[FREE_ADDRESS[i]].address;
//                 }

//                 ptr = memoryRegister[FREE_ADDRESS[i]].address;
//                 memoryRegister[FREE_ADDRESS[i]].size = size;

//                 memoryRegister[nRegisters].address = memoryRegister[FREE_ADDRESS[i]].address += memfree_size - size;
//                 memoryRegister[nRegisters].size = memfree_size - size;
//                 memoryRegister[nRegisters].index = nRegisters;
//                 memoryRegister[nRegisters].state = NOT_USING;
//                 FREE_ADDRESS[i] = nRegisters;
//                 nRegisters++;

//                 return ptr;
//             }
//         }
//     }

//     if(nextaddress + size < MEMORY + VIRTUAL_MEMORY){
//         ptr = (void*)nextaddress;
//         memoryRegister[nRegisters].address = ptr;
//         memoryRegister[nRegisters].size = size;
//         memoryRegister[nRegisters].index = nRegisters;
//         memoryRegister[nRegisters].state = USING;
//         nextaddress += size;
//         nRegisters++;
//         return ptr;
//     }

//     return ptr;
// }

// char freeMemory(void *ptr){
//     u32 i = 0;
//     for(; i < nRegisters; i++){
//         if(memoryRegister[i].address == ptr){
//             if(memoryRegister[i].state != USING)
//                 return IS_NULL;

//             memoryRegister[i].state = NOT_USING;
//             FREE_ADDRESS[nRegistersFree++] = memoryRegister[i].index;

//             return 0;
//         }
//     }

//     return ADDR_NOT_FOUND;
// }

// List* newList(u32 size){
//     List *list = memoryAlloc(size * sizeof(List));
//     list->GN_Fields.extention = 0;
//     list->GN_Fields.capacity = size;
//     list->GN_Fields.lengthstr = 3;
//     list->GN_Fields.modify_flag = 0;
//     list->GN_Fields.dataStructurestr = NULL;
//     return list;
// }

// int main(){
//     List *list = newList(1), *listt = newList(1);
//     list[0].ref_ty = __i64__;
//     list[0].types.primitiveTys.intTys.i64_ty = 1000000000;
    
//     listt[0].ref_ty = __i8__;
//     listt[0].types.primitiveTys.intTys.i8_ty = 27;

//     printf("list[0].types.primitiveTys.intTys.i64_ty: %lld\n", list[0].types.primitiveTys.intTys.i64_ty);
//     printf("listt[0].types.primitiveTys.intTys.i8_ty: %d\n", listt[0].types.primitiveTys.intTys.i8_ty);

//     return 0;
// }

#include "includedefines/allocs.h"
#include "includedefines/defines.h"
#include "includedefines/referenceTypes.h"
#include <stdio.h>
#include <string.h>

#define getmemory(ptr, size, nptr, nsize) ((ptr) + (size) < (nptr) + (nsize))

#define USING    1
#define NOTUSING 0

typedef unsigned char VIRTUALMEMORY;
typedef unsigned int u64;

typedef struct MemoryRegister{
    u64 mem_allctd;
    char   state;
    void   *ptr;
}MemoryRegister;

VIRTUALMEMORY *MEMORY = NULL;
VIRTUALMEMORY *memptr_n = NULL;
u64 mem_allocated = 0;
u32 memcnt = 0;

MemoryRegister *memRegister = NULL;

void initializeVirtualMemory(u64 totalmemallc){
    MEMORY = (VIRTUALMEMORY*)malloc(sizeof(VIRTUALMEMORY) * totalmemallc);
    memRegister = (MemoryRegister*)malloc(sizeof(MemoryRegister) * totalmemallc);
    memptr_n = MEMORY;
    mem_allocated = totalmemallc;
}

void destroyVirtualMemory(){
    free(MEMORY);
    free(memRegister);
}

void create(void *ptr){
    memRegister[memcnt].ptr = ptr;
    memRegister[memcnt].mem_allctd = 0;
    memRegister[memcnt].state = NOTUSING;
}

void* e_alloc(u64 size){
    void *ptr = NULL;

    if(getmemory(memptr_n, size, MEMORY, mem_allocated)){
        ptr = (void*)memptr_n;
        memptr_n += size;
        // memRegister[memcnt].ptr = ptr;
        // memRegister[memcnt].mem_allctd = size;
        // memRegister[memcnt++].state = USING;
        // create(memptr_n);
    }

    return ptr;
}

void e_free(void *ptr){
    
}

int main(){
    initializeVirtualMemory(1024);

    int *arr = (int*)e_alloc(10 * sizeof(int));
    char *string = (char*)e_alloc(30);

    for(int i = 0; i < 10; i++)
        arr[i] = 35 + i;

    for(int i = 0; i < 10; i++)
        printf("%d\n", arr[i]);

    strcpy(string, "Sherlock Holmes");
    printf("%s\n", string);

    int *a = (int*)e_alloc(sizeof(int));
    *a = 35;
    printf("%d\n", *a);

    char *c = (char*)e_alloc(1);
    *c = 'E';
    printf("%c\n\nAddress\n\n", *c);

    printf("%d\n%d\n%d\n%d", arr, string, a, c);

    destroyVirtualMemory();
}

// {..., ..., ..., ..., ..., ..., ..., ..., ..., ...} # structure with 10 positions

// ptr1: 0 -> 2
// ptr2: 3 -> 4
// ptr3: 5 -> 7
// ptr4: 8 -> 9

//  |----ptr1----| |-ptr2-|  |----ptr3----| |-ptr4-| 
// {..., ..., ..., ..., ..., ..., ..., ..., ..., ...}

// {..., ...}