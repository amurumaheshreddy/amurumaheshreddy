# This function find_move_to_end() checks if the element num is present in numbers.
# If present then moves the element to the last and returns the tuple else returns the same tuple unchanged.
def find_move_to_end(numbers,num):
    # in operator checks whether num is present in numbers or not.
    # If present returns true else returns false.
    if(num in numbers):
        # We first create a tuple with all the elements before num from the start using slice operator.
        # In slice operator the end index in exclusive.
        data = numbers[:numbers.index(num)]
        # Next we add all elements after the num using the slice operator till the end.
        data += numbers[numbers.index(num)+1:]
        # Then finally we add the num at last.
        # We cannot add a single number as it is into the tuple so we add a comma at the end.
        # If we add a comma at the end then the num is considered as tuple else it considers as an integer and throws an error.
        data+=(num,)
        # At last we return the changed tuple.
        return data
    # else if the num is not present in the numbers then we return the unchanged tuple.
    else:
        return numbers
    
#We have created a tuple with elements in it.   
numbers = (4, -1, 0, 3, 6, 10)
# Finally we have called the find_move_to_end function.
print(find_move_to_end(numbers,1))
