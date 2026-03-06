#include <stdio.h>
#include <string.h>



int main() {  

  // Primeira forma de declarar uma struct 
  struct Aluno {
    int id;        // variáveis ou membros da struct
    int nota;
  };


  // Primeira forma de acessar os membros de uma struct 
  struct Aluno yuri;
  yuri.id = 1;  
  yuri.nota = 10;
  

  // Segunda forma de acessar os membros de uma struct 
  struct Aluno iran = {2, 10};

  printf("%s %s %d\n", yuri.id, yuri.nota);
  printf("%s %s %d\n", iran.id, iran.nota);



  printf("\n");




  // Segunda forma de declarar uma struct
  typedef struct {
    int id;        // variáveis ou membros da struct
    char disciplina[30];
  } Professor;


  
  Professor igor = {1, "Algoritmos"};
  Professor toshi = {1, "DevLife"};

  printf("%s %s %d\n", igor.id, igor.disciplina);
  printf("%s %s %d\n", toshi.id, toshi.disciplina);
  return 0;


  // Observação: 
  // Quando você se deparar com algo assim: 
  typedef struct Antonio {

  } Iran; 

  // Basicamente "Antonio" é o nome original da struct e "Iran" é um Alias (apelido)
  // Você pode declarar a struct como: struct Antonio pessoa 
  // Ou você pode declarar dessa forma: Iran pessoa 



}