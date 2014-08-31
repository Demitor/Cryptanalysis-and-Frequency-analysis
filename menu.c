
/**************************************************************/
/* DVGC19 decryption program                                */
/**************************************************************/
/* A. PAYNE & A. KÄCK - test version                          */
/**************************************************************/

/**************************************************************/
/* include files and  global data objects                     */
/**************************************************************/

#include <stdio.h>
#include "main.h"

#define   MAXLNC   80        /* max number of input line chars*/
#define   MAXLN    MAXLNC+1  /* max size of input line buffer */


/**************************************************************/
/* global data objects                                        */
/**************************************************************/

char       lnbuff[MAXLN];             /* input line buffer    */


/*****************************************************************************/
/*  get_choice: get user input from keyboard (1 character)                   */
/*****************************************************************************/

static char get_choice() { scanf("%s", lnbuff); return(lnbuff[0]); }



/*****************************************************************************/
/*  dispmenu: display the user menu                                          */
/*****************************************************************************/

static void dispmenu()

{

   printf("\n");
   printf("***************************************************************\n");
   printf("***                                                         ***\n");
   printf("***   m:   display this menu                                ***\n");
   printf("***   p:   print text                                       ***\n");
   printf("***                                                         ***\n");
   printf("***   a:   analyse crypted text                             ***\n");
   printf("***   d:   decrypt text                                     ***\n");
   printf("***                                                         ***\n");
   printf("***   c:   crypt text from file                             ***\n");
   printf("***                                                         ***\n");
   printf("***   q:   quit the program                                 ***\n");
   printf("***                                                         ***\n");
   printf("***************************************************************\n");
   printf("\n");

}



/****************************************************************************/
/*  runmenu: execute the user menu                                          */
/****************************************************************************/

void runmenu()

{
   char   choice;                     /* user menu selection  */

   dispmenu();
   do {
      printf("\n Enter choice => "); choice = get_choice();
      switch(choice) {

         case 'm': case 'M': dispmenu();                        break;
         case 'p': case 'P': listf(); printt();                 break;
         case 'a': case 'A': listf(); analysec();               break;
         case 'd': case 'D': listf(); decryptt();               break;
         case 'c': case 'C': listf(); cryptt();                 break;

         case 'q': case 'Q': printf(" *** BYE BYE! ***");       break;

         default:  printf("\n INVALID MENU CHOICE ***\n");
                   dispmenu();                                  break;
         }
      } while (choice != 'Q' && choice != 'q');
      printf("\n");
}