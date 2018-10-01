#ifndef __DOUBLE_VECTOR_H__
#define __DOUBLE_VECTOR_H__

#include <vector>

// forward declarations
class IntegerVector;
class CharacterVector;

class DoubleVector
{
   private:
      std::vector<double> doubleVector;

   public:
      DoubleVector();
      ~DoubleVector();

      int    size();
      double get(int index);
      void   put(double value, int index);
      void   put(double value);

      void appendIntegerVector(IntegerVector& integerVector);
      void appendCharacterVector(CharacterVector& characterVector);
};

#endif
