# ============= gyro=gy-521	MPU-6050(GY-521) accelerometer  0x68 or 0xE8

MPU6050 Pinout Configuration

Pin Number	Pin Name			Description
1		Vcc				Provides power for the module, can be +3V to +5V. Typically +5V is used
2		Ground				Connected to Ground of system
3		Serial Clock (SCL)		Used for providing clock pulse for I2C Communication
4		Serial Data (SDA)		Used for transferring Data through I2C communication
5		Auxiliary Serial Data (XDA)	Can be used to interface other I2C modules with MPU6050. It is optional
6		Auxiliary Serial Clock (XCL)	Can be used to interface other I2C modules with MPU6050. It is optional
7		AD0				If more than one MPU6050 is used a single MCU, then this pin can be used to vary the address
8		Interrupt (INT)			Interrupt pin to indicate that data is available for MCU to read.

    MEMS 3-aixs accelerometer and 3-axis gyroscope values combined
    Power Supply: 3-5V
    Communication : I2C protocol
    Built-in 16-bit ADC provides high accuracy
    Built-in DMP provides high computational power
    Can be used to interface with other IIC devices like magnetometer
    Configurable IIC Address
    In-built Temperature sensor


INT — настраиваемое прерывание;
AD0 — I2C адрес; по-умолчанию AD0 подтянут к земле, поэтому адрес устройства — 0x68; если соединить AD0 к контактом питания, то адрес изменится на 0x69;


Sensitivity UN  340
Temp Offset 35 -521

Temperature: TEMP_degC  = ((TEMP_OUT – RoomTemp_Offset)/Temp_Sensitivity) + 21degC
                                (T - (35'C=521))/340 + 21
                                (T - 521)/340+35

# ===============  compas=HMC5883L GY-273
