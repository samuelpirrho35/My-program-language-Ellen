#include <windows.h>
#include <stdio.h>

DWORD WINAPI funcao_thread(LPVOID lpParam) {
    // Código da função executada pela thread
    printf("Thread executando...\n");
    return 0;
}

int main() {
    HANDLE thread_handle;
    DWORD thread_id;

    // Criação da thread
    thread_handle = CreateThread(NULL, 0, funcao_thread, NULL, 0, &thread_id);

    if (thread_handle == NULL) {
        printf("Erro ao criar a thread.\n");
        return 1;
    }

    // Aguarda a thread terminar
    WaitForSingleObject(thread_handle, INFINITE);

    // Fecha o handle da thread
    CloseHandle(thread_handle);

    return 0;
}
