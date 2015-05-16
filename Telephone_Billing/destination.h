#ifndef __DESTINATION_H_INCLUDED__
#define __DESTINATION_H_INCLUDED__

#define LOCAL_MULT 		1.0
#define INTERNATIONAL_MULT 	2.0 

//Define the destinations 
//Local calls have a multiplier of 1 and international calls double the rate per minute

class destination
{
	private:
		float destination_multiplier;	//Define the destination multiplier
	protected:
		destination(float destination_multiplier_val = LOCAL_MULT)
			:destination_multiplier(destination_multiplier_val){}; //Constructor
	public:	
		virtual float get_destination_multiplier(){return destination_multiplier;}	//Return the destination multiplier rate
};
//Define a local destination for local calls
class local_destination : public destination
{
	private:	
		local_destination(float multiplier = LOCAL_MULT)
			:destination(multiplier){};
	public:
		static local_destination* singleton_instance;
		static local_destination * getInstance(){
			if(!singleton_instance)
				singleton_instance = new local_destination;
			return singleton_instance;
		}

};
//Define an international destination for international calls
class international_destination : public destination
{
	private:
		international_destination(float multiplier = INTERNATIONAL_MULT)
			:destination(multiplier){};
	public:
		static international_destination* singleton_instance;
		static international_destination * getInstance(){
			if(!singleton_instance)
				singleton_instance = new international_destination;
			return singleton_instance;
		}

};
local_destination* local_destination::singleton_instance = NULL;
international_destination* international_destination::singleton_instance = NULL;


#endif //__DESTINATION_H_INCLUDED__
