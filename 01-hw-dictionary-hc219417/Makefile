# Created by: Nasseef Abukamail
# This Makefile will allow you to run tests for the appointment class
#
# Usage:
#    make run_tests
#    mingw32-make run_tests_win
#
# Variables
CC = g++
CFLAGS = -g -Wall -std=c++11

# Add a rule to compile your project below this line

a.out: main.cc dictionary.h
	$(CC) $(CFLAGS) main.cc -o a.out

######################################## R U N   T E S T s ##################################################
run_tests: dictionary.h
	head dictionary.h
	$(CC) $(CFLAGS) _TEST/TEST_cases.cc -o _TEST/run_tests ; _TEST/run_tests -sr compact
##############################################################################################################

clean:
	rm -rf _TEST/*.o _TEST/run_tests a.out _TEST/a.out

# ######################################### R U N   T E S T s ##################################################
# run_tests: appointment.h appointment.o
# 	head appointment.cc
# 	$(CC) $(CFLAGS) _TEST/TEST_cases.cc _TEST/appointment.o -o _TEST/a.out && ./_TEST/a.out -sr compact
# ##############################################################################################################
