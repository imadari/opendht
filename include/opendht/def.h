#pragma once

#if defined _WIN32 || defined __CYGWIN__
  #ifdef BUILDING_DLL
    #ifdef __GNUC__
      #define RING_PUBLIC __attribute__ ((dllexport))
    #else
      #define RING_PUBLIC __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #else
    #ifdef __GNUC__
      #define RING_PUBLIC __attribute__ ((dllimport))
    #else
      #define RING_PUBLIC __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #endif
  #define RING_LOCAL
#else
  #define RING_PUBLIC __attribute__ ((visibility ("default")))
  #define RING_LOCAL  __attribute__ ((visibility ("hidden")))
#endif
