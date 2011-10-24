#ifndef TIMER_H
#define TIMER_H

#include <ctime>

/**
 * Class representing a simple timer. 
 * This class is useful for measuring rendering times etc.
 */
class Timer
{
public:
	/// Constructs a timer initialized to the current time.
	Timer() : mStart(std::clock()) { }
	
	/// Starts the timer.
	void start() { mStart = std::clock(); }
	
	/// Stops the timer and returns the time in seconds since the object was
	/// constructed, or since last call to start().
	float stop() { return (float)(std::clock()-mStart)/(float)CLOCKS_PER_SEC; }

protected:
	std::clock_t mStart;		///< Start time in ticks.
};

#endif
