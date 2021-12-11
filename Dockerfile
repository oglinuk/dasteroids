FROM ubuntu:18.04
ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y vim \
	build-essential \
	liballegro*5.2 \
	liballegro*5-dev
ADD . /src
WORKDIR /src
RUN make
CMD ["./asteroids"]
