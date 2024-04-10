


import random

#yoooo read all values from a file and store in array
def read_values(filename):
    with open(filename, 'r') as inputfile:
        values = [int(line.strip()) for line in inputfile]
    return values


def generate_random_numbers(x_values, y_values, z_values):
    while True:
        #grabs random value from the 3 files
        x = random.choice(x_values)
        y = random.choice(y_values)
        z = random.choice(z_values)

        seed_value = x + y + z
        random.seed(seed_value)

        random_number = random.randint(0, 1000)
        return random_number
        

def main():
    #read the files and save
    x_values = read_values('x.txt')
    y_values = read_values('y.txt')
    z_values = read_values('z.txt')

    random_number = generate_random_numbers(x_values, y_values, z_values)

    print(random_number)
    return (random_number)


if __name__ == "__main__":
    main()