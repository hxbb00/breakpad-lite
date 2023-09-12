#include "breakpadlite.h"

#include "client/linux/handler/exception_handler.h"

static bool dumpCallback(const google_breakpad::MinidumpDescriptor& descriptor,
void* context, bool succeeded) {
  printf("Minidump path: %s\n", descriptor.path());
  return succeeded;
}

int regExceptionHandler() {
  google_breakpad::MinidumpDescriptor descriptor("./dump_dir");
  google_breakpad::ExceptionHandler eh(descriptor, NULL, dumpCallback, NULL, true, -1);
  return 0;
}