from asyncio import sleep
import random
import time
import datetime
import os  
 

# --------------------- note:: class body---------------------
class carsDetail:
    c1 = {
        "name": "Hyundai",
        "model": "BR-V",
        "color": "Red",
        "seats": "4 Seats",
        "max_speed": "180 Km/h",
        "available": 3,
        "type": "Economy",
        "advance_amount": 150,
        "per_day_amount": 50,
    }

    c2 = {
        "name": "Ford",
        "model": "ECO-SPORT",
        "color": "black",
        "seats": "2 Seats",
        "max_speed": "180 Km/h",
        "available": 2,
        "type": "Standard",
        "advance_amount": 200,
        "per_day_amount": 80,
    }

    c3 = {
        "name": "Suzuki",
        "model": "SWIFT",
        "color": "yellow",
        "seats": "4 Seats",
        "max_speed": "165 Km/h",
        "available": 4,
        "type": "cheap",
        "advance_amount": 250,
        "per_day_amount": 110,
    }

    c4 = {
        "name": "Audi",
        "model": "A6-SERIES",
        "color": "Blue",
        "seats": "2 Seats",
        "max_speed": "250 Km/h",
        "available": 1,
        "type": "luxury",
        "advance_amount": 300,
        "per_day_amount": 140,
    }

    c5 = {
        "name": "Tesla",
        "model": "MODEL-S",
        "color": "Red",
        "seats": "4 Seats",
        "max_speed": "322 Km/h",
        "available": 2,
        "type": "luxury",
        "advance_amount": 350,
        "per_day_amount": 170,
    }

    c6 = {
        "name": "Lexus",
        "model": "RX 400",
        "color": "Brown",
        "seats": "4 Seats",
        "max_speed": "200 Km/h",
        "available": 3,
        "type": "luxury",
        "advance_amount": 400,
        "per_day_amount": 200,
    }

    c7 = {
        "name": "Mercedes",
        "model": "BENZ-S",
        "color": "Silver",
        "seats": "2 Seats",
        "max_speed": "250 Km/h",
        "available": 1,
        "type": "luxury",
        "advance_amount": 450,
        "per_day_amount": 230,
    }

    c8 = {
        "name": "Toyota",
        "model": "VIGO",
        "color": "Black",
        "seats": "4 Seats",
        "max_speed": "180 Km/h",
        "available": 5,
        "type": "Standard",
        "advance_amount": 500,
        "per_day_amount": 260,
    }

    c9 = {
        "name": "BMW",
        "model": "X3-SERIES",
        "color": "grey",
        "seats": "2 Seats",
        "max_speed": "240 Km/h",
        "available": 2,
        "type": "luxury",
        "advance_amount": 520,
        "per_day_amount": 290,
    }

    cars = [c1, c2, c3, c4, c5, c6, c7, c8, c9]


# --------------------- note:: class body---------------------


# --------------------- note:: class body---------------------
class personDetail:
    def __init__(self, name, nationalID, address, job):
        self.name = name
        self.nationalID = nationalID
        self.address = address
        self.job = job

    def getINFO(self):
        os.system("cls")
        print("\n\t\t\t\t----------------------------------------------")
        print("\t\t\t\t           Enter Your credentials               ")
        print("\t\t\t\t----------------------------------------------")
        self.name = input("\t\t\t\tEnter Your name: ")
        self.nationalID = int(input("\t\t\t\tEnter Your nationalID: "))
        self.address = input("\t\t\t\tEnter Your address: ")
        self.job = input("\t\t\t\tEnter Your job title: ")
        print("\n\t\t\t\t----------------------------------------------")
        try:
            f = open(
                "E:\\Code Playground\\Python Workspace\\6th semester\\Car Rental\\Info.txt",
                "a",
            )
            f.write("\n\n")
            f.write(f"Customer Details:")
            f.write(f"\nName:        {self.name.title()}")
            f.write(f"\nNational ID: {self.nationalID}")
            f.write(f"\nAddress:   {self.address}")
            f.write(f"\nJob title: {self.job}")
            f.close()
        except:
            print("Person credentials could not be saved")

    def displayPersonDetails(self):
        os.system("cls")
        print("\n\t\t\t\t----------------------------------------------")
        print(f"\t\t\t\tName : {self.name.title()}")
        print(f"\t\t\t\tNational ID No : {self.nationalID}")
        print(f"\t\t\t\tAddress : {self.address}")
        print(f"\t\t\t\tJob title : {self.job.title()}")
        print("\n\t\t\t\t----------------------------------------------")


# --------------------- note:: class body---------------------

# --------------------- note:: outside classes and function---------------------
userchoice = None
selected_car = None
no_of_rent_days = None
# --------------------- note:: outside classes and function---------------------


