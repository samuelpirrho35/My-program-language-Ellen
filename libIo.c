#include "includelib/libIo.h"
#include "includelib/libString.h"
#include "includelib/convertObjectsTypes.h"
#include "includelib/List.h"
#include "includedefines/defines.h"
#include "includedefines/referenceTypes.h"
#include "includedefines/allocs.h"
#include "includeclass/objectsStruct.h"
#include <stdlib.h>
#include <stdio.h>

#define ERRORGETi8 -1

#ifdef WINDOWS
#include <windows.h>

unsigned char WindowsWrt(String StringObject, String end){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    String str = strmerger(StringObject, end);

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

u8 wrtlchar(lchar i64Char){
    String strLchar = STRALLOC(2);
    strLchar[0] = i64Char;
    strLchar[1] = L'\0';
#ifdef WINDOWS
    if(WindowsWrt(strLchar, L"")){
        return 1;
    }
#endif
    return 0;
}

i8 wrt(List **objects){
    if(printList(objects, MODE_PRINT_FUNC, 0, (*objects)->GN_Fields.extention) == -1)
        return -1;

    return 0;
}

lchar geti8(){
#ifdef WINDOWS
    lchar buffer[2];
    u32 numberOfCharsRead;

    HANDLE hConsole = GetStdHandle(STD_INPUT_HANDLE);
    if(hConsole == INVALID_HANDLE_VALUE){
        return ERRORGETi8;
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
        return ERRORGETi8;
    }
#endif
}

String rd(String msg){
#ifdef WINDOWS
    WindowsWrt(msg, L"");

    lchar i64Char[2];
    i64 size = 100, index = 0;
    String str = STRALLOC((size + 1));

    while(1){
        i64Char[0] = geti8();
        i64Char[1] = '\0';
        if(i64Char[0] == L'\n' || i64Char[0] == L'\r'){
            str[index] = '\0';
            break;
        }

        else if((i32)i64Char[0] == 8){
            if(index > 0){
                index--;
                WindowsWrt(L"\b \b", L"");
            }
        }

        else{
            WindowsWrt(i64Char, L"");
            str[index] = i64Char[0];
            index++;
            if(index == size - 2){
                size += size >> 1;
                String newstr = (String)realloc(str, size * sizeof(lchar));
                if(newstr == NULL)
                    return NULL;
                
                str = newstr;
            }
        }
    }

    WindowsWrt(L"\n", L"");

    return str;
#endif
}
