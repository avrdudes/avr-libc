/*
 * (C)2012 Michael Duane Rice All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer. Redistributions in binary
 * form must reproduce the above copyright notice, this list of conditions
 * and the following disclaimer in the documentation and/or other materials
 * provided with the distribution. Neither the name of the copyright holders
 * nor the names of contributors may be used to endorse or promote products
 * derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/* $Id$ */

/** \file */
	
/**    \defgroup avr_time <time.h>: Time
	\code #include <time.h> \endcode
	<h3>Introduction to the Time functions</h3>
    This file declares the time handling system that is implemented in \c avr-libc.
    
    The implementation attempts to conform to ISO/IEC 9899 (C90). However, since there is no 
    platform standard method to obtain the current time, time zone, or daylight savings 
    'rules', the application needs to initialize the time system with this information. 
	The functions set_zone(), set_dst(), and set_system_time() are provided for this intialization.
	
	Once initialized, system time may be maintained by calling system_tick() at one
	second intervals.
*/ 
#ifndef TIME_H
#define TIME_H

#ifdef __cplusplus
extern "C" {
#endif

#include <inttypes.h>
#include <stdlib.h>

/** \ingroup avr_time */
/*@{*/

/** 
	time_t represents seconds elapsed from Midnight, Jan 1 2000 UTC (the Y2K 'epoch'). 
	Its range allows time to be handled properly up to Tue Feb 6 01:28:15 2136.
*/
typedef uint32_t time_t;

/**
The time function returns the systems current time stamp.
If timer is not a null pointer, the return value is also assigned to the object it points to.
*/
time_t time( time_t *);	

/**
The difftime function returns the difference between two binary time stamps, 
time1 - time0.
*/
int32_t difftime(time_t time1, time_t time0); 


/**
	The tm structure contains a representation of time 'broken down' into its components.
	The normal ranges of the elements are..
	
\code
	tm_sec 		seconds after the minute - [0, 60]
	tm_min 		minutes after the hour - [0, 59]
	tm_hour 	hours since midnight - [0, 23]
	tm_mday 	day of the month - [1, 31]
	tm_wday 	days since Sunday - [0, 6]
	tm_mon		months since January - [0, 11]	
	tm_year 	years since 1900
	tm_yday 	days since January 1 - [0, 365]	
	tm_isdst	Daylight Saving Time flag

\endcode
	
	The value of tm_isdst is zero if Daylight Saving Time is not in effect, 
	negative if the information is not available. 
	If Daylight Saving Time is in effect, the value represents the number of 
	seconds the clock is advanced.

*/
struct tm{
	int8_t tm_sec; 		/* 	seconds after the minute - [0, 60] 		*/
	int8_t tm_min; 		/* 	minutes after the hour - [0, 59] 		*/
	int8_t tm_hour; 	/* 	hours since midnight - [0, 23]			*/
	int8_t tm_mday; 	/*	day of the month - [1, 31]				*/
	int8_t tm_wday; 	/*	days since Sunday - [0, 6]				*/
	int8_t tm_mon; 		/*	months since January - [0, 11]			*/
	int16_t tm_year; 	/*	years since 1900						*/
	int16_t tm_yday; 	/*	days since January 1 - [0, 365]			*/
	int16_t tm_isdst;	/*	Daylight Saving Time flag				*/
};


/**
This function 'compiles' the broken-down time, returning a time stamp.
The values of timeptr are interpreted as representing Local time.

The original values of the tm_wday and tm_yday components of the structure are ignored, 
and the original values of the other components are not restricted.

On successful completion, the values of all components of the structure are set to their appropriate ranges.
*/
time_t mktime(struct tm *timeptr); 

/**
This function 'compiles' the broken-down time, returning a time stamp.
The values of timeptr are interpreted as representing UTC.

The original values of the tm_wday and tm_yday components of the structure are ignored, 
and the original values of the other components are not restricted.
*/
time_t mk_gmtime(struct tm * timeptr);

/**
The gmtime function converts the time stamp pointed to by timer into broken-down time, 
expressed as UTC.
*/
struct tm *gmtime(const time_t *timer);

/**
	Re entrant version of gmtime(). 
*/
void gmtime_r(const time_t * timer, struct tm *timeptr);

/**
The localtime function converts the time stamp pointed to by timer into broken-down time, 
expressed as Local time.
*/
struct tm *localtime(const time_t *timer);

/**
	Re entrant version of localtime(). 
*/
void localtime_r(const time_t * timer, struct tm *timeptr);

/**
The asctime function converts the broken-down time of timeptr, into an ascii string in the form

	Sun Mar 23 01:03:52 2013
*/
char *asctime(const struct tm *timeptr); 

/**
	Re entrant version of asctime(). 
*/
void asctime_r(const struct tm *timeptr, char *buf);

/**
	The ctime function is equivalent to asctime(localtime(timer))
*/
char *ctime(const time_t *timer); 

/**
	Re entrant version of ctime(). 
*/
void ctime_r(const time_t *timer, char *buf);

/**
The isotime function converts the broken-down time of timeptr, into an ascii string in the form

	2013-03-23 01:03:52
*/
char * isotime(struct tm * tmptr);

/**
	Re entrant version of isotime()
*/
void isotime_r(struct tm *, char *);

/**
A complete description of strftime() is beyond the pale of this document. 
Refer to ISO/IEC document 9899 for details.

This implementation handles all conversions specified by the standard, with the exception of g, G, V, and Z.

All conversions are made in the 'C Locale', ignoring the E or O modifiers.
*/
size_t strftime(char * s, size_t maxsize, const char * format, const struct tm * timeptr);

/**
	Specify the Daylight Saving function.
	
	The Daylight Saving function should examine its parameters to determine whether
	Daylight Saving is in effect, and return a value appropriate for tm_isdst.
	
	Working examples for the USA and the EU are available..
		
		\code #include <util/eu_dst.h>\endcode
		for the European Union, and 
		\code #include <util/usa_dst.h>\endcode
		for the United States 
		
	If a Daylight Saving function is not specified, the system will ignore it.	
*/
void set_dst( int (*)(const time_t*, int32_t *));

/** 
	Set the 'time zone'. The parameter is given as seconds East of Greenwich.
	Example for New York City:
	\code set_zone(-5 * ONE_HOUR);\endcode
	
	If the time zone is not set, the time system will operate in UTC.
*/
void set_zone(int32_t);

/**
	Set the system time. The values of tmptr are interpreted as Local Standard Time.
*/
void set_system_time(struct tm * tmptr);

/**
	This function increments the system clock, and must be called at a rate of one Hertz 
	to maintain the system time.
*/
void system_tick(void);

/**
	This function increments the system clock, and must be called at a rate of one Hertz 
	to maintain the system time. This function is safe to be called from a 'naked' ISR...
	    
	    ISR(TIMER2_COMPA_vect, ISR_NAKED)
	    {
	        system_tick_i();
	        reti();
	    }
	    
	This is an experimental function not really meant for release. If it can be ensured to work in
	all cases, it should replace the original 'c' code system_tick().
*/
void system_tick_i(void);

enum _WEEK_DAYS_{
	SUNDAY,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY
} ;

enum _MONTHS_{
	JANUARY,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
} ;

/**
	Returns non-zero if year is a leap year.
	Returns zero otherwise.
*/
uint8_t is_leap_year( int16_t year);

/**
 	Returns the length of month, given the year and month, where month is in the range 1 to 12.
 */
uint8_t length_of_month(int16_t year, uint8_t month);

/**
 	Returns the calendar week of year, where the first week is considered to begin on the
 	day of week specified by 'start'. Thus, the returned value may range from zero to 52.
*/
uint8_t week_of_year(const struct tm * timeptr, uint8_t start);

/**
 	Returns the calendar week of month, where the first week is considered to begin on the
 	day of week specified by 'start'. Thus, the returned value may range from zero to 5.
*/
uint8_t week_of_month(const struct tm * timeptr, uint8_t start);

/**
	Convert a Y2K time stamp into a FAT file system time stamp.
*/
uint32_t fatfs_time(struct tm * timeptr);

/** One hour, expressed in seconds */
#define ONE_HOUR 3600

/** Angular degree, expressed in arc seconds */
#define ONE_DEGREE 3600

/** One day, expressed in seconds */
#define ONE_DAY 86400

/** Difference between the Y2K and the UNIX epochs, in seconds. To convert a Y2K
	timestamp to UNIX...
	\code
	long unix;
	time_t y2k;
	
	y2k = time(NULL);
	unix = y2k + UNIX_OFFSET;
	\endcode
*/
#define UNIX_OFFSET 946684800

/** Difference between the Y2K and the NTP epochs, in seconds. To convert a Y2K
	timestamp to NTP...
	\code
	unsigned long ntp;
	time_t y2k;
	
	y2k = time(NULL);
	ntp = y2k + NTP_OFFSET;
	\endcode
*/
#define NTP_OFFSET 3155673600

/*	===================================================================================
				Ephemera 
*/

/**
	Set the geographic coordinates of the 'observer', for use with several of the
	following functions. Parameters are passed as seconds of North Latitude, and seconds
	of East Longitude.
	
	For New York City...
	\code set_position( 40.7142 * ONE_DEGREE, -74.0064 * ONE_DEGREE); \endcode
*/
void set_position( int32_t latitude, int32_t longitude);

/**
	Computes the 'Equation of Time', which is the difference between apparent solar time and mean solar time.
	The returned value is in seconds.
*/
int16_t equation_of_time(time_t * timer);

/**
	Computes the amount of time the sun is above the horizon, at the location of the observer.
	
	NOTE: At observer locations inside the polar circles, this value can be zero during the winter,
	and can exceed ONE_DAY during the summer.
	
	The returned value is in seconds.
*/
int32_t daylight_seconds(time_t * timer );

/**
	Return the time of sunrise, at the location of the observer. See the note about daylight_seconds().
*/
time_t sun_rise(time_t * timer);

/**
	Return the time of sunset, at the location of the observer. See the note about daylight_seconds().
*/
time_t sun_set(time_t * timer);

/**	Returns the declination of the sun in radians. */
double solar_declination(time_t * timer);

/**
	Returns an approximation to the phase of the moon.
	The sign of the returned value indicates a waning or waxing phase.
	The magnitude of the returned value indicates the percentage illumination.
*/
int8_t moon_phase(time_t * timer);

/**
	Returns Greenwich Mean Sidereal Time, as seconds into the sidereal day.
	The returned value will range from 0 through 86399 seconds.
*/
unsigned long gm_sidereal(const time_t * timer);

/**
	Returns Local Mean Sidereal Time, as seconds into the sidereal day.
	The returned value will range from 0 through 86399 seconds.
*/
unsigned long lm_sidereal(const time_t * timer);

/*@}*/
#ifdef __cplusplus
}
#endif

#endif /*	TIME_H	*/
