/*
 * typedefs.h
 *
 * 2019/12/08
 *
 * Redefine types for easier use
 *
 */


#ifndef __TYPEDEFS_H__
  #define __TYPEDEFS_H__


  #ifndef STD_ON
    #define STD_ON 1
  #endif /* STD_ON */

  #ifndef STD_OFF
    #define STD_OFF 0
  #endif /* STD_OFF */

  #ifndef TRUE
    #define TRUE 1
  #endif /* TRUE */

  #ifndef FALSE
    #define FALSE 0
  #endif /* FALSE */


/* For character variable will be used char keyword so there is no
 * mixxing types between characters and 8-bit integers              */

  //boolean
  typedef unsigned char boolean;


  //signed integer 8-bit
  typedef char sint8;

  //unsigned integer/char 8-bit
  typedef unsigned char uint8;


  //signed integer 16-bit
  typedef short int sint16;

  //unsigned integer 16-bit
  typedef unsigned short int uint16;


  //signed integer 32-bit
  typedef int sint32;

  //unsigned integer 32-bit
  typedef unsigned int uint32;


#endif /* __TYPEDEFS_H__ */