#include <stdio.h>
#include <string.h>

// Create a structure called myStructure
struct myStructure {
  int myNum;
  char myLetter;
  char myString[30];
};


// Para acessar a estrutura, você precisa criar uma variável para ela.
// Utilize a struct palavra-chave dentro do main() método, seguida pelo nome da estrutura e, em seguida, pelo nome da variável da estrutura:
void test() {

  // Create a structure variable of myStructure called s1
  struct myStructure s1;

  // Para acessar os membros de uma estrutura, use a sintaxe de ponto (.):
  s1.myNum = 7;
  s1.myLetter = 'B';

  // infelizmente, você não pode atribuir um valor a uma matriz dessa forma:
  // s1.myString = "Some text"; 

  // Forma correta
  strcpy(s1.myString, "Some text");
  

  // Print values
  printf("My number: %d\n", s1.myNum);
  printf("My letter: %c\n", s1.myLetter);
  printf("My string: %s\n", s1.myString);
  printf("\n");



  // Como fazer tudo isso de uma forma mais clean 
  struct myStructure s2 = {25, 'i', "hello world"};
  printf("My number: %d\n", s2.myNum);
  printf("My letter: %c\n", s2.myLetter);
  printf("My string: %s\n", s2.myString);
  printf("\n");

  return;
}


// Exemplo da vida real
struct Car {
  char brand[30];
  char model[30];
  int year;
};

int main() {
  struct Car car1 = {"BMW", "X5", 1999};
  struct Car car2 = {"Ford", "Mustang", 1969};
  struct Car car3 = {"Toyota", "Corolla", 2011};


  printf("%s %s %d\n", car1.brand, car1.model, car1.year);
  printf("%s %s %d\n", car2.brand, car2.model, car2.year);
  printf("%s %s %d\n", car3.brand, car3.model, car3.year);

  return 0;
}