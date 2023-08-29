.DEFAULT_GOAL = help

build: cspice cmake emtg ## build EMTGv9

install: ## install EMTGv9
	cd emtg && make install

nix-build: ## build (nix package) emtg
	nix build --debug --print-build-logs

cmake: export GSL_PATH = $(shell gsl-config --prefix)
cmake: ## generate project files, e.g.: Makefile
	echo $(IPOPT_INCLUDE_DIR)
	echo $(IPOPT_LIBRARY_DIR)
	cd emtg && find . -name CMakeCache.txt | xargs rm -f && cmake --fresh .

emtg: ## build EMTG
	cd emtg && make -j 16 VERBOSE=1

cspice: ## build cspice
	cd emtg && ln -fs ../cspice ## hack to satisfy emtg/CMakeLists.txt
	cd emtg/cspice && mkdir -p lib && tcsh ./makeall.csh

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

docker: ## build a docker image
	nix build .#docker

ipopt: ## build Ipopt (not used and don't use)
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
	rm -f result
	nix-store --gc

nix-build-clean: ## clean up after nix build
	nix-store --gc		
	nix-store --gc --print-roots | egrep -v "^(/nix/var|/run/\w+-system|\{memory|/proc)"

help: ## help
	@grep -E '^[a-zA-Z00-9_%-]+:.*?## .*$$' $(MAKEFILE_LIST) \
	| awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-18s\033[0m %s\n", $$1, $$2}'

.PHONY: cspice emtg
