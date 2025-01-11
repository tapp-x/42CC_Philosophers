
# Philosopher's Dining Problem

This project implements the dining philosophers problem using threads and mutexes in C.

## Project Structure

```
philo/
    includes/
        philo.h
    main.c
    Makefile
    src/
        ft_atoi.c
        init_data.c
        monitoring.c
        routine.c
        utils.c
```

## Compilation

To compile the project, use the following command:

```sh
make
```

## Execution

To run the program, use the following command:

```sh
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```