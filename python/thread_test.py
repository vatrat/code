# import time
import threading
import logging
import Queue


# Logging Setup
logging.basicConfig(level=logging.DEBUG,
                    format='[%(levelname)s] (%(threadName)-10s) %(message)s',)


def worker():
    logging.debug("start")
    while True:
        a = q.get()
        logging.debug(a)
    logging.debug("stop")


def q_reader(q, file):
    while True:
        file.write(q.get())


with open("test.txt", 'a') as file:
    q = Queue.Queue()
    t = threading.Thread(target=q_reader, args=(q, file))
    t.start()
    while True:
        x = raw_input("Number:\n> ")
        q.put(x)
