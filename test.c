#include <stdio.h>
#include <stdlib.h>

#define STARTBYTE_0X0E 0x0E
#define STARTBYTE_0X0F 0x0F
#define ENDBYTE 0x0A

#define LEFT 1
#define RIGHT 0

typedef struct Biginteger Biginteger;

typedef struct Biginteger{
    unsigned char val;
    Biginteger *next;
    Biginteger *previous;
}Biginteger;

Biginteger* newBigint(){
    Biginteger *Bigint = (Biginteger*)malloc(sizeof(Biginteger));
    return Bigint;
}

Biginteger* setBigi32eger(unsigned char data[]){
    Biginteger *Lefti8 = newBigint();
    Biginteger *Righti8 = newBigint();
    Lefti8->previous = Righti8;
    Righti8->next = Lefti8;

    Lefti8->val = data[0];
    Righti8->val = data[0];

    Biginteger *aux1 = Lefti8;
    Biginteger *aux2;

    int j = 1;
    while(data[j] != ENDBYTE){
        aux1->next = newBigint();
        aux2 = aux1;
        aux1 = aux1->next;
        aux1->previous = aux2;
        aux1->val = data[j++];
    }

    aux1->next = Righti8;
    Righti8->previous = aux1;

    return Lefti8;
}

void printBiginteger(Biginteger *_Bigint, char direction){
    printf("\ninit\n\n");
    Biginteger *Bigint = (direction) ? _Bigint->next : _Bigint->previous->previous;
    while(Bigint->val != STARTBYTE_0X0E && Bigint->val != STARTBYTE_0X0F){
        printf("i8: %d\n", Bigint->val);
        Bigint = (direction) ? Bigint->next : Bigint->previous;
    }
    printf("\nend...\n");
}

void freeBiginteger(Biginteger *Bigint){
    Biginteger *_Bigint = Bigint->next;
    Biginteger *__Bigint;
    free(Bigint);
    while(_Bigint != Bigint){
        __Bigint = _Bigint->next;
        free(_Bigint);
        _Bigint = __Bigint;
    }
}

Biginteger* sumOuroboros(Biginteger *ouroboros1, Biginteger *ouroboros2){
    Biginteger *ouroboros_left = newBigint();
    Biginteger *ouroboros_right = newBigint();
    Biginteger *aux, *aux2;
    
    ouroboros_left->previous = ouroboros_right;
    ouroboros_right->next = ouroboros_left;
    
    ouroboros_left->val = STARTBYTE_0X0E;
    ouroboros_right->val = STARTBYTE_0X0E;
    
    unsigned char val1, val2, upone = 0, sum = 0;
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
        aux->previous = newBigint();
        aux->previous->val = sum % 10;
        aux2 = aux;
        aux = aux->previous;
        aux->next = aux2;
        
        if((ouroboros1->val == STARTBYTE_0X0E || ouroboros1->val == STARTBYTE_0X0F) &&
           (ouroboros2->val == STARTBYTE_0X0E || ouroboros2->val == STARTBYTE_0X0F))
            break;
    }

    if(upone){
        aux->previous = newBigint();
        aux->previous->next = aux;
        aux = aux->previous;
        aux->val = upone;
    }

    aux->previous = ouroboros_left;
    ouroboros_left->next = aux;
    
    return ouroboros_left;
}

