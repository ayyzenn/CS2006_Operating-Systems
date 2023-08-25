from multiprocessing import Process

def f(name):
    print('Hello {}'.format(name))

if __name__ == '__main__':
    p1 = Process(target=f, args=('World',))
    p2 = Process(target=f, args=('Saad',))
    p3 = Process(target=f, args=('Ahmad',))
    
    p1.start()
    p2.start()
    p3.start()
    
    p1.join()
    p2.join()
    p3.join()
