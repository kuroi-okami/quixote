# Use the latest tagged ubuntu image from dockerhub
FROM ubuntu:latest

# Install essentials for dev, and some extras
RUN \
	apt update && \
	apt install -y -q \
		build-essential\
		cmake\
		ninja-build\
		valgrind\
		cppcheck\
		git\
		openssh-server

