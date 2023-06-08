#ifndef ICALENDAR_EXT_H
#define ICALENDAR_EXT_H

#include <time.h>

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus
  size_t icalendarlib_timestamp_s_to_str(const time_t epoch_time_s, char *date);
  time_t icalendarlib_str_to_timestamp_s(const char *ical_date);
  bool icalendarlib_is_timestamp_s_within_any_event(const char *calendar_path, const time_t epoch_time_s);
#ifdef __cplusplus
}
#endif // __cplusplus

#endif // ICALENDAR_EXT_H
