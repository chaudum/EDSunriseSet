//
//  AppDelegate.h
//  EDSunriseSet
//
//  Created by Christian Haudum on 09/08/2012.
//  Copyright (c) 2012 Christian Haudum. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate, CLLocationManagerDelegate>

@property (strong, nonatomic) UIWindow *window;
@property (retain, nonatomic) CLLocationManager *locationManager;

@end
