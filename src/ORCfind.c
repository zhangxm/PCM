#include "ORCfind.h"

   int
ORCoriginfind(int *a,
      int length,
      const int elem,
      int *index)
{
   int error = 0;
   int i;
   
   error = ORCcheckpointer (a);
   if ( error )  goto TERMINATE;

   for (i = 0; i < length; ++i) {
      if ( a[i] == elem ) {
         *index = i;
      }
   }

TERMINATE:
   return error;
} /* End of ORCoriginfind*/

   int
ORCbinfind(int *a, 
      int length, 
      const int elem, 
      int *index)
{
   int error = 0;
   int mid = 0;
   int low = 0;
   int high = length-1;
   
   error = ORCcheckpointer (a);
   if ( error )  goto TERMINATE;

   *index = -1;
   while (low <= high) {
      mid = (low + high)/2;
      if ( elem > a[mid] ) {
         low  = mid + 1;
      }
      else if( elem < a[mid] ) {
         high = mid - 1;
      }
      else {
         *index = mid;
         goto TERMINATE;
      }
   }

TERMINATE:
   return error;
} /* End of ORCbinfind*/

