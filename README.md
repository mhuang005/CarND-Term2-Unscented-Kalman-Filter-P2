## **Unscented Kalman Filter (UKF)**


### Overview

---
In this project an [unscented Kalman filter](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.5.2891&rep=rep1&type=pdf) is implemented (in C++) to estimate the state of a moving object of interest with noisy Lidar and Radar measurements. The object runs in a simulator which can be downloaded [here](https://github.com/udacity/self-driving-car-sim/releases). 
Also, [uWebSocketIO](https://github.com/uWebSockets/uWebSockets) is needed in this project which is responsible for the communication between the unscented Kalman filter and the simulator.




### Dependencies
---
* cmake >= 3.5
* make >= 4.1 (Linux, Mac)
* gcc/g++ >= 5.4
 

### Building the code 
---
Once the install for uWebSocketIO is complete, the main program can be built and run by doing the following from the project top directory.

1. mkdir build
2. cd build
3. cmake ..
4. make

Note: This would generate an excutable **UnscentedKF** in the **build** directory.

### Running and testing UKF
---

1. Run the simulator
2. Execute ./UnscentedKF in the build directory 
3. Choose Dataset 1 or 2 in the simulator and Click **Start** button



The following figures show the positions from the measurements (red and blue dots) and the esitimate positions from the UKF (green dots) at each time step.  Also, the real-time RMSEs (in terms of position and velocity) can be observed when the object is moving. The RMSEs at the final time step are shown in the figures below. 

![alt text](./images/ukf-dataset-1.jpg)


![alt text](./images/ukf-dataset-2.jpg)


### Consistency check 
---

The Normalized Innovation Squared (NIS) is used to check the consistency of UKF. A reference can found [here](http://www.robots.ox.ac.uk/~ian/Teaching/Estimation/LectureNotes2.pdf). 
The Laser NIS is expected to follow the [Chi-Squared distribution](https://en.wikipedia.org/wiki/Chi-squared_distribution) with 2 degrees of freedom, and the Radar NIS is expected to
follow the [Chi-Squared distribution](https://en.wikipedia.org/wiki/Chi-squared_distribution) with 3 degrees of freedom.  The figures below show Laser and Radar NIS values when the filter is tested on 
Dateset 1. 

![alt text](./images/nis-laser-1.png)


![alt text](./images/nis-radar-1.png)

