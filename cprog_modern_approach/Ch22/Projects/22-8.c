#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
  int number;
  int on_hand;
  char name[NAME_LEN+1];
} inventory[MAX_PARTS];

int num_parts = 0;   /* number of parts currently stored */

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void dump(void);
void load(void);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'i': insert();
                break;
      case 's': search();
                break;
      case 'u': update();
                break;
      case 'p': print();
                break;
      case 'd': dump();
                break;
      case 'l': load();
                break;
      case 'q': return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

/**********************************************************
 * find_part: Looks up a part number in the inventory     *
 *            array. Returns the array index if the part  *
 *            number is found; otherwise, returns -1.     *
 **********************************************************/
int find_part(int number)
{
  int i;

  for (i = 0; i < num_parts; i++)
    if (inventory[i].number == number)
      return i;
  return -1;
}

/**********************************************************
 * insert: Prompts the user for information about a new   *
 *         part and then inserts the part into the        *
 *         database. Prints an error message and returns  *
 *         prematurely if the part already exists or the  *
 *         database is full.                              *
 **********************************************************/
void insert(void)
{
  int part_number;

  if (num_parts == MAX_PARTS) {
    printf("Database is full; can't add more parts.\n");
    return;
  }

  printf("Enter part number: ");
  scanf("%d", &part_number);
  if (find_part(part_number) >= 0) {
    printf("Part already exists.\n");
    return;
  }

  inventory[num_parts].number = part_number;
  printf("Enter part name: ");
  read_line(inventory[num_parts].name, NAME_LEN);
  printf("Enter quantity on hand: ");
  scanf("%d", &inventory[num_parts].on_hand);
  num_parts++;
}

/**********************************************************
 * search: Prompts the user to enter a part number, then  *
 *         looks up the part in the database. If the part *
 *         exists, prints the name and quantity on hand;  *
 *         if not, prints an error message.               *
 **********************************************************/
void search(void)
{
  int i, number;

  printf("Enter part number: ");
  scanf("%d", &number);
  i = find_part(number);
  if (i >= 0) {
    printf("Part name: %s\n", inventory[i].name);
    printf("Quantity on hand: %d\n", inventory[i].on_hand);
  } else
    printf("Part not found.\n");
}

/**********************************************************
 * update: Prompts the user to enter a part number.       *
 *         Prints an error message if the part doesn't    *
 *         exist; otherwise, prompts the user to enter    *
 *         change in quantity on hand and updates the     *
 *         database.                                      *
 **********************************************************/
void update(void)
{
  int i, number, change;

  printf("Enter part number: ");
  scanf("%d", &number);
  i = find_part(number);
  if (i >= 0) {
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);
    inventory[i].on_hand += change;
  } else
    printf("Part not found.\n");
}

/**********************************************************
 * print: Prints a listing of all parts in the database,  *
 *        showing the part number, part name, and         *
 *        quantity on hand. Parts are printed in the      *
 *        order in which they were entered into the       *
 *        database.                                       *
 **********************************************************/
void print(void)
{
  int i;

  printf("Part Number   Part Name                  "
         "Quantity on Hand\n");
  for (i = 0; i < num_parts; i++)
    printf("%7d       %-25s%11d\n", inventory[i].number,
           inventory[i].name, inventory[i].on_hand);
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  dump
 *  Description:  dump contents of inventory to file
 * =====================================================================================
 */
void dump(void) {
    FILE *fp;
    char filename[NAME_LEN];
    int i;

    printf("Enter name of output file: ");
    read_line(filename, NAME_LEN);

    // open file for writing
    fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "could not open file for writing");
        exit(EXIT_FAILURE);
    }

    // write
    for (i = 0; i < num_parts; i++) {
        // for each item in inventory
        // write each part - number, on_hand, and name
        fprintf(fp, "%d ", inventory[i].number);
        fprintf(fp, "%d ", inventory[i].on_hand);
        fprintf(fp, "%s\n", inventory[i].name);
    }

    rewind(fp);
    fclose(fp);
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  load
 *  Description:  load inventory from file saved by a previous call of dump()
 * =====================================================================================
 */
void load(void) {
    FILE *fp;
    char filename[NAME_LEN], buf[sizeof(struct part)];
    int i, num_written = 0;
    
    // get filename
    printf("Enter filename to load: ");
    read_line(filename, NAME_LEN);

    if ((fp = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "could not open file for reading");
        exit(EXIT_FAILURE);
    }

    // read file into inventory
    for (i = 0; i < MAX_PARTS; i++) {
        if (feof(fp)) {
            break;
        }
        fgets(buf, sizeof(struct part), fp);
        sscanf(buf, "%d %d %s\n", &inventory[i].number, &inventory[i].on_hand, inventory[i].name);
    }

    // check read status, exit
    rewind(fp);
    fclose(fp);
}
