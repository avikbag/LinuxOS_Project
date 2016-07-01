-----BEGIN PGP SIGNED MESSAGE-----
Hash: SHA1

Format: 3.0 (quilt)
Source: gdb
Binary: gdb, gdb-minimal, gdb64, gdb-multiarch, gdbserver, gdb-source, gdb-doc
Architecture: any all
Version: 7.7.1-0ubuntu5~14.04.2
Maintainer: Ubuntu Developers <ubuntu-devel-discuss@lists.ubuntu.com>
Uploaders: Luca Bruno <lucab@debian.org>, Samuel Bronson <naesten@gmail.com>
Homepage: http://www.gnu.org/s/gdb/
Standards-Version: 3.9.4
Vcs-Browser: http://anonscm.debian.org/gitweb/?p=crosstoolchain/gdb.git
Vcs-Git: git://anonscm.debian.org/crosstoolchain/gdb.git
Build-Depends: cdbs (>= 0.4.17), debhelper (>= 7.0.50), lsb-release, bzip2, autoconf, libtool, gettext, bison, dejagnu, flex | flex-old, procps, g++-multilib [i386 powerpc s390 sparc], gcj-jdk | gcj, gobjc, mig [hurd-any], texinfo (>= 4.7-2.2), texlive-base, libexpat1-dev, lib64expat1-dev [i386 powerpc s390 sparc], libncurses5-dev, lib64ncurses5-dev [i386 powerpc s390 sparc], libreadline-dev, lib64readline6-dev [i386 powerpc s390 sparc], zlib1g-dev, libbz2-dev, liblzma-dev, libpython3-dev, libkvm-dev [kfreebsd-any], libunwind7-dev [ia64], systemtap-sdt-dev [!arm64 !ppc64el], texlive-latex-base, texlive-fonts-recommended
Package-List: 
 gdb deb devel optional
 gdb-doc deb doc optional
 gdb-minimal deb devel optional
 gdb-multiarch deb devel optional
 gdb-source deb devel optional
 gdb64 deb devel optional
 gdbserver deb devel optional
Checksums-Sha1: 
 35228319f7c715074a80be42fff64c7645227a80 24849503 gdb_7.7.1.orig.tar.bz2
 662f1ac8eab1cc9b553fb93945f86ada5b862074 75475 gdb_7.7.1-0ubuntu5~14.04.2.debian.tar.gz
Checksums-Sha256: 
 0dbd5260406f1b0c70fcf027c6488527fadde0cd9bb574593491fe076eb03aa5 24849503 gdb_7.7.1.orig.tar.bz2
 9715e1e12b0b5c5bf337125b5c6928fa7c102f771c81b4662097e49dd1a2b282 75475 gdb_7.7.1-0ubuntu5~14.04.2.debian.tar.gz
Files: 
 77b20b515e7c25f032cb9732a66620fe 24849503 gdb_7.7.1.orig.tar.bz2
 56fb0dfca46b3dc879849583e802c549 75475 gdb_7.7.1-0ubuntu5~14.04.2.debian.tar.gz
Original-Maintainer: Héctor Orón Martínez <zumbi@debian.org>

-----BEGIN PGP SIGNATURE-----
Version: GnuPG v1

iEYEARECAAYFAlQ2kBsACgkQStlRaw+TLJxlJQCgseDs4e8bc7k/u54rxUKHURNz
FQkAoIGTZba8/XC/a2UvDl0MuML5uhQA
=QvZE
-----END PGP SIGNATURE-----
