//
//  AppDelegate.m
//  EDSunriseSet
//
//  Created by Christian Haudum on 09/08/2012.
//  Copyright (c) 2012 Christian Haudum. All rights reserved.
//

#import "AppDelegate.h"
#import "EDSunriseSet.h"

@implementation AppDelegate

@synthesize window;
@synthesize locationManager;

- (void)dealloc {
  [window release];
  [locationManager release];
  [super dealloc];
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  self.window = [[[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]] autorelease];
  // Override point for customization after application launch.
  self.window.backgroundColor = [UIColor whiteColor];
  [self.window makeKeyAndVisible];
  
  self.locationManager = [[[CLLocationManager alloc] init] autorelease];
  [locationManager setDesiredAccuracy:kCLLocationAccuracyKilometer];
  [locationManager setDelegate:self];
  [locationManager startUpdatingLocation];
  
  return YES;
}

- (void)applicationWillTerminate:(UIApplication *)application {
  [locationManager stopUpdatingLocation];
  [self setLocationManager:nil];
}

- (void)locationManager:(CLLocationManager *)manager didUpdateToLocation:(CLLocation *)newLocation fromLocation:(CLLocation *)oldLocation {
  if (oldLocation && newLocation && newLocation.horizontalAccuracy < 1000.0) {
    
    NSDate *now = [NSDate date];
    EDSunriseSet *sunRiseSet = [EDSunriseSet sunrisesetWithTimezone:[NSTimeZone localTimeZone] latitude:newLocation.coordinate.latitude longitude:newLocation.coordinate.longitude];
    [sunRiseSet calculate:now];
    
    NSCalendar *cal = [NSCalendar currentCalendar];
    
    NSLog(@"Local nautical civil twilight start   %@", [cal dateFromComponents:[sunRiseSet localNauticalCivilTwilightStart]]);
    NSLog(@"Local civil twilight start            %@", [cal dateFromComponents:[sunRiseSet localCivilTwilightStart]]);
    NSLog(@"Local sunrise                         %@", [cal dateFromComponents:[sunRiseSet localSunrise]]);
    NSLog(@"Local sunset                          %@", [cal dateFromComponents:[sunRiseSet localSunset]]);
    NSLog(@"Local civil twilight end              %@", [cal dateFromComponents:[sunRiseSet localCivilTwilightEnd]]);
    NSLog(@"Local nautical civil twilight end     %@", [cal dateFromComponents:[sunRiseSet localNauticalCivilTwilightEnd]]);
    
    [self.locationManager stopUpdatingLocation];
    [self setLocationManager:nil];
  } else {
    NSLog(@"Waiting for location ...");
  }
}

- (void)locationManager:(CLLocationManager *)manager didFailWithError:(NSError *)error {
  NSLog(@"Failed to receive location.");
  NSLog(@"%@", [error localizedDescription]);
}


@end
