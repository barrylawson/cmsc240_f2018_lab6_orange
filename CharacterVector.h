#ifndef __CHARACTER_VECTOR_H__
#define __CHARACTER_VECTOR_H__

#include <vector>

// forward declarations
class IntegerVector;
class DoubleVector;

class CharacterVector
{
   private:
      std::vector<char> characterVector;

   public:
      CharacterVector();
      ~CharacterVector();

      int  size();
      char get(int index);
      void put(char value, int index);
      void put(char value);

      void appendIntegerVector(IntegerVector& integerVector);
      void appendDoubleVector(DoubleVector& doubleVector);
};

#endif
