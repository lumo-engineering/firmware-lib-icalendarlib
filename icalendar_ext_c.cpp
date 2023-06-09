#include "icalendar.h"
#include "icalendar_ext_c.h"

size_t icalendarlib_timestamp_s_to_str(const time_t timestamp_s, char *icalendarlib_str)
{
  time_t t = timestamp_s;
  struct tm *tm = localtime(&t);
  size_t n = strftime(icalendarlib_str, 16, "%Y%m%dT%H%M%S", tm);
  icalendarlib_str[n] = 0;
  return n;
}

time_t icalendarlib_str_to_timestamp_s(const char *ical_date)
{
  struct tm tm = {0};
  strptime(ical_date, "%Y/%m/%d %H:%M", &tm);
  return mktime(&tm);
}

bool icalendarlib_is_timestamp_s_within_any_event(const char *calendar_path, const time_t timestamp_s)
{
  ICalendar Calendar(calendar_path);
  Event *CurrentEvent;
  ICalendar::Query SearchQuery(&Calendar);

  char date[21];
  icalendarlib_timestamp_s_to_str(timestamp_s, date);

  std::string date_string(date);
  SearchQuery.Criteria.From = "19700101T000000";
  SearchQuery.Criteria.To = date_string;
  SearchQuery.ResetPosition();

  while ((CurrentEvent = SearchQuery.GetNextEvent(false)) != NULL) {
    const time_t start_timestamp_s = icalendarlib_str_to_timestamp_s(CurrentEvent->DtStart.Format().c_str());
    const time_t end_timestamp_s = icalendarlib_str_to_timestamp_s(CurrentEvent->DtEnd.Format().c_str());
    if (start_timestamp_s <= timestamp_s && timestamp_s <= end_timestamp_s) {
      return true;
    }
  }

  return false;
}
