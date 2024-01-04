import sys
import os
import random

instance_dir = sys.argv[1]
number = random.randint(0x00ff, 0xffff)
if not os.path.exists(instance_dir):
    os.makedirs(instance_dir)
with open(os.path.join(instance_dir, "number"), "w") as f:
    f.write(f"{number:016b}")
