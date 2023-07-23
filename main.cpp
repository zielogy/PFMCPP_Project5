#include <iostream>
#include <string>
/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only
what you need to new projects you will learn how to write code that doesn't leak
as well as how to refactor.

NOTE: there are 2 sets of instructions:
       One for if you completed project 3
       One for if you skipped project 3.

 Destructors

===============================================================
 If you completed Project 3:

 1) Copy 3 of your user-defined types (the ones with constructors and
for()/while() loops from Project 3) here Choose the classes that contained
nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.
===============================================================
If you skipped Project 3:
write 3 UDTs below that EACH have:
        5 member variables
            the member variable names and types should be relevant to the work
the UDT will perform. pick properties that can be represented with 'int float
double bool char std::string' 3 member functions with an arbitrary number of
parameters give some of those parameters default values. constructors that
initialize some of these member variables the remaining member variables should
be initialized in-class for() or while() loops that modify member variables 1) 2
of your 3 UDTs need to have a nested UDT. this nested UDT should fulfill the
same requirements as above: 5 member variables 3 member functions constructors
and loops.

 2) Define your implementations of all functions OUTSIDE of the class.
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
===============================================================

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new
UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.
        maybe print out the name of the class being destructed, or call a member
function of one of the members.  be creative

 7) copy over your main() from the end of Project3
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.

 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.

 9) After you finish, click the [run] button.  Clear up any errors or warnings
as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list
of compiler arguments in the .replit file. all of the "-Wno" in that file are
compiler arguments. You can resolve any [-Wpadded] warnings by adding
-Wno-padded to the list of compiler arguments in the .replit file. all of the
"-Wno" in that file are compiler arguments.

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.

 */

/*
 copied UDT 1:
 */

struct IKEAStore {
  // 5 properties:
  //     1) list of article
  std::string listOfArticle[3];
  //     2) number of co worker
  int numOfCoWorker;
  //     3) average revenue per day
  float avgRevenuePerDay;
  //     4) number of stores
  int numOfStores;

  std::string storeName;

  IKEAStore();
  ~IKEAStore();

  struct Restaurant {
    //     1) number of waiter
    int numOfWaiter;
    //     2) count of revenue per day
    float revenuePerDay;
    //     3) number of chef
    int numOfChef;
    //     4) list of raw material
    std::string listOfRawMaterial[3];
    //     5) list of menu
    std::string listOfMenul[3];
    std::string restoName;

    Restaurant();
    ~Restaurant();

    // 3 things it can do:
    //     1) made food for customer
    void madeFood(std::string orderedMenu, int totalOrder);
    //     2) charge customer
    double customerBilling(int numOrderedMenu, int numCustomer,
                           float price); // return     customer billing
    //     3) serving customer
    void servingCustomer(int orderNumber, std::string orderedMenu);
  };

  // 3 things it can do:
  //     1) Delivery order to customer
  void deliverToCustomer(int totalOrder, std::string customerDetail,
                         std::string deliveryAddress);
  //     2) showcase room setting
  void showCaseRoomSetting(int roomSize, std::string roomName,
                           std::string targetCustomer);
  //     3) return articles
  void returnArticle(std::string articleName, int receiptNum,
                     std::string customerName);
  //     4) contactless ordering food
  void contactlessOrderingFood(std::string ikeaCustResto, std::string foodMenu,
                               int quantity, std::string custName);

  //    5) fulfillment food supply on Store
  void foodFulfillment(std::string restoname, std::string foodMenu);

  Restaurant IKEAFoodRestaurant;
};

