//!!! TODO:
//b and c of chapter 13, project 2

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60      /* max length of reminder message */

int read_line(char str[], int n);

int main(void)
{
  char reminders[MAX_REMIND][MSG_LEN+9];
  char day_str[12], msg_str[MSG_LEN+1];
  int month, day, hour, min, i, j, num_remind = 0;

  for (;;) {
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }

    printf("Enter month/day, time, and reminder: ");
    scanf("%02d/%02d", &month, &day);
    if (month == 0 || day == 0)
      break;
    else if (day < 0 || day > 31) {
        printf("invalid day\n");
        int ch;
        while ((ch = getchar()) != EOF && ch != '\n')
            ;
        continue;
    }
    scanf(" %02d: %02d", &hour, &min);
    sprintf(day_str, "%02d/%02d %02d:%02d", month, day, hour, min);
    read_line(msg_str, MSG_LEN);

    for (i = 0; i < num_remind; i++)
      if (strcmp(day_str, reminders[i]) < 0)
          break;
    for (j = num_remind; j > i; j--)
      strcpy(reminders[j], reminders[j-1]);

    strcpy(reminders[i], day_str);
    strcat(reminders[i], msg_str);

    printf("reminder: %s\n", reminders[i]);

    num_remind++;
  }

  printf("\nDay Reminder\n");
  for (i = 0; i < num_remind; i++)
    printf(" %s\n", reminders[i]);

  return 0;
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}
