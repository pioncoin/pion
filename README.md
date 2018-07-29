Pion Core staging tree 0.12.3
===============================

`master:` [![Build Status](https://travis-ci.org.pioncoinpay/pion.svg?branch=master)](https://travis-ci.org.pioncoinpay/pion) `develop:` [![Build Status](https://travis-ci.org.pioncoinpay/pion.svg?branch=develop)](https://travis-ci.org.pioncoinpay/pion/branches)

https://www.pioncoin.org


What is Pion?
----------------

Pion is a new decentralized Peer to Peer cryptocurrency that is simple, fast, and secure. The system uses Proof of Work (Mining) utilizing X16R algorithm and Masternodes for a fair and efficient allotment/distribution of Pion coins. To keep the coin decentralized the mining will be limited to GPU’s only and will be ASIC resistant. Pion wants to remove barriers to entry by making it simple for people to acquire and transact coins on the Pion network. Pion makes it effortless for people from all walks of life to mine, earn, own, trade and transact using the Pion coin.


License
-------

Pion Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `master` branch is meant to be stable. Development is normally done in separate branches.
[Tags](https://github.com/pioncoin/pion/tags) are created to indicate new official,
stable release versions of Pion Core.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](src/test/README.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`. Further details on running
and extending unit tests can be found in [/src/test/README.md](/src/test/README.md).

There are also [regression and integration tests](/qa) of the RPC interface, written
in Python, that are run automatically on the build server.
These tests can be run (if the [test dependencies](/qa) are installed) with: `qa/pull-tester/rpc-tests.py`

The Travis CI system makes sure that every pull request is built for Windows, Linux, and OS X, and that unit/sanity tests are run automatically.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.

Translations
------------

Changes to translations as well as new translations can be submitted to
[Pion Core's Transifex page](https://www.transifex.com/projects/p/pion/).

Translations are periodically pulled from Transifex and merged into the git repository. See the
[translation process](doc/translation_process.md) for details on how this works.

**Important**: We do not accept translation changes as GitHub pull requests because the next
pull from Transifex would automatically overwrite them again.

Translators should also follow the [forum](https://www.pioncoin.org/forum/topic/pion-worldwide-collaboration.88/).
