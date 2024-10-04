{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixpkgs-unstable"; # or "nixpkgs/nixos-22.05"
    flake-utils.url = "github:numtide/flake-utils";

    # must be git not github for submodules
    qmk_firmware = { url = "git+https://github.com/qmk/qmk_firmware?submodules=1&shallow=1"; flake = false; };
  };

  outputs = { self, nixpkgs, flake-utils, qmk_firmware }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };
	userDir = "/qmk_firmware/users/fride";
	keyboard = "ferris/0_2";
      in
      rec {
        # TODO could probably make this a standalone thing
        packages.firmware = pkgs.stdenv.mkDerivation rec {
          name = "firmware.bin";
          src = qmk_firmware;

          buildInputs = with pkgs; [
            qmk
	    qmk-udev-rules
	    git
	    just
          ];

          postUnpack = ''
            ln -s ${./src/users/fride} $sourceRoot/users/fride
	    ln -s ${./src/keymaps/ferris} $sourceRoot/keyboards/ferris/keymaps/fride
          '';

          buildPhase = ''
            # make keebio/nyquist/rev2:alternate SKIP_GIT=1
	    make ferris/0_2:fride SKIP_GIT=1
	    # qmk compile -kb ${keyboard} -km fride
          '';

          installPhase = ''
	    cp ferris_0_2_base_fride.bin $out
          '';
        };

        packages.flash = pkgs.writeScript "qmk-flash" ''
          cd ${qmk_firmware}
          ${pkgs.qmk}/bin/qmk flash ${packages.firmware}
        '';

        apps.flash = {
          type = "app";
          program = "${packages.flash}";
        };

        # Defaults =======================

        packages.default = packages.firmware;
        apps.default = apps.flash;
      });
}

