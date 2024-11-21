#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* programa para calcular la probabilidad
 * de ganar el coche en el problema de Monty Hall
 */

int main(int argc, char *argv[]) {
    /* inicializar el generador de números aleatorios */
    srand(time(NULL));

    /* n: numero de intentos
        * win: numero de veces que se gana sin cambiar
        * choice: elección inicial
        * car: puerta con el coche
        * open: puerta abierta por el presentador
        * change: elección final
        * change_win: numero de veces que se gana cambiando
        * p_win: probabilidad de ganar sin cambiar
        * p_switch_win: probabilidad de ganar cambiando
        */
    int i, n, win, choice, car, open, change, change_win;
    double p_win, p_switch_win;

    /* comprobar el número de argumentos */
    if (argc != 2) {
        printf("Usage: %s <number of trials>\n", argv[0]);
        return 1;
    }

    /* convertir el argumento a un entero
     * e inicializar las variables
     */
    n = atoi(argv[1]);
    win = 0;
    change_win = 0;

    /* bucle para realizar los n intentos */
    for (i = 0; i < n; i++) {
        /* el coche y la elección se eligen aleatoriamente */
        car = rand() % 3 + 1;
        choice = rand() % 3 + 1;
        open = rand() % 3 + 1;

        /* el presentador abre una puerta que no tiene el coche
         * ni ha sido elegida por el jugador
         */
        while (open == car || open == choice) {
            open = rand() % 3 + 1;
        }
        /* el jugador cambia de puerta */
        change = 6 - choice - open;
        //printf("Car: %d, Choice: %d, Open: %d, Change: %d\n", car, choice, open, change);

        /* comprobar si el jugador gana sin cambiar */
        if (choice == car) {
            win++;
        }

        /* comprobar si el jugador gana cambiando */
        if (change == car) {
            change_win++;
        }
    }

    /* calcular las probabilidades */
    p_win = (double) win/n;
    p_switch_win = (double) change_win/n;

    /* imprimir los resultados */
    printf("Probability to win the car without switching: %.2f %% \n", p_win*100);
    printf("Probability to win the car by switching: %.2f %% \n", p_switch_win*100);

    return 0;

}
