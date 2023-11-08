
import java.util.InputMismatchException;
import java.util.Scanner;

public class GenericMethodTest <E extends Number>
{                         
   public E operation(E a,E b,char c)
   {
	   E result=null;
	   switch (c)
		{
		case '+':
			 if (a instanceof Integer && b instanceof Integer)
		      return (E) (Integer) ((Integer)a + (Integer)b);
			 if (a instanceof Float && b instanceof Float)
			      return (E) (Float) ((Float)a + (Float)b);
			 if (a instanceof Double && b instanceof Double)
			      return (E) (Double) ((Double)a + (Double)b);
			 	
		case '-':
			 if (a instanceof Integer && b instanceof Integer)
			      return (E) (Integer) ((Integer)a - (Integer)b);
			 if (a instanceof Float && b instanceof Float)
			      return (E) (Float) ((Float)a - (Float)b);
			 if (a instanceof Double && b instanceof Double)
			      return (E) (Double) ((Double)a - (Double)b);
				
		
		case '*':
			 if (a instanceof Integer && b instanceof Integer)
			      return (E) (Integer) ((Integer)a * (Integer)b);
			 if (a instanceof Float && b instanceof Float)
			      return (E) (Float) ((Float)a * (Float)b);
			 if (a instanceof Double && b instanceof Double)
			      return (E) (Double) ((Double)a * (Double)b);
				
			
		case '/':
			 if (a instanceof Integer && b instanceof Integer)
			      return (E) (Integer) ((Integer)a / (Integer)b);
			 if (a instanceof Float && b instanceof Float)
			      return (E) (Float) ((Float)a / (Float)b);
			 if (a instanceof Double && b instanceof Double)
			      return (E) (Double) ((Double)a / (Double)b);
		case '%':
			 if (a instanceof Integer && b instanceof Integer)
		      return (E) (Integer) ((Integer)a % (Integer)b);
			 if (a instanceof Float && b instanceof Float)
			      return (E) (Float) ((Float)a % (Float)b);
			 if (a instanceof Double && b instanceof Double)
			      return (E) (Double) ((Double)a % (Double)b);
				
		}
	return result;
		
   }

    public static void main( String args[] )
    {
        Scanner in=new Scanner(System.in);
        Number x=null,y = null;
        String one=null,two=null;
        GenericMethodTest g=new GenericMethodTest();
        do
        {
        int set=0;
        System.out.println("ENTER TWO NUMBERS ");
        try
        {
        x=in.nextInt();
        y=in.nextInt();
        set=1; 
        }
        catch(InputMismatchException e)
        {}
        if(set !=1)
        {
        try
        {
        x=in.nextFloat();
        y=in.nextFloat();
        set=1;
        }
        catch(InputMismatchException e)
        {}}
        if(set!=1)
        {
        try
        {
        x=in.nextDouble();
        y=in.nextDouble();
        set=1;
        }
        catch(InputMismatchException e)
        {}}
        if(set!=1)
        {
        try
        {
        	 one=in.nextLine();
        	 two=in.nextLine();
        	 System.out.println(""+(one+two));
        	
        }
        catch (InputMismatchException e)
        {}}
        
		if(set==1)
		{
			System.out.println("ENTER OPERATION :");
	        in.nextLine();
	        String q=in.nextLine();
	        char z=q.charAt(0);
	        @SuppressWarnings("unchecked")
			Number s1=g.operation (x,y,z);
			System.out.println(""+s1);
		}
		}while(true);
       } 
}