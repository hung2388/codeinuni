while 1:
    print("Tell me your car brand by typing the first letter of your car brand.")
    print("For example:")
    print("     BMW type B")
    print("     Toyota type T")
    print("     ...")
    x=input("Type the first letter of your car brand: ")
    x=x.lower()
    match x:
        case "l":
            print("100$")
        case "d":
            print("200$")
        case "f":
            print("300$")
        case "t":
            print("500$")
        case "b":
            print("500$")
        case "p":
            print("1000$")
        case "v":
            print("Nothing")
        case _:
            print("ERROR: we don't pay for this car")
    print("Do you want to insure another car")
    y=input("Type y for yes and n for no [y/n]")
    y=y.lower()
    if y=="n":
        print("Thanks for your patient")
        break


