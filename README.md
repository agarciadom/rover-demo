Rover demo
==========

Example projects for the [Papyrus IC rover](https://wiki.polarsys.org/Rover5_BOM). The main Rover project is based on the one from the [supporting material](http://flux.cs.queensu.ca/mase/papyrus-rt-resources/supporting-material-for-the-models17-tutorial/) from the Papyrus-RT tutorial given at [MoDELS 2017](https://www.cs.utexas.edu/models2017/home).

Main changes so far:

* HC-SR04 is now filtered through a sliding 5-median filter, to avoid stopping the robot due to a single noisy read.
* Motor speed has been extracted into a property for the top capsule.

The goal is to include some supporting material for a 1.5-hour interactive lecture on an introduction to UML-RT and Papyrus-RT in particular.
