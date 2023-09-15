#include "breakpadlite.h"

#include "client/windows/handler/exception_handler.h"

static bool dumpCallback(const wchar_t* dump_path,
                         const wchar_t* minidump_id,
                         void* context,
                         EXCEPTION_POINTERS* exinfo,
                         MDRawAssertionInfo* assertion,
                         bool succeeded) {
  wprintf(L"Minidump path: %i :: %s/%s\n", succeeded, dump_path, minidump_id);
  return succeeded;
}

google_breakpad::ExceptionHandler* g_breakpadExceptionHandler = NULL;
void* regExceptionHandler() {
  CreateDirectory(TEXT("./dump_dir"), NULL);

  g_breakpadExceptionHandler = new google_breakpad::ExceptionHandler(
      L"./dump_dir", NULL, dumpCallback, NULL,
      google_breakpad::ExceptionHandler::HANDLER_ALL);
  return g_breakpadExceptionHandler;
}

void unregExceptionHandler(void* handle) {
  if (handle) {
    delete g_breakpadExceptionHandler;
    g_breakpadExceptionHandler = NULL;
  }
}
