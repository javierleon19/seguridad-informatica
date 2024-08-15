# seguridad-informatica
proyectos de seguridad informatica
Tarea 1, Crear Keylogger para sistema linux
Profesor este es un proyecto creado para la terminal de mi Mac M1 se que era para Linux pero e intentado instalar alguna maquina virtual que funcione bien y no he tenido éxito con ello, solo lo logre una vez con UTM pero mi equipo va muy muy lento, estoy en negociación con la compra de un nuevo equipo sencillo pero que me sea útil para instalarle Linux, aun asi quería intentar el programa y lo realice en un nano en c para mi terminal, funcionó :)


-- ¿Cómo funciona?
el programa desactiva el modo canónico y el eco de la terminal(es una configuración de la terminal en la que la entrada de txt o caracteres se procesa línea por línea o sea que hasta que se presiona enter envia la entrada al programa y eco es la función que hace que lo que escribes en la terminal se muestre en la pantalla) esto permite que las teclas se capturen una por una sin necesidad de presionar enter y sin que se muestren en la pantalla.

cada vez que se presiona una tecla el programa la guarda en el archivo keylog.txt Si se presiona la tecla “Esc” el programa se cierra al terminar el programa restaura la configuración original del terminal para que vuelva a funcionar normalmente.

-- pasos a seguir para ejecutar el programa 
* se guarda el arcvhivo keylogger.c
* se abre la terminal
* se compila el programa con gcc -o keylogger keylogger.c
* se ejecuta con ./keylogger
* puede comenzar a escribir y en la terminal no se vera reflejada ninguna tecla presionada si no hasta revisar en el finder un archivo nuevo llamado "leylog.txt"
* se presiona esc al terminar la prueba 
* al abril el archivo se vera el contenido escrito 
