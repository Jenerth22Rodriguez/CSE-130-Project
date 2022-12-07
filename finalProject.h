/*
I think this could be our main header file for the final project.  We can add functions to include in our main program from other
files here.
*/

// Generates a randomized CarInventory.csv file.  Returns true on successful file creation, false on failure.
// Takes one argument, an integer defining how many cars will be created.
// Omits the headers (Dealer Inventory Number,Auto VIN,...) from the created file, however data is in the format:
// Dealer Inventory Number,Auto VIN,Make,Model,Exterior Color,Interior Color,Transmission Type,Retail Price
// each car is on its own line
bool generateCSV(long int cars);