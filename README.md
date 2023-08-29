#### EMTGv9

To run EMTGv9 on your local computer, run the following commands:
1. git clone https://github.com/Karmanplus/EMTG
1. cd EMTG
1. git checkout k+
1. make pull
1. make run

The make targets and shell commands are in the Makefile.

NB:
- the EMTG docker image is public: https://hub.docker.com/r/karmanplus/emtg
- <emtg-dir>/work is shared as /work in the docker container
- you can edit files on your host computers in <emtg-dir>/work and it'll show up in /work in the emtg docker container
