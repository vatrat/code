from sys import argv
from os.path import isfile


def parse_file(filename):
    with open(filename, 'r') as file:
        contents = file.read()
    lines = contents.split('\n')
    data = []
    for line in lines:
        sections = line.split(',')
        if len(sections) == 3:
            raw = sections[2]
            if raw not in ["Start bit", "Stop bit"]:
                data.append(raw)
    return data


def process_data(data):
    data_final = []
    for raw in data:
        if raw == "[0D]":
            data_final.append('\n')
        elif raw == "[0A]":
            pass
        else:
            data_final.append(raw)
    final = ''.join(data_final)
    return final

if __name__ == "__main__":
    try:
        if len(argv) == 1:
            while True:
                filename = raw_input("File to parse: ")
                if filename[-4:].lower() == ".csv" and isfile(filename):
                    break
                print """Not a proper file.
Enter a .csv file that exists and is in this directory."""
        else:
            filename = argv[1]
            if filename[-4:].lower() == ".csv" and isfile(filename):
                pass
            else:
                print """Not a proper file.
Enter a .csv file that exists and is in this directory."""
        data = parse_file(filename)
        final = process_data(data)
        file_out = filename[:-4] + "_out.txt"
        with open(file_out, 'w') as file:
            file.write(final)
        print final
    except Exception as e:
        print e
