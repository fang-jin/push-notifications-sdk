/*
 * Copyright (C) 2001-2012 Ideaworks3D Ltd.
 * All Rights Reserved.
 *
 * This document is protected by copyright, and contains information
 * proprietary to Ideaworks Labs.
 * This file consists of source code released by Ideaworks Labs under
 * the terms of the accompanying End User License Agreement (EULA).
 * Please do not use this program/source code before you have read the
 * EULA and have agreed to be bound by its terms.
 */
/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
#ifndef S3E_EXT_PUSHWOOSH_H
#define S3E_EXT_PUSHWOOSH_H

#include <s3eTypes.h>

//typedef int32 (*pushRegisteredCallback)(char* token, void* userData);
//typedef int32 (*pushRegisterErrorCallback)(char* token, void* userData);
//typedef int32 (*pushReceivedCallback)(char* msg, void* userData);

enum s3ePushWooshCallback
{
	S3E_PUSHWOOSH_REGISTRATION_SUCCEEDED,
	S3E_PUSHWOOSH_REGISTRATION_ERROR,
	S3E_PUSHWOOSH_MESSAGE_RECEIVED,
	S3E_PUSHWOOSH_CALLBACK_MAX
};
// \cond HIDDEN_DEFINES
S3E_BEGIN_C_DECL
// \endcond

/**
 * Returns S3E_TRUE if the PushWoosh extension is available.
 */
s3eBool s3ePushWooshAvailable();

/**
 * Registers a callback to be called for an operating system event.
 *
 * The available callback types are listed in @ref s3ePushWooshCallback.
 * @param cbid ID of the event for which to register.
 * @param fn callback function.
 * @param userdata Value to pass to the @e userdata parameter of @e NotifyFunc.
 * @return
 *  - @ref S3E_RESULT_SUCCESS if no error occurred.
 *  - @ref S3E_RESULT_ERROR if the operation failed.\n
 *
 * @see s3ePushWooshUnRegister
 * @note For more information on the system data passed as a parameter to the callback
 * registered using this function, see the @ref s3ePushWooshCallback enum.
 */
s3eResult s3ePushWooshRegister(s3ePushWooshCallback cbid, s3eCallback fn, void* userData);

/**
 * Unregister a callback for a given event.
 * @param cbid ID of the callback for which to register.
 * @param fn Callback Function.
 * @return
 * - @ref S3E_RESULT_SUCCESS if no error occurred.
 * - @ref S3E_RESULT_ERROR if the operation failed.\n
 * @note For more information on the systemData passed as a parameter to the callback
 * registered using this function, see the s3ePushWooshCallback enum.
 * @note It is not necessary to define a return value for any registered callback.
 * @see s3ePushWooshRegister
 */
s3eResult s3ePushWooshUnRegister(s3ePushWooshCallback cbid, s3eCallback fn);

/**
 * Returns S3E_TRUE if PushWooshNotifications extension is available.
 */
s3eBool s3ePushWooshNotificationsAvailable();

/**
 * Registers for push notifications.
 */
s3eResult s3ePushWooshNotificationRegister();

/**
 * Returns push notifications token if available
 */
char * s3ePushWooshGetToken();

/**
 * Unregisters from push notifications (Android only)
 */
s3eResult s3ePushWooshNotificationUnRegister();

s3eResult s3ePushWooshNotificationSetIntTag(const char * tagName, int tagValue);

s3eResult s3ePushWooshNotificationSetStringTag(const char * tagName, const char * tagValue);

S3E_END_C_DECL

#endif /* !S3E_EXT_PUSHWOOSH_H */
