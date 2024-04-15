


import random
import argparse



#yoooo read all values from a file and store in array
def read_values(filename):
    with open(filename, 'r') as inputfile:
        values = [int(line.strip()) for line in inputfile]
    return values


def generate_random_numbers(x_values, y_values, z_values, upper_bound, lower_bound):
    while True:
        #grabs random value from the 3 files
        x = random.choice(x_values)
        y = random.choice(y_values)
        z = random.choice(z_values)

        seed_value = x + y + z
        random.seed(seed_value)

        random_number = random.randint(lower_bound, upper_bound)
        return random_number
        
def calculate_variance(data):
    n = len(data)
    mean = sum(data) / n
    variance = sum((x - mean) ** 2 for x in data) / n
    return variance

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-l", type=int)
    parser.add_argument("-u", type=int)
    parser.add_argument("-n", type=int)
    args = parser.parse_args()

    if args.l is None:
        lower_bound = 0
    else:
        lower_bound = args.l
    if args.u is None:
        upper_bound = 1000
    else:
        upper_bound = args.u
    if args.n is None:
        num_rands = 1
    else:
        num_rands = args.n

    #read the files and save
    x_values = read_values('x.txt')
    y_values = read_values('y.txt')
    z_values = read_values('z.txt')

    
    rands = []
    x = 0
    while x < num_rands:
        random_number = generate_random_numbers(x_values, y_values, z_values, upper_bound, lower_bound)
        print(random_number)
        rands.append(random_number)
        x = x+1

    variance = calculate_variance(rands)
    print("Variance:", variance)

    return (rands)


if __name__ == "__main__":
    main()