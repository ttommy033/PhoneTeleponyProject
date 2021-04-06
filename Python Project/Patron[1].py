import random

# Each Patron has a unique identifier, starting floor, and destination
class Patron(object):
  start_floor = None
  d_floor = None
  ID = None

# constructor for patron takes in value for current floor and dest floor
  def __init__(self, ID, floorT):
    self.ID = ID
    self.start_floor = random.randint(0, floorT-1)
    self.d_floor = random.randint(0, floorT-2)
    if self.d_floor >= self.start_floor:
      self.d_floor += 1

  