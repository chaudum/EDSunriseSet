//
//  EDSunriseSet.h
//
//  Created by Ernesto García  on 20/08/11.
//  Copyright 2011 Ernesto García. All rights reserved.
//

//  C/C++ sun calculations created by Paul Schlyter
//  sunriset.c 
//  http://stjarnhimlen.se/english.html
//  SUNRISET.C - computes Sun rise/set times, start/end of twilight, and
//  the length of the day at any date and latitude
//  Written as DAYLEN.C, 1989-08-16
//  Modified to SUNRISET.C, 1992-12-01
//  (c) Paul Schlyter, 1989, 1992
//  Released to the public domain by Paul Schlyter, December 1992
//


#import <Foundation/Foundation.h>

@interface EDSunriseSet : NSObject {

@private
    double      _latitude;
    double      _longitude;

    NSCalendar  *_calendar;

    NSTimeZone  *_utcTimeZone;
    NSTimeZone  *_timezone;

    NSDate      *_sunrise;
    NSDate      *_sunset;
    NSDate      *_civilTwilightStart;
    NSDate      *_civilTwilightEnd;
    NSDate      *_nauticalTwilightStart;
    NSDate      *_nauticalTwilightEnd;
    NSDate      *_astronomicalTwilightStart;
    NSDate      *_astronomicalTwilightEnd;

}


- (EDSunriseSet *)initWithTimezone:(NSTimeZone *)timezone latitude:(double)lat longitude:(double)lng;
+ (EDSunriseSet *)sunrisesetWithTimezone:(NSTimeZone *)timezone latitude:(double)lat longitude:(double)lng;
- (void)calculateSunriseSunset:(NSDate *)date;
- (void)calculateTwilight:(NSDate *)date;
- (void)calculate:(NSDate *)date;
- (NSDateComponents *)localSunrise;
- (NSDateComponents *)localSunset;
- (NSDateComponents *)localCivilTwilightStart;
- (NSDateComponents *)localCivilTwilightEnd;
- (NSDateComponents *)localNauticalCivilTwilightStart;
- (NSDateComponents *)localNauticalCivilTwilightEnd;
- (NSDateComponents *)localAstronomicalTwilightStart;
- (NSDateComponents *)localAstronomicalTwilightEnd;

@property (readonly,retain) NSDate *sunset;
@property (readonly,retain) NSDate *sunrise;
@property (readonly,retain) NSDate *civilTwilightStart;
@property (readonly,retain) NSDate *civilTwilightEnd;
@property (readonly,retain) NSDate *nauticalTwilightStart;
@property (readonly,retain) NSDate *nauticalTwilightEnd;
@property (readonly,retain) NSDate *astronomicalTwilightStart;
@property (readonly,retain) NSDate *astronomicalTwilightEnd;

@end
