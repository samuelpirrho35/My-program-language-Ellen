#include <stdio.h>

#define keyqdrtlen   12
#define fnqdrtlen    5

#define keyfirst_quadrant   _U16
#define keysecond_quadrant  LIST
#define keythird_quadrant   PUBLIC
#define keyfourth_quadrant  ATTRIBUTE

#define fnfirst_quadrant    COPY
#define fnsecond_quadrant   LENGTH
#define fnthird_quadrant    REVERSE
#define fnfourth_quadrant   READFILELINE



#define keyqdrt1     {0,           keyqdrtlen           }
#define keyqdrt2     {keyqdrtlen,  keyqdrtlen    * 2    }
#define keyqdrt3     {keyqdrtlen * 2, keyqdrtlen * 3    }
#define keyqdrt4     {keyqdrtlen * 3, keyqdrtlen * 4 - 2}

#define fnqdrt1      {0,             fnqdrtlen    }
#define fnqdrt2      {fnqdrtlen,     fnqdrtlen * 2}
#define fnqdrt3      {fnqdrtlen * 2, fnqdrtlen * 3}
#define fnqdrt4      {fnqdrtlen * 3, fnqdrtlen * 4}

#define allqdrt      (char[][2]){                                           \
                                    keyqdrt1, keyqdrt2, keyqdrt3, keyqdrt4,  \
                                    fnqdrt1,  fnqdrt2,  fnqdrt3,  fnqdrt4     \
                                }


int main(){
    printf("{%d, %d}\n", allqdrt[0][0], allqdrt[0][1]);
}