{
  description = "A flake for pythonification";

  inputs = { 
    nixpkgs.url = "github:nixos/nixpkgs";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils, ... }@inputs:
  flake-utils.lib.eachSystem ["x86_64-darwin" "aarch64-darwin" "x86_64-linux" "aarch64-linux"] (system:
  let
    pkgs = import nixpkgs { inherit system; };
  in {

    devShells = {
      default = pkgs.mkShell {
        name = "namirs";
        packages = with pkgs; [ clang ];
      };
    };

    
    packages.default = pkgs.stdenv.mkDerivation (finalAttrs: {
        pname = "namirs";
        version = "0.0.1";
        src = ./.;

        installPhase = ''
          mkdir -p $out/bin
          cp -r bin $out
        '';

    });

  });
}