import Elevator
import Patron

class Building(object):
 # building will have # of floors, its own lists of patrons,  its own elevator object
  number_floors = None
  patron_list = list()
  elevator = None

  strategy = 0

  def __init__(self):
    self.number_floors = self.get_value("Enter the # of floors this building should have: ",\
    "Number of floors should be higher then 1", 2)
    patrons = self.get_value("Enter # of patrons: ",\
    "Number of patrons cannot be negative", 0)
    for i in range(patrons):
      self.patron_list.append(Patron.Patron(i, self.number_floors))
    self.patron_list = sorted(self.patron_list, key = lambda x : x.start_floor)
    self.elevator = Elevator.Elevator()

  def get_value(self, message, i_message, m_value):
    val = None
    try:
      val = int(input(message))
    except ValueError:
      print(i_message)
      return self.get_value(message, i_message, m_value)
    if val < m_value:
      print(i_message)
      return self.get_value(message, i_message, m_value)
    else:
      return val

  # main startegy for elevator movement starts at the top floor, works it way downward
  def main_start_dir(self):
    if self.elevator.current_floor >= self.number_floors - 1:
      self.elevator.direction = -1
    elif self.elevator.current_floor <= 0:
      self.elevator.direction = 1

  # bad startegy for performace of elevator example
  def bad_start_dir(self):
    if len(self.elevator.register_list) == 0:
      self.main_start_dir()
      return
    fval = self.elevator.register_list[0].d_floor
    if self.elevator.current_floor > fval:
      self.elevator.direction = -1
    else:
      self.elevator.direction = 1

  def load_patron(self):
    for patron in list(self.patron_list):
      if patron.start_floor == self.elevator.current_floor:
        self.elevator.register_patron(patron)
        self.patron_list.remove(patron)

  def run(self):
    self.load_patron()
    if self.strategy == 0:
      self.main_start_dir()
    else:
      self.bad_start_dir()
    self.elevator.move()
    self.elevator.exit_patrons()

  def output(self):
    t_number = 0
    while self.wait_patron():
      self.run()
      t_number += 1
    return t_number

  def wait_patron(self):
    if len(self.patron_list) > 0 or len(self.elevator.register_list) > 0:
      return True
    return False