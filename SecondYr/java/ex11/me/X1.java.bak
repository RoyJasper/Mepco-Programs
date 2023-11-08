xclass A { 
int value; 

public void setA(int v) { 
value=v; 
} 

public int getA() { 
return value; 
} 
} 

class put implements Runnable { 

A obj; 

public void run() { 
for(int i=1;i<=10;i++) { 
System.out.println("putting in A value is " + i ); 
obj.setA(i); 
} 
} 

put(A ob) { 
obj=ob; 
} 
} 


class get implements Runnable { 
A obj; 

get(A ob) { 
obj = ob; 
} 


public void run() {  
for(int i=10;i>0;i--)
System.out.println(i); } 


} 

public class X1 { 

public static void main(String arg[]) { 
A obj = new A(); 

put p = new put(obj); 
get g = new get(obj); 

Thread p1 = new Thread(p); 
Thread g2 = new Thread(g); 

p1.start(); 
g2.start(); 
} 
} 
