#include "includelib/libIo.h"
#include "includelib/libString.h"
#include "includelib/convertObjectsTypes.h"
#include "includelib/objectsFunctions.h"
#include "includedefines/defines.h"
#include "includedefines/inttypes.h"
#include "includedefines/allocs.h"
#include "includeclass/objectsStruct.h"
#include <stdlib.h>
#include <stdio.h>

#define ERRORGETByte -1

#ifdef WINDOWS
#include <windows.h>

unsigned char WindowsWrt(lchar *StringObject, lchar *end){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    lchar *str = strmerger(StringObject, end);

    if(hConsole == INVALID_HANDLE_VALUE){
        return 1;
    }

    DWORD charsWritten;
    if(!WriteConsoleW(hConsole, str, strsize(str), &charsWritten, NULL)){
        return 2;
    }

    free(str);
    return 0;
}
#endif

u8 wrtlchar(lchar LongChar){
    String strLchar = STRALLOC(2);
    strLchar[0] = LongChar;
    strLchar[1] = L'\0';
#ifdef WINDOWS
    if(WindowsWrt(strLchar, L"")){
        return 1;
    }
#endif
    return 0;
}

Byte wrt(List **objects){
    Byte result = printList(objects, MODE_PRINT_FUNC, 0, (*objects)->GN_Fields.extention);
    freeList((*objects));

    if(result == -1){
        return -1;
    }

    return 0;
}

lchar getByte(){
#ifdef WINDOWS
    lchar buffer[2];
    Int numberOfCharsRead;

    HANDLE hConsole = GetStdHandle(STD_INPUT_HANDLE);
    if(hConsole == INVALID_HANDLE_VALUE){
        return ERRORGETByte;
    }

    SetConsoleMode(hConsole, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_INSERT_MODE | ENABLE_EXTENDED_FLAGS);

    if(ReadConsoleW(hConsole, buffer, 1, &numberOfCharsRead, NULL)){
        SetConsoleMode(hConsole, ENABLE_PROCESSED_INPUT);
        FlushConsoleInputBuffer(hConsole);
        return buffer[0];
    } 
    else{
        SetConsoleMode(hConsole, ENABLE_PROCESSED_INPUT);
        FlushConsoleInputBuffer(hConsole);
        return ERRORGETByte;
    }
#endif
}

String rd(String msg){
#ifdef WINDOWS
    WindowsWrt(msg, L"");

    lchar LongChar[2];
    Long size = 100, index = 0, counter = 0;
    String str = STRALLOC((size + 1));

    while(1){
        LongChar[0] = getByte();
        LongChar[1] = '\0';
        if(LongChar[0] == L'\n' || LongChar[0] == L'\r'){
            str[index] = '\0';
            break;
        }

        else if((Int)LongChar[0] == 8){
            if(index > 0){
                index--;
                WindowsWrt(L"\b \b", L"");
            }
        }

        else{
            WindowsWrt(LongChar, L"");
            str[index] = LongChar[0];
            index++;
            if(index == size - 2){
                size += size / 2;
                str = (String)realloc(str, size * sizeof(lchar));
            }
        }
    }

    return str;
#endif
}

/*int main(){
    lchar c = L'é';
    printf("size: %d", (int)c);
}*/