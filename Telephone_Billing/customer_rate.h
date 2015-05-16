#ifndef __CUSTOMER_RATE_H_INCLUDED__
#define __CUSTOMER_RATE_H_INCLUDED__

#include "tariff.h"
#include <map>
#include <string>
//Define the rates for different cutomer types

class customer_rate
{
	private:
		std::map<std::string,float> tariff_map;
	protected:
		customer_rate(){
			//Initialize tariff Map
			tariff_map[regular_rate::getInstance()->get_name()]=regular_rate::getInstance()->get_rate();
			tariff_map[late_night_rate::getInstance()->get_name()]=late_night_rate::getInstance()->get_rate();
			tariff_map[weekend_rate::getInstance()->get_name()]=weekend_rate::getInstance()->get_rate();
		}
		void update_map(std::string name, float rate){
			tariff_map[name]=rate;
		}
	public:
		virtual float get_rate(std::string name){
			return tariff_map.find(name)->second;
		}
};
//Define a new customer tariff map
class new_customer_rate : public customer_rate
{
	private:
		new_customer_rate(){
			//Update the tariff map for new customer 
			//Discount the regular rate to the late night rate
			customer_rate::update_map(regular_rate::getInstance()->get_name(),late_night_rate::getInstance()->get_rate());
		}
	public:
		static new_customer_rate * singleton_instance;
		static new_customer_rate * getInstance()
		{
			if(!singleton_instance)
				singleton_instance=new new_customer_rate;
			return singleton_instance;
		}

};
//Define a tariff map for an existing customer
class existing_customer_rate : public customer_rate
{
	private:
		existing_customer_rate(){}
	public:
		static existing_customer_rate * singleton_instance;
		static existing_customer_rate * getInstance()
		{
			if(!singleton_instance)
				singleton_instance=new existing_customer_rate;
			return singleton_instance;
		}
};

new_customer_rate* new_customer_rate::singleton_instance = NULL;
existing_customer_rate* existing_customer_rate::singleton_instance = NULL;

#endif // __CUSTOMER_RATE_H_INCLUDED__
