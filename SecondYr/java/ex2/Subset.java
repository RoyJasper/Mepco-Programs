import java.io.*;
import java.util.*;
class Subset
{
    public static void main(String arg[])
    {
        Scanner obj=new Scanner(System.in);
        int []b=new int[10];
        int []c=new int[100];
        int i,n,m=1,k=0,count=0;
        System.out.println("\nEnter size \n");
        n=obj.nextInt();
        for(i=0; i<n; i++)
        {
            System.out.println("\nEnter elements\n");
            b[i]=obj.nextInt();
        }
        while(n!=0)
        {
            for(i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    c[k]=c[k]+b[i+j];
                }
                k++;
            }
            n--;
            m++;
        }
        for(int p=0; p<k; p++)
        {
            if(c[p]<0)
                count++;
        }
        System.out.println("\nTotal no of negative sub arrays are"+ count);
    }
}

