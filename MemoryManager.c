#include <stdio.h>
#include <string.h>
#include "includeclass/objectsStruct.h"

#define VIRTUAL_MEMORY 1024 //bytes
#define V_MEMORY_FREE   128 //bytes
#define USING             0
#define NOT_USING         1
#define IS_NULL         (-1)
#define ADDR_NOT_FOUND  (-2)

typedef char memory_ty;

typedef struct{
    void *address;
    u32 size;
    u32 index;
    char state;
}MemoryRegister;

memory_ty MEMORY[VIRTUAL_MEMORY];
memory_ty *nextaddress = MEMORY;
MemoryRegister memoryRegister[VIRTUAL_MEMORY];
u32 nRegisters = 0;

u32 FREE_ADDRESS[V_MEMORY_FREE];
u8 nRegistersFree = 0;

void* memoryAlloc(u32 size){
    void *ptr = NULL;

    if(nRegistersFree){
        u32 i = 0;
        for(; i < nRegistersFree; i++){
            u32 memfree_size = memoryRegister[FREE_ADDRESS[i]].size;
            if(memfree_size >= size){
                memoryRegister[FREE_ADDRESS[i]].state = USING;

                if(memfree_size == size){
                    nRegistersFree--;
                    FREE_ADDRESS[i] = 0;
                    return memoryRegister[FREE_ADDRESS[i]].address;
                }

                ptr = memoryRegister[FREE_ADDRESS[i]].address;
                memoryRegister[FREE_ADDRESS[i]].size = size;

                memoryRegister[nRegisters].address = memoryRegister[FREE_ADDRESS[i]].address += memfree_size - size;
                memoryRegister[nRegisters].size = memfree_size - size;
                memoryRegister[nRegisters].index = nRegisters;
                memoryRegister[nRegisters].state = NOT_USING;
                FREE_ADDRESS[i] = nRegisters;
                nRegisters++;

                return ptr;
            }
        }
    }

    if(nextaddress + size < MEMORY + VIRTUAL_MEMORY){
        ptr = (void*)nextaddress;
        memoryRegister[nRegisters].address = ptr;
        memoryRegister[nRegisters].size = size;
        memoryRegister[nRegisters].index = nRegisters;
        memoryRegister[nRegisters].state = USING;
        nextaddress += size;
        nRegisters++;
        return ptr;
    }

    return ptr;
}

char freeMemory(void *ptr){
    u32 i = 0;
    for(; i < nRegisters; i++){
        if(memoryRegister[i].address == ptr){
            if(memoryRegister[i].state != USING)
                return IS_NULL;

            memoryRegister[i].state = NOT_USING;
            FREE_ADDRESS[nRegistersFree++] = memoryRegister[i].index;

            return 0;
        }
    }

    return ADDR_NOT_FOUND;
}

List* newList(u32 size){
    List *list = memoryAlloc(size * sizeof(List));
    list->GN_Fields.extention = 0;
    list->GN_Fields.capacity = size;
    list->GN_Fields.lengthstr = 3;
    list->GN_Fields.modify_flag = 0;
    list->GN_Fields.dataStructurestr = NULL;
    return list;
}

int main(){
    List *list = newList(1), *listt = newList(1);
    list[0].ref_ty = __i64__;
    list[0].types.primitiveTys.intTys.i64_ty = 1000000000;
    
    listt[0].ref_ty = __i8__;
    listt[0].types.primitiveTys.intTys.i8_ty = 27;

    printf("list[0].types.primitiveTys.intTys.i64_ty: %lld\n", list[0].types.primitiveTys.intTys.i64_ty);
    printf("listt[0].types.primitiveTys.intTys.i8_ty: %d\n", listt[0].types.primitiveTys.intTys.i8_ty);

    return 0;
}