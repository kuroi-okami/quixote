# Use the latest tagged ubuntu image from dockerhub
FROM ubuntu:latest

# Install essentials for dev, and some extras
RUN \
	apt install update && \
	apt install \
		build-essential\
		ninja-build\
		valgrind\
		cppcheck
