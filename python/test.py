import time
time.sleep(1)
# -----
def time_get():
    print time.asctime().split()[3]
# -----

if __name__ == "__main__":
    time_get()

if True:
    print "test"
