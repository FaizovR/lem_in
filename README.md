# Lem-in

Lem-in project for **21 School Moscow**.

In brief, the project consists in running a certain amount of 'ants' in the fastest way possible in an 'anthill'. My implementation uses [Dinic pathfinding algorithm](http://e-maxx.ru/algo/dinic).

## Getting Started

This project has only been compiled and tested on **macOS Mojave (10.14.6)**. A few modifications might be necessary to compile it on any other system.

### Installing

After cloning the repository, simply run

```
make
```

to compile. An executable named ./lem-in should be created.

## How to use

lem-in takes commands on stdin. Sample maps can be found in the [maps](maps/) folder.

```
Usage: ./lem-in          read map from stdin
       ./lem-in < map    use map specified in the file
```

## Author

* **Faizov Rustam (hbarrett)**
