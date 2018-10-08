#include <iostream>
#include <string>
#include <stdexcept>
#include "IntegerVector.h"
#include "DoubleVector.h"
#include "CharacterVector.h"
#include <stdexcept>
int main()
{
   IntegerVector   iv;
   DoubleVector    dv;
   CharacterVector cv;

   //-------------------------------------------------------------------------

   // test IntegerVector: put, get, size, out_of_range

   std::cout << "--------------" << std::endl;
   std::cout << "IntegerVector:" << std::endl;
   iv.put(1,0);
   std::cout << iv.get(0) << std::endl;
   std::cout << iv.size() << std::endl;
//   try{
//	std::cout<<iv.get(100)<<std::endl;
//}
//   catch(char* strg){
//        std::cout<<"Caught the exception: "<< strg <<std::endl;}

   //-------------------------------------------------------------------------

   // test CharacterVector: put, get, size, out_of_range

   std::cout << std::endl;
   std::cout << "----------------" << std::endl;
   std::cout << "CharacterVector:" << std::endl;
   cv.put('a',0);
   cv.put('b',1);
   std::cout << "Put test: "<< std::endl;
   for(int i = 0; i < cv.size(); i++) {
	std::cout << cv.get(i) << std::endl;
   }
   std::cout << "Size test: " << cv.size() << std::endl;
   try{
       	std::cout << cv.get(100)<< std::endl;

      }
   catch(const std::invalid_argument& e){
        std::cout << "Out of range exception: " << e.what() << std::endl;
}
   std::cout << "----------------" << std::endl;

   //-------------------------------------------------------------------------

   // test DoubleVector: put, get, size, out_of_range

   std::cout << std::endl;
   std::cout << "-------------" << std::endl;
   std::cout << "DoubleVector:" << std::endl;
   std::cout << "-------------" << std::endl;
//put tests
	dv.put(2.,293854);
	dv.put(4);
	dv.put(5);
	dv.put(7., 1);

	std::cout << "Put test: ";
	for(int i = 0; i < dv.size(); i++) {std::cout << dv.get(i);}
	std::cout << " [275]" << std::endl;

	std::cout << "Size test: " << dv.size() << " [3]" << std::endl;

try{
	std::cout << "Get test: " << dv.get(2) << " [5]" << std::endl;	
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
   std::cout << iv2.get(iv.size() - 1) << std::endl;
   iv2.appendDoubleVector(dv);
   std::cout << iv2.get(iv.size() - 1) << std::endl;
   std::cout << "----------------------------" << std::endl;
   std::cout << "--------------------------" << std::endl;

   //-------------------------------------------------------------------------

   // using empty CharacterVector, test appending iv & dv from above
   CharacterVector cv2;

   std::cout << std::endl;
   std::cout << "----------------------------" << std::endl; 
   std::cout << "appended-to CharacterVector:" << std::endl;
   cv2.appendIntegerVector(iv);
   cv2.appendDoubleVector(dv);
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
	std::cout << "[1] [97] [98]" << std::endl;
    //-------------------------------------------------------------------------

   return 0;
}
