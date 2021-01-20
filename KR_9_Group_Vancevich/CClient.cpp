#include "CClient.h"

CClient::CClient(char* from)
{
#pragma warning(suppress : 4996)
   char* pch = strtok(from, " ");
   int index = 0;
   while (pch != NULL)
   {
      switch (index)
      {
         case 0:
         {
            this->FirstName = pch;
            break;
         }
         case 1:
         {
            this->SecondName = pch;
            break;
         }
         case 2:
         {
            this->LastName = pch;
            break;
         }
         default:
         {
            return;
         }
      }
#pragma warning(suppress : 4996)
      pch = strtok(NULL, " ");
      index++;
   }
}
