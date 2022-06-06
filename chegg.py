# This function reads numbers from the file.
# Finds the sum of even elements and sum of odd elements.
# Returns a tuple with sum of even and odd elements.
def get_sum_evens_odds(filename):
    # We open the file in read mode.
    file = open(filename,"r")
    # We have initialzied odd and even to 0.
    # These stores the sum of odd and even elements respectively.
    odd = 0
    even = 0
    # Now we traverse through each line in the file.
    for line in file:
        # We split a line whenever space occurs.
        # Example: 18 19 20
        # split(' ') returns ['18','19','20']
        a = line.split(' ')
        # Now we traverse through this list a.
        for num in a:
            # We use strip() to remove all the new line character at the end.
            num = num.strip()
            # If the num is not an empty string.
            if(num!=''):
                # Then we convert the num to integer.
                num = int(num)
                # We check if num is an even number 
                # If yes then we add it to the even sum.
                if(num%2==0):
                    even+=num 
                # Else we add it to the odd sum.
                else:
                    odd+=num
    # We close the file after completing all the operations.
    file.close()
    # We create a tuple with even sum and odd sum as elements and return the tuple.
    return (even,odd)

# We have assigned the name of the file to filename  
filename = "rand_numbers1.txt"
# Next we call the get_sum_evens_odds() with the filename as a parameter.
value = get_sum_evens_odds(filename)
# prints the tuple that is returned by the function.
print(value)
# Prints the type of the value variable.
print(type(value))