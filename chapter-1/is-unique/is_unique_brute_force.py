import sys

def is_unique(input):
    pass

def main(argv):
    if (len(argv) is not 2):
        print("[ERROR]\tPlease enter a single string as input.")
        return -1
    input = argv[1]
    print("[DBG]\tYour input:", input)

if __name__ == "__main__":
    main(sys.argv)