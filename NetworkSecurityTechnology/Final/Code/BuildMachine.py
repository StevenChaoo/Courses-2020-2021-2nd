import numpy as np


class Machine:
    '''
    To build a machine for synchrony the weight
    Param:
        k: the number of kernals
        n: the number of input neuron per kernal
        l: the depth of network
        W: weights in neural network
    '''

    def __init__(self, k=3, n=4, l=6):
        self.k = k
        self.n = n
        self.l = l
        self.W = np.random.randint(-l, l + 1, [k, n])
