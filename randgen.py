

import random

#yoooo read the value from the file and save that shit
def read_values(filename):
    with open(filename, 'r') as inputfile:
        values = [int(line.strip()) for line in inputfile]
    return values

#get those numbers queen
def generate_random_numbers(x_values, y_values, z_values):
    while True:
        #basically loop through and grab the first value 
        #and save it to the corresponding var
        for x, y, z in zip(x_values, y_values, z_values):
            # i just did addition? idk i feel like we might should do something more complex
            seed_value = x + y + z
            random.seed(seed_value)
            #should we take a range as input from the user?
            random_number = random.randint(0, 1000)
            yield random_number

def main():
    #read the files and save as a array thingy (is it an array in python?)
    x_values = read_values('x.txt')
    y_values = read_values('y.txt')
    z_values = read_values('z.txt')

    random_number_generator = generate_random_numbers(x_values, y_values, z_values)

    #this is super basic user interface
    #we can totally do something more fun though
    input("Press Enter")

    try:
        while True:
            random_number = next(random_number_generator)
            print(random_number)
            input("Another?")
    #if you ctrl c yah know?
    except KeyboardInterrupt:
        print("\nExiting...kachow")

if __name__ == "__main__":
    main()
