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
        defaultPackage = self.packages.${system}.${pkg-name};

        devShell = pkgs.mkShell {
          buildInputs = with pkgs; [
            boost
            cmake
            curl
            gcc
            gfortran
            gsl
            ipopt
            lapack
            pkg-config
            openblas
            openjdk
          ];
          shellHook = ''
            export SHELL=$BASH
            export LANG=en_US.UTF-8
            export PS1="emtg|$PS1"
          '';
        };
      });
}
