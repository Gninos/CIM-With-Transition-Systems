## The main goal

The main goal is to accomplish a final state where the grid doesn't have any car as fast as possible without collisions between the CAVs. The model has a token "d" (range of 0 to n - number of vehicles, 0 = initial state) that changes whenever a car can switch its state, so it always stores the information about which car had the last opportunity to move. Another variable of the system is "out", that wares binary information. If a specific car has left the grid, it stores the value 1. Otherwise, it stores the value 0.

We can call each combination of all the variables d,  out, position x, position y, and the array a, as a marking (state) of the system. For instance, the following states are, respectively, the initial and the final state for a model with four CAVs.

![s0](https://user-images.githubusercontent.com/50747436/66580992-b0a71c00-eb55-11e9-8eb7-9314e6b50063.png)

![statef](https://user-images.githubusercontent.com/50747436/66580990-b00e8580-eb55-11e9-9bf2-c4788d61c7f8.JPG)

Even with the constraints, there are many possible combinations. The shortest_path function from NetworkX library filters the shortest sequence of transitions between the initial state and the desired final state.



