/*
	RoboCore Ultrasonic sensor Library
		(v1.0 - 30/03/2017)

  Ultrasonic sensor functions for Arduino
    (tested with Arduino 1.6.5)

  Copyright 2017 RoboCore (Hallszombie) ( http://www.RoboCore.net )
  
  ------------------------------------------------------------------------------
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
  ------------------------------------------------------------------------------
*/

#include "Arduino.h"
#include "Ultrasonic.h"

HC_SR04::HC_SR04(uint8_t pintrigger, uint8_t pinecho)
{
	pinMode(pintrigger,OUTPUT);
	pinMode(pinecho,INPUT);
	_pintrigger = pintrigger;
	_pinecho = pinecho;

}

uint16_t HC_SR04::distance()
{
	digitalWrite(_pintrigger,LOW);
	delayMicroseconds(2);
	digitalWrite(_pintrigger,HIGH);
	delayMicroseconds(10);
	digitalWrite(_pintrigger,LOW);

 	return pulseIn(_pinecho,HIGH)/59;
}
