FROM alpine:latest
ARG DEBIAN_FRONTEND=noninteractive
RUN apk update && apk add vim \
	build-base\
	allegro \
	allegro-dev \
	mesa-dri-intel
ADD . /src
WORKDIR /src
RUN make
CMD ["./asteroids"]
