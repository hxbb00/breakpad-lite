#include "breakpadlite.h"

#include "client/linux/handler/exception_handler.h"

static bool dumpCallback(const google_breakpad::MinidumpDescriptor& descriptor,
void* context, bool succeeded) {
  printf("Minidump path: %s\n", descriptor.path());
  return succeeded;
}

google_breakpad::ExceptionHandler* g_breakpadExceptionHandler = NULL;
void* regExceptionHandler() {
  google_breakpad::MinidumpDescriptor descriptor("./dump_dir");
  g_breakpadExceptionHandler = new google_breakpad::ExceptionHandler(descriptor, NULL, dumpCallback, NULL, true, -1);
  return g_breakpadExceptionHandler;
}

void unregExceptionHandler(void* handle){
  if(handle){
    delete g_breakpadExceptionHandler;
    g_breakpadExceptionHandler = NULL;
  }
}