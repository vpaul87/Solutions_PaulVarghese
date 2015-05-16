#ifndef __CALL_HISTORY_H_INCLUDED__
#define __CALL_HISTORY_H_INCLUDED__

#include <vector>
#include "tariff.h"
#include "destination.h"
#include "customer_rate.h"

//Define a class that contains the per call details
class log_entry
{
	private:
		float duration;			//Duration of call
		tariff* rate_val;		//Tariff of call
		destination* destination_val;	//Destination of call
	public:
		log_entry(float temp=0.0,destination *temp_des=local_destination::getInstance(),tariff* temp_tariff = regular_rate::getInstance())
			:duration(temp),
			destination_val(temp_des),
			rate_val(temp_tariff)
	{};
		float get_cost(customer_rate* cust){
			//Calcuate the cost of the call
			return (duration)*(cust->get_rate(rate_val->get_name()))*(destination_val->get_destination_multiplier());
		}
};
//Define a call log for a customer
class call_history
{
	private:
		std::vector <log_entry> history;
	public:
		call_history(){};
		call_history(std::vector <log_entry> history_val )
			:history(history_val)
		{};
		//Add a call log entry to the log
		void add_log_entry(log_entry temp){
			history.push_back(temp);
		}
		//Get the total cost of the customer
		float get_total_cost(customer_rate* cust){
			float total_cost = 0.0;
			for(int ii =0;ii<history.size();++ii)
				total_cost += history[ii].get_cost(cust);
			return total_cost;
		}
};

#endif // __CALL_HISTORY_H_INCLUDED__
