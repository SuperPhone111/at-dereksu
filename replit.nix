{ pkgs }: {
	deps = [
   pkgs.tig
		pkgs.clang
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}