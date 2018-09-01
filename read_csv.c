/* ***********
* Created by Jordan Puckridge 24/08/2018
*
* Read and parse .csv input for Olympic Athlete data
*/


/* read from a file and input the data to a struct? */

#define BUFFER_SIZE 512

void read_csv_into_struct(char *filename, struct *olympian){

  /* use fgets to parse the whole string then sscanf to break up the format */
  char[BUFFER_SIZE] temp_string;
  if( (fgets(temp_string, BUFFER_SIZE, filename)) != NULL)
  {
    sscanf(
      filename, "%d,%[^,],%c,%d,%f,%f,%[^,],%[$,],%[^,],%d,%[^,],%[^,],%[^,],%[^,],%[^]\n",
      olympian->id;
      olympian->name;
      olympian->sex;
      olympian->age;
      olympian->height;
      olympian->weight;
      olympian->team_name;
      olympian->NOC;
      olympian->games;
      olympian->year;
      olympian->season;
      olympian->city;
      olympian->sport;
      olympian->event;
      olympian->medal;
      )
  }

}

// Do i read the csv and then convert to data?
// No, need to read in each line as a insert the function?
//Read a single line?
