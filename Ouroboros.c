#include "System/System.h"
#include "includeclass/objectsStruct.h"
#include "includedefines/defines.h"
#include "includedefines/referenceTypes.h"
#include "includedefines/allocs.h"
#include "includelib/libIo.h"
#include "includelib/libString.h"
#include "includelib/convertObjectsTypes.h"
#include "includelib/compressBytes.h"
#include "includeEnumerator/typeObjects.h"
#include <stdio.h>


//-------------<Functions for Ouroboros Object>-----------------

Ouroboros* newOuroboros(){
    Ouroboros *ouroboros = (Ouroboros*)malloc(sizeof(Ouroboros));
    return ouroboros;
}


Ouroboros* initOuroboros(u8 data[]){
    Ouroboros *Lefti8 = newOuroboros();
    Ouroboros *Righti8 = newOuroboros();
    Lefti8->previous = Righti8;
    Righti8->next = Lefti8;

    Lefti8->val = data[0];
    Righti8->val = data[0];

    Ouroboros *aux1 = Lefti8;
    Ouroboros *aux2;

    u16 j = 1;
    while(data[j] != ENDBYTE){
        aux1->next = newOuroboros();
        aux2 = aux1;
        aux1 = aux1->next;
        aux1->previous = aux2;
        aux1->val = data[j++];
    }

    aux1->next = Righti8;
    Righti8->previous = aux1;

    return Lefti8;
}


void freeOuroboros(Ouroboros *ouroboros){
    Ouroboros *_ouroboros = ouroboros->next;
    Ouroboros *__ouroboros;
    free(ouroboros);
    while(_ouroboros != ouroboros){
        __ouroboros = _ouroboros->next;
        free(__ouroboros);
        _ouroboros = __ouroboros;
    }
}


Ouroboros* sumOuroboros(Ouroboros *ouroboros1, Ouroboros *ouroboros2){
    Ouroboros *ouroboros_left = newOuroboros();
    Ouroboros *ouroboros_right = newOuroboros();
    Ouroboros *aux, *aux2;
    
    ouroboros_left->previous = ouroboros_right;
    ouroboros_right->next = ouroboros_left;
    
    ouroboros_left->val = STARTBYTE_0X0E;
    ouroboros_right->val = STARTBYTE_0X0E;
    
    u8 val1, val2, upone = 0, sum = 0;
    aux = ouroboros_right;
    aux->next = ouroboros_right;

    while(1){
        if(ouroboros1->val == STARTBYTE_0X0E || ouroboros1->val == STARTBYTE_0X0F)
            val1 = 0;

        else{
            val1 = ouroboros1->val;
            ouroboros1 = ouroboros1->previous;
        }

        if(ouroboros2->val == STARTBYTE_0X0E || ouroboros2->val == STARTBYTE_0X0F)
            val2 = 0;

        else{
            val2 = ouroboros2->val;
            ouroboros2 = ouroboros2->previous;
        }


        sum = val1 + val2 + upone;
        upone = (sum > 9) ? 1 : 0;
        aux->previous = newOuroboros();
        aux->previous->val = sum % 10;
        aux2 = aux;
        aux = aux->previous;
        aux->next = aux2;
        
        if((ouroboros1->val == STARTBYTE_0X0E || ouroboros1->val == STARTBYTE_0X0F) &&
           (ouroboros2->val == STARTBYTE_0X0E || ouroboros2->val == STARTBYTE_0X0F))
            break;
    }

    if(upone){
        aux->previous = newOuroboros();
        aux->previous->next = aux;
        aux = aux->previous;
        aux->val = upone;
    }

    aux->previous = ouroboros_left;
    ouroboros_left->next = aux;
    
    return ouroboros_left;
}
