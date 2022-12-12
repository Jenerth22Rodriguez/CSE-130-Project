/*
Generates randomized car data based on Jenerth's original CSV format.
This will make the dealership feel more complete when it is finished.
*/

#include <stdio.h>
#include <cstdlib>
#include <time.h>
//#include "../finalProject.h"
#include <math.h>
#include <string>
#include <vector>
#include <iostream>
// multipliers for cost of cars depending on brand
#define lowValueBrandsMult 1
#define highValueBrandsMult 3
// ratio of manuals to autos
#define transRatio 0.3
// ratio of high to low value cars
#define valueRatio 0.2
// base price for car price generation
#define basePrice 600
// definitions of brands and possible models for brands
const std::string highValueBrands[] = {"Mercedes", "BMW", "Tesla", "Audi"};
const std::string lowValueBrands[] = {"Toyota", "Mazda", "Honda", "Ford"};
const std::string Ford[] = {"MUSTANG", "F-150", "Windstar", "Focus"};
const std::string Honda[] = {"Civic", "Accord", "Passport", "Ridge"};
const std::string Mazda[] = {"Miata", "Mazda3", "CX-50", "Mazda3 Hatchback"};
const std::string Toyota[] = {"Camry", "Corolla", "Frontier", "Yaris"};
const std::string Audi[] = {"A7", "A3", "A8", "e-tron"};
const std::string Tesla[] = {"Model S", "Model Y", "Model X", "Model 3"};
const std::string BMW[] = {"X3", "M8 Competition", "M2", "Z4 Roadster"};
const std::string Mercedes[] = {"GLA", "G-Class", "Maybach", "AMG GT"};
// possible colors
const std::string colors[9] = {"Red", "White", "Black", "Blue", "Green", "Orange", "Silver", "Yellow", "Gold"};
// generates random integer 1-100
int randInt()
{
    // seeds pseudorandom gen to sys time

    return (rand() % 100 + 1);
}
// generates random VIN that is always greater than 10 digits
long long int randVin()
{
    long long int vin = randInt() * randInt() * 9223372036 * randInt();
    while (vin > 1000000000)
    {
        vin /= 10;
    }
    return vin;
}
// returns 3 string vector of car brand and car model and price
std::vector<std::string> randCar()
{
    std::vector<std::string> car;
    if (randInt() > 100 * valueRatio)
    {
        // low value regime
        const int i = randInt() % 4;
        switch (i)
        {
        case 0:
            car.assign({lowValueBrands[i], Toyota[(randInt() % 4)], (std::to_string(randInt() * basePrice * lowValueBrandsMult))});
            break;
        case 1:
            car.assign({lowValueBrands[i], Mazda[(randInt() % 4)], (std::to_string(randInt() * basePrice * lowValueBrandsMult))});
            break;
        case 2:
            car.assign({lowValueBrands[i], Honda[(randInt() % 4)], (std::to_string(randInt() * basePrice * lowValueBrandsMult))});
            break;
        case 3:
            car.assign({lowValueBrands[i], Ford[(randInt() % 4)], (std::to_string(randInt() * basePrice * lowValueBrandsMult))});
            break;
        }
    }
    else
    {
        // high value regime
        const int i = randInt() % 4;
        switch (i)
        {
        case 0:
            car.assign({highValueBrands[i], Mercedes[(randInt() % 4)], (std::to_string(randInt() * basePrice * highValueBrandsMult))});
            break;
        case 1:
            car.assign({highValueBrands[i], BMW[(randInt() % 4)], (std::to_string(randInt() * basePrice * highValueBrandsMult))});
            break;
        case 2:
            car.assign({highValueBrands[i], Tesla[(randInt() % 4)], (std::to_string(randInt() * basePrice * highValueBrandsMult))});
            break;
        case 3:
            car.assign({highValueBrands[i], Audi[(randInt() % 4)], (std::to_string(randInt() * basePrice * highValueBrandsMult))});
            break;
        }
    }
    return car;
}
bool generateCSV(long int cars)
{
    srand(time(0));
    // create pointer and open file
    FILE *csvFilePointer;
    csvFilePointer = fopen("CarInventory.csv", "w+");
    for (long int i = 0; i < cars; i++)
    {
        // generate random colors for this car
        const std::string interiorColor = colors[(randInt() % 9)];
        const std::string exteriorColor = colors[(randInt() % 9)];
        // determine transmission type for this car
        std::string transType;
        if (randInt() < 100 * transRatio)
        {
            transType = "Manual";
        }
        else
        {
            transType = "Automatic";
        }
        // get randomized car data
        std::vector<std::string> car = randCar();
        // get random VIN
        const long long int VIN = randVin();
        // compiles randomized values to a CSV string, then writes that to a new line in the csv file
        fprintf(csvFilePointer, "%ld,%0.10lld,%s,%s,%s,%s,%s,%s\n", i, VIN, car[0].c_str(), car[1].c_str(), exteriorColor.c_str(), interiorColor.c_str(), transType.c_str(), car[2].c_str());
    }
    // close file from editing
    fclose(csvFilePointer);
    // reopen file to check for its existence
    if ((csvFilePointer = fopen("CarInventory.csv", "r")))
    {
        return true;
    }
    else
    {
        return false;
    }
}
// main here for testing purposes only
// Can compile and run this file alone as part of the project check in, and then see the randomly generated
// CarInventory.csv file
int main()
{
    std::cout << generateCSV(100000);
}