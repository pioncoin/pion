Pion Core version 0.12.3.3
==========================

Release is now available from:

  <https://www.pioncoin.org/downloads/#wallets>

This is a critical bugfix release, bringing various bugfixes and other
improvements.

Please report bugs using the issue tracker at github:

  <https://github.com/pioncoin/pion/issues>


Upgrading and downgrading
=========================

How to Upgrade
--------------

If you are running an older version, shut it down. Wait until it has completely
shut down (which might take a few minutes for older versions), then run the
installer (on Windows) or just copy over /Applications/Pion-Qt (on Mac) or
piond/pion-qt (on Linux).

Downgrade warning
-----------------

### Downgrade to a version < 0.12.2.2

Because release 0.12.2.2 included the [per-UTXO fix](release-notes/pion/release-notes-0.12.2.2.md#per-utxo-fix)
which changed the structure of the internal database, you will have to reindex
the database if you decide to use any pre-0.12.2.2 version.

Wallet forward or backward compatibility was not affected.

### Downgrade to 0.12.2.2/3, 0.12.3.1/2

Downgrading to these versions does not require any additional actions, should be
fully compatible.


Notable changes
===============

Fix crash bug with duplicate inputs within a transaction
--------------------------------------------------------
There was a critical bug discovered in Bitcoin Core's codebase recently which
can cause node receiving a block to crash https://github.com/bitcoin/bitcoin/pull/14247

Improve initial sync
--------------------

Some users had problems getting their nodes synced. The issue occured due to nodes trying to
get additional data from each available peer but not being able to process this data fast enough.
This was recognized as a stalled sync process and thus the process was reset. To address the issue
we limited sync process to 3 peers max now and the issue should no longer appear as long as there
are at least 4 connections.

Testnet/Devnet fixes
--------------------

Turned out that a low-diff rule for slow blocks backported from Bitcoin works a bit too aggressive for
a blockchain which uses a dynamic per-block difficulty adjustment algorithm (DGW). While blocks are still
produced at a more or less constant rate on average, the rate however is way too high.

We also lifted multiple ports restriction on devnet and also incuded other fixes which should improve
connectivity on devnets which are using nodes with multiple different ports.


0.12.3.3 Change log
===================

See detailed [change log](https://github.com/pioncoin/pion/compare/v0.12.3.2...pioncoin:v0.12.3.3) below.

### Network:
- [`3abb3befb`](https://github.com/pioncoin/pion/commit/3abb3befb) Sync mn list and mnw list from 3 peers max (#2169)
- [`3abb3befb`](https://github.com/pioncoin/pion/commit/3abb3befb) A few devnet related fixes (#2168)

### Mining:
- [`3abb3befb`](https://github.com/pioncoin/pion/commit/3abb3befb) Add tests for special rules for slow blocks on devnet/testnet (#2176)
- [`3abb3befb`](https://github.com/pioncoin/pion/commit/3abb3befb) Allow mining min diff for very slow (2h+) blocks (#2175)
- [`3abb3befb`](https://github.com/pioncoin/pion/commit/3abb3befb) Adjust diff for slow testnet/devnet blocks a bit smoother (#2161)

### GUI:
- [`3abb3befb`](https://github.com/pioncoin/pion/commit/3abb3befb) Fix issues with selections on Masternode tab (#2170)
- [`3abb3befb`](https://github.com/pioncoin/pion/commit/3abb3befb) Make PS Buttons not react to spacebar (#2154)

### Other:
- [`5849b7c09`](https://github.com/pioncoin/pion/commit/5849b7c09) Fix miner tests for x16r. Update release notes 


Credits
=======

Thanks to everyone who directly contributed to this release:

- Pion Core

As well as Dash Core Developers and everyone who submitted issues and reviewed pull requests.


Older releases
==============

Pion was previously known as Darkcoin.

Darkcoin tree 0.8.x was a fork of Litecoin tree 0.8, original name was XCoin
which was first released on Jan/18/2014.

Darkcoin tree 0.9.x was the open source implementation of masternodes based on
the 0.8.x tree and was first released on Mar/13/2014.

Darkcoin tree 0.10.x used to be the closed source implementation of Darksend
which was released open source on Sep/25/2014.

Pion Core tree 0.11.x was a fork of Bitcoin Core tree 0.9,
Darkcoin was rebranded to Pion.

Pion Core tree 0.12.0.x was a fork of Bitcoin Core tree 0.10.

Pion Core tree 0.12.1.x was a fork of Bitcoin Core tree 0.12.

These release are considered obsolete. Old release notes can be found here:
- [v0.12.3.2](https://github.com/pioncoin/pion/blob/master/doc/release-notes/pion/release-notes-0.12.3.2.md) released Aug/02/2018
- [v0.12.3.1](https://github.com/pioncoin/pion/blob/master/doc/release-notes/pion/release-notes-0.12.3.1.md) released Jul/03/2018
- [v0.12.2.3](https://github.com/pioncoin/pion/blob/master/doc/release-notes/pion/release-notes-0.12.2.3.md) released Jan/12/2018
- [v0.12.2.2](https://github.com/pioncoin/pion/blob/master/doc/release-notes/pion/release-notes-0.12.2.2.md) released Dec/17/2017
- [v0.12.2](https://github.com/pioncoin/pion/blob/master/doc/release-notes/pion/release-notes-0.12.2.md) released Nov/08/2017
- [v0.12.1](https://github.com/pioncoin/pion/blob/master/doc/release-notes/pion/release-notes-0.12.1.md) released Feb/06/2017
- [v0.12.0](https://github.com/pioncoin/pion/blob/master/doc/release-notes/pion/release-notes-0.12.0.md) released Jun/15/2015
- [v0.11.2](https://github.com/pioncoin/pion/blob/master/doc/release-notes/pion/release-notes-0.11.2.md) released Mar/04/2015
- [v0.11.1](https://github.com/pioncoin/pion/blob/master/doc/release-notes/pion/release-notes-0.11.1.md) released Feb/10/2015
- [v0.11.0](https://github.com/pioncoin/pion/blob/master/doc/release-notes/pion/release-notes-0.11.0.md) released Jan/15/2015
- [v0.10.x](https://github.com/pioncoin/pion/blob/master/doc/release-notes/pion/release-notes-0.10.0.md) released Sep/25/2014
- [v0.9.x](https://github.com/pioncoin/pion/blob/master/doc/release-notes/pion/release-notes-0.9.0.md) released Mar/13/2014

