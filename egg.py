def egg_cost(n,f):
    dozen=n//12 
    n=n-dozen*12
    if n!=11:
        cost=dozen*5+n*0.50 
    else:
        cost=(dozen+1)*5
    if f:
        cost=cost+0.20*cost 
    return cost 
if __name__=="__main__":
    print(egg_cost(27,False))
    print(egg_cost(2,True))
    print(egg_cost(35,True))
    print(egg_cost(35,True))