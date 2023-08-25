{
  description = "EMTG+Ipopt";

  inputs = {
    nixpkgs.url        = "github:nixos/nixpkgs/nixpkgs-unstable";
    flake-utils.url    = "github:numtide/flake-utils";
    flake-compat.url   = "github:edolstra/flake-compat";
    flake-compat.flake = false;
  };

  outputs = { self, nixpkgs, flake-utils, flake-compat }:
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
        packages.default = self;
        defaultPackage = self.packages.${system}.${pkg-name};

        devShell = pkgs.mkShell {
          stdenv = pkgs.clangStdenv;
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
