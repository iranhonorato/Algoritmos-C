# Processos e Sistema Operacional

## O que é um Sistema Operacional (SO)?

Um Sistema Operacional é o software responsável por gerenciar o hardware do computador e fornecer uma interface para que outros programas possam usá-lo.

Sem o SO, cada programa teria que saber exatamente como conversar com a memória RAM, o disco, a placa de rede, etc. O SO resolve isso fazendo essa ponte.

```
+-----------------------------+
|        Seus programas       |  ← você escreve código aqui
+-----------------------------+
|     Sistema Operacional     |  ← gerencia tudo
+-----------------------------+
|           Hardware          |  ← CPU, memória, disco...
+-----------------------------+
```

---

## As camadas do SO

### 1. Hardware
A camada mais baixa. É o físico: processador, memória RAM, disco, placa de rede.
O hardware não entende C, Python ou qualquer linguagem — só executa instruções binárias.

---

### 2. Kernel
O núcleo do SO. É o software que tem acesso direto ao hardware e gerencia todos os recursos da máquina.

O kernel é responsável por:
- **Gerenciar processos** — criar, pausar, encerrar e alternar entre processos
- **Gerenciar memória** — decidir quanta memória cada processo recebe
- **Gerenciar arquivos** — ler e escrever no disco
- **Gerenciar dispositivos** — teclado, mouse, placa de rede, etc.

Quando seu programa chama `fork()`, ele não cria o processo — ele **pede ao kernel** que crie. O kernel é quem de fato faz o trabalho.

Essa "pedida" se chama **syscall (system call)**: uma chamada que seu programa faz ao kernel solicitando algum serviço.

```
seu programa
    |
    |  syscall (ex: fork, read, write)
    v
  kernel
    |
    v
 hardware
```

---

### 3. Shell
O terminal que você usa (bash, zsh, etc.). É um programa comum que fica entre você e o kernel, interpretando seus comandos e transformando-os em chamadas ao SO.

Quando você digita `./intro_executavel`, o shell pede ao kernel para criar um processo e executar aquele programa.

---

### 4. Programas de usuário
Tudo que roda "por cima" do kernel: seu navegador, editor de texto, e os programas que você escreve em C.

Esses programas não têm acesso direto ao hardware — tudo que precisam fazer passa pelo kernel via syscalls.

---

## Por que isso importa para processos?

Quando você chama `fork()` no seu código C:

1. Seu programa faz uma **syscall** ao kernel
2. O kernel duplica o processo atual, criando um filho
3. O kernel atribui um **PID** (Process ID) ao novo processo
4. O kernel retorna o PID do filho para o pai, e 0 para o filho
5. Os dois processos passam a rodar de forma independente

O kernel é também quem decide a ordem em que os processos rodam — isso se chama **escalonamento**. É por isso que a ordem de impressão entre pai e filho não é garantida.

---

## Resumo visual

```
Você escreve C
      |
      | compila com gcc
      v
  Executável
      |
      | roda no terminal (shell)
      v
 Processo criado pelo kernel
      |
      | fork() → syscall
      v
 Kernel cria processo filho
      |
      v
 Dois processos rodando independentemente
```
