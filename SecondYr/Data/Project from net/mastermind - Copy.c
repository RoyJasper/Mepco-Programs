#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct set
{
    int count;
    void **values;
} *SR;

SR create(void *values,...);//
int  set_count(SR this);
bool contains(SR this, void *value);
int rscore(SR set1, void *value, int score);


int main(int argc,char **argv )
{
    int t = 0, n = 0 ,k = 0,q = 0, score = 0,i,c;
    char ch;
    int arr1[n];
    int arr2[n];
   // printf("Please enter the number of test cases(between 1 to 100):");
    scanf("%d",&t);
    printf("\n");
    for ( i = 1; i<=t;i++)
    {
     //   printf("Please enter values of n,k, q:");
        scanf("%i %i %i",&n, &k, &q);

        printf("\n");
       // printf("Enter the values of secret key");
        score = 0;
        for ( c = 0 ; c < n ; c++ )
        {
            scanf("%d",&arr1[c]);
         }
        printf("\n");
       // printf("Enter the values of guess");
            for (  c = 0 ; c < n ; c++ )
            {
                scanf("%d",&arr2[c]);
             }

        }
       SR set1 = create(&arr1);
       SR set2 = create(&arr2);
       for ( i = 0; i < set2->count; i++){
            void *val = set2->values[i];
            score = rscore(set1, val,score);
        }
        if ( score == set1->count)
            printf("Yes");
        else
            printf("No");
        printf("\n");
    }


SR create(void *values,...)//
{
    SR set = calloc(1, sizeof(struct set));
    if (values)
    {
        int count = 1;
         va_list args;
         va_start(args, values);
        while (va_arg(args, void *))
        {
            count++;
        }
        va_end(args);
        set->count = count;
        set->values = calloc(count, sizeof(void *));
        set->values[0] = values;
        va_start(args, values);
        int i = 1;
        void *val;
        while ((val = va_arg(args, void *)))
        {
            set->values[i++] = val;
        }
        va_end(args);
    }
    return set;
}
int set_count(SR this)
{
    return this->count;
}
bool contains(SR this, void *value)
{
    int i;
    for ( i = 0; i < this->count; i++)
    {
        if (value == this->values[i])
            return true;
    }
    return false;
}

int rscore(SR set1, void *value, int score){
    void *val = value;
    if (contains(set1, val))
        score ++;
    return score;
}
