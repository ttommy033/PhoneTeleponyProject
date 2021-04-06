##Date:         December 18th, 2020
##File:         Main File
import Building as bld
from copy import deepcopy

def main():
  building_main_strat =  bld.Building()
  building_bad_strat = deepcopy(building_main_strat)

  print("This is the total number of steps the elevator must make in the best case: ", building_main_strat.output())
  building_bad_strat.strategy = 1
  print("This is the total number of steps the elevator must make in the worst case: ", building_bad_strat.output())

  

if __name__ == "__main__":
  main()