def menu():
    os.system("cls")
    print("\n\t-------------------------------------------------------------------------------------------------------------")
    print("\t\t\t\t            WELCOME TO SIMPLE CAR RENTAL SYSTEM")
    print("\t-------------------------------------------------------------------------------------------------------------")
    global userchoice
    carMenu = carsDetail()
    print(
        "\t{:<12} || {:<12} || {:<20} || {:<10} || {:<10} || {:<12} || {:<12}".format(
            "Brand",
            "Model",
            "Comfort & Luxuriness",
            "Color",
            "Seats",
            "Max Speed",
            "Available",
        )
    )

    for car in carMenu.cars:
        print(
            "\t{:<12}    {:<12}    {:<20}    {:<10}    {:<10}    {:<12}    {:<12}".format(
                car["name"],
                car["model"],
                car["type"],
                car["color"],
                car["seats"],
                car["max_speed"],
                car["available"],
            )
        )
    print("\t-------------------------------------------------------------------------------------------------------------")
    userchoice = input("\n\t\t\t\tPlease select your choice: ").strip()
    
    validate = any(car['name'].lower() == userchoice.lower() for car in carMenu.cars)
    if not validate:
        print("\n\t\t\t\tInvalid input, try again!")
        time.sleep(1)
        menu()


def displayCarDetails():
    os.system("cls")
    carDet = carsDetail()
    global selected_car
    global userchoice
    global no_of_rent_days
    print("\n\t\t\t\t----------------------------------------------")
    print("\t\t\t\t                 Car Details                  ")
    print("\t\t\t\t----------------------------------------------")
    # selected_car = None
    for car in carDet.cars:
        if car['name'].lower() == userchoice.lower():
            selected_car = car
            break

    if selected_car:
        print(f"\t\t\t\tyou have selected: {selected_car['name']}")
        print(f"\t\t\t\tModel: {selected_car['model']}")
        print(f"\t\t\t\tColor: {selected_car['color']}")
        print(f"\t\t\t\tMax Speed: {selected_car['max_speed']}")
        print(f"\t\t\t\tNo of Seats: {selected_car['seats']}")
        print("\n\t\t\t\t----------------------------------------------\n")
        cho = input("\t\t\t\tcontinue or go back(c/b): ")
        if cho.lower() == "b":
            menu()
            displayCarDetails()
        else:
            no_of_rent_days = int(input("\t\t\t\tHow many days you want to rent the car: "))
            try:
                f = open(
                    "E:\\Code Playground\\Python Workspace\\6th semester\\Car Rental\\Info.txt",
                    "a",
                )
                f.write("\n\n")
                f.write(f"\nCar Rented Details:")
                f.write(f"\nRented Car :{selected_car['name']}")
                f.write(f"\ntModel: {selected_car['model']}")
                f.write(f"\nColor: {selected_car['color']}")
                f.write(f"\nMax Speed: {selected_car['max_speed']}")
                f.write(f"\nNo of Seats: {selected_car['seats']}")
                f.close()
            except:
                print("Car details could not be saved")
            else:
                print("\t\t\t\tCar not found, please select a valid car brand.")


cardetails = carsDetail()

def bill():
    os.system("cls")
    temp = datetime.datetime.now()
    date = temp.date()
    time = temp.time()
    os.system("color E5")
    print("\n\t\t\t\t----------------------------------------------")
    print("\t\t\t\t         Car Rental - Customer Invoice          ")
    print("\t\t\t\t----------------------------------------------")
    print(f"\t\t\t\t{date.strftime("%x")}                           {time.strftime("%X")} {time.strftime("%p")}")
    print("\t\t\t\t----------------------------------------------\n")
    print(f"\t\t\t\t| Invoice Number:       {random.randint(10000,20000):6}")
    print(f"\t\t\t\t| Customer Name:         {personset.name.title()}")
    print(f"\t\t\t\t| Customer National ID:  {personset.nationalID}")
    print(f"\t\t\t\t| Advance Amount:        {selected_car['advance_amount']} $")
    print(f"\t\t\t\t| Rental Amount:         {selected_car['per_day_amount']} $")
    print(f"\t\t\t\t| Miscellaneous charges: 0 $")
    print(
        f"\t\t\t\t| Total Bill:            {selected_car['advance_amount']+(selected_car['per_day_amount'] * no_of_rent_days)} $"
    )
    print(f"\n\t\t\t\tThis is a computer generated invoice")
    print("\n\n\t\t\t\tNote:")
    print("\t\t\t\tYou are advised to pay up the amount before due date.")
    print("\t\t\t\tOtherwise penalty fee will be applied\n\n")
    print("\n\t\t\t\t----------------------------------------------")
    try:
        f = open("E:\\Code Playground\\Python Workspace\\6th semester\\Car Rental\\Bill.txt","a")
        f.write(f"\n\nBill Details:")
        f.write(f"\n{date.strftime("%x")}                           {time.strftime("%X")} {time.strftime("%p")}")
        f.write(f"\n| Invoice Number:       {random.randint(10000,20000):6}")
        f.write(f"\n| Customer Name:         {personset.name.title()}")
        f.write(f"\n| Customer National ID:  {personset.nationalID}")
        f.write(f"\n| Advance Amount:        {selected_car['advance_amount']} $")
        f.write(f"\n| Rental Amount:         {selected_car['per_day_amount']} $")
        f.write(f"\n| Miscellaneous charges: 0 $")
        f.write(f"\n| Total Bill:             {selected_car['advance_amount']+(selected_car['per_day_amount'] * no_of_rent_days)} $")
    except:
        print("Bill could not be saved")

while True:
    os.system("color 60")
    menu()
    displayCarDetails()
    personset = personDetail("", 13, "", "")
    personset.getINFO()
    bill()
    cho = input("\n\t\t\t\t\tDo you want to Continue(y/n): ")
    if cho == "N" or cho == "n":
        break
