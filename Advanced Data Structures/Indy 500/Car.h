// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// raparks

#include <string>

class Car
{
	public:
		Car(); //constructor
		Car(std::string name, int speed, int control, int lapNumber);
		~Car(); //destructor
	
		//get and set functions
		std::string getName();
		void setName(std::string name);
		int getSpeed();
		void setSpeed(int speed);
		int getControl();
		void setControl(int control);
		int getLapNum();
		void setLapNum(int lapNumber);
		
	private:
		std::string name_;
		int speed_;
		int control_;
		int lapNumber_;
};