# Use the latest tagged ubuntu image from dockerhub
FROM ubuntu:latest

# Install essentials for dev, and some extras
RUN \
	apt-get install -y -q update && \
	apt install -y -q \
		build-essential\
		ninja-build\
		valgrind\
		cppcheck
