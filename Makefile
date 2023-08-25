.DEFAULT_GOAL = help

cmake: GSL_PATH = $(shell gsl-config --prefix)
cmake: ## generate project files, e.g.: Makefile
	echo $(IPOPT_INCLUDE_DIR)
	echo $(IPOPT_LIBRARY_DIR)
	cd emtg && cmake --fresh .

emtg: ## build EMTG
	cd emtg && make -j 16 VERBOSE=1

cspice: get-cspice ## build cspice
	cd cspice && for i in $$(find . -type f -name \*.csh); do \
		echo $$i; \
		sed --in-place '1 i\#!/usr/bin/env tcsh' $$i; \
	done
	cd cspice && ./makeall.csh
	cd emtg && ln -s ../cspice

get-cspice: OS = $(shell uname --kernel-name | tr "[A-Z]" "[a-z]")
get-cspice: ## build cspice
	@if [ "darwin" = "$(OS)" ]; then \
		CS_URL=https://naif.jpl.nasa.gov/pub/naif/toolkit/C/MacM1_OSX_clang_64bit/packages/cspice.tar.Z; \
		CSS_URL=https://naif.jpl.nasa.gov/pub/naif/toolkit//C/MacM1_OSX_clang_64bit/packages/importCSpice.csh; \
	elif [ "linux" = "$(OS)" ]; then \
		CS_URL=https://naif.jpl.nasa.gov/pub/naif/toolkit//C/PC_Linux_GCC_64bit/packages/cspice.tar.Z; \
		CSS_URL=https://naif.jpl.nasa.gov/pub/naif/toolkit//C/PC_Linux_GCC_64bit/packages/importCSpice.csh; \
	else \
		echo "error: no cspice for $(OS)" && exit 1; \
	fi; \
	if [ ! -d "./cspice" ]; then \
		curl --output cspice.tar.Z $$CS_URL; \
		tar xzf cspice.tar.Z; \
		rm -f cspice.tar.Z; \
	fi

ipopt: ## build Ipopt (not used)
	git clone https://github.com/coin-or/Ipopt.git
	cd Ipopt && rm -rf .git
	cd Ipopt && ./configure --prefix=${PWD}/local && make -j8 && make install

clean: ## clean
	cd emtg && make clean

clobber: ## rm all generated file
	cd emtg/src && find . -type d -name CMakeFiles | xargs rm -rf
	cd emtg/src && find . -type f -name \*.cmake | xargs rm -f
	cd emtg/src && find . -type f -name Makefile | xargs rm -f
	cd emtg && rm -f Makefile cmake_install.cmake && rm -rf CMakefiles
	rm -rf cspice Ipopt

help: ## help
	@grep -E '^[a-zA-Z00-9_%-]+:.*?## .*$$' $(MAKEFILE_LIST) \
	| awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-18s\033[0m %s\n", $$1, $$2}'

.PHONY: emtg
