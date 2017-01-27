class AccountError(Exception):
  def __init__(self, value):
    self.value = value
  def str(self):
    return repr(self.value)
 
def make_account(balance, interest):
  t = 0
  def withdraw(amount, time):
    nonlocal balance
    nonlocal t
    if time <= t:
      raise AccountError("Timestamp error")
    balance += (time - t) * interest * balance
    t = time
    if balance >= amount:
      balance = balance - amount
    else:
      raise AccountError("Account balance too low")
      
  def deposit(amount, time):
    #nonlocal balance
    nonlocal t
    if time <= t:
      raise AccountError("Timestamp error")
    balance += (time - t) * interest * balance
    t = time
    balance = balance + amount
  
  def get_value():
    return balance
  
  public_methods = {'withdraw' : withdraw, 'deposit' : deposit, 'get_value' : get_value}
  return public_methods
