#include "ORCstring.h"
   int
ORCdelcharofstring (char * str,
      int  c)
{
   int i     = 0;
   int j     = 0;
   int error = 0;

   /*    assert (str != NULL); */
   if ( str == NULL ) {
      error = ORCERRNULLPOINTER;
   }
   else {
      for (i = 0, j = 0; str[i] != '\0'; ++i) {
         if ( str[i] != c ) {
            str[j++] = str[i];
         }
      }
      str[j] = '\0';
   }

TERMINATE:
   return error;
} /* End of ORCdelcharofstring */

   int
ORCstrlen (const char *str,
      size_t     *len)
{
   int i     = 0;
   int error = 0;

   if ( str == NULL ) {
      error = ORCERRNULLPOINTER;
   }
   else {
      while ( str[i] != '\0')
         ++i;
   }
   *len = i;

TERMINATE:
   return error;
} /* End of ORCstrlen */

   int
ORCstrtrim (char *str)
{
   int error = 0;
   size_t n  = 0;
   int i     = 0;

   error = ORCstrlen (str, &n);
   if ( error )  goto TERMINATE;

   if ( n > 0 ) {
      for (i = n-1; (i >= 0) && (str[i] == ' ' || str[i] == '\t'); --i);
      if ( i >= -1 ) {
         ++i;
         str[i] = '\0';
      }
   }

TERMINATE:
   return error;
} /* End of ORCstrtrim*/

   int
ORCstreverse (char *str)
{
   int error = 0;
   int i     = 0;
   int j     = 0;
   int temp  = 0;

   size_t n  = 0;

   error = ORCstrlen (str, &n);
   if ( error )  goto TERMINATE;

   if ( n > 0 ) {
      j = n - 1;
      /* Can not use ORCswapint here */
      while (i < j) {
         ORCswapchar (str, i, j);
         ++i;
         --j;
      }
   }

TERMINATE:
   return error;
} /* End of ORcstreverse */

/*
   ORCstrncpy copy src to des, with length n.
   */
   int
ORCstrncpy (char       *des,
      const char *src,
      int n)
{
   int error  = 0;
   int i      = 0;
   size_t len = 0;


   if ( des == NULL ||
         src == NULL   ) {
      error = ORCERRNULLPOINTER;
   }
   else {
      error = ORCstrlen (src, &len);
      if ( error )  goto TERMINATE;

      if ( len <= n ) {
         while ((*des++ = *src++) != '\0'){}
      }
      else {
         while (i < n) {
            des[i] = src[i];
            ++i;
         }
         des[i] = '\0';
      }
   }

TERMINATE:
   return error;
} /* End of ORCstrncpy*/

   int
ORCstrncat (char *des,
      const char *src,
      int n)
{
   int error  = 0;
   int i      = 0;
   size_t len = 0;

   if( des == NULL ||
         src == NULL ) {
      error = ORCERRNULLPOINTER;
   }
   else {
      error = ORCstrlen (src, &len);
      if ( error )  goto TERMINATE;

      while (*des != '\0') {
         ++des;
      }

      if( len <= n ) {
         while ((*des++ = *src++) != '\0');
      }
      else {
         while (i < n) {
            des[i] = src[i];
            ++i;
         }
         des[i] = '\0';
      }
   }

TERMINATE:
   return error;
} /* End of ORCstrncat function*/

int
ORCstrblkstoblk (char *str) {
   int error = 0;
   int lastc = 'a';
   int i = 0;
   int j = 0;

   while (str[i] != '\0') {
      if ( str[i] != ' ' ||
            lastc != ' '   ) {
         str[j++] = str[i];
      }
      lastc = str[i];
      ++i;
   }
   str[j] = '\0';

TERMINATE:
   return error;
} /* End of ORCstrlbkstoblk*/

   int
ORCstrindex(char *str, char *substr, int *index)
{
   int error = 0;
   int i = 0;
   int j = 0;
   int k = 0;

   if ( (str    == NULL) ||
         (substr == NULL)   ) {
      error = ORCERRNULLPOINTER;
      goto TERMINATE;
   }

   *index = -1;
   for (i = 0; str[i] != '\0'; ++i) {
      for ( j = i, k = 0; (substr[k] != '\0') && (substr[k] == str[j]); ++j, ++k);

      if ( k > 0 && substr[k] == '\0' ) {
         *index = i;
         printf ("%s in %s at %d\n", substr, str, *index);
      }
   }

TERMINATE:
   return error;
} /* End of ORCstrindex*/

