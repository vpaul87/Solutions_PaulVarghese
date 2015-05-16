#ifndef __CUSTOMER_H_INCLUDED__
#define __CUSTOMER_H_INCLUDED__

#include "call_history.h"

class customer
{
	private:
		int phone_number;
		call_history customer_history;
		customer_rate * type;
	public:
		customer(int temp_phone=0,call_history temp_history=call_history(),customer_rate* temp_type=new_customer_rate::getInstance())
			:phone_number(temp_phone),
			customer_history(temp_history),
			type(temp_type){};
		float get_customer_cost(){
			return customer_history.get_total_cost(type);
		}
};


#endif // __CUSTOMER_H_INCLUDED__
