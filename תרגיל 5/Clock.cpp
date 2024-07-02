#include "Clock.h"
#include <string>

Clock::Clock(int h, int m, int s) {
	if (s < 0)
		throw "Invalid time - negative number of seconds.\n";
	else if(s > 59)
		throw "Invalid time - more than 60 seconds.\n";
	else if(m < 0)
		throw "Invalid time - negative number of minutes.\n";
	else if(m > 59)
		throw "Invalid time - more than 60 minutes.\n";
	else if(h < 0)
		throw "Invalid time - negative number of hours.\n";
	else if(h > 23)
		throw "Invalid time - more than 24 hours.\n";
	else
	this->hour = h,
	this->minute = m,
	this->second = s;
}

void Clock::setHour(int h) {
 if (h < 0)
	throw "Invalid time - negative number of hours.\n";
else if (h > 23)
throw "Invalid time - more than 24 hours.\n";
else
this->hour = h;
}

void Clock::setMinute(int m) {
	 if (m < 0)
		throw "Invalid time - negative number of minutes.\n";
	else if (m > 59)
		throw "Invalid time - more than 60 minutes.\n";
	else
		this->hour = m;
}

void Clock::setSecond(int s) {
	 if (s < 0)
		throw "Invalid time - negative number of seconds.\n";
	else if (s > 59)
		throw "Invalid time - more than 60 seconds.\n";
	else
		this->hour = s;
}

int Clock::gethour() {
	return hour;
}

int Clock::getminute() {
	return minute;
}

int Clock::getsecond() {
	return second;
}

bool Clock::equals(Clock c) {
	if(this->hour == c.gethour() && 
		this->minute == c.getminute() &&
		this->second == c.getsecond())
			return true;
		else
			return false;
}

bool Clock::before(Clock c) {
	if (this->hour < c.gethour())
		return true;
	else if (this->hour == c.gethour() && this->minute < c.getminute())
		return true;
	else if (this->hour == c.gethour() && this->minute == c.getminute() && this->second < c.getsecond())
		return true;
	else
		return false;
}

bool Clock::after(Clock c) {
if (this->hour > c.gethour())
		return true;
	else if (this->hour == c.gethour() && this->minute > c.getminute())
		return true;
	else if (this->hour == c.gethour() && this->minute == c.getminute() && this->second > c.getsecond())
		return true;
	else
		return false;
}

Clock Clock::operator+=(int sec) {
	if (sec >= 0) {
		if(this->second + sec > 59) {
			this->minute += (this->second + sec) / 60;
			this->second = (this->second + sec) % 60;
			if (this->minute > 59) {
				this->hour += this->minute / 60;
				this->minute = this->minute % 60;
				if (this->hour > 23) {
					this->hour = this->hour % 24;
				}
			}
		}
		else
			this->second += sec;
		return *this;
	}
	else
		throw "Invalid time - negative number of seconds.\n";
}

istream& operator>>(istream& is, Clock& c) {
	int h, m, s;
	char junk1, junk2;
	is >> h >> junk1 >> m >> junk2 >> s;
	if (junk1 == ':' &&
		junk2 == ':' &&
		h >= 0 && h < 23 &&
		m >= 0 && m < 59 &&
		s >= 0 && s < 59) {
		c = Clock(h, m, s);
	}
	return is;
}

ostream& operator<<(ostream& os, const Clock& c) {
	os << (c.hour < 10 ? "0" : "") << c.hour << ":"
		<< (c.minute < 10 ? "0" : "") << c.minute << ":"
		<< (c.second < 10 ? "0" : "") << c.second;
	return os;
}
