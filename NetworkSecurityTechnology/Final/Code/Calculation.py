class Machine:
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
