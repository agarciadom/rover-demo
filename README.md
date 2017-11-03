Rover demo
==========

Example projects for the [Papyrus IC rover](https://wiki.polarsys.org/Rover5_BOM). The main Rover project is based on the one from the [supporting material](http://flux.cs.queensu.ca/mase/papyrus-rt-resources/supporting-material-for-the-models17-tutorial/) from the Papyrus-RT tutorial given at [MoDELS 2017](https://www.cs.utexas.edu/models2017/home) by Nicolas Hili, Ernesto Posse and Juergen Dingel.

Main changes so far:

* HC-SR04 is now filtered through a sliding 5-median filter, to avoid stopping the robot due to a single noisy read.
* Motor speed has been extracted into a property for the top capsule.

The `slides` directory includes supporting material for a 1.5-hour interactive lecture on an introduction to UML-RT and Papyrus-RT in particular.

The `videos` directory contains videos demonstrating the behaviour achieved by the various branches in this repository.

For step-by-step instructions on how to get started, you can follow [this blog post](https://xmleye.wordpress.com/2017/10/17/running-uml-rt-models-on-a-raspberry-pi-based-rover/) for GNU/Linux environments.
