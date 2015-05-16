The Tariff class defines the different tariffs ( Regular rate, Late night rate, Weekend rate...). Each of them is defined by a single instance.
Tariff classes can be added later for new rates. 

The destination class defines the multipliers for different destinations. Currently the Local (x1) and the International (x2) destinations are available.

The customer rate class defines the tariff maps for different customer levels. New Customers have a discounted Regular Rate tariff, while existing customers use the default tariff map.

The call_history class contains a log_entry class which provides details for a particular call log. The call duration in minutes, the call tariff class, the call destination class are saved for each log_entry. The call_history maintains a list of all call log_entries for a particular customer.
The log_entry class has a method get_cost() defined to provide the cost of a particular log_entry based on a customer tariff map.
THe call_history class has a get_total_cost() defined to provide the cost of all log_entries contained in the call_history.

The customer class defines a customer object. They can be identified via a unique phone number. They have a customer_rate class defined to store their tariff maps. and a call history is defined for each customer.
The get_customer_cost() function can be used to obtain the cost per customer.


