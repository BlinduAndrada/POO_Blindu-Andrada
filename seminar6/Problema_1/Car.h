#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include "Libs.h"

class Car {

	
public:
	virtual ~Car() = 0;
	virtual float carTime(bool&, int, int) = 0; 
	virtual char* GetName()const = 0; //metoda virtuala, neimplementata

};

#endif // !CAR_H_INCLUDED