IKEAStore::IKEAStore()
    : listOfArticle{"POANG", "MALM", "OFTAST"}, numOfCoWorker(1200),
      numOfStores(7), avgRevenuePerDay(100000) {
  std::cout << "IKEA store class is constructed\n";
}
IKEAStore::~IKEAStore() { std::cout << "IKEA Store class is destructed\n"; }
IKEAStore::Restaurant::Restaurant()
    : numOfWaiter(7), revenuePerDay(1000),
      numOfChef(3), listOfRawMaterial{"Letuce", "Cabbage", "Carrot"},
      listOfMenul{"Meatball Plantbase", "Sweedish Meatball", "Fried Rice"} {
  restoName = "";
  std::cout << "Restaurant class is constructed\n";
}
IKEAStore::Restaurant::~Restaurant() {
  std::cout << "Restaurant class is destructed\n";
}
void IKEAStore::deliverToCustomer(int totalOrder, std::string customerDetail,
                                  std::string deliveryAddress) {
  std::cout << "Delivery to customer from Warehouse\n";
}
void IKEAStore::showCaseRoomSetting(int roomSize, std::string roomName,
                                    std::string targetCustomer) {
  std::cout << "Showroom customer to see Insipiration\n";
}
void IKEAStore::returnArticle(std::string articleName, int receiptNum,
                              std::string customerName) {
  std::cout << "Return goods will be put on AS IS section \n";
}
void IKEAStore::contactlessOrderingFood(std::string ikeaCustResto,
                                        std::string foodMenu, int quantity,
                                        std::string custName) {
  std::cout << "Contactless food ordering at Store\n";
}
void IKEAStore::foodFulfillment(std::string restoName,
                                std::string foodMenu) {
  IKEAStore::IKEAFoodRestaurant.restoName = restoName;
  std::cout << "Restock raw material for Food store\n";
}
void IKEAStore::Restaurant::madeFood(std::string orderedMenu, int totalOrder) {
  std::cout << "IKEA Food resto is made food for customer\n";
}
double IKEAStore::Restaurant::customerBilling(int numOrderedMenu,
                                              int numCustomer, float price) {
  std::cout << "Bill to paid by customer after order\n";
  return 1000;
}
void IKEAStore::Restaurant::servingCustomer(int orderNumber,
                                            std::string orderedMenu) {
  std::cout << "Finished order serving to customer\n";
}
/*
 copied UDT 2:
 */
struct barcodeScanner {
  std::string deviceName;
}; // UDT 5
struct customerPoleDisplay {
  std::string deviceName;
}; // UDT 6
struct mainPOSDisplay {
  std::string deviceName;
}; // UDT 7
struct receiptPrinter {
  std::string deviceName;
}; // UDT 8
struct cashDrawer {
  std::string deviceName;
}; // UDT 9

struct POS {
  barcodeScanner
      scanner; // a member variabledeclaration of an instance of UDT 5
  customerPoleDisplay
      poleDisplay; // a member variabledeclaration of an instance of UDT 6
  mainPOSDisplay
      POSDisplay; // a member variabledeclaration of an instance of UDT 7
  receiptPrinter
      receipt;       // a member variabledeclaration of an instance of UDT 8
  cashDrawer drawer; // a member variabledeclaration of an instance of UDT 9
  std::string deviceName;

  POS();
  ~POS();
  //     1) Input transaction
  void inputTransaction(int articleNumber, float price, int quantity);
  //     2) print reciept
  void printReceipt(int orderNumber, std::string orderDetail);
  //     3) open cash drawer
  void openCashDrawer();
};

POS::POS() : scanner(), poleDisplay(), POSDisplay(), receipt(), drawer() {
  std::cout << "POS Class is constructed\n";
}
POS::~POS() { std::cout << "POS Class is destructed\n"; }
void POS::inputTransaction(int articleNumber, float price, int quantity) {
  std::cout << "Input transaction on the POS\n";
}
void POS::printReceipt(int orderNumber, std::string orderDetail) {
  std::cout << "Print customer receipt\n";
}

/*
 copied UDT 3:
 */
struct Hotel {
  //     1) number of rooms
  int numOfRooms;
  //     2) list of hotel menu
  std::string listOfHotelMenu[3];
  //     3) total of co worker
  int totalCoWorker;
  //     4) count of smoking room
  int cntSmookingRoom;
  //     5) average occupancy per day
  int avgVisitPerDay;

  Hotel();
  ~Hotel();
  struct Room {
    int roomNum;
    int roomType;

    Room();
    ~Room();

    void roomFacility(int roomType);
    void roomAmnesties(int roomType);
  };
  // 3 things it can do:
  //     1) provide room service
  void roomService(int roomNumber, std::string requestedService);
  //     2) book room for stay
  void bookRoom(int roomNumber, std::string visitorName, float price);
  //     3) reserve hotel restaurant
  void reserveRestaurant(std::string customerName, int numofCustomer);
};

Hotel::Hotel()
    : numOfRooms(100), listOfHotelMenu{"Sandwich Tuna", "Tenderloin Steak",
                                       "Fried Fries"},
      totalCoWorker(120), cntSmookingRoom(20), avgVisitPerDay(60) {
  std::cout << "Hotel class is constructed\n";
}
Hotel::~Hotel() { std::cout << "Hotel class is destructed"; }

Hotel::Room::Room() : roomNum(12), roomType(2) {
  std::cout << "Room class is constructed\n";
}
Hotel::Room::~Room() { std::cout << "Room class is destructed\n"; }

