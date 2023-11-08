package pack1;

public class B {
	public static void print(){
		A obj=new A();
		System.out.println("\n Public specifier "+(obj.a)+"\n Private specifier Not accessble "+"\n Protected specifier "+(obj.c)+"\n Default specifier "+(obj.d));
	}

}
