/*
 * Helium DBusKit: a simple Cocoa binding to libdbus
 *
 * Copyright (C) 2021 Zoe Knox <zoe@pixin.net>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#import <Foundation/NSObject.h>
#import "DKConnection.h"
#import "DKMessage.h"

@interface DKMenu: NSObject {
    DKConnection *connection;
    uint32_t layoutVersion;
    BOOL _pathWasRegistered;
    NSString *menuObjectPath;
}

- initWithConnection: (DKConnection *)conn;
- (NSString *)objectPath;
- (BOOL) registerWindow: (uint32_t)windowID objectPath: (NSString *)path;
- (BOOL) registerWindow: (uint32_t)windowID;
- (BOOL) unregisterWindow: (uint32_t)windowID;
- (NSString *) getMenuForWindow: (uint32_t)windowID;
- (void) getLayout: (DKMessage *)message;
- (void) layoutDidUpdate;
- (void) itemPropertiesDidUpdate;
@end
