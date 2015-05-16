#include<string.h>
#ifndef __STACK_H_INCLUDED__
#define __STACK_H_INCLUDED__

#define DEFAULT_STACK_SIZE 10
template <class T>
class Stack {
	public:
		//Constructor
		Stack(int size = DEFAULT_STACK_SIZE) :
			stack_index(0), stack_memory(new T[size]), stack_capacity(size)  
		{};
		//Stack Push
		void push(T elem)
		{
			//Resize stack if at memory exhausted
			if (stack_index == stack_capacity)
				stack_resize(2 * stack_capacity);
			stack_memory[stack_index++] = elem;
		}
		//Stack Pop
		T pop()
		{	
			//Throw exception if empty stack
			if(stack_index==0)
				throw "Empty Stack";
			return stack_memory[--stack_index];
		}
		//Resize stack with twice the previous size
		void stack_resize(int size)
		{
			if (size > stack_capacity)
			{
				T* temp = new T[size];
				memcpy(temp,stack_memory,stack_capacity*sizeof(T));
				delete[] stack_memory;
				stack_memory=temp;
				stack_capacity = size;
			}
		}

	private:
		//Pointer to stack variables
		T* stack_memory; 
		//Index to stack pointer
		int stack_index;
		//Stack capacity
		int stack_capacity;
};
#endif //__STACK_H_INCLUDED__
