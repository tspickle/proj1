FROM gcc:4.9

RUN apt-get update

RUN apt-get install -y valgrind

COPY . /usr/src/myapp

WORKDIR /usr/src/myapp

CMD ["/bin/bash"]

