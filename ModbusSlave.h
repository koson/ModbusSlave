/*
  ModbusSlave.cpp - Libreria modbus RTU esclavo sobre linea serie
  Copyright (c) 2012 Raimundo Alfonso
  Ray Ingeniería Electrónica, S.L.
  Basada en la librería Modbus By Juan Pablo Zometa: jpmzometa@gmail.com
  http://sites.google.com/site/jpmzometa/
  Samuel Marco: sammarcoarmengol@gmail.com
  and Andras Tucsni.
  
  Esta librería está basada en software libre. Tu puedes redistribuir
  y/o modificar esta librería bajo los terminos de licencia GNU.

  Esta biblioteca se distribuye con la esperanza de que sea útil,
  pero SIN NINGUNA GARANTÍA, incluso sin la garantía implícita de
  COMERCIALIZACIÓN O PARA UN PROPÓSITO PARTICULAR.
  Consulte los terminos de licencia GNU para más detalles.
*/

#ifndef ModbusSlave_h
#define ModbusSlave_h

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif


/* enum of supported modbus function codes. If you implement a new one, put its function code here ! */
enum { 
		FC_READ_REGS  = 0x03,   //Read contiguous block of holding register
        FC_WRITE_REG  = 0x06,   //Write single holding register
        FC_WRITE_REGS = 0x10,   //Write block of contiguous registers
        FC_READ_COILS_REGS  = 0x01   //Read contiguous block of coils		
};

/* constants */
enum { 
        MAX_READ_REGS = 0x7D, 
        MAX_WRITE_REGS = 0x7B, 
        MAX_MESSAGE_LENGTH = 256 
};


enum { 
        RESPONSE_SIZE = 6, 
        EXCEPTION_SIZE = 3, 
        CHECKSUM_SIZE = 2 
};

/* exceptions code */
enum { 
        NO_REPLY = -1, 
        EXC_FUNC_CODE = 1, 
        EXC_ADDR_RANGE = 2, 
        EXC_REGS_QUANT = 3, 
        EXC_EXECUTE = 4 
};

/* positions inside the query/response array */
enum { 
        SLAVE = 0, 
        FUNC, 
        START_H, 
        START_L, 
        REGS_H, 
        REGS_L, 
        BYTE_CNT 
};



/* supported functions. If you implement a new one, put its function code into this array! */
const unsigned char fsupported[] = { FC_READ_REGS, FC_WRITE_REG, FC_WRITE_REGS, FC_READ_COILS_REGS};
	

class ModbusSlave{
	public:
	ModbusSlave();
	ModbusSlave(byte);
	
	void actualiza(int *, unsigned int);
	void config(long, char);
	void port(int);	
	int direccion;
	
	private:
 };


#endif