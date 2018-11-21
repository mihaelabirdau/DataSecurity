#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define MX 5


char[] vigenereEncrypt(char message[100], char key[100]) {

    int msgLen = strlen(message);
	int keyLen = strlen(key);
	int i;
	int j;

    char newKey[msgLen];
	char encryptedMsg[msgLen];

    //generating new key
    for(i = 0, j = 0; i < msgLen; ++i, ++j){
        if(j == keyLen)
            j = 0;

        newKey[i] = key[j];
    }

    newKey[i] = '\0';

    for(i = 0; i < msgLen; ++i)
        encryptedMsg[i] = ((message[i] + newKey[i]) % 26) + 'A';

    encryptedMsg[i] = '\0';

	return encryptedMsg;
}

char[] vigenereDecrypt(char message[100], char key[100]) {
	    int msgLen = strlen(message);
	int keyLen = strlen(key);
	int i;
	int j;

    char newKey[msgLen];
	char decryptedMsg[msgLen];

    //generating new key
    for(i = 0, j = 0; i < msgLen; ++i, ++j){
        if(j == keyLen)
            j = 0;

        newKey[i] = key[j];
    }

    newKey[i] = '\0';

    for(i = 0; i < msgLen; ++i)
        decryptedMsg[i] = (((message[i] - newKey[i]) + 26) % 26) + 'A';

    decryptedMsg[i] = '\0';
	return decryptedMsg;
}

void frequency(char string[100]) {
 	int c = 0, temp, count[26] = {0}, x;
    char string[] = "TEST";
    int letterSorted[26];
   while (string[c] != '\0') {

      if (string[c] >= 'A' && string[c] <= 'Z') {
         x = string[c] - 'A';
         count[x]++;
      }

      c++;
   }

   for(int i = 0; i < 26; i++) {
	   letterSorted[i] = i;
   }

	for(int i = 0; i < 25; i++) {
		for(int j = i + 1; j < 26; j++) {
			if(count[i] < count[j]) {
				temp = count[i];
				count[i] = count[j];
				count[j] = temp;
				temp = letterSorted[i];
				letterSorted[i] = letterSorted[j];
				letterSorted[j] = temp;
			}
		}
	}

   for (c = 0; c < 26; c++)
         printf("%c occurs %d times in the string.\n", letterSorted[c] + 'A', count[c]);

}

int removeduplicate(int size,char a[])
{
 int i,j,k;
 for(i = 0; i < size;i ++){

    for(j = i+1;j < size;){

        if(a[i] == a[j]){

            for(k = j;k < size;k ++){
                a[k] = a[k+1];
             }
            size--;
        }
        else{
            j++;
        }
    }
 }
    return(size);
}

void playfairEncrypt(char ch1, char ch2, char key[MX][MX]) {
    int i, j, positionColCh1, positionColCh2, positionRowCh1, positionRowCh2;


    for (i = 0; i < MX; i++) {
        for (j = 0; j < MX; j++) {
            if (ch1 == key[i][j]) {
                positionRowCh1 = i;
                positionColCh1 = j;
            } else if (ch2 == key[i][j]) {
                positionRowCh2 = i;
                positionColCh2 = j;
            }
        }
    }
    if (positionRowCh1 == positionRowCh2) {

        positionColCh1 = (positionColCh1 + 1) % MX;
        positionColCh2 = (positionColCh2 + 1) % MX;

        printf("%c%c", key[positionRowCh1][positionColCh1], key[positionRowCh2][positionColCh2]);

    } else if (positionColCh1 == positionColCh2) {
        positionRowCh1 = (positionRowCh1 + 1) % MX;
        positionRowCh2 = (positionRowCh2 + 1) % MX;
        printf("%c%c", key[positionRowCh1][positionColCh1], key[positionRowCh2][positionColCh2]);

    } else {
        printf("%c%c", key[positionRowCh1][positionColCh2], key[positionRowCh2][positionColCh1]);
    }
}

