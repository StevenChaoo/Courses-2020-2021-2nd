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
