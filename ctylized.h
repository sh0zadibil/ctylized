#ifndef CTYLIZED_H
#define CTYLIZED_H

#ifdef _WIN32
    #include <windows.h> // Required for Windows-specific console color manipulation. Implement Windows-specific functions if needed.
#else
    #include "include/func.h"
    #include "include/constants.h"
#endif
#endif