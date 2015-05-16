#include<iostream>
#include<string>


#ifndef __TARIFF_H_INCLUDED__
#define __TARIFF_H_INCLUDED__


#define REGULAR_RATE 	0.05 
#define LATE_NIGHT_RATE 0.02
#define WEEKEND_RATE 	0.01

//tariff class - Defines the type of rates

class tariff
{
	private:
		float rate;	  //Define the rate per minute
		std::string name; //Define the name of the tariff
	protected:
		tariff(std::string name_val, float rate_val)
			:name(name_val),
			rate(rate_val)
	{};
	public:
		virtual float get_rate(){return rate;};
		virtual std::string get_name(){return name;}
};
//Define a regular_rate tariff
class regular_rate : public tariff
{
	private:
		regular_rate(float rate_val = REGULAR_RATE):
			tariff("REGULAR",REGULAR_RATE){};
	public:
		static regular_rate* singleton_instance;
		static regular_rate * getInstance(){
			if(!singleton_instance)
				singleton_instance = new regular_rate;
			return singleton_instance;
		}
};
//Define a late night tariff
class late_night_rate : public tariff
{
	private:
		late_night_rate(float rate_val = LATE_NIGHT_RATE):
			tariff("LATE_NIGHT",LATE_NIGHT_RATE){};
	public:
		static late_night_rate* singleton_instance;
		static late_night_rate * getInstance(){
			if(!singleton_instance)
				singleton_instance = new late_night_rate;
			return singleton_instance;
		}
};
//Define a weekend tariff
class weekend_rate : public tariff
{
	private:
		weekend_rate(float rate_val = WEEKEND_RATE):
			tariff("WEEKEND",WEEKEND_RATE){};
	public:
		static weekend_rate* singleton_instance;
		static weekend_rate * getInstance(){
			if(!singleton_instance)
				singleton_instance = new weekend_rate;
			return singleton_instance;
		}
};
regular_rate* regular_rate::singleton_instance = NULL;
late_night_rate* late_night_rate::singleton_instance = NULL;
weekend_rate* weekend_rate::singleton_instance = NULL;

#endif // __TARIFF_H_INCLUDED
