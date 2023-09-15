#ifndef __INCLUDE_BREAKPAD_LITE_MAIN_H__
#define __INCLUDE_BREAKPAD_LITE_MAIN_H__

#if defined(__GNUC__)
#	ifdef BREAKPAD_LITE_EXPORT
#		define BREAKPAD_LITE_API __attribute__((visibility("default")))
#	else
#		define BREAKPAD_LITE_API
#	endif
#else
#	ifdef BREAKPAD_LITE_EXPORT
#		define BREAKPAD_LITE_API __declspec(dllexport)
#	else
#		define BREAKPAD_LITE_API __declspec(dllimport)
#	endif
#endif

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

BREAKPAD_LITE_API void* regExceptionHandler();
BREAKPAD_LITE_API void unregExceptionHandler(void* handle);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __INCLUDE_BREAKPAD_LITE_MAIN_H__