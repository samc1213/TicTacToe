#include "corefunctions.h"


char CoreFunctions::GetSymbolFromValue(int value)
{
  switch(value)
  {
    case -1:
      return 'O';
    case 1:
      return 'X';
    default:
      return ' ';
  }
}
