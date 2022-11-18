InventoryGen.cpp contains code for two functions:

randInt()
    Takes no arguments and returns a random number in the range 1-100
    of type int.

generateCSV(long int cars)
    Seeds the random number genorator "rand()" function with system time when called
    Returns boolean :
        True upon successfull creation of CSV 
        False if creation fails
    Takes a single argument, of type long int
        This argument is the number of cars to generate in the format of
        Dealer Inventory Number,Auto VIN,Make,Model,Exterior Color,Interior Color,Transmission Type,Retail Price
    Each car has these values on a single line in a CarInventory.csv file.
    Each value is separated by a comma, no trailing comma at EOL
    Theese values are defined as follows

    Dealer Inventory Number:
        Are line numbers for all the cars in the file, starting at 0
    
    Auto VIN:
        Random 10 digit number
    
    Make:
        One of 8 possible strings defined in arrays within InventoryGen.cpp

    Model:
        One of 4 possible strings defined in arrays within InventoryGen.cpp
        These sets of 4 are specific to each model 

    Exterior color:
        One of 9 possible strings defined in array within InventoryGen.cpp
        can be one of any: "Red", "White", "Black", "Blue", "Green", "Orange", "Silver", "Yellow", "Gold"

    Interior color:
        One of 9 possible strings defined in array within InventoryGen.cpp
        can be one of any: "Red", "White", "Black", "Blue", "Green", "Orange", "Silver", "Yellow", "Gold"
    
    Transmission type:
        can be either automatic or manual

    Retail price:
        A randomly generated number 
        

    Tweakables:
        **car model and make arrays should not be tweaked***

        basePrice:
            multiplied by random number 1-100 and value multiplier to create car price
        
        lowValueBrandsMult:
            Value multiplier for low value brands
            see basePrice

        highValueBrandsMult:
            Value multiplier for high value brands
            see basePrice

        valueRatio:
            ratio of high value cars to low value cars
        
        transRatio:
            Ratio of manual to automatic transmission types
