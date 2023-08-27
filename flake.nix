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
          # stdenv.mkDerivation {
          stdenv.mkDerivation {
            name = "${pkg-name}";
            src = self;
            system = system;

            dontUseCmakeConfigure = true;

            updateAutotoolsGnuConfigScriptsPhase = "true";
            # phases = [ "buildPhase" "installPhase" ];
            # unpackPhase = "true";
            configurePhase = "true";
            buildPhase = "make build";
            installPhase = "make install && mkidr -p $out/bin && cp ./bin/EMTGv9 $out/bin";            

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
          };
        
        devShell = pkgs.mkShell rec {
          name = "${pkg-name}";
          stdenv = pkgs.clangStdenv;
          # inputsFrom = builtins.attrValues self.defaultPackage;
          packages = with pkgs; [
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
