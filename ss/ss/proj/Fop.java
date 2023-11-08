mport java.io.File;

public class RenameFileJava {

    /**
     * Rename File  or Move File in Java example
     * @param args
     */
    public static void main(String[] args) {
        //absolute path rename file
        File file = new File("/Users/pankaj/java.txt");
        File newFile = new File("/Users/pankaj/java1.txt");
        if(file.renameTo(newFile)){
            System.out.println("File rename success");;
        }else{
            System.out.println("File rename failed");
        }
        
        //relative path rename file
        file = new File("DB.properties");
        newFile = new File("DB_New.properties");
        if(file.renameTo(newFile)){
            System.out.println("File rename success");;
        }else{
            System.out.println("File rename failed");
        }
        
        //move file from one directory to another
        file = new File("/Users/pankaj/DB.properties");
        newFile = new File("DB_Move.properties");
        if(file.renameTo(newFile)){
            System.out.println("File move success");;
        }else{
            System.out.println("File move failed");
        }
        
        //when source file is not present
        file = new File("/Users/pankaj/xyz.txt");
        newFile = new File("xyz.properties");
        if(file.renameTo(newFile)){
            System.out.println("File move success");;
        }else{
            System.out.println("File move failed");
        }
        
        // when destination already have a file with same name
        file = new File("/Users/pankaj/export.sql");
        newFile = new File("/Users/pankaj/java1.txt");
        if(file.renameTo(newFile)){
            System.out.println("File move success");;
        }else{
            System.out.println("File move failed");
        }
    }

}------------------------------------------------------------------

package com.mkyong.file;

import java.io.File;

public class DeleteFileExample
{
    public static void main(String[] args)
    {
    	try{

    		File file = new File("c:\\logfile20100131.log");

    		if(file.delete()){
    			System.out.println(file.getName() + " is deleted!");
    		}else{
    			System.out.println("Delete operation is failed.");
    		}

    	}catch(Exception e){

    		e.printStackTrace();

    	}

    }
}--------------------------------------------------------

public class Main {
   public static void main(String[] args)  {
      try {
         BufferedWriter out = new BufferedWriter
         (new FileWriter("filename"));
         out.write("aString1\n");
         out.close();
         boolean success = (new File
         ("filename")).delete();
         if (success) {
            System.out.println("The file has 
            been successfully deleted"); 
         }
         BufferedReader in = new BufferedReader
         (new FileReader("filename"));
         String str;
         while ((str = in.readLine()) != null) {
            System.out.println(str);
         }
         in.close();
         }
         catch (IOException e) {
            System.out.println("exception occoured"+ e);
            System.out.println("File does not exist 
            or you are trying to read a file that 
            has been deleted");
         }
      }
   }
}---------------------------------------------------------------
package com.tutorialspoint;

import java.io.File;

public class FileDemo {
   public static void main(String[] args) {
      
      File f = null;
      File f1 = null;
      boolean bool = false;
      
      try{      
         // create new File objects
         f = new File("C:/test.txt");
         f1 = new File("C:/testABC.txt");
         
         // rename file
         bool = f.renameTo(f1);
         
         // print
         System.out.print("File renamed? "+bool);
         
      }catch(Exception e){
         // if any error occurs
         e.printStackTrace();
      }
   }
}
---------------------------------------------------------


-----------------------------------------------------------------

