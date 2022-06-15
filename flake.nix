{
  description = "A better, safer C++ Core Library";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    utils.url = "github:numtide/flake-utils/v1.0.0";
  };

  outputs = {
    self,
    nixpkgs,
    utils,
  }:
    utils.lib.eachDefaultSystem (system: let
      pkgs = nixpkgs.legacyPackages.${system};
    in {
      devShells.default = pkgs.mkShell {
        packages = with pkgs; [
          # C++
          cmake
          ninja
          gdb
          doxygen

          # Formatting
          fd
          alejandra # Nix
          clang-tools # C++
          cmake-format # CMake
          nodePackages.prettier # JSON, YAML
          shfmt # Shell
        ];
      };
    });
}
