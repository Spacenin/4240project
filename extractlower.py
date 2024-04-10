import sys


#gets lower bits from a number
def extract_lower_bits(value):
    #8 bits is arbitrary
    return value & 0xFF

def main(input_file):
    x_values = []
    y_values = []
    z_values = []

    #iterate through file
    with open(input_file, 'r') as file:
        lines = file.readlines()
        for i in range(0, len(lines), 4):


            if i + 3 >= len(lines):
                break  

            # get the values
            x = int(lines[i + 1].split(': ')[1])
            y = int(lines[i + 2].split(': ')[1])
            z = int(lines[i + 3].split(': ')[1])
            
            # get the low bits
            x_values.append(extract_lower_bits(x))
            y_values.append(extract_lower_bits(y))
            z_values.append(extract_lower_bits(z))
    
    # stick em in output files
    with open('x.txt', 'w') as x_file:
        for value in x_values:
            x_file.write(str(value) + '\n')

    with open('y.txt', 'w') as y_file:
        for value in y_values:
            y_file.write(str(value) + '\n')

    with open('z.txt', 'w') as z_file:
        for value in z_values:
            z_file.write(str(value) + '\n')



if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("python extractlower.py <input_file>")
        sys.exit(1)
    
    input_file = sys.argv[1]
    main(input_file)