void Hotel::roomService(int roomNumber, std::string requestedService) {
  std::cout << "Requested room service to receiptionist\n";
}
void Hotel::bookRoom(int roomNumber, std::string visitorName, float price) {
  std::cout << "Book room for stay\n";
}
void Hotel::reserveRestaurant(std::string customerName, int numofCustomer) {
  std::cout << "Reserve restaurant for dinner\n";
}

/*
 new UDT 4:
 with 2 member functions
 */
struct ClusterHouseArea {
  IKEAStore nearestIKEAStore;
  IKEAStore::Restaurant nearestIKEAFood;

  ClusterHouseArea();
  ~ClusterHouseArea();

  std::string FindNearestIKEAStore(std::string clusterName, int vehicleType);
  int calcNumOfResident(std::string clusterName, int houseUnit,
                         int avgResidentPerHouse);
};

ClusterHouseArea::ClusterHouseArea() : nearestIKEAStore(), nearestIKEAFood() {
  std::cout << "Cluster house area class is constructed\n";
}
ClusterHouseArea::~ClusterHouseArea() {
  std::cout << "Cluster house area class is destructed\n";
}

std::string ClusterHouseArea::FindNearestIKEAStore(std::string clusterName,
                                                   int vehicleType) {

  if (clusterName == "Carllio")
    if (vehicleType == 1) // vehicleType = 1 (car), 2 (Bus)
      return nearestIKEAStore.storeName = "Alam Sutera";

  return nearestIKEAStore.storeName = "Taman Angrek";
}

int ClusterHouseArea::calcNumOfResident(std::string clusterName, int houseUnit, int avgResidentPerHouse)
{
    if (clusterName == "Carllio")
        return 1000;
    return houseUnit *  avgResidentPerHouse;
}

/*
 new UDT 5:
 with 2 member functions
 */
struct ElectronicStore {
  POS posDevice;
  barcodeScanner scannerDevice;

  ElectronicStore();
  ~ElectronicStore();

  int buyPOS(std::string deviceName, int quantity, int price);
  bool checkStockScanner(std::string deviceName);
};

ElectronicStore::ElectronicStore() {
  posDevice.deviceName = "Dell";
  std::cout << "Electronic Store class is constructed\n";
}
ElectronicStore::~ElectronicStore() {
  std::cout << "Electronic Store class is destructed\n";
}

int ElectronicStore::buyPOS(std::string deviceName, int quantity, int price) {
  if (deviceName == posDevice.deviceName)
    if (quantity >= 1)
      return 1000;
  return quantity * price;
}

bool ElectronicStore::checkStockScanner(std::string deviceName) {
  if (deviceName == "Dell")
    return true;
  return false;
}
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left,
 entering a message, and click [Commit and push].

 If you didn't already:
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single
 message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */
int main() {
  //===================IKEAStore==================
  IKEAStore store;
  // 1
  store.deliverToCustomer(10, "Ariq", "carillo");
  // 2
  store.showCaseRoomSetting(100, "living room", "Parents with 1 kids");
  // 3
  store.returnArticle("MALM", 01, "Ariq");
  // 4
  store.contactlessOrderingFood("Customer Restaurant", "Sweedish Meatball", 1, "Ariq");
  //5
  store.foodFulfillment("Customer Restaurant", "Meatball");
  //6
  store.IKEAFoodRestaurant.madeFood("Tenderloin Steak", 1);
  //7
  store.IKEAFoodRestaurant.customerBilling(10, 10, 1000.0f);
  //8
  store.IKEAFoodRestaurant.servingCustomer(10, "Fish and Chips");

  //===================POS==================
  POS posDevice; 
  //1
  posDevice.inputTransaction(00113223, 100.0f, 10);
  //2
  posDevice.printReceipt(0102313013,"ABCD");

  //===================HOTEL==================
  Hotel hotel;
  //1
  hotel.roomService(10, "Cleaning");
  //2
  hotel.bookRoom(2, "Ariq", 100.03f);
  //3
  hotel.reserveRestaurant("Ariq", 6262424);

  //===================ClusteredHouse==================
  ClusterHouseArea clustered;
  //1
  std::cout << clustered.FindNearestIKEAStore("Carllio", 1) << std::endl;
  //2
  std::cout << clustered.calcNumOfResident("Carllio", 9, 2) << std::endl;

  //===================ElectronicStore==================

  ElectronicStore elecStore;
  //1
  std::cout << elecStore.buyPOS("Dell", 3, 1000) << std::endl;
  //2
  std::cout << elecStore.checkStockScanner("Dell") << std::endl;
   
  std::cout << "good to go!" << std::endl;
}
