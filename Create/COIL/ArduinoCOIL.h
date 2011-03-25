/*
 * ArduinoCOIL.h
 *
 *  Created on: Mar 14, 2011
 *      Author: abraham
 */

#ifndef ARDUINOCOIL_H_
#define ARDUINOCOIL_H_

#include <QObject>
#include <QString>
#include <QThread>

#include "qextserialport/qextserialport.h"

typedef unsigned char	byte;

class ArduinoCOIL : public QObject
{
	Q_OBJECT
public:
	ArduinoCOIL(QString portName);
	virtual ~ArduinoCOIL();

	int cwrite (QextSerialPort *port, byte* buf, int numbytes);
	int cread (QextSerialPort *port, byte* buf, int numbytes);

public:

		/** \brief Sensor trail for data verification
		 *
		 * Comments
		 */
		typedef enum
		{
			TRAILER									= 0x23,
			CARRIAGE_RETURN							= 0x0D
		}seeyou_verification;

	 	/** \brief Sensor packet constants
	     *
	     * Comments
	     */
	    typedef enum
	    {
	    	SENSOR_UNKNOWN                           = 0x30,
			SENSOR_IR_0,
			SENSOR_IR_1,
			SENSOR_IR_2,
			SENSOR_IR_3,
			SENSOR_LED_INDICATOR,
			SENSOR_COMPASS,
			SENSOR_LEFT_PINGER,
			SENSOR_RIGHT_PINGER
	    }seeyou_sensor;





private:
	QextSerialPort *port;
	static int debug;			//< debug mode status

public:
    int setBaud (BaudRateType rate);
    int stopOI ();
    int setLEDState ();
    int readRawSensor (byte* buffer, int size);
    int readRawSensor (seeyou_sensor packet, byte* buffer, int size);
    int readSensor (seeyou_sensor packet);
    int readCompass();
    int readLeftPinger();
    int readRightPinger();
    int readInfraredFront();
    void enableDebug();
    void disableDebug();


};

#endif /* ARDUINOCOIL_H_ */