Biginteger* subtractOuroboros(Biginteger *ouroboros1, Biginteger *ouroboros2){
    Biginteger *ouroboros_left = newBigint();
    Biginteger *ouroboros_right = newBigint();
    Biginteger *aux, *aux2, *ouro1, *ouro2;
    
    ouroboros_left->previous = ouroboros_right;
    ouroboros_right->next = ouroboros_left;
    
    unsigned char val1, val2, Sign = STARTBYTE_0X0E;
    aux = ouroboros_right;
    aux->next = ouroboros_right;

    ouro1 = ouroboros1;
    ouro2 = ouroboros2;

    while(1){
        if(!(ouro1->val == STARTBYTE_0X0E || ouro1->val == STARTBYTE_0X0F)){
            val1 = ouro1->val;
            ouro1 = ouro1->previous;
        }

        else
            val1 = 0;

        if(!(ouro2->val == STARTBYTE_0X0E || ouro2->val == STARTBYTE_0X0F)){
            val2 = ouro2->val;
            ouro2 = ouro2->previous;
        }

        else
            val2 = 0;

        printf("val1 -> %d\n", val1);
        printf("val2 -> %d\n", val2);

        if(val1 > val2)
            Sign = STARTBYTE_0X0E; 
        
        else if(val1 < val2)
            Sign = STARTBYTE_0X0F;

        if((ouro1->val == STARTBYTE_0X0E || ouro1->val == STARTBYTE_0X0F) &&
           (ouro2->val == STARTBYTE_0X0E || ouro2->val == STARTBYTE_0X0F))
            break;
    }

    if(Sign == STARTBYTE_0X0E){
        ouro1 = ouroboros1;
        ouro2 = ouroboros2;
    }
    else{
        ouro1 = ouroboros2;
        ouro2 = ouroboros1;
    }

    ouroboros_left->val = Sign;
    ouroboros_right->val = Sign;

    while(1){
        if(ouro1->val == STARTBYTE_0X0E || ouro1->val == STARTBYTE_0X0F)
            val1 = 0;

        else{
            val1 = ouro1->val;
            ouro1 = ouro1->previous;
        }

        if(ouro2->val == STARTBYTE_0X0E || ouro2->val == STARTBYTE_0X0F)
            val2 = 0;

        else{
            val2 = ouro2->val;
            ouro2 = ouro2->previous;
        }

        if(val1 < val2){
            val1 += 10;
            ouro1->val -= 1;
        }

        aux->previous = newBigint();
        aux->previous->val = val1 - val2;
        aux2 = aux;
        aux = aux->previous;
        aux->next = aux2;
        
        if((ouro1->val == STARTBYTE_0X0E || ouro1->val == STARTBYTE_0X0F) &&
           (ouro2->val == STARTBYTE_0X0E || ouro2->val == STARTBYTE_0X0F))
            break;
    }

    aux->previous = ouroboros_left;
    ouroboros_left->next = aux;
    
    return ouroboros_left;
}

int main(){
    Biginteger *Ouroboros0 = setBigi32eger((unsigned char[]){STARTBYTE_0X0E, 3, 5, 0, 8, ENDBYTE});
    Biginteger *Ouroboros1 = setBigi32eger((unsigned char[]){STARTBYTE_0X0E, 7, 4, 4, 4, ENDBYTE});
    Biginteger *Ouroboros2 = setBigi32eger((unsigned char[]){STARTBYTE_0X0E, 2, 5, 0, 4, 2, 0, 0, 6, ENDBYTE});
    Biginteger *Ouroboros3 = setBigi32eger((unsigned char[]){STARTBYTE_0X0E, 9, 9, 9, ENDBYTE});
    Biginteger *Ouroboros4 = setBigi32eger((unsigned char[]){STARTBYTE_0X0E, 1, ENDBYTE});

    Biginteger *MEGA = subtractOuroboros(Ouroboros1->previous->previous, Ouroboros0->previous->previous);
    printf("-------<=>-------\n");
    printBiginteger(MEGA, LEFT);
    printf("-------<=>-------\n");
    printBiginteger(MEGA, RIGHT);
    printf("-------<=>-------\n");
    printf("liberando not(MEGA)\n");
    freeBiginteger(Ouroboros0);
    freeBiginteger(Ouroboros1);
    freeBiginteger(Ouroboros2);
    freeBiginteger(Ouroboros3);
    freeBiginteger(Ouroboros4);
    printf("not(MEGA) liberado\n");
    printf("liberando MEGA\n");
    //freeBiginteger(MEGA);
    printf("MEGA liberado\n");
}