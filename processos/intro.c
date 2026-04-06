#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main () {

    // pid_t é um alias para int, definido em <sys/types.h>.
    // Usar pid_t em vez de int é uma convenção semântica: deixa claro que
    // a variável vai guardar um PID (Process ID), o identificador numérico
    // que o SO usa para gerenciar processos.
    // Os nomes "pai" e "filho" aqui são apenas nomes de variáveis —
    // a ordem de declaração e os nomes não definem nenhuma relação parental.
    pid_t pai, filho;

    int variavel = 5;

    // fork() é uma syscall que pede ao kernel para duplicar o processo atual.
    // A partir dessa linha, existem DOIS processos rodando o mesmo código:
    // o processo pai (que já existia) e o processo filho (recém-criado).
    // Quem chamou o fork() é o pai. Quem foi criado pelo kernel é o filho.
    // Essa relação é definida pelo SO — as variáveis não têm nada a ver com isso.
    //
    // fork() retorna valores diferentes em cada processo:
    //   - No processo pai:  filho = PID do filho criado (ex: 430)
    //   - No processo filho: filho = 0
    //
    // É esse valor de retorno que permite saber em qual processo o código está rodando.
    filho = fork();

    if (filho == 0) {
        // Estamos no processo filho (fork() retornou 0 aqui).
        // Cada processo tem sua própria cópia da memória (independente do pai),
        // então alterações em "variavel" aqui não afetam o pai.
        pai = getppid(); // pega o PID do processo pai
        filho = getpid(); // pega o próprio PID
        variavel *= 2; // apenas a cópia do filho é alterada (pai continua com 5)
        printf("eu sou o processo filho %d, meu pai é %d\nvariavel %d\n",
        filho, pai, variavel);
    } else {
        // Estamos no processo pai (fork() retornou o PID do filho).
        // "filho" aqui contém o PID do processo filho criado.
        pai = getpid(); // pega o próprio PID
        printf("eu sou o processo pai %d, meu filho é %d\nvariavel %d\n",
            pai, filho, variavel);
    }

    // Obs: a ordem de impressão do pai e do filho não é garantida —
    // depende do escalonador do SO decidir qual processo roda primeiro.

    return 0;
}
