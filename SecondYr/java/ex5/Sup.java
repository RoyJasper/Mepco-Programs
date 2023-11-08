import java.io.*;
import java.lang.*;
class Batsman
{
 private String name;
 private float avg;
 private int nocen,nof,runs,nom;

 Batsman(String name,int nocen,int nof,int runs,int nom)
 {
  this.name=name;
  this.nocen=nocen;
  this.nof=nof;
  this.runs=runs;
  this.nom=nom;
 }
 public void avgcalc()
 {
  avg=runs/nom;
 }
 public void display()
 {
  System.out.println("\nName:"+name+"\nNo of matches:"+nom+"\nNo of centuries:"+nocen+"\nNo of fifty:"+nof+"\nRuns:"+runs+"\n Avg is :"+avg);
 }
}
interface Bowler
{
 int getnow();
 int getnoc();
 int getlbw();
 int getbolt();
}
class AllRounder extends Batsman implements Bowler
{
 int now,noc,lbw,bolt;
 AllRounder(String name,int nocen,int nof,int runs,int nom,int now,int noc,int lbw,int bolt)
 {
 super( name, nocen, nof, runs, nom);
 this.now=now;
 this.noc=noc;
 this.lbw=lbw;
 this.bolt=bolt;
 }
 public int getnow()
  {
   return now; 
  }
 public int getnoc()
  {
   return noc;
  }
 public int getlbw()
  {
   return lbw;
  }
 public int getbolt()
  {
   return bolt;
  }
}
class Demo
{
 public static void main(String args[]) throws IOException
 {
  //Scanner obj=new Scanner (System.in);
  AllRounder obj=new AllRounder("Roy",20,56,2564,89,23,65,15,45);
  obj.avgcalc();
  //number=obj.nextInt();
  System.out.println("\nBatsman Details are");
  obj.display();
  System.out.println("\nNo of wickets are:"+obj.getnow()+"\nNo of catches:"+obj.getnoc()+"\nNo of lbw:"+obj.getlbw()+"\nNo of bolt:"+obj.getbolt());
 }
}
