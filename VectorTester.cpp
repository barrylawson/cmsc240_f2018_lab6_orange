#include <iostream>
#include <string>
#include <stdexcept>
#include "IntegerVector.h"
#include "DoubleVector.h"
#include "CharacterVector.h"
#include <stdexcept>
#include <vector>
int main()
{
   IntegerVector   iv;
   DoubleVector    dv;
   CharacterVector cv;

   //-------------------------------------------------------------------------

   // test IntegerVector: put, get, size, out_of_range

   std::cout << "--------------" << std::endl;
   std::cout << "IntegerVector:" << std::endl;
   iv.put(76,0);
   std::cout << iv.get(0) << std::endl;
   std::cout << "Size test: " << iv.size() << std::endl;  
   try{
       	std::cout << cv.get(100)<< std::endl;
      }
   catch(const std::out_of_range& e){
	std::cout  << "Out of Range error." << e.what() << std::endl;
	}

   //-------------------------------------------------------------------------

   // test CharacterVector: put, get, size, out_of_range

   std::cout << std::endl;
   std::cout << "----------------" << std::endl;
   std::cout << "CharacterVector:" << std::endl;
   cv.put('a',0);
   cv.put('b',1);
   cv.put('c',2);
   std::cout << "Put test: "<< std::endl;
   for(int i = 0; i < cv.size(); i++) {
	std::cout << cv.get(i) << std::endl;
   }
   std::cout << "Size test: " << cv.size() << std::endl;
   try{
       	std::cout << cv.get(100)<< std::endl;

      }
   catch(const std::out_of_range& e){
        std::cout << "Out of range exception:  " << e.what() << std::endl;
}
   std::cout << "----------------" << std::endl;

   //-------------------------------------------------------------------------

   // test DoubleVector: put, get, size, out_of_range

   std::cout << std::endl;
   std::cout << "-------------" << std::endl;
   std::cout << "DoubleVector:" << std::endl;
   std::cout << "-------------" << std::endl;
//put tests
	dv.put(53.00000,0);
	dv.put(77.0);
	dv.put(49.0);
	dv.put(112.0, 3);

	std::cout << "Put test: ";
	for(int i = 0; i < dv.size(); i++) {std::cout << dv.get(i) << std::endl;}

	std::cout << "Size test: " << dv.size() << " [4]" << std::endl;

try{
	std::cout << "Get test: " << dv.get(10) << " [index out of bound]" << std::endl;	
}  
catch (const std::out_of_range& e){
	std::cout << "Out of range exception: " << e.what() << std::endl;
}
   //-------------------------------------------------------------------------

   // using empty IntegerVector, test appending cv & dv from above 
   IntegerVector iv2;

   std::cout << std::endl;
   std::cout << "--------------------------" << std::endl;
   std::cout << "appended-to IntegerVector:" << std::endl;
   iv2.appendCharacterVector(cv);
   iv2.appendDoubleVector(dv);
   for(int i = 0; i < iv2.size(); i++){
                std::cout << iv2.get(i) << " ";
        }
   std::cout << std::endl;
   std::cout << "----------------------------" << std::endl;

   //-------------------------------------------------------------------------

   // using empty CharacterVector, test appending iv & dv from above
   CharacterVector cv2;

   std::cout << std::endl;
   std::cout << "----------------------------" << std::endl; 
   std::cout << "appended-to CharacterVector:" << std::endl;
  
   cv2.appendIntegerVector(iv);
   std::cout << "Size: " << cv2.size() << " [1]" << std::endl;
   std::cout << "Values: " << std:: endl;
   for(int i = 0; i < cv2.size(); i++ ){
   	std::cout << cv2.get(i) << std::endl;
   }
   cv2.appendDoubleVector(dv);
   std::cout << "Size: " << cv2.size() << " [5]" << std::endl;
   std::cout << "Values: " << std::endl;
   for(int i = 0; i < cv2.size(); i++ ){
        std::cout << cv2.get(i) << std::endl;
   }
   std::cout << "----------------------------" << std::endl;

   //-------------------------------------------------------------------------

   // using empty DoubleVector, test appending iv & cv from above
   DoubleVector dv2;

   std::cout << std::endl;
   std::cout << "-------------------------" << std::endl;
   std::cout << "appended-to DoubleVector:" << std::endl;
   std::cout << "-------------------------" << std::endl;

	dv2.appendIntegerVector(iv);
	dv2.appendCharacterVector(cv);
	for(int i = 0; i < dv2.size(); i++){
		std::cout << dv2.get(i) << " ";
	}
	std::cout << std::endl;
    //-------------------------------------------------------------------------

   return 0;
}
