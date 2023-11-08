/* Mastermind Game.
This game uses functions to determine the colors of pegs and makes sure there are correctly put. */
#include <stdio.h>
#include <conio.h>
//include <random.h>
//#include <bool.h>
using namespace std;
int random(int);


        bool HasDuplicate() //this is the function heading
         /*Pre: decides if any of the parameters have the same value.
          Post: runs the function again until there are no duplicates.*/
       {

        bool duplicate = false;
        int PegOne;
        int PegTwo;
        int PegThree;


       while(PegOne==PegTwo||PegTwo==PegThree||PegThree==PegOne)
       {
          AssignColors(PegOne, PegTwo, PegThree);
       }

           return(false);
}
       //-------------------------------------------//




       void AssignColors(int &PegOne, int &PegTwo, int &PegThree) //this is the function heading
             /*Pre: randomly assigns unique colors to 3 pegs.
              Post: assings the values and checks to make sure there are no duplicates.*/

         {
          PegOne= random(5)+1;
            PegTwo= random(5)+1;
            PegThree= random(5)+1;
            HasDuplicate(PegOne, PegTwo, PegThree);
         }

       //-------------------------------------------//
       void GetGuess(int peg1, int peg2, int peg3) //this is the function heading
         /*Pre: prompts the user to guess the color of the pegs.
          Post: Keeps them going until they guess the correct numbers, checks for valid numbers and repeats.*/
       {
          peg1=0;
          peg2=0;
          peg3=0;

         cout<<"Guess the color of peg number one using numbers 1-5 for red, orange, yellow, green, or blue: ";
         cin>>peg1;
   cout<<"Guess the color of peg number two using numbers 1-5 for red, orange, yellow, green, or blue: ";
        cin>>peg2;
        cout<<"Guess the color of peg number one using numbers 1-5 for red, orange, yellow, green, or blue: ";
        cin>>peg3;
          if(peg1>5||peg2>5||peg3>5)
         {
         cout<<"You have picked an invalid number. Please pick a number from 1-5. ";
         }
         HasDuplicate(peg1, peg2, peg3);

}
       //-------------------------------------------//


       void CorrectOrder(int peg1,int peg2,int peg3) //this is the function heading
          /*Pre: Uses the functions to count how many correct order guesses there are.
           Post: displays they number of correct order guesses.*/
 {
     int counter=0;
         int PegOne;
         int PegTwo;
         int PegThree;
         int peg1;
         int peg2;
         int peg3;
         AssignColors(PegOne, PegTwo, PegThree);
         GetGuess(peg1, peg2, peg3);
         if(PegOne==peg1)
         {
         counter++;
         }
         else if(PegTwo==peg2)
         {
         counter++;
         }
         else if(PegThree==peg3)
         {
         counter++;
         }
         else
         {
           AssignColors(PegOne, PegTwo, PegThree);
           GetGuess(peg1, peg2, peg3);
         }
         cout<<"Correct Peg(s): " <<counter;

         }
       //-------------------------------------------//
       void CorrectColors(PegOne, PegTwo, PegThree) //this is the function heading
         /*Pre: counts how many colors have been guessed correctly.
          Post: displays the number of colors guessed correctly by the user.*/
 {
        int counter2;
         int PegOne;
         int PegTwo;
         int PegThree;
         int peg1;
         int peg2;
         int peg3;
         AssignColors(PegOne, PegTwo, PegThree);
         GetGuess(peg1, peg2, peg3);
         if(PegOne==peg1)
         {
         counter2++;
         }
         else if(PegTwo==peg2)
         {
         counter2++;
         }
         else if(PegThree==peg3)
         {
         counter2++;
         }
         else
         {
           AssignColors(PegOne, PegTwo, PegThree);
           GetGuess(peg1, peg2, peg3);
         }
         cout<<"Correct Color(s): " <<counter2;

         }

 //---------------------------------------------------------------------/



       int main()
       /*Pre: declares appropriate variables to play the game.
        Post: Displays the number of correct guesses it took to break the code using functions.*/

{
       int firstpeg;
       int secondpeg;
       int thirdpeg;
       int guess=1;

       do
       {
        cout<<"Guess " <<guess <<':'  <<endl;
        AssignColors(firstpeg, secondpeg, thirdpeg);
        cout<<GetGuess(firstpeg, secondpeg, thridpeg);
        cout<<CorrectOrder(firstpeg, secondpeg, thirdpeg);
        cout<<CorrectColor(firstpeg, secondpeg, thirdpeg);
        guess++;
       }while(CorrectOrder!=CorrectColor);

  getche();
  return(0);

}
