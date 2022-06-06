import foo 
#defining the function clamp_all
def clamp_all(lst, low_bound, high_bound):
    #iterating over the list
    #to modify it inplace
    for i in range(len(lst)):
        #replacing the ith element with the result
        #from the clamp method in the foo module
        lst[i] = foo.clamp(lst[i], low_bound, high_bound)

#testcases
if __name__ == '__main__':
    lst = [12, -7, 16, 25, 99]
    clamp_all(lst, 10, 20)
    print(lst)
    lst = [12, -7, 16, 25, 99]
    clamp_all(lst, 40, 10)
    print(lst)
    lst = [24, 8, 16, 34, 9]
    clamp_all(lst, 40, 10)
    print(lst)