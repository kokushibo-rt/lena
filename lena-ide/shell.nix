{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = [
    pkgs.glfw3
    pkgs.pkg-config
    pkgs.libGL
  ];
}
