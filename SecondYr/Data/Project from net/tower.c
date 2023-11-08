#include<stdio.h>

void transfer(int n, char from, char to, char temp);

int main(){

    int n;

    printf("WELCOME TO THE TOWERS OF HONAI\n\n");

    printf("How many disks? ");

    scanf("%d", &n);

    printf("\n");

    transfer(n,'L','R','C');

    return 0;

}

void transfer(int n, char from, char to, char temp){

    /** n = number of disks

        from = orinin

        to = destination

        temp = temporary storage  **/

    if(n>0){

        /** move n-1 disks from origin to temporary **/

        transfer(n-1, from, temp, to);

        /** move nth disk from origin to destination **/

        printf("Move disk %d from %c to %c\n", n, from, to);

        /** move n-1 disks from temporary to destination **/

        transfer(n-1, temp, to, from);

    }

}


/*Output

WELCOME TO THE TOWERS OF HONAI

How many disks? 3

Move disk 1 from L to R
Move disk 2 from L to C
Move disk 1 from R to C
Move disk 3 from L to R
Move disk 1 from C to L
Move disk 2 from C to R
Move disk 1 from L to R
*/
