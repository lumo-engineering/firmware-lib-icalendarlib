#include <stdio.h>
#include <time.h>

#include "icalendar.h"

int main()
{
  printf("Is there any ongoing event: %s\n", is_timestamp_s_within_any_event("calendar.ics", 1686110600) ? "true" : "false");
  return 0;
}
