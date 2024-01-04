/*
The code below doesn’t work as it’s supposed to. Fix the functions so that 
they work as the comments describe and don’t produce compiler errors or warnings, 
nor valgrind errors or memory leaks. The main function has no problems, and 
it cannot be changed. You can also assume that there are no mistakes with the road 
points and their handling in any way. The structures are also defined correctly, 
and no includes are missing. In general, the logic of the code is correct.

The program handles map data, more specifically roads. The program saves them in 
a Map structure, that holds a location name and an array of the roads. 
The Road structure holds the data for a single road, and stores the name of the road 
and a point (latitude-longitude pair) of the road.

There are six mistakes in the program, each of them clearly visible either in the 
compiler errors/warnings or valgrind output. Note that there might be more than one 
error/warning per mistake as a single mistake can create many problems at once.

There is one mistake in the createRoads function.
There are three mistakes in the createMap function.
There is one mistake in the printRoadInfo function.
There is one mistake in the freeMemory function.
*/

// --------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief A road structure that specifies the road location as 
 * latitude-longitude pair and its name
 */
typedef struct road {
	double point[2]; //!< The location of the road as latitude and longitude
	char* name;		 //!< The name of the road
} Road;

/**
 * \brief A map structure that holds the roads on a map location
 * 
 */
typedef struct map {
	Road* roads;   //!< The array of roads
	int roadCount; //!< Number of roads in the map location
	char locationName
		[41]; //!< The name of the location, which can have max 40 characters.
} Map;

/**
 * \brief Create an array of Road objects
 * 
 * \param roadNames  an array of road names
 * \param roadPoints an array of pairs of doubles that have the longitude-latitude pairs
 * \param roadCount The number of roads
 * \return An array of Road objects initialized using the data given as parameters
 */
Road* createRoads(char** roadNames, double roadPoints[][2], int roadCount) {

	// Allocate memory for roads, based on the given roadCount
	Road* roadArray = malloc(sizeof(Road) * roadCount);

	// Go through all the given data and store it in the array
	for(int i = 0; i < roadCount; i++) {
		// Allocate memory for the road name and copy it to the structure
		roadArray[i].name = malloc(strlen(roadNames[i]) + 1);
		strcpy(roadArray[i].name, roadNames[i]);

		// Copy the road point to the road, as lat-lon (from lon-lat)
		roadArray[i].point[1] = roadPoints[i][0];
		roadArray[i].point[0] = roadPoints[i][1];
	}

	return roadArray;
}

/**
 * \brief Create a Map object using the function arguments
 * 
 * \param locationName The name of the location
 * \param roadNames An array of the names of the roads
 * \param roadPoints An array of pairs of doubles that have the longitude-latitude pairs
 * \param roadCount The number of roads
 * \return The created Map object, which is dynamically allocated
 */
Map* createMap(char* locationName,
			   char** roadNames,
			   double roadPoints[][2],
			   int roadCount) {

	// We only accept location names with max. 40 characters
	if(strlen(locationName) > 40) {
		return NULL;
	}

	// Allocate memory for the Map structure
	Map* map = malloc(sizeof(Map));

	// Store the road amount
	map->roadCount = roadCount;

	// Store the location name
	strcpy(map->locationName, locationName);

	// Store the road information
	map->roads = createRoads(roadNames, roadPoints, roadCount);

	return map;
}

/**
 * \brief Prints road information for a Map object
 * 
 * \details This function prints the Map structure information in the following 
 * 			format:
 * 			
 * 			<place name> has the following roads:
 * 			Road named <road name> has point (latitude, longitude)
 * 			...
 * 
 * \param map The map object to be printed
 */
void printRoadInfo(Map* map) {
	printf("%s has the following roads:\n", map->locationName);

	// Loop through the roads and print their info
	for(int i = 0; i < map->roadCount; i++) {
		printf("Road named %s has point (%f, %f)\n",
			   map->roads[i].name,
			   map->roads[i].point[0],
			   map->roads[i].point[1]);
	}
}

/**
 * \brief Frees the dynamically allocated memory for a map object
 * 
 * \param map The object to be freed
 */
void freeMemory(Map* map) {
	// Free road name memory
	for(int i = 0; i < map->roadCount; i++)
		free(map->roads[i].name);

	free(map->roads);
	free(map);
}

/**
 * \brief Main function of the program
 * 
 * \return Returns 0
 */
int main() {
	// Original data for roads:
	// Names
	char* roadNames[] = {"Otaniementie",
						 "Servinkuja",
						 "Otakaari",
						 "Jämeräntaival",
						 "Konemiehentie",
						 "Tietotie",
						 "Maarintie"};

	// Points, a longitude-latitude pair from the road
	double roadPoints[][2] = {{24.828333109617233, 60.183956563100736},
							  {24.833828955888748, 60.190652085365116},
							  {24.826131016016006, 60.18603297448641},
							  {24.834622889757156, 60.187685874773706},
							  {24.823522567749023, 60.18826727050029},
							  {24.820438027381897, 60.18519015666757},
							  {24.819988757371902, 60.18665107158762}};

	// Create a map structure based on the data
	Map* map = createMap("Otaniemi", roadNames, roadPoints, 7);

	// Print roads information
	printRoadInfo(map);

	// Free the reserved memory
	freeMemory(map);

	return 0;
}