{ pkgs ? import <nixpkgs> { }
, lkgs ? import <nixpkgs> { system = "x86_64-linux"; }
}:

pkgs.dockerTools.pullImage {
  imageName = "nixos/nix";
  finalImageName = "nix";
  finalImageTag = "unstable";
  sha256 = "1d4a73080ee9bed1fa20306e0b40da7da603a5e4fafc99e2b1df530d92610246";
  imageDigest = "1d4a73080ee9";
  os = "linux";
  arch = "x86_64";
}
  
pkgs.dockerTools.buildImage {
  name = "emtg";
  tag = "latest";

  config = {
    Cmd = [ "${lkgs.bash}/bin/bash" ];
  };
}
