// using splint to check bounds
// splint test.c +bounds
#include "PCMfile.h"

   int
main(int argc, char **argv)
   /*main ()*/
{
   int error = 0;

   PCMfile *fp = NULL;

   error = PCMfilecreate(&fp);
   if ( error )  goto TERMINATE;

   /* error = PCMfileopen(fp, "../data/git.txt"); */
   /* error = PCMfileopen(fp,"../data/01.mps");*/
   /* error = PCMfileopen(fp, "makefile");*/
   /* error = PCMfileopen(fp, "../data/questions.txt"); */
   error = PCMfileopen(fp, argv[1]);
   if ( error )  goto TERMINATE;

   error = PCMfilestatistics(fp);
   if ( error )  goto TERMINATE;

   char str[PCMFILEMAXLINE] = {0};
   int len = 0;

   error = PCMfilegetmaxline (fp, str, &len);
   if ( error )  goto TERMINATE;
   printf ("+The longest line is: %s, length = %d\n", str, len);

   /* printf ("cat %s\n", fp->name);*/

   /*do{*/
   /*error = PCMfilegetline(fp, PCMFILEMAXLINE, str, &len);*/
   /*if ( error )  goto TERMINATE;*/
   /*printf ("%s", str);*/
   /*}*/
   /*while (len > 0);*/


   error = PCMfilefree(&fp);
   if ( error )  goto TERMINATE;

TERMINATE:
   PCMcheckerror(error);
   return 0;
}
