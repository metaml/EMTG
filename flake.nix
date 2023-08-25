{
  description = "EMTGv9+Ipopt";

  inputs = {
    nixpkgs.url        = "github:nixos/nixpkgs/nixpkgs-unstable";
    flake-utils.url    = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:  
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};

        pkg-name = "emtg";
        emtg = pkgs.runCommand
          pkg-name
          { preferLocalBuild = true; buildInputs = [ pkg-name ]; }
          '''';
        
        revision = "${self.lastModifiedDate}-${self.shortRev or "dirty"}";
      in {
        defaultPackage = with import nixpkgs { inherit system; };
          pkgs.stdenv.mkDerivation rec {
            name = "${pkg-name}";
            src = self;
            version = "9.02";

            nativeBuildInputs = with pkgs; [
              boost
              clang
              cmake
              curl
              gfortran
              gnugrep
              gnused
              gsl
              ipopt
              lapack
              pkg-config
              python3
              openblas
              openjdk
              tcsh
              which
            ];

            buildInputs = with pkgs; [];

            dontUseCmakeConfigure = true;
            
            configurePhase = "echo skipping...";
            buildPhase = ''
              ls
              find /build -type f -name CMakeCache.txt | xargs rm -f
              make build
            '';
            installPhase = "make install";
            meta = with pkgs.lib; {
              homepage = "https://github.com/Karmanplus/EMTG";
              description = "EMTGv9+Ipopt";
            };
          };
                
        devShell = pkgs.mkShell {
          stdenv = pkgs.clangStdenv;
          # inputsFrom = builtins.attrValues self.defaultPackage;
          buildInputs = with pkgs; [
            boost
            clang
            cmake
            curl
            gfortran
            gnugrep
            gnused
            gsl
            ipopt
            lapack
            pkg-config
            python3
            openblas
            openjdk
            tcsh
          ];
          shellHook = ''
            export SHELL=$BASH
            export LANG=en_US.UTF-8
            export PS1="emtg|$PS1"
          '';
        };
      });
}
