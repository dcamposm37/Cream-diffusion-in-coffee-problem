# Cream-diffusion-in-coffee-problem
The proposed problem to be solved is called 'The cream in your coffee problem' and is introduced in chapter 7.7 of the book Computational Physics. It is considered that if we start with a cup of black coffee and carefully drop a drop of cream in the center, the white mass of cream will slowly spread until it fills the cup where the coffee will finally acquire a uniform brownish color. On a Microscopic level the cream drop consists of a large number of cream molecules. If we follow the movement of one of these molecules through the coffee, we will find that it follows a complicated trajectory. More precisely, it will move for short periods of time in a straight line (according to Newton's first law) between collisions with other molecules. Moreover, each collision will cause abrupt changes in the velocity of our molecule.

![image](https://github.com/dcamposm37/Cream-diffusion-in-coffee-problem/assets/66316978/2d38a2ea-93d5-4702-a14a-c7f059c3409b)

For this problem the (real) deterministic process can be modeled by stochastic processes having the same mean properties. In particular, each trajectory can be modeled by random walkers. In this case the steps of the walker correspond to the motion of the cream molecules between collisions. The change of direction of the velocity of the molecules after each collision is modeled by letting the direction of each walker step be random. Therefore, our random walkers will follow a zigzag path which resembles the effective trajectory of the cream molecules. The following activities arise from this problem:
- Calculate the final entropy of the system.
- Calculate the entropy as a function of time for cups of different sizes and show that the time required for the entropy to reach equilibrium increases with the square of the size.
- Show that the size of the cream drop increases as $\sqrt{t}$. Additionally show that this behavior changes as the cream drop uniformly fills the cup.
- Perform the 'cream diffusion' simulation and let one of the walls possess a small gap through which molecules can escape. Show that the number of cream molecules in the cup, which is proportional to the partial pressure of the cream molecules, varies as $exp{(-t/\tau)}$ where $\tau$ is the effective time constant for escape.

![image](https://github.com/dcamposm37/Cream-diffusion-in-coffee-problem/assets/66316978/18efb2cd-4cb3-4109-a968-ff860b593c3d)

