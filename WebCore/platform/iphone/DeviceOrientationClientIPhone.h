/*
 * Copyright (C) 2010 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef DeviceOrientationClientIPhone_h
#define DeviceOrientationClientIPhone_h

#include "DeviceOrientationClient.h"
#include "DeviceOrientationController.h"
#include "DeviceOrientation.h"
#include <wtf/PassOwnPtr.h>
#include <wtf/RefPtr.h>

#ifdef __OBJC__
@class CoreMotionManager;
#else
class CoreMotionManager;
#endif

namespace WebCore {

class DeviceOrientationClientIPhone : public DeviceOrientationClient {
public:
    static PassOwnPtr<DeviceOrientationClientIPhone> create()
    {
        return adoptPtr(new DeviceOrientationClientIPhone());
    }
    DeviceOrientationClientIPhone();
    virtual ~DeviceOrientationClientIPhone();
    virtual void setController(DeviceOrientationController*);
    virtual void startUpdating();
    virtual void stopUpdating();
    virtual DeviceOrientation* lastOrientation() const;
    virtual void deviceOrientationControllerDestroyed();

    void orientationChanged(double, double, double, double, double);

private:
    CoreMotionManager* m_motionManager;
    DeviceOrientationController* m_controller;
    RefPtr<DeviceOrientation> m_currentDeviceOrientation;
    bool m_updating;
};

} // namespace WebCore

#endif // DeviceOrientationClientIPhone_h
