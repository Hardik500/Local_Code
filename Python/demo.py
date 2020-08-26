def main():
    largest = -9223372036854775808
    smallest = 9223372036854775807

    while(True):
        try:
            x = input()
            if(x == "done"):
                print("Maximum is ",largest)
                print("Minimum is ",smallest)
                break
            elif(not x.isdigit()):
                raise ValueError('Please enter a valid number')
            else:
                x = int(x)
                largest = max(largest, x)
                smallest = min(smallest, x)
        except Exception as error:
            print(repr(error))


if __name__ == "__main__":
    main()
