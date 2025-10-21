# 2404_A3: Podcast Network Project Final
# Quynh Vo (101203972)

## What it does
A mini podcast network in C++ where users (Subscribers) connect through a Client and can stream or download podcast Episodes. The system models real components—Network, Podcast, Episode, Subscriber, Client—and provides a test harness to drive scenarios without real networking.

## Files
1. Location (Entity object): A virtual base class for StoreLocation and WHLocation classes.
    Location.h, Location.cc

2. StoreLocation (Entity object): Concrete implementation for in-store product locations.
    StoreLocation.h, StoreLocation.cc

3. WHLocation (Entity object): Concrete implementation for warehouse product locations.
    WHLocation.h, WHLocation.cc

4. Product (Entity object): Contains information about the product, including the StoreLocation and WHLocations it is stored in.
    Product.h, Product.cc

5. List (Container object): A list of Products that can grow arbitrarily large.
    List.h, List.cc

6. Queue (Container object): A first-in-first-out (FIFO) data structure for storing WHLocations. The FIFO nature of the data structure ensures that we use older stock first.
    Queue.h, Queue.cc

7. Store (Control object): Provides an interface for interacting with the inventory system.
    Store.h, Store.cc

8. Control (Control object): Controls the interaction between the inventory system (Store) and the user.
    Control.h, Control.cc

9. View (View object): Collects user input and provides system output.
    View.h, View.cc

10. defs.h
11. main.cc
12. Makefile

## Typical Flow
1. Build Network → add Podcasts (each with Episodes) → add Subscribers.
2. Client connects (name match), runs a Search to create a playlist.
3. Client streams episodes or downloads a Podcast; then plays locally from its own storage.
4. Even if the Network deletes that Podcast, the Client’s deep-copied version still plays.

## Instruction (Terminal)
1. make 
2. ./a3
3. Selection a number to test
    (1) receive order: fill in-store location, make new product if cannot find the input product
    (2) fill order: remove the amount and return amount of order that you could not fill
    (3) print store locations: print all store locations that have a product assigned to them
    (4) print warehouse locations: print all warehouse locations that are not empty
    (5) print products: list of products in store
    (0) exit: exit the program
