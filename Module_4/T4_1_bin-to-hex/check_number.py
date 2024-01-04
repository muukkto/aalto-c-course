import sys
import re

max_points = 10
points = 0
try:
    with open('number') as orig_file:
        # the file from the generated personalized exercise instance
        number_str = orig_file.read().strip()
        start = int(number_str, 2)
    with open('solution') as submitted_file:
        # student's submission
        sol_value = submitted_file.read().strip()
        if sol_value.startswith("0x"):
            sol_value = sol_value[len("0x"):]
        if sol_value.startswith("x"):
            sol_value = sol_value[1:]
    number_check = re.match('^[0-9A-Fa-f]+$', sol_value)
    if number_check is not None:
        solution = int(sol_value, 16)
        print(f"Original number in binary 0b{number_str} = {start} in decimal")
        print(f"Your solution 0x{sol_value} = {solution} in decimal")
        if solution == start:
            # correct solution
            points = max_points
            print("CORRECT!")
        else:
            print("DIFFERENT!")
    else:
        print("Your input is not a hexadecimal number", file=sys.stderr)

except Exception as e:
    print("ERROR", file=sys.stderr)
    print(e, file=sys.stderr)
finally:
    print("TotalPoints: {}".format(points))
    print("MaxPoints: {}".format(max_points))