void playfairDecrypt(char ch1, char ch2, char key[MX][MX]) {
     int i, j, positionColCh1, positionColCh2, positionRowCh1, positionRowCh2;


    for (i = 0; i < MX; i++) {
        for (j = 0; j < MX; j++) {
            if (ch1 == key[i][j]) {
                positionRowCh1 = i;
                positionColCh1 = j;
            } else if (ch2 == key[i][j]) {
                positionRowCh2 = i;
                positionColCh2 = j;
            }
        }
    }
    if (positionRowCh1 == positionRowCh2) {

        positionColCh1 = ((positionColCh1 - 1)+MX) % MX;
        positionColCh2 = ((positionColCh2 - 1)+MX) % MX;

        printf("%c%c", key[positionRowCh1][positionColCh1], key[positionRowCh2][positionColCh2]);

    } else if (positionColCh1 == positionColCh2) {
        positionRowCh1 = ((positionRowCh1 - 1)+MX) % MX;
        positionRowCh2 = ((positionRowCh2 - 1)+MX) % MX;
        printf("%c%c", key[positionRowCh1][positionColCh1], key[positionRowCh2][positionColCh2]);

    } else {
        printf("%c%c", key[positionRowCh1][positionColCh2], key[positionRowCh2][positionColCh1]);
    }
}

void encryptPlayfair(char plainText[1000], char keystr[100]) {
	int i, j, k, m=0,lenghtKeyStr;

    char key[MX][MX], keyminus[25];

    char alpa[26] = {
        'A',  'B',  'C',  'D',  'E',  'F',  'G',  'H',  'I',  'J',  'K',  'L',  'M',  'N',  'O',  'P',  'Q',  'R',  'S',
        'T',  'U',  'V',  'W',  'X', 'Y',  'Z'  };

    lengthKeyStr = strlen(keystr);
    lengthKeyStr = removeduplicate(lengthKeyStr, keystr);

    j = 0;
    for (i = 0; i < 26; i++) {
        for (k = 0; k < lengthKeyStr; k++) {
            if (keystr[k] == alpa[i] || (alpa[i] == 'J'))
                break;
        }
        if (k == lengthKeyStr) {
            keyminus[j] = alpa[i];
            j++;
        }
    }

    k = 0;
    for (i = 0; i < MX; i++) {
        for (j = 0; j < MX; j++) {
            if (k < lengthKeyStr) {
                key[i][j] = keystr[k];
                k++;
            } else {
                key[i][j] = keyminus[m];
                m++;
            }
        }
    }

    for (i = 0; i < strlen(plainText); i++) {
        if (plainText[i] == 'J')
                plainText[i] = 'I';

        if (plainText[i + 1] == '\0')
                playfairEncrypt(plainText[i], 'X', key);
        else {
            if (plainText[i + 1] == 'J')
                    plainText[i + 1] = 'I';
            if (plainText[i] == plainText[i + 1])
                    playfairEncrypt(plainText[i], 'X', key);
            else {
                    playfairEncrypt(plainText[i], plainText[i + 1], key);
                    i++;
            }
        }
    }
}

void decryptPlayfair(char cypherText[1000], char keystr[100]) {

	int i, j, k, m = 0,lengthKeyStr;
    char key[MX][MX], keyminus[25];

    char alpa[26] = {
        'A',  'B',  'C',  'D',  'E',  'F',  'G',  'H',  'I',  'J',  'K',  'L',  'M',  'N',  'O',  'P',  'Q',  'R',  'S',
        'T',  'U',  'V',  'W',  'X', 'Y',  'Z'  };

    lengthKeyStr = strlen(keystr);
    lengthKeyStr = removeduplicate(lengthKeyStr, keystr);

    j = 0;
    for (i = 0; i < 26; i++) {
        for (k = 0; k < lengthKeyStr; k++) {
            if ((keystr[k] == alpa[i]) ||(alpa[i] == 'J'))
                break;
        }
        if (k == lengthKeyStr) {
            keyminus[j] = alpa[i];
            j++;
        }
    }
    k = 0;
    for (i = 0; i < MX; i++) {
        for (j = 0; j < MX; j++) {
            if (k < lengthKeyStrn) {
                key[i][j] = keystr[k];
                k++;
            } else {
                key[i][j] = keyminus[m];
                m++;
            }
        }
    }

    for (i = 0; i < strlen(cypherText); i++) {
        if (cypherText[i] == 'J')
                cypherText[i] = 'I';
        if (cypherText[i + 1] == '\0')
                playfairDecrypt(cypherText[i], 'X', key);
        else {
            if (cypherText[i + 1] == 'J')
                    cypherText[i + 1] = 'I';
            if (cypherText[i] == cypherText[i + 1])
                    playfairDecrypt(cypherText[i], 'X', key);
            else {
                playfairDecrypt(cypherText[i], cypherText[i + 1], key);
                i++;
            }
        }
    }
}
int main() {

	FILE *fp;
    char str[MAXCHAR];
    char* filename = "c:\\temp\\file.txt";

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    while (fgets(str, MAXCHAR, fp) != NULL);
}


