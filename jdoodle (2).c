#include <stdio.h>
#define FILENAME "data.csv"
#include <stdlib.h>
typedef struct {
  int id;
  char color[10];
  double grams;
} record_t;

record_t data[] = {
  { 123, "red", 1.23 },
  { 456, "green", 4.56},
  { 789, "blue", 7.89}
};

int main(void) {
  printf("CSV File\n");
  printf("Code by Levi Leichtfuss\n");

  size_t num_records = sizeof(data) / sizeof(data[0]);

  printf("Writing a total of %lu records to %s\n", num_records, FILENAME);

  // Open FIle
  FILE *file = fopen(FILENAME, "w");
  if (NULL == FILENAME) {
    perror("fopen");
    return 1;
  }

  // Write Contents to file
   for (size_t i = 0; i < num_records; i++) {
    fprintf(file, "%d,%s,%.2f\n", data[i].id, data[i].color, data[i].grams);
  }
  
  // Close FIle
  fclose(file);

  // Show Results
  system("cat ./" FILENAME);
  return 0;
}