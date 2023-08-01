#include<stdio.h>
#include<math.h>

int main(){
int i,num,max;
int c = 0;

FILE *fp = fopen ("config.txt","r");
    fscanf(fp,"%d", &max);
    fclose(fp);


FILE *fpointer = fopen ("Divisors.txt","w");
fprintf(fpointer,"The only divisor of 1 is 1");

for(num=2;num<=max;num++){
    c=2;
    fprintf(fpointer,"\nThe divisors of %d are 1",num);
    for(i=2;i <= num/2;i++){
        if(num % i == 0){
            fprintf(fpointer,", %d",i);
            c++;
        }
    }
    fprintf(fpointer,", and %d",num);

    FILE *counter = fopen ("Divisor counter.txt","a");
    fprintf(counter,"%d has %d divisors\n",num, c);
    fclose(counter);
}

fclose(fpointer);
return 0;
}