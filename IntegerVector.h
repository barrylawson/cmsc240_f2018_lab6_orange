#ifndef __INTEGER_VECTOR_H__
#define __INTEGER_VECTOR_H__

#include <vector>

// forward declarations
class DoubleVector;
class CharacterVector;

class IntegerVector
{
   private:
      std::vector<int> integerVector;

   public:
      IntegerVector();
      ~IntegerVector();

      int  size();
      int  get(int index);
      void put(int value, int index);
      void put(int value);

      void appendDoubleVector(DoubleVector& doubleVector);
      void appendCharacterVector(CharacterVector& characterVector);
};

#endif
