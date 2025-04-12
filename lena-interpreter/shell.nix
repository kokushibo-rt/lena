{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = [
    pkgs.gcc
    pkgs.clang
    pkgs.cmake
    pkgs.ninja
    pkgs.libffi
  ];
}
