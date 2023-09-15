#ifndef __INCLUDE_BREAKPAD_LITE_MAIN_H__
#define __INCLUDE_BREAKPAD_LITE_MAIN_H__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

void* regExceptionHandler();
void unregExceptionHandler(void* handle);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __INCLUDE_BREAKPAD_LITE_MAIN_H__