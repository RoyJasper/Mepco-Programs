import java.io.*;
import java.util.*;
class Batsman
{
private String name;
private int nor;
private int noc;
private int nof;
private int nom;
private double avg;
Batsman(String name,int nor,int noc,int nof,int nom)
{
this.name=name;
this.nor=nor;
this.noc=noc;
this.nof=nof;
this.nom=nom;
avg=0.0;
}
public void averagecal()
{
avg=nor/nom;
}
public void display()
{
System.out.println("\nName of the player is " +name);
System.out.println("\nNo of runs he scored"+nor);
System.out.println("\nNo of centuries" +noc);
System.out.println("\nNo of fifties" +nof);
System.out.println("\nNo of matches he played" +nom);
System.out.println("\nAverage runs he scored in every match " +avg);
}
}
interface Bowler
{
int getnow();
int getnoc();
int getnol();
int getnob();
}
class Allrounder extends Batsman implements Bowler
{
int now,noc,nol,nob;
Allrounder(String nam,int nor1,int noc1,int nof1,int nom1,int wic,int cat,int lbw,int bolt)
{
super (nam,nor1,noc1,nof1,nom1);
now=wic;
noc=cat;
nol=lbw;
nob=bolt;
}
public int getnow()
{
return now;
}
public int getnoc()
{
return noc;
}
public int getnol()
{
return nol;
}
public int getnob()
{
return nob;
}
}
class Demo
{
public static void main(String[] args) throws IOException
{
int now,noc,nol,nob;
Allrounder obj=new Allrounder("rakhav",8090,25,37,216,123,66,23,33);
obj.averagecal();
System.out.println("\nBatsman Details are ");
obj.display();
now=obj.getnow();
noc=obj.getnoc();
nol=obj.getnol();
nob=obj.getnob();
System.out.println("\nBowler Details are ");
System.out.println("\nNo of wickets he took" +now);
System.out.println("\nNo of Catch wickets " +noc);
System.out.println("\nNo of lbw wickets" +nol);
System.out.println("\nNo of bolt wickets" +nob);
}
}

