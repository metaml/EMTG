.DEFAULT_GOAL = help

cmake: ## make project files
	cd emtg && cmake --fresh .

build: ## build
	cd emtg && make

cspice: OS = $(shell uname --kernel-name | tr "[A-Z]" "[a-z]")
cspice: ## copy NASA's SPICE into ./cspice
	@if [ "darwin" = "$(OS)" ]; then \
		CS_URL=https://naif.jpl.nasa.gov/pub/naif/toolkit/C/MacM1_OSX_clang_64bit/packages/cspice.tar.Z; \
		CSS_URL=https://naif.jpl.nasa.gov/pub/naif/toolkit//C/MacM1_OSX_clang_64bit/packages/importCSpice.csh; \
	elif [ "linux" = "$(OS)" ]; then \
		CS_URL=https://naif.jpl.nasa.gov/pub/naif/toolkit//C/PC_Linux_GCC_64bit/packages/cspice.tar.Z; \
		CSS_URL=https://naif.jpl.nasa.gov/pub/naif/toolkit//C/PC_Linux_GCC_64bit/packages/importCSpice.csh; \
	else \
		echo "error: no cspice for $(OS)" && exit 1; \
	fi; \
	curl --output cspice.tar.Z $$CS_URL
	tar xzf cspice.tar.Z
	rm -f cspice.tar.Z
	cd cspice && ./makeall.csh

ipopt: ## copy lpopt source int ./Ipopt
	git clone https://github.com/coin-or/Ipopt.git
	cd Ipopt && ./configure && make

clean: ## clean
	cd emtg && make clean

clobber: ## rm all generated file
	cd emtg/src && find . -type d -name CMakeFiles | xargs rm -rf
	cd emtg/src && find . -type f -name \*.cmake | xargs rm -f
	cd emtg/src && find . -type f -name Makefile | xargs rm -f
	cd emtg && rm -f Makefile cmake_install.cmake && rm -rf CMakefiles

help: ## help
	@grep -E '^[a-zA-Z00-9_%-]+:.*?## .*$$' $(MAKEFILE_LIST) \
	| awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-18s\033[0m %s\n", $$1, $$2}'
