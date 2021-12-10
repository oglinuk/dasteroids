FROM ubuntu:20.04
ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt install -y vim \
	liballegro*5.2 \
	liballegro*5-dev
ADD . /src
WORKDIR /src
RUN make
CMD ["./main"]
