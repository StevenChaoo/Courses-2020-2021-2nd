# Author: StevenChaoo
# -*- coding:UTF-8 -*-


import numpy as np
import matplotlib.pyplot as mpl
import sys
import time


class UpdateRules():
    '''
    One of the following learning rules can be used for the synchronization:
       -Hebbian learning rule:
        w_i = w_i + \sigma_i\times x_i\times\theta(\sigma_i,\tau^A)\theta(\tau^A, \tau^B)
       -Anti-Hebbian learning rule:
        w_i = w_i - \sigma_i\times x_i\times\theta(\sigma_i,\tau^A)\theta(\tau^A, \tau^B)
       -Random walk:
        w_i = w_i + x_i\times\theta(\sigma_i,\tau^A)\theta(\tau^A, \tau^B)
    '''

    def theta(self, t1, t2):
        '''
        Param:
            t1:
            t2:
        Return:
            a bool value
        '''
        return 1 if t1 == t2 else 0

    def hebbian(self, W, X, sigma, tau1, tau2, l):
        '''
        Hebbian learning rule
        Param:
            W:     weights in neural network
            X:     inputs of neural network
            sigma: \sigma_i = \sum w_i\times x_i
            tau1:  tau^A \tau = \prod\sigma_i
            tau2:  tau^B \tau = \prod\sigma_i
            l:     the depth of network
        '''
        k, n = W.shape
        for (i, j), _ in np.ndenumerate(W):
            W[i, j] += X[i, j] * sigma[i] * \
                self.theta(sigma[i], tau1) * self.theta(tau1, tau2)
            W[i, j] = np.clip(W[i, j], -l, l)

    def anti_hebbian(self, W, X, sigma, tau1, tau2, l):
        '''
        Anti-Hebbian learning rule
        Param:
            W:     weights in neural network
            X:     inputs of neural network
            sigma: \sigma_i = \sum w_i\times x_i
            tau1:  tau^A \tau = \prod\sigma_i
            tau2:  tau^B \tau = \prod\sigma_i
            l:     the depth of network
        '''
        k, n = W.shape
        for (i, j), _ in np.ndenumerate(W):
            W[i, j] -= X[i, j] * sigma[i] * \
                self.theta(sigma[i], tau1) * self.theta(tau1, tau2)
            W[i, j] = np.clip(W[i, j], -l, l)

    def random_walk(self, W, X, sigma, tau1, tau2, l):
        '''
        Ranfom walk learning rule
        Param:
            W:     weights in neural network
            X:     inputs of neural network
            sigma: \sigma_i = \sum w_i\times x_i
            tau1:  tau^A \tau = \prod\sigma_i
            tau2:  tau^B \tau = \prod\sigma_i
            l:     the depth of network
        '''
        k, n = W.shape
        for (i, j), _ in np.ndenumerate(W):
            W[i, j] += X[i, j] * \
                self.theta(sigma[i], tau1) * self.theta(tau1, tau2)
            W[i, j] = np.clip(W[i, j], -l, l)


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

    def get_output(self, X):
        '''
        Calculate the final score
        Param:
            X: inputs of neural network
        Return:
            tau: final score
        '''
        k = self.k
        n = self.n

        # initialized with np.random.randint function
        W = self.W

        # reshape X in same size to W
        X = X.reshape([k, n])

        # np.sign function to get the sign of the value
        # np.sum function to find the sum of all elements in the matrix
        sigma = np.sign(np.sum(X * W, axis=1))

        # np.prod function to find the product of all elements in the matrix
        tau = np.prod(sigma)

        self.X = X
        self.sigma = sigma
        self.tau = tau

        return tau

    def __call__(self, X):
        '''
        Overriding overloaded function
        '''
        return self.get_output(X)

    def update(self, tau2, update_rule='random_walk'):
        '''
        Update the weight matrix
        Param:
            tau2: tau^B
            update_rule: learning update rules, default is random_walk
        '''
        rules = UpdateRules()
        X = self.X
        tau1 = self.tau
        sigma = self.sigma
        W = self.W
        l = self.l

        if (tau1 == tau2):
            if update_rule == 'hebbian':
                rules.hebbian(W, X, sigma, tau1, tau2, l)
            elif update_rule == 'anti_hebbian':
                rules.anti_hebbian(W, X, sigma, tau1, tau2, l)
            elif update_rule == 'random_walk':
                rules.random_walk(W, X, sigma, tau1, tau2, l)
            else:
                raise Exception("Invalid update rule. Valid update rules are: " +
                                "\'hebbian\', \'anti_hebbian\' and \'random_walk\'.")


def random(k, n, l):
    '''
    Initialize the input matrix
    Param:
        k: the number of kernals
        n: the number of input neuron per kernal
        l: the depth of network
    Return:
        the initialized input matrix
    '''
    return np.random.randint(-l, l + 1, [k, n])


def sync_score(m1, m2, l):
    '''
    Calculate the synchronized score
    Param:
        m1:
        m2:
        l:  the depth of network
    Return:
        the value description of how different between m1 and m2
    '''
    return 1.0 - np.average(1.0 * np.abs(m1.W - m2.W)/(2 * l))


if __name__ == "__main__":

    # Hyper-parameters
    k = 100
    n = 10
    l = 10

    # Alternative learning rules
    update_rules = ['hebbian', 'anti_hebbian', 'random_walk']
    update_rule = update_rules[0]

    print("Creating machines : k=" + str(k) +
          ", n=" + str(n) + ", l=" + str(n))
    print("Using " + update_rule + " update rule.")

    # Instantiate object
    Alice = Machine(k, n, l)
    Bob = Machine(k, n, l)
    Eve = Machine(k, n, l)

    sync = False
    nb_updates = 0
    nb_eve_updates = 0
    sync_history = []

    # Start the timer
    start_time = time.time()

    while(not sync):

        # Initialize the input matrix
        X = random(k, n, l)

        # Get the final score of Alice, Bob and Eve
        tauA = Alice(X)
        tauB = Bob(X)
        tauE = Eve(X)

        # Update the weights
        Alice.update(tauB, update_rule)
        Bob.update(tauA, update_rule)

        # Eve updates the weights
        if tauA == tauB == tauE:
            Eve.update(tauA, update_rule)
            # Statistics Eve update times
            nb_eve_updates += 1

        # Statistics Alice and Bob update times
        nb_updates += 1

        # Calculate the synchronized score
        score = 100 * sync_score(Alice, Bob, l)

        sys.stdout.write('\r' + "Synchronization = " + str(int(score)) + "%    Updates = " +
                         str(nb_updates) + "    Eve's updates = " + str(nb_eve_updates))

        # Synchronization complete
        if score == 100:
            sync = True

        # For plot
        sync_history.append(score)

    # Stop the timer and calculate the time difference
    end_time = time.time()
    time_taken = end_time - start_time

    print('\nMachines have been synchronized.')
    print('Time taken = ' + str(time_taken)[:6] + " seconds.")
    print('Updates = ' + str(nb_updates) + ".")

    eve_score = 100 * int(sync_score(Alice, Eve, l))
    if eve_score > 100:
        print("Oops! Nosy Eve synced her machine with Alice's and Bob's !")
    else:
        print("Eve's machine is only " + str(eve_score) + " % " +
              "synced with Alice's and Bob's and she did " + str(nb_eve_updates) + " updates.")

    mpl.plot(sync_history)
    mpl.show()
