# Elevator class, elevator is set to deafault position, and set to a specific direction
class Elevator(object):
  register_list = list()
  current_floor = 0
  direction = 1

  # Function to move the Elevator
  def move(self):
    self.current_floor += self.direction

  # Function to release the patrons onto the desired floor
  def exit_patrons(self):
    for patron in list(self.register_list):
      if patron.d_floor == self.current_floor:
        self.r_patron(patron)
  
  # Function that will add patron to elevetor
  def register_patron(self, patron):
    self.register_list.append(patron)

  # Function will remove patron from Elevator
  def r_patron(self, patron):
    self.register_list.remove(patron)


  