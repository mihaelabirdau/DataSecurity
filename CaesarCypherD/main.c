#include <stdio.h>
#include <stdlib.h>

//Caesar cypher decryption
int main(int argc, char** argv) {

   char message[100];
   int key;
   int index;

   printf("Enter message to decrypt\n");
   scanf("%s", &message);

   printf("Enter the key\n");
   scanf("%d", &key);

   for (index = 0; message[index] != '\0'; index ++){

        message[index] = message[index] - key;

        if (message[index] < 'a')
               message[index] = message[index] + 26;
    }

    printf("Decrypted message is: %s\n", message);

